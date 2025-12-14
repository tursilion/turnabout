#!/usr/bin/env python3
import sys
import re
from collections import Counter

def extract_strings_from_story(filename):
    """
    Parse C++ source file and extract all strings from story[] declaration.
    
    Args:
        filename: Path to C++ source file
        
    Returns:
        List of strings found in the story[] array
    """
    with open(filename, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Find the story array declaration
    pattern = r'const\s+Story_t\s+story\[\]\s*=\s*\{'
    match = re.search(pattern, content)
    if not match:
        raise ValueError("Could not find 'const Story_t story[] = {' declaration")
    
    # Start parsing from the opening brace
    start_pos = match.end()
    brace_count = 1
    end_pos = start_pos
    
    # Find matching closing brace
    for i in range(start_pos, len(content)):
        if content[i] == '{':
            brace_count += 1
        elif content[i] == '}':
            brace_count -= 1
            if brace_count == 0:
                end_pos = i
                break
    
    if brace_count != 0:
        raise ValueError("Could not find matching closing brace for story[] declaration")
    
    # Extract the array content
    array_content = content[start_pos:end_pos]
    
    # Extract all quoted strings from the array content
    # Matches strings in double quotes, handling escaped quotes
    string_pattern = r'"([^"\\]*(?:\\.[^"\\]*)*)"'
    strings = re.findall(string_pattern, array_content)
    
    # Filter out empty strings
    strings = [s for s in strings if s]
    
    return strings

def build_dictionary(strings):
    """
    Build dictionary of 2 and 3 character fragments from string list.
    Excludes any fragments containing backslash due to compiler bug.
    
    Process:
    1. Extract all 3-character sequences
    2. Extract all 2-character sequences
    3. Filter out any containing backslash
    4. Count occurrences across all strings
    
    Args:
        strings: List of strings to process
        
    Returns:
        Counter object with fragment counts
    """
    dictionary = Counter()
    
    # Join all text for processing
    all_text = ' '.join(strings)
    
    # Add 3-character sequences (excluding those with backslash)
    for i in range(len(all_text) - 2):
        fragment = all_text[i:i+3]
        if '\\' not in fragment:
            dictionary[fragment] += 1
    
    # Add 2-character sequences (excluding those with backslash)
    for i in range(len(all_text) - 1):
        fragment = all_text[i:i+2]
        if '\\' not in fragment:
            dictionary[fragment] += 1
    
    return dictionary

def calculate_compression_value(entry, count):
    """
    Calculate compression value for a dictionary entry.
    
    Value is based on how many characters are saved by using this entry.
    A fragment saves (length - 1) * count characters.
    
    Args:
        entry: The string (fragment)
        count: Number of occurrences
        
    Returns:
        Integer representing compression value (characters saved)
    """
    # Each occurrence saves (length - 1) characters
    # because the entry replaces 'length' characters with 1 token
    return (len(entry) - 1) * count

def count_substring_occurrences(haystack_list, needle):
    """
    Count how many times a substring appears in a list of strings.
    
    Args:
        haystack_list: List of strings to search in
        needle: Substring to search for
        
    Returns:
        Total count of occurrences
    """
    total = 0
    for haystack in haystack_list:
        # Count overlapping occurrences
        pos = 0
        while True:
            pos = haystack.find(needle, pos)
            if pos == -1:
                break
            total += 1
            pos += 1
    return total

def is_entry_redundant(entry, selected_entries, strings):
    """
    Check if an entry is completely covered by higher-ranking entries.
    
    An entry is redundant if all its occurrences can be matched by
    already-selected dictionary entries.
    
    Args:
        entry: The dictionary entry to check
        selected_entries: List of already-selected higher-value entries
        strings: Original list of strings from the file
        
    Returns:
        True if entry is redundant, False otherwise
    """
    # Count how many times this entry appears in the original text
    actual_count = count_substring_occurrences(strings, entry)
    
    if actual_count == 0:
        return True
    
    # Simulate greedy matching with selected entries to see if they cover this entry
    covered_count = 0
    
    for text in strings:
        pos = 0
        text_bytes = text.encode('utf-8')
        
        while pos < len(text_bytes):
            # Try to match with selected entries (longest first)
            matched = False
            
            for selected_entry in selected_entries:
                selected_bytes = selected_entry.encode('utf-8')
                if text_bytes[pos:pos+len(selected_bytes)] == selected_bytes:
                    # This selected entry matches here
                    # Check if it covers an occurrence of our test entry
                    matched_text = text[pos:pos+len(selected_entry)]
                    if entry in selected_entry:
                        # Count how many times entry appears in this match
                        covered_count += matched_text.count(entry)
                    
                    pos += len(selected_bytes)
                    matched = True
                    break
            
            if not matched:
                pos += 1
    
    # If all occurrences are covered, this entry is redundant
    return covered_count >= actual_count

def remove_redundant_entries(sorted_entries, strings, max_entries=254):
    """
    Remove dictionary entries that are completely covered by higher-ranking entries.
    Stop when max_entries non-redundant entries have been found.
    
    Args:
        sorted_entries: List of (entry, count) tuples sorted by compression value
        strings: Original list of strings from the file
        max_entries: Maximum number of entries to retain (default 254)
        
    Returns:
        Filtered list of (entry, count) tuples with redundant entries removed
    """
    filtered = []
    
    for entry, count in sorted_entries:
        # Stop if we've reached the maximum
        if len(filtered) >= max_entries:
            break
        
        # Check if this entry is redundant given the already-selected entries
        selected_entries_only = [e for e, c in filtered]
        
        if not is_entry_redundant(entry, selected_entries_only, strings):
            filtered.append((entry, count))
        else:
            print("Removing redundant entry: '{}'".format(entry.replace(' ', '<space>').replace('\\', '<backslash>')))
    
    return filtered

def get_top_entries(dictionary, strings, max_entries=254):
    """
    Sort dictionary by compression value and retain only top N entries.
    Compression value = (length - 1) * count
    This prefers longer fragments when they save more space.
    Also removes redundant entries that are completely covered by higher-ranking ones.
    Finally sorts by length (longest first) for optimal greedy matching.
    
    Args:
        dictionary: Counter object with fragment counts
        strings: Original list of strings from the file
        max_entries: Maximum number of entries to retain (default 254)
        
    Returns:
        List of tuples (entry, count) sorted by length descending
    """
    # Calculate compression value for each entry
    # Sort by compression value (descending), then by length (descending), then alphabetically
    entries_with_value = []
    for entry, count in dictionary.items():
        value = calculate_compression_value(entry, count)
        entries_with_value.append((entry, count, value))
    
    # Sort by compression value (descending), then length (descending), then alphabetically
    sorted_entries = sorted(entries_with_value, 
                           key=lambda x: (-x[2], -len(x[0]), x[0]))
    
    # Convert to (entry, count) tuples
    sorted_entries = [(entry, count) for entry, count, value in sorted_entries]
    
    # Remove redundant entries, stopping at max_entries
    filtered_entries = remove_redundant_entries(sorted_entries, strings, max_entries)
    
    # Final sort: longest strings first, then alphabetically
    # This ensures greedy matching finds longest matches first
    filtered_entries = sorted(filtered_entries, key=lambda x: (-len(x[0]), x[0]))
    
    return filtered_entries

def compress_string(text, dictionary_list):
    """
    Compress a string using the dictionary.
    Uses greedy longest-match algorithm.
    Dictionary must be sorted longest-first for this to work optimally.
    
    Encoding:
    - Bytes 0-253: Dictionary indices
    - Byte 254: Literal sequence escape (followed by length byte, then literal bytes)
    - Byte 255: Single literal escape (followed by one literal byte)
    
    Args:
        text: String to compress (as bytes)
        dictionary_list: List of dictionary entries (strings), sorted longest-first
        
    Returns:
        List of integers representing compressed bytes
    """
    compressed = []
    pos = 0
    text_bytes = text.encode('utf-8')
    
    while pos < len(text_bytes):
        # Try to find longest matching dictionary entry starting at current position
        # Since dictionary is sorted longest-first, first match is best match
        best_match_len = 0
        best_match_idx = -1
        
        for idx, entry in enumerate(dictionary_list):
            entry_bytes = entry.encode('utf-8')
            if text_bytes[pos:pos+len(entry_bytes)] == entry_bytes:
                # Found a match - take it (it's the longest due to sorting)
                best_match_len = len(entry_bytes)
                best_match_idx = idx
                break
        
        if best_match_idx >= 0:
            # Found a match in dictionary
            compressed.append(best_match_idx)
            pos += best_match_len
        else:
            # No match - need to output literal bytes
            # Collect consecutive unmatched bytes
            literal_start = pos
            while pos < len(text_bytes):
                # Check if any dictionary entry matches at this position
                found_match = False
                for entry in dictionary_list:
                    entry_bytes = entry.encode('utf-8')
                    if text_bytes[pos:pos+len(entry_bytes)] == entry_bytes:
                        found_match = True
                        break
                
                if found_match:
                    break
                pos += 1
            
            literal_bytes = text_bytes[literal_start:pos]
            literal_len = len(literal_bytes)
            
            if literal_len == 1:
                # Single literal - use escape code 255
                compressed.append(255)
                compressed.append(literal_bytes[0])
            else:
                # Multiple literals - use escape code 254
                compressed.append(254)
                compressed.append(literal_len)
                compressed.extend(literal_bytes)
    
    return compressed

def escape_byte(byte_val):
    """
    Convert a byte value to C string representation.
    Only escape characters that C requires to be escaped.
    Skip backslash entirely due to compiler bug.
    
    Args:
        byte_val: Integer (0-255) representing byte value
        
    Returns:
        String representation for C source, or None for backslash
    """
    # Skip backslash due to compiler bug
    if byte_val == 92:  # ASCII backslash
        return None
    
    # Printable ASCII characters (excluding special cases)
    if 32 <= byte_val <= 126:
        char = chr(byte_val)
        # Only escape characters that must be escaped in C strings
        if char == '"':
            return '\\"'
        else:
            return char
    else:
        # Non-printable - use octal escape
        return '\\{:03o}'.format(byte_val)

def escape_string_for_c(text):
    """
    Escape a string for C string literal output.
    Only escape characters that C requires to be escaped.
    Skip backslash entirely due to compiler bug.
    
    Args:
        text: String to escape
        
    Returns:
        Escaped string suitable for C source
    """
    result = []
    for char in text:
        # Skip backslash due to compiler bug
        if char == '\\':
            continue
        
        byte_val = ord(char)
        if char == '"':
            result.append('\\"')
        elif 32 <= byte_val <= 126:
            result.append(char)
        else:
            result.append('\\{:03o}'.format(byte_val))
    return ''.join(result)

def compress_and_format_string(text, dictionary_list):
    """
    Compress string and format as C string literal with length prefix.
    
    Args:
        text: Original string
        dictionary_list: List of dictionary entries
        
    Returns:
        Tuple of (formatted_string, original_size, compressed_size)
    """
    compressed = compress_string(text, dictionary_list)
    
    # Build output string with length prefix, skipping backslashes
    output_chars = []
    escaped_len = escape_byte(len(compressed))
    if escaped_len is not None:
        output_chars.append(escaped_len)
    
    for byte_val in compressed:
        escaped = escape_byte(byte_val)
        if escaped is not None:
            output_chars.append(escaped)
    
    return ('"{}"'.format(''.join(output_chars)), len(text.encode('utf-8')), len(compressed))

def generate_dictionary_code(dictionary_list):
    """
    Generate C code for the dictionary array.
    
    Args:
        dictionary_list: List of dictionary entries
        
    Returns:
        String containing C code for dictionary declaration
    """
    lines = []
    lines.append("/* Dictionary for string compression */")
    lines.append("/* Indices 0-253: Dictionary entries */")
    lines.append("/* Index 254: Literal sequence escape */")
    lines.append("/* Index 255: Single literal escape */")
    lines.append("/* Note: Backslash characters removed due to compiler bug */")
    lines.append("const char* story_dictionary[] = {")
    
    for idx, entry in enumerate(dictionary_list):
        escaped_entry = escape_string_for_c(entry)
        lines.append('    "{}",  /* {:3d} */'.format(escaped_entry, idx))
    
    lines.append("};")
    lines.append("")
    
    return '\n'.join(lines)

def process_file(filename, dictionary_list):
    """
    Process C file and compress all strings in story[] array.
    
    Args:
        filename: Input filename
        dictionary_list: List of dictionary entries for compression
        
    Returns:
        Tuple of (new_content, original_size, compressed_size)
    """
    with open(filename, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Find the story array declaration
    pattern = r'const\s+Story_t\s+story\[\]\s*=\s*\{'
    match = re.search(pattern, content)
    if not match:
        raise ValueError("Could not find 'const Story_t story[] = {' declaration")
    
    # Insert dictionary before the story array
    dictionary_code = generate_dictionary_code(dictionary_list)
    insertion_point = match.start()
    
    start_pos = match.end()
    brace_count = 1
    end_pos = start_pos
    
    # Find matching closing brace
    for i in range(start_pos, len(content)):
        if content[i] == '{':
            brace_count += 1
        elif content[i] == '}':
            brace_count -= 1
            if brace_count == 0:
                end_pos = i
                break
    
    array_content = content[start_pos:end_pos]
    
    # Process each line in the array
    original_size = 0
    compressed_size = 0
    new_lines = []
    
    for line in array_content.split('\n'):
        # Find string in quotes
        string_match = re.search(r'"([^"\\]*(?:\\.[^"\\]*)*)"', line)
        if string_match:
            original_string = string_match.group(1)
            
            # Check if empty string - output as-is
            if not original_string:
                new_lines.append(line)
                continue
            
            # Unescape the string for processing
            unescaped = original_string.replace('\\"', '"').replace('\\\\', '\\')
            
            compressed_str, orig_len, comp_len = compress_and_format_string(unescaped, dictionary_list)
            original_size += orig_len
            compressed_size += comp_len + 1  # +1 for length byte
            
            # Replace the string in the line
            new_line = line[:string_match.start()] + compressed_str + line[string_match.end():]
            new_lines.append(new_line)
        else:
            new_lines.append(line)
    
    # Reconstruct file
    new_array_content = '\n'.join(new_lines)
    new_content = (content[:insertion_point] + 
                   dictionary_code + 
                   content[match.start():start_pos] + 
                   new_array_content + 
                   content[end_pos:])
    
    return (new_content, original_size, compressed_size)

def calculate_dictionary_size(dictionary_list):
    """
    Calculate total size of dictionary text in bytes.
    Excludes backslashes due to compiler bug.
    
    Args:
        dictionary_list: List of dictionary entries
        
    Returns:
        Total size in bytes
    """
    total = 0
    for entry in dictionary_list:
        # Count bytes, excluding backslashes
        total += len(entry.replace('\\', '').encode('utf-8'))
    return total

def main():
    if len(sys.argv) != 2:
        print("Usage: {} <cpp_source_file>".format(sys.argv[0]))
        sys.exit(1)
    
    filename = sys.argv[1]
    
    try:
        # Extract strings from C source
        strings = extract_strings_from_story(filename)
        print("Extracted {} non-empty strings from story[] declaration".format(len(strings)))
        
        # Build dictionary with counts (excluding fragments with backslash)
        dictionary = build_dictionary(strings)
        print("Dictionary contains {} unique entries before filtering".format(len(dictionary)))
        
        # Get top 254 entries (indices 0-253)
        # Indices 254 and 255 are reserved for escape codes
        print("\nRemoving redundant entries...")
        top_entries = get_top_entries(dictionary, strings, 254)
        
        # Build final dictionary list
        dictionary_list = [entry for entry, count in top_entries]
        
        # Calculate dictionary size
        dict_size = calculate_dictionary_size(dictionary_list)
        
        print("\nDictionary entries (0-{}) - sorted longest first:\n".format(len(top_entries) - 1))
        print("-" * 60)
        
        for idx, (entry, count) in enumerate(top_entries):
            value = calculate_compression_value(entry, count)
            # Show space character visibly
            display_entry = entry.replace(' ', '<space>').replace('\\', '<backslash>')
            print("{:3d}: {:40s} : count={:4d} value={:5d}".format(idx, display_entry, count, value))
        
        print("\nEscape codes:")
        print("254: Literal sequence (followed by length byte + literal bytes)")
        print("255: Single literal (followed by one literal byte)")
        
        # Compress and write output file
        new_content, original_size, compressed_size = process_file(filename, dictionary_list)
        
        output_filename = filename.rsplit('.', 1)[0] + '.packed.i'
        with open(output_filename, 'w', encoding='utf-8') as f:
            f.write(new_content)
        
        print("\n" + "=" * 60)
        print("Compression complete:")
        print("Dictionary entries:          {}".format(len(dictionary_list)))
        print("Dictionary size:             {} bytes (backslashes excluded)".format(dict_size))
        print("Original string data size:   {} bytes".format(original_size))
        print("Compressed string data size: {} bytes".format(compressed_size))
        print("Compression ratio:           {:.1f}%".format(100.0 * compressed_size / original_size if original_size > 0 else 0))
        print("Saved:                       {} bytes".format(original_size - compressed_size))
        print("\nOutput written to: {}".format(output_filename))
        
    except Exception as e:
        print("Error: {}".format(str(e)))
        sys.exit(1)

if __name__ == "__main__":
    main()
    