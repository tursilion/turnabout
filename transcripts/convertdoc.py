#!/usr/bin/env python3
"""
docx_to_js_struct.py

Reads a Word (.docx) script file formatted as speaker dialogue and converts
each line into a C-like structure entry for use in JavaScript source files.

Output format per line:
    {evidence: EV_NONE, frame: 0, cmdwho: PP_<SPEAKER> | CMD_NONE, text: "..." },

Speaker lines:      "Name: text"   -> PP_NAME
Section/title lines (no colon, not blank) -> PP_NONE
Special keywords (Objection!, Hold it!, Take that!) -> PP_NONE
Bold-formatted lines in the docx are treated as section headers -> PP_NONE

Usage:
    python3 docx_to_js_struct.py input.docx [output.txt]

    If output.txt is omitted, result is written to stdout.

Requirements:
    pip install python-docx
"""

import sys
import re
import unicodedata
import docx


# ---------------------------------------------------------------------------
# Unicode -> ASCII transliteration table.
# Covers common extended characters that appear in script documents.
# Superscripts, curly quotes, dashes, etc.
# ---------------------------------------------------------------------------
UNICODE_TO_ASCII = {
    # Superscript digits and letters
    '\u00B9': '1',   # superscript 1
    '\u00B2': '2',   # superscript 2
    '\u00B3': '3',   # superscript 3
    '\u2070': '0',   # superscript 0
    '\u2074': '4',   # superscript 4
    '\u2075': '5',   # superscript 5
    '\u2076': '6',   # superscript 6
    '\u2077': '7',   # superscript 7
    '\u2078': '8',   # superscript 8
    '\u2079': '9',   # superscript 9
    '\u00AA': 'a',   # feminine ordinal indicator (superscript a)
    '\u00BA': 'o',   # masculine ordinal indicator (superscript o)
    '\u02B0': 'h',   # modifier letter small h
    '\u02B3': 'r',   # modifier letter small r
    '\u02B4': 'r',   # modifier letter small turned r
    '\u02B5': 'r',   # modifier letter small r with hook
    '\u02B6': 'R',   # modifier letter small capital inverted r
    '\u02B8': 'y',   # modifier letter small y
    '\u02E2': 's',   # modifier letter small s
    '\u02E3': 'x',   # modifier letter small x
    '\u207F': 'n',   # superscript n  (used in "th", "nd", "rd", "st" patterns)
    '\u1D57': 't',   # superscript t
    '\u1D58': 'u',   # superscript u
    '\u1D5B': 'v',   # superscript v
    '\u1D48': 'd',   # superscript d
    '\u02E1': 'l',   # superscript l

    # Curly/smart quotes -> straight quotes
    '\u2018': "'",   # left single quotation mark
    '\u2019': "'",   # right single quotation mark / apostrophe
    '\u201A': "'",   # single low-9 quotation mark
    '\u201B': "'",   # single high-reversed-9 quotation mark
    '\u201C': '"',   # left double quotation mark
    '\u201D': '"',   # right double quotation mark
    '\u201E': '"',   # double low-9 quotation mark
    '\u201F': '"',   # double high-reversed-9 quotation mark
    '\u2039': '<',   # single left-pointing angle quotation mark
    '\u203A': '>',   # single right-pointing angle quotation mark
    '\u00AB': '"',   # left-pointing double angle quotation mark
    '\u00BB': '"',   # right-pointing double angle quotation mark

    # Dashes and spacing
    '\u2013': '-',   # en dash
    '\u2014': '--',  # em dash
    '\u2015': '--',  # horizontal bar
    '\u2012': '-',   # figure dash
    '\u2010': '-',   # hyphen
    '\u2011': '-',   # non-breaking hyphen
    '\u00AD': '-',   # soft hyphen
    '\u2212': '-',   # minus sign
    '\u00A0': ' ',   # non-breaking space
    '\u202F': ' ',   # narrow no-break space
    '\u2009': ' ',   # thin space
    '\u200A': ' ',   # hair space
    '\u2007': ' ',   # figure space
    '\u2008': ' ',   # punctuation space
    '\u3000': ' ',   # ideographic space

    # Ellipsis
    '\u2026': '...',

    # Misc punctuation
    '\u2022': '*',   # bullet
    '\u2023': '>',   # triangular bullet
    '\u00B7': '.',   # middle dot
    '\u00D7': 'x',   # multiplication sign
    '\u00F7': '/',   # division sign
    '\u00B0': ' degrees',  # degree sign

    # Accented characters -> base ASCII
    '\u00C0': 'A',  '\u00C1': 'A',  '\u00C2': 'A',  '\u00C3': 'A',
    '\u00C4': 'A',  '\u00C5': 'A',  '\u00C6': 'AE', '\u00C7': 'C',
    '\u00C8': 'E',  '\u00C9': 'E',  '\u00CA': 'E',  '\u00CB': 'E',
    '\u00CC': 'I',  '\u00CD': 'I',  '\u00CE': 'I',  '\u00CF': 'I',
    '\u00D0': 'D',  '\u00D1': 'N',  '\u00D2': 'O',  '\u00D3': 'O',
    '\u00D4': 'O',  '\u00D5': 'O',  '\u00D6': 'O',  '\u00D8': 'O',
    '\u00D9': 'U',  '\u00DA': 'U',  '\u00DB': 'U',  '\u00DC': 'U',
    '\u00DD': 'Y',  '\u00DE': 'Th', '\u00DF': 'ss',
    '\u00E0': 'a',  '\u00E1': 'a',  '\u00E2': 'a',  '\u00E3': 'a',
    '\u00E4': 'a',  '\u00E5': 'a',  '\u00E6': 'ae', '\u00E7': 'c',
    '\u00E8': 'e',  '\u00E9': 'e',  '\u00EA': 'e',  '\u00EB': 'e',
    '\u00EC': 'i',  '\u00ED': 'i',  '\u00EE': 'i',  '\u00EF': 'i',
    '\u00F0': 'd',  '\u00F1': 'n',  '\u00F2': 'o',  '\u00F3': 'o',
    '\u00F4': 'o',  '\u00F5': 'o',  '\u00F6': 'o',  '\u00F8': 'o',
    '\u00F9': 'u',  '\u00FA': 'u',  '\u00FB': 'u',  '\u00FC': 'u',
    '\u00FD': 'y',  '\u00FE': 'th', '\u00FF': 'y',
}

