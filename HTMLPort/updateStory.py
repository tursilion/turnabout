#!/usr/bin/env python3
"""
Converts C source file containing Story_t structures into JavaScript format.
Reads location-based story data and outputs as JavaScript object with indexed arrays.
"""

import sys
import re

def parse_c_story_to_js(input_file, output_file):
    """
    Parse C source file and convert Story_t structures to JavaScript format.
    
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
    
    # Pattern to match location definitions (e.g., LOCATION_IS_0)
    location_pattern = re.compile(r'#ifdef\s+LOCATION_IS_(\d+)')
    
    # Pattern to match story structure entries
    # Captures four comma-separated fields within braces
    entry_pattern = re.compile(
        r'\{\s*([^,]+),\s*([^,]+),\s*([^,]+),\s*("(?:[^"\\]|\\.)*")\s*\}',
        re.MULTILINE
    )
    
    locations = {}
    current_location = None
    
    lines = content.split('\n')
    in_story_block = False
    
    for line in lines:
        # Check for location marker
        location_match = location_pattern.search(line)
        if location_match:
            current_location = int(location_match.group(1))
            locations[current_location] = []
            continue
        
        # Check for start of story array
        if 'const Story_t story[]' in line or 'Story_t story[]' in line:
            in_story_block = True
            continue
        
        # Check for end of story block (closing brace followed by semicolon)
        if in_story_block and '};' in line:
            in_story_block = False
            current_location = None
            continue
        
        # Parse story entries if we're in a story block and have a current location
        if in_story_block and current_location is not None:
            entry_match = entry_pattern.search(line)
            if entry_match:
                # Extract all four fields verbatim (strip whitespace only)
                evidence = entry_match.group(1).strip()
                frame = entry_match.group(2).strip()
                cmdwho = entry_match.group(3).strip()
                text = entry_match.group(4).strip()
                
                locations[current_location].append({
                    'evidence': evidence,
                    'frame': frame,
                    'cmdwho': cmdwho,
                    'text': text
                })
    
    # Generate JavaScript output
    output_lines = ['const storyData = {']
    
    # Sort location keys for consistent output
    sorted_locations = sorted(locations.keys())
    
    for i, loc_key in enumerate(sorted_locations):
        entries = locations[loc_key]
        output_lines.append(f'    {loc_key}: [')
        
        for j, entry in enumerate(entries):
            # Format entry with proper field names
            line = (f'        {{evidence: {entry["evidence"]}, '
                   f'frame: {entry["frame"]}, '
                   f'cmdwho: {entry["cmdwho"]}, '
                   f'text: {entry["text"]}}}')
            
            # Add comma if not last entry
            if j < len(entries) - 1:
                line += ','
            
            output_lines.append(line)
        
        # Close array, add comma if not last location
        if i < len(sorted_locations) - 1:
            output_lines.append('    ],')
        else:
            output_lines.append('    ]')
    
    output_lines.append('};')
    
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
    
    parse_c_story_to_js(input_file, output_file)
    print(f"Conversion complete: {input_file} -> {output_file}")

if __name__ == '__main__':
    main()
