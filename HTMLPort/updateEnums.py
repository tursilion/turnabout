#!/usr/bin/env python3
"""
Converts C enum definitions to JavaScript const declarations.
Reads first enum block and generates individual const declarations
until EV_MAX is encountered. Ignores C-style comments.
"""

import sys
import re

def remove_comments(text):
    """
    Remove C-style comments (both // and /* */) from text.
    
    Args:
        text: Input text containing C code
        
    Returns:
        Text with comments removed
    """
    # Remove single-line comments (//)
    text = re.sub(r'//.*?$', '', text, flags=re.MULTILINE)
    
    # Remove multi-line comments (/* */)
    text = re.sub(r'/\*.*?\*/', '', text, flags=re.DOTALL)
    
    return text

def parse_enum_to_js(input_file, output_file):
    """
    Parse C enum and convert to JavaScript const declarations.
    Stops when EV_MAX is encountered.
    
    Args:
        input_file: Path to input C source file
        output_file: Path to output JavaScript file
    """
    try:
        with open(input_file, 'r', encoding='utf-8') as f:
            content = f.read()
    except IOError as e:
        print(f"Error reading input file: {e}", file=sys.stderr)
        sys.exit(1)
    
    # Remove all comments first
    content = remove_comments(content)
    
    # Find first enum block
    # Pattern matches: enum { ... }
    enum_pattern = re.compile(r'enum\s*\{([^}]+)\}', re.DOTALL)
    enum_match = enum_pattern.search(content)
    
    if not enum_match:
        print("Error: No enum block found", file=sys.stderr)
        sys.exit(1)
    
    enum_body = enum_match.group(1)
    
    # Parse enum entries
    # Match identifier optionally followed by = value
    # Handles whitespace
    entry_pattern = re.compile(
        r'([A-Za-z_][A-Za-z0-9_]*)\s*(?:=\s*([^,\n]+))?\s*,?',
        re.MULTILINE
    )
    
    entries = []
    current_value = 0
    
    for match in entry_pattern.finditer(enum_body):
        identifier = match.group(1).strip()
        explicit_value = match.group(2)
        
        # Skip empty matches
        if not identifier:
            continue
        
        # Stop at EV_MAX
        if identifier == 'EV_MAX':
            break
        
        # Calculate value
        if explicit_value:
            explicit_value = explicit_value.strip()
            
            # Try to evaluate as integer if it's a simple number
            try:
                current_value = int(explicit_value, 0)
            except ValueError:
                # If not a simple number, keep as expression
                # This handles cases like 1<<5 or other constants
                entries.append((identifier, explicit_value))
                # Can't auto-increment from expression, next must be explicit
                current_value = None
                continue
        
        if current_value is None:
            print(f"Error: {identifier} follows non-numeric value without explicit assignment", file=sys.stderr)
            sys.exit(1)
        
        entries.append((identifier, str(current_value)))
        current_value += 1
    
    # Generate JavaScript output
    output_lines = []
    
    for identifier, value in entries:
        output_lines.append(f'const {identifier} = {value};')
    
    # Write output
    try:
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write('\n'.join(output_lines))
            f.write('\n')
    except IOError as e:
        print(f"Error writing output file: {e}", file=sys.stderr)
        sys.exit(1)

def main():
    """
    Main entry point. Expects input and output filenames as command line arguments.
    """
    if len(sys.argv) != 3:
        print("Usage: python script.py <input.c> <output.js>", file=sys.stderr)
        sys.exit(1)
    
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    
    parse_enum_to_js(input_file, output_file)
    print(f"Conversion complete: {input_file} -> {output_file}")

if __name__ == '__main__':
    main()
    