#ifndef VOICE_H
#define VOICE_H

// Voices are 8192hz, 4 bit samples stored 4 bits per sample (2 samples per byte), most significant first.
// First two bytes are the length of the sample in bytes (maximum 4k).
// 
// they are stored in AMS RAM at the pages listed below, and identified via a word selected because
// it's unique to each sample. We preload what we can to avoid needing to load them all at once, and
// if AMS is not available we don't process the samples.

// page 1 - (overlaps ROM) SAMPLE: All Objection (ending)
// page 2 - >2000
// page 3 - >3000
// page 4 - (overlaps DSR) SAMPLE: Trixie Objection
// page 5 - (overlaps DSR) SAMPLE: Trixie Holdit
// page 6 - (overlaps cart) SAMPLE: Phoenix Holdit
// page 7 - (overlaps cart) SAMPLE: Phoenix Objection
// page 8 - (overlaps I/O) SAMPLE: Phoenix TakeThat / Judge Objection (final scene)
// page 9 - (overlaps I/O) SAMPLE: Fluttershy Objection / Twilight Objection

// voice storage information
// CMD_TRIXIEOBJ   , // play trixie objection      S0
// CMD_PHOENIXOBJ  , // play phoenix objection     S1
// CMD_TWIOBJ      , // play twilight objection    S2
// CMD_FLUTTEROBJ  , // play fluttershy objection  S3
// CMD_JUDGEOBJ    , // play judge objection       S4
// CMD_GROUPOBJ    , // play group objection       S5
// CMD_TRIXIEHOLD  , // play trixie holdit         S6
// CMD_PHOENIXHOLD , // play phoenix holdit        S7
// CMD_PHOENIXTAKE , // play phoenix take that!    S8

// filename index
#define ALL_OBJECT_IDX          5
#define TRIXIE_OBJECT_IDX       0
#define TRIXIE_HOLDIT_IDX       6
#define PHOENIX_HOLDIT_IDX      7
#define PHOENIX_OBJECT_IDX      1
#define PHOENIX_TAKETHAT_IDX    8
#define FLUTTERSHY_OBJECT_IDX   3
#define JUDGE_OBJECT_IDX        4
#define TWILIGHT_OBJECT_IDX     2

// AMS page
#define ALL_OBJECT_PAGE         1
#define TRIXIE_OBJECT_PAGE      4
#define TRIXIE_HOLDIT_PAGE      5
#define PHOENIX_HOLDIT_PAGE     6
#define PHOENIX_OBJECT_PAGE     7
#define PHOENIX_TAKETHAT_PAGE   8
#define FLUTTERSHY_OBJECT_PAGE  9
#define JUDGE_OBJECT_PAGE       8
#define TWILIGHT_OBJECT_PAGE    9

// voice tag words (offset 0x0110 in sample - WARNING: IF SAMPLES CHANGES, THIS CHANGES! MUST BE UNIQUE!)
// This is how we tell if it was already loaded
// It's at 0x110 in the raw binary, but 0x112 after the 2 byte length header is prepended
// (if looking at hexdump, remember the 0x80 bytes of TIFILES header don't get loaded, so there it's 0x192)
#define TAG_OFFSET_WORD         0x0112

#define JUDGE_OBJECT_TAG        0x1122
#define TWILIGHT_OBJECT_TAG     0x1213
#define TRIXIE_OBJECT_TAG       0x15ea
#define TRIXIE_HOLDIT_TAG       0x2134
#define ALL_OBJECT_TAG          0x2222
#define PHOENIX_TAKETHAT_TAG    0x4333
#define PHOENIX_OBJECT_TAG      0x4544
#define FLUTTERSHY_OBJECT_TAG   0x5432
#define PHOENIX_HOLDIT_TAG      0xfdf5

void play_voice(int voice);
void load_voices();

// this one is not intended for external use, but I need it for the voice test
void load_one_voice(int idx);

#endif