# Ordinal suffix patterns rendered as superscript runs (e.g. 1^st, 2^nd).
# If the preceding word ends in a digit and we see a superscript suffix word,
# we concatenate without a space.  Handled implicitly by the run-level pass.

# Keywords that trigger a PP_NONE speaker even when they don't have a colon.
# Match is case-insensitive, full-line or as a standalone word.
SPECIAL_KEYWORDS = re.compile(
    r'^(objection!?|hold\s+it!?|take\s+that!?)$',
    re.IGNORECASE
)


def to_ascii(text):
    """
    Convert a Unicode string to 7-bit ASCII.

    Process:
    1. Apply explicit character substitutions from UNICODE_TO_ASCII.
    2. Use unicodedata NFKD decomposition to strip combining marks from
       any remaining accented characters.
    3. Drop any character still outside the printable ASCII range (32-126).

    Returns a plain ASCII string.
    """
    # Step 1: explicit map substitutions
    result = []
    for ch in text:
        if ch in UNICODE_TO_ASCII:
            result.append(UNICODE_TO_ASCII[ch])
        else:
            result.append(ch)
    text = ''.join(result)

    # Step 2: NFKD decomposition - strip combining diacritical marks (category Mn)
    normalized = unicodedata.normalize('NFKD', text)
    text = ''.join(c for c in normalized if unicodedata.category(c) != 'Mn')

    # Step 3: drop any remaining non-printable-ASCII characters
    text = ''.join(c if 32 <= ord(c) <= 126 else '?' for c in text)

    return text


def is_superscript_run(run):
    """
    Return True if the docx run is formatted as superscript.

    python-docx exposes superscript via run.font.superscript.
    """
    return bool(run.font.superscript)


def paragraph_to_text(paragraph):
    """
    Reconstruct the paragraph's text from its runs, handling superscript
    runs by appending their text directly (no space) to the previous run's
    output, which gives us "1st", "2nd", etc. from "1" + superscript "st".

    Returns the assembled Unicode string (not yet ASCII-converted).
    """
    parts = []
    prev_super = False

    for run in paragraph.runs:
        run_text = run.text
        cur_super = is_superscript_run(run)

        if cur_super:
            # Superscript: append without leading space so "1" + "st" = "1st"
            parts.append(run_text)
        else:
            # Normal run.  If previous was superscript we already appended
            # directly; just add this run normally.
            parts.append(run_text)

        prev_super = cur_super

    return ''.join(parts)


def is_bold_paragraph(paragraph):
    """
    Return True if all non-empty runs in the paragraph are bold,
    which indicates a section header / title in the document convention.
    """
    runs = [r for r in paragraph.runs if r.text.strip()]
    if not runs:
        return False
    return all(r.bold for r in runs)


def speaker_to_pp(speaker_name):
    """
    Convert a speaker name string to a PP_ constant identifier.

    Rules:
    - Strip leading/trailing whitespace.
    - Replace internal spaces with underscores.
    - Uppercase everything.
    - Prepend "PP_".

    Example: "Rainbow Dash" -> "PP_RAINBOW_DASH"
    """
    name = speaker_name.strip().upper().replace(' ', '_')
    return 'PP_' + name


