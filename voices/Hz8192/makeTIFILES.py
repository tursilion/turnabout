#!/usr/bin/env python3
"""
TIFILES Binary Prepender
Reads a binary file, prepends a 2-byte length header to the payload,
then wraps everything in a 128-byte TIFILES header.
"""

import sys
import struct
from pathlib import Path

def create_tifiles_header(total_sectors, file_type='PROGRAM', 
                          rec_per_sect=0, eof_offset=0, rec_length=0, 
                          flags=0x01):
    """
    Create a 128-byte TIFILES header.
    
    Args:
        total_sectors: Total number of 256-byte sectors in the file
        file_type: 'PROGRAM', 'DATA_FIXED', or 'DATA_VARIABLE'
        rec_per_sect: Records per sector (for data files)
        eof_offset: EOF offset in last sector (for variable files)
        rec_length: Record length (for fixed files)
        flags: File flags byte (default 0x01 for PROGRAM)
    
    Returns:
        bytes: 128-byte TIFILES header
    """
    header = bytearray(128)
    
    # Bytes 0-7: Magic number "TIFILES"
    header[0] = 0x07
    header[1:8] = b'TIFILES'
    
    # Byte 8-9: Total number of sectors (big-endian)
    header[8:10] = struct.pack('>H', total_sectors)
    
    # Byte 10: Flags
    header[10] = flags
    
    # Byte 11: Records per sector
    header[11] = rec_per_sect
    
    # Byte 12: EOF offset
    header[12] = eof_offset
    
    # Byte 13: Record length
    header[13] = rec_length
    
    # Byte 14-15: Number of Level-3 records (little-endian, 0x0000 for program)
    header[14:16] = struct.pack('<H', 0)
    
    # Bytes 16-127: All zeros (no filename, timestamp, or other fields)
    # Already initialized to 0x00 by bytearray(128)
    
    return bytes(header)

def read_binary_file(filepath):
    """
    Read binary file contents.
    
    Args:
        filepath: Path to input binary file
    
    Returns:
        bytes: File contents
    """
    with open(filepath, 'rb') as f:
        return f.read()

def create_tifiles(input_path, output_path):
    """
    Read binary file, prepend 2-byte length, wrap in TIFILES header.
    
    Args:
        input_path: Path to input binary file
        output_path: Path to output TIFILES file
    """
    # Read input binary
    binary_data = read_binary_file(input_path)
    binary_length = len(binary_data)
    
    # Create 2-byte length header (big-endian)
    length_header = struct.pack('>H', binary_length)
    
    # Combine length header with binary data
    payload = length_header + binary_data
    payload_length = len(payload)
    
    # Calculate total sectors needed (round up to 256-byte boundaries)
    total_sectors = (payload_length + 255) // 256
    
    # Pad payload to sector boundary
    padded_payload = payload + b'\x00' * (total_sectors * 256 - payload_length)
    
    # Calculate EOF offset (bytes used in last sector, 0 if full)
    eof_offset = payload_length % 256
    if eof_offset == 0 and payload_length > 0:
        eof_offset = 0  # Last sector is full
    
    # Create TIFILES header for PROGRAM file
    # Flags: 0x01 = PROGRAM/Data file
    header = create_tifiles_header(
        total_sectors=total_sectors,
        file_type='PROGRAM',
        rec_per_sect=0,
        eof_offset=eof_offset,
        rec_length=0,
        flags=0x01
    )
    
    # Write complete TIFILES file
    with open(output_path, 'wb') as f:
        f.write(header)
        f.write(padded_payload)
    
    print(f"Created TIFILES: {output_path}")
    print(f"  Original binary size: {binary_length} bytes")
    print(f"  Payload size (with 2-byte length): {payload_length} bytes")
    print(f"  Total sectors: {total_sectors}")
    print(f"  EOF offset: {eof_offset}")
    print(f"  Total file size: {128 + len(padded_payload)} bytes")

def main():
    """Main entry point."""
    if len(sys.argv) < 3:
        print("Usage: python tifiles_prepend.py <input_binary> <output_tifiles>")
        print("  input_binary: Path to input binary file")
        print("  output_tifiles: Path to output TIFILES file")
        sys.exit(1)
    
    input_path = sys.argv[1]
    output_path = sys.argv[2]
    
    if not Path(input_path).exists():
        print(f"Error: Input file not found: {input_path}")
        sys.exit(1)
    
    create_tifiles(input_path, output_path)

if __name__ == '__main__':
    main()
    