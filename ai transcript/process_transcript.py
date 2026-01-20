#!/usr/bin/env python3
"""
Process Part3_Phoenix.txt and convert to C structure format.
"""

import re
import sys

# Define speaker codes
PP_NONE = "PP_NONE"
PP_PHOENIX = "PP_PHOENIX"
PP_MIA = "PP_MIA"
PP_TWILIGHT = "PP_TWILIGHT"
PP_PINKIE = "PP_PINKIE"
PP_RAINBOW = "PP_RAINBOW"
PP_SONATA = "PP_SONATA"
PP_GUARD = "PP_GUARD"
PP_DERPY = "PP_DERPY"
PP_RARITY = "PP_RARITY"
PP_FLUTTERSHY = "PP_FLUTTERSHY"
PP_APPLEJACK = "PP_APPLEJACK"
PP_TRIXIE = "PP_TRIXIE"
PP_BIGMAC = "PP_BIGMAC"
PP_UNKNOWN = "PP_UNKNOWN"

def correct_typos(text):
    """
    Correct common typos in the transcript.
    """
    corrections = {
        # Character name corrections
        'Beanie': 'Feenie',
        'beanie': 'Feenie',
        'Barry': 'Rarity',
        'barry': 'Rarity',
        'Phoebe': 'Phoenix',
        'phoebe': 'Phoenix',
        'Feeny': 'Feenie',
        'Pinky': 'Pinkie',
        'Sonanda': 'Sonata',
        'der-': 'Derp-',
        'Dirpy': 'Derpy',
        'really.': 'Rarity.',
        'Lisanata.': 'Listen, Sonata.',
        # Common word corrections
        'deep dude': 'in deep doo-doo',
        'nailed here by': 'mailed here by',
        'pants pants all your hands': 'getting all your hands',
        # Grammar and spelling
        'indignified': 'undignified',
        'an dignified': 'an undignified',
        'mosey on now': 'mosey on now',  # Correct - Applejack's dialect
    }

    corrected = text
    for wrong, right in corrections.items():
        corrected = corrected.replace(wrong, right)

    return corrected