def escape_c_string(text):
    """
    Escape a string for use inside a C/JS double-quoted string literal.

    Escapes backslashes first, then double quotes.
    Newlines and tabs are replaced with a space (dialogue is single-line).
    """
    text = text.replace('\\', '\\\\')
    text = text.replace('"', '\\"')
    text = text.replace('\n', ' ')
    text = text.replace('\r', '')
    text = text.replace('\t', ' ')
    return text


def make_entry(speaker_pp, text):
    """
    Format one C-like structure entry string.

    Parameters:
        speaker_pp : str  - the PP_ constant, e.g. "PP_PHOENIX"
        text       : str  - the dialogue or title text (ASCII, unescaped)

    Returns the formatted entry line as a string (no trailing newline).
    """
    ascii_text = to_ascii(text)
    escaped   = escape_c_string(ascii_text)
    return ('{evidence: EV_NONE, frame: 0, '
            'cmdwho: %s | CMD_NONE, text: "%s" },' % (speaker_pp, escaped))


def classify_paragraph(paragraph):
    """
    Determine whether a paragraph is:
        'blank'   - empty or whitespace only
        'speaker' - starts with "Name:" pattern
        'special' - a known interjection keyword (Objection!, Hold it!, etc.)
        'header'  - section title / location info (bold or no colon)

    Returns a tuple: (kind, speaker_name_or_None, text_body)
        kind          : one of 'blank', 'speaker', 'special', 'header'
        speaker_name  : the speaker name string if kind=='speaker', else None
        text_body     : the dialogue/title text (Unicode, not yet ASCII)
    """
    raw_text = paragraph_to_text(paragraph).strip()

    # Blank line
    if not raw_text:
        return ('blank', None, '')

    # Bold paragraphs are section headers regardless of colon presence
    if is_bold_paragraph(paragraph):
        return ('header', None, raw_text)

    # Check for special interjection keywords (no colon expected)
    if SPECIAL_KEYWORDS.match(raw_text):
        return ('special', None, raw_text)

    # Check for "Speaker: dialogue" pattern.
    # The colon must appear before any significant amount of text.
    # We allow multi-word speaker names (e.g. "Rainbow Dash: Hey!").
    # Guard: colon must be within the first 40 characters to avoid treating
    # sentence punctuation as a speaker delimiter.
    colon_pos = raw_text.find(':')
    if 0 < colon_pos <= 40:
        potential_speaker = raw_text[:colon_pos].strip()
        # Speaker name should not contain sentence-ending punctuation
        # and should look like a name (letters, spaces, hyphens, apostrophes).
        if re.match(r"^[A-Za-z][A-Za-z '\-]*$", potential_speaker):
            dialogue = raw_text[colon_pos + 1:].strip()
            return ('speaker', potential_speaker, dialogue)

    # No colon or colon too far in -> treat as a section header / title
    return ('header', None, raw_text)


def convert_docx(input_path):
    """
    Open the docx file at input_path and convert its paragraphs to a list
    of formatted structure entry strings.

    Returns a list of strings, one per dialogue/header entry.
    Blank lines in the source are skipped.
    """
    doc = docx.Document(input_path)
    entries = []

    for paragraph in doc.paragraphs:
        kind, speaker_name, text_body = classify_paragraph(paragraph)

        if kind == 'blank':
            # Skip blank lines - they are just formatting separators
            continue

        elif kind == 'speaker':
            pp = speaker_to_pp(speaker_name)
            entries.append(make_entry(pp, text_body))

        elif kind in ('special', 'header'):
            # Section titles and interjections use PP_NONE
            entries.append(make_entry('PP_NONE', text_body))

    return entries


def main():
    """
    Entry point.  Parse command-line arguments and run conversion.

    Usage:
        python3 docx_to_js_struct.py input.docx [output.txt]
    """
    if len(sys.argv) < 2:
        print('Usage: python3 docx_to_js_struct.py input.docx [output.txt]',
              file=sys.stderr)
        sys.exit(1)

    input_path  = sys.argv[1]
    output_path = sys.argv[2] if len(sys.argv) >= 3 else None

    try:
        entries = convert_docx(input_path)
    except Exception as e:
        print('Error processing %s: %s' % (input_path, e), file=sys.stderr)
        sys.exit(2)

    output_text = '\n'.join(entries) + '\n'

    if output_path:
        try:
            with open(output_path, 'w', encoding='ascii') as f:
                f.write(output_text)
            print('Wrote %d entries to %s' % (len(entries), output_path),
                  file=sys.stderr)
        except IOError as e:
            print('Error writing %s: %s' % (output_path, e), file=sys.stderr)
            sys.exit(3)
    else:
        sys.stdout.write(output_text)


if __name__ == '__main__':
    main()