def guess_speaker(text, prev_speaker, context_history):
    """
    Guess who is speaking based on text content and context.
    """
    text_lower = text.lower()

    # Phoenix's internal thoughts (in parentheses)
    if text.strip().startswith('(') and text.strip().endswith(')'):
        return PP_PHOENIX

    # Sound effects and non-dialog
    if text.strip() in ['[Giggles]', '*Sigh*', '*laughs*', '[Doorbell rings]', '*Ding*']:
        return prev_speaker

    # Character-specific speech patterns and keywords

    # Pinkie Pie indicators (she's very enthusiastic and energetic)
    pinkie_strong = [
        'feenie!', 'hooray!', 'yay!', 'ooh,', 'classic!',
        'double rainbow', 'all the way!', 'wabniar',
        'i slept in', 'throwing parties', 'pinkie sense',
        'i cost!', 'twitchy tail'
    ]
    if any(ind in text_lower for ind in pinkie_strong):
        return PP_PINKIE

    # Pinkie patterns - exclamation-heavy, enthusiastic speech
    if text.count('!') >= 3 and len(text) < 100:
        return PP_PINKIE

    # Pinkie asking excited questions or making random statements
    if any(phrase in text_lower for phrase in [
        'i tried to make', 'i know!', 'oh, oh, oh',
        'that would be so', 'i love', 'i have a bad habit'
    ]):
        # Check if it's enthusiastic enough for Pinkie
        if '!' in text:
            return PP_PINKIE

    # Big Mac (very simple - just says "Yup" or "Nope" or "Eeyup")
    if text.strip() in ['Yup.', 'Nope.', 'Eeyup.', 'Yup', 'Nope', 'Eeyup', 'Nnope.', 'Nnope']:
        return PP_BIGMAC

    # Applejack indicators (southern dialect)
    applejack_indicators = [
        "y'all", "ain't", "gonna", "mosey", "partner",
        "apple bloom", "reckon", "gotta find",
        "knock-up side", "prissy"
    ]
    if any(ind in text_lower for ind in applejack_indicators):
        if "partner" in text_lower or "mosey" in text_lower or "y'all" in text_lower:
            return PP_APPLEJACK

    # Rarity indicators
    rarity_indicators = [
        'darling', 'fabulous', 'simply', 'elegant',
        'marvelous', 'dignified', 'discourse', 'multitasking',
        'mr. feeny', 'feeny', 'sophisticated', 'boutique',
        'positively', 'sharp dresser'
    ]
    # Check for Rarity's refined speech
    if any(ind in text_lower for ind in rarity_indicators):
        if 'feeny' in text_lower or 'fabulous' in text_lower or 'marvelous' in text_lower or 'darling' in text_lower:
            return PP_RARITY

    # Derpy indicators (clumsy, works for mail service)
    derpy_strong = [
        'i-i-i-i-i', 'eyes!', 'in deep doo-doo',
        'some airhead', 'letter not posted',
        'mail carrier', 'optometrist', 'mean no-see',
        'ahem! the defense', 'mr. beard', 'little apple bloom'
    ]
    if any(ind in text_lower for ind in derpy_strong):
        return PP_DERPY

    # Derpy's name or her speaking about letters
    if "derpy hooves" in text_lower and "name's" in text_lower:
        return PP_DERPY

    # Sonata indicators
    sonata_indicators = [
        'sonata', 'mr. wright', 'mr wright', 'strike one',
        'canterlot', 'ace swift', 'manager'
    ]
    if any(ind in text_lower for ind in sonata_indicators):
        return PP_SONATA

    # Check for formal "Mr. Wright" usage (Sonata)
    if 'mr. wright' in text_lower or 'mr wright' in text_lower:
        return PP_SONATA

    # Phoenix-specific indicators
    phoenix_strong = [
        'pinkie,', 'pinkie pie', 'sweating bullets',
        'i was just', "don't quit your day job",
        'phoenix wright, best attorney',
        'chief', 'maya fey', 'what the heck',
        'sonata,', 'i believe in her', 'take that!',
        'hold it', 'objection', 'hi, hello?', 'he-hello?',
        'a concerned friend?'
    ]
    if any(ind in text_lower for ind in phoenix_strong):
        return PP_PHOENIX

    # Phoenix talking about being human/not from Equestria
    if 'not being a pony' in text_lower or 'not from around here' in text_lower:
        return PP_PHOENIX

    # Phoenix addressing others by name
    if any(name in text_lower for name in ['pinkie,', 'rarity,', 'sonata,']):
        return PP_PHOENIX

    # Check for very short responses that alternate
    short_responses = {
        'yes?': None,  # Depends on context
        'what?': None,
        'huh?': PP_PHOENIX,  # Phoenix is often confused
        'really?': None,
        'okay.': None,
        'hmph!': PP_DERPY,  # Often Derpy
        'later!': PP_APPLEJACK,  # Applejack's casual goodbye
    }

    text_stripped = text.strip().lower()
    if text_stripped in short_responses:
        result = short_responses[text_stripped]
        if result:
            return result

    # Check context from recent dialog for question-answer pairs
    if len(context_history) > 0:
        last_text = context_history[-1]['text']
        last_speaker = context_history[-1]['speaker']

        # If last line was a question and this is an answer, likely different speaker
        if '?' in last_text and not text.strip().startswith('('):
            # Simple yes/no answers alternate speakers
            if text_stripped in ['yes.', 'no.', 'yes?', 'no?', 'okay.', 'alright.']:
                if last_speaker != PP_PHOENIX:
                    return PP_PHOENIX
                else:
                    # Return to the other person in conversation
                    recent_speakers = [c['speaker'] for c in context_history[-10:]]
                    # Find most recent non-Phoenix speaker
                    for entry in reversed(context_history[-10:]):
                        if entry['speaker'] != PP_PHOENIX:
                            return entry['speaker']
                    return PP_PINKIE  # Default to Pinkie if unclear

    # Default: try to alternate speakers for dialog flow
    # But only if the line seems like dialog (not a thought)
    if len(context_history) > 0:
        if prev_speaker == PP_PHOENIX and '?' not in text:
            # Could be continuation or response
            # Check if it's a response-like statement
            if text_stripped.startswith(('yes', 'no', 'well', 'okay', 'uh', 'hmm')):
                # Likely someone responding to Phoenix
                recent_non_phoenix = [c['speaker'] for c in context_history[-10:] if c['speaker'] != PP_PHOENIX]
                if recent_non_phoenix:
                    return recent_non_phoenix[-1]

    # Default to Phoenix for narrative or unclear lines
    return PP_PHOENIX


def process_transcript(input_file, output_file):
    """
    Process the transcript file and generate C structure code.
    """

    entries = []
    context_history = []
    prev_speaker = PP_PHOENIX

    with open(input_file, 'r', encoding='utf-8-sig') as f:
        lines = f.readlines()

    for line in lines:
        line = line.strip()

        # Skip empty lines
        if not line:
            continue

        # Skip comment lines
        if line.startswith('((') or line.startswith('//'):
            continue

        # Extract dialog with timestamp pattern [HH:MM:SS.MS - HH:MM:SS.MS] text
        match = re.match(r'\[[\d:.\s-]+\]\s*(.+)', line)
        if match:
            text = match.group(1).strip()

            # Skip empty text
            if not text:
                continue

            # Correct typos
            text = correct_typos(text)

            # Escape quotes and backslashes for C string
            escaped_text = text.replace('\\', '\\\\').replace('"', '\\"')

            # Guess the speaker
            speaker = guess_speaker(text, prev_speaker, context_history)

            # Create entry
            entry = {
                'evidence': 'EV_NONE',
                'frame': 0,
                'speaker': speaker,
                'command': 'CMD_NONE',
                'text': escaped_text
            }

            entries.append(entry)
            context_history.append(entry)
            prev_speaker = speaker

    # Write output file
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write("// Generated from Part3_Phoenix.txt\n")
        f.write("// Structure definition for conversation entries\n")
        f.write("typedef struct {\n")
        f.write("    int evidence;\n")
        f.write("    int frame;\n")
        f.write("    int cmdwho;\n")
        f.write("    char* text;\n")
        f.write("} ConversationEntry;\n\n")

        f.write("// Define constants\n")
        f.write("#define EV_NONE 0\n")
        f.write("#define PP_NONE 0\n")
        f.write("#define PP_PHOENIX 1\n")
        f.write("#define PP_MIA 2\n")
        f.write("#define PP_TWILIGHT 3\n")
        f.write("#define PP_PINKIE 4\n")
        f.write("#define PP_RAINBOW 5\n")
        f.write("#define PP_SONATA 6\n")
        f.write("#define PP_GUARD 7\n")
        f.write("#define PP_DERPY 8\n")
        f.write("#define PP_RARITY 9\n")
        f.write("#define PP_FLUTTERSHY 10\n")
        f.write("#define PP_APPLEJACK 11\n")
        f.write("#define PP_TRIXIE 12\n")
        f.write("#define PP_BIGMAC 13\n")
        f.write("#define PP_UNKNOWN 14\n\n")

        f.write("#define CMD_NONE 0\n")
        f.write("#define CMD_BLACK 1\n")
        f.write("#define CMD_WHOOSH 2\n")
        f.write("#define CMD_CRASH 3\n")
        f.write("#define CMD_RIP 4\n")
        f.write("#define CMD_BADUMTISH 5\n")
        f.write("#define CMD_BREAKLOCK 6\n")
        f.write("#define CMD_PARTY_HORN 7\n\n")

        f.write("ConversationEntry part3_phoenix_transcript[] = {\n")

        for i, entry in enumerate(entries):
            cmdwho = f"{entry['speaker']} | {entry['command']}"
            f.write(f'    {{evidence: {entry["evidence"]}, frame: {entry["frame"]}, ')
            f.write(f'cmdwho: {cmdwho}, text: "{entry["text"]}" }},\n')

        # Add terminating entry
        f.write('    {evidence: EV_NONE, frame: 0, cmdwho: PP_NONE | CMD_NONE, text: "" }\n')
        f.write("};\n\n")

        f.write("// Number of entries in the array\n")
        f.write("#define PART3_PHOENIX_TRANSCRIPT_SIZE (sizeof(part3_phoenix_transcript) / sizeof(ConversationEntry))\n")

    print(f"Processed {len(entries)} dialog entries")
    print(f"Output written to: {output_file}")


if __name__ == '__main__':
    input_file = '/mnt/d/work/ti/Phoenix Wright - turnabout storm/ai transcript/Part3_Phoenix.txt'
    output_file = '/mnt/d/work/ti/Phoenix Wright - turnabout storm/ai transcript/Part3_Phoenix_structure.c'

    process_transcript(input_file, output_file)
