#ifndef STRUCTURES_H
#define STRUCTURES_H

// NOTE: max text is 8*32 = 256 bytes. And we lose more with word wrap.
// We'd get 320 if we switched to 40 column text mode... ah, but we don't control the CPU during TIPI calls.

#ifdef CLASSIC99
// define what we are building for here - this will be external on the build line for the makefile builds
//#define LOCATION_IS_LOADER
//#define LOCATION_IS_0
//#define LOCATION_IS_1
//#define LOCATION_IS_2
//#define LOCATION_IS_3
//#define LOCATION_IS_4
//#define LOCATION_IS_5
//#define LOCATION_IS_6
//#define LOCATION_IS_10
//#define LOCATION_IS_11
//#define LOCATION_IS_12
//#define LOCATION_IS_13
//#define LOCATION_IS_14
//#define LOCATION_IS_15
//#define LOCATION_IS_16
#define LOCATION_IS_17
#endif

// some types
#ifndef NULL
#define NULL (0)
#endif

// Image loading PAB address in VDP
#define VDP_PAB_ADDRESS 0x3800

/* Evidence structure - const side */
typedef struct {
    const char *name;          /* Display name */
    const char *description;   /* Text shown when examined */
} Evidence_t;

// investigation bitflags - cells indicate which cells have evidence for feedback
#define IV_CELL0    0x0001
#define IV_CELL1    0x0002
#define IV_CELL2    0x0004
#define IV_CELL3    0x0008
#define IV_CELL4    0x0010
#define IV_CELL5    0x0020
#define IV_CELL6    0x0040
#define IV_CELL7    0x0080
#define IV_LEFTOK   0x0100
#define IV_RIGHTOK  0x0200 

// evidence - remember anything dealing with people needs to be UNSIGNED
enum {
    EV_NONE,

    EV_BADGE,                       // Nobody would believe I was an attorney without this.
    EV_MAGATAMA,                    // A gift from Maya. Allows me to see if anyone is hiding any deep secret in their heart from me.
    EV_FILLIES,                     // Earth Ponies founded Land. Unicorns use magic. Pegasi soar through the air.
    EV_E_BADGE,                     // A heart shaped badge that gives all the privileges of an Equestrian defense Attorney
    EV_EQ500,                       // Equestria 500 race
    EV_EVERFREE,                    // Everfree forest - incredibly dark
    EV_PHOTO1,                      // Charred and blackened grass around body.
    EV_BURNT,                       // A metal object that was severely burned by something. It is unidentifiable now.
    EV_PHOTO2,                      // An imprint of what seems to be something long. Next to it some markings indicating someone had scuffled the dirt around.
    EV_FEATHER,                     // A suspicious brown feather that doesn't belong to a bird or a pony.
    EV_AUTOPSY,                     // Estimated time of death: 8:30pm - 9:00pm. Cause: died instantly due to severe electrocution. Burn mark on the back of neck: unknown cause.
    EV_CRIMESCENE,                  // A diagram of the scene of the crime and where lightning struck that night. (#154)
    EV_WEATHER,                     // Rainbow Dash scheduled to create a thunder storm at 3:00PM on the eastern side of Ponyville.
    EV_CLOUDREPORT,                 // A cloud Rainbow Dash was in charge of disappeared at 4:00PM on the night of the murder, and was found above the Everfree Forest Clearing.
    EV_PICTURES,                    // Several pictures of Rainbow Dash... Why in her right mind would she be doing this...? Photos found in a bag on the victim.
    EV_BLACKMAIL,                   // A letter blackmailing Rainbow Dash that she found on her doorstep.
    EV_ACEKEY,                      // A key to the hotel Ace Swift was staying in while in Ponyville.
    EV_TORNRESIGN,                  // Someone was planning on quitting something after the Equestrian 500. The other half is missing.
    EV_UNICORNSPELL,                // A book found in the victim's hotel room. Small note scribbled on one of the pages. "Continue from here."
    EV_LIST,                        // A list with several names including Rainbow Dash.

    // internal inventory items
    EV_START_INTERNAL,              // don't display evidence starting here - internal flags
    EV_I_QUESTIONCLOUD,             // questioned the storm cloud evidence
    EV_I_IN1FLAG1,                  // flagged first search done
    EV_I_WHINEBED,                  // whined about bed
    EV_I_WHINEBREAKFAST,            // whined about breakfast
    EV_I_DAY1DESPERATE,             // day 1 first desperate question asked
    EV_I_FLUTTERANIMALS,            // learn about Fluttershy's animals

    EV_MAX_STORED_EV,               // nothing after here is saved in inventory arrays

    EV_I_0,                         // investigation square
    EV_I_1,                         // investigation square
    EV_I_2,                         // investigation square
    EV_I_3,                         // investigation square
    EV_I_4,                         // investigation square
    EV_I_5,                         // investigation square
    EV_I_6,                         // investigation square
    EV_I_7,                         // investigation square
    EV_I_SEARCH_LEFT,               // investigation move left
    EV_I_SEARCH_RIGHT,              // investigation move right

    // story tags - not stored in inventory, but used to find blocks
    EV_START_TAGS,                  // story tags - do not store in inventory starting here
    EV_T_SNDBCK,
    EV_T_SNDBCK2,
    EV_T_WHORU,
    EV_T_CRIME,
    EV_T_DETAIL,
    EV_T_HUMAN,
    EV_T_NOHUMAN,
    EV_T_LAWYERBADGE,
    EV_T_NOBADGE,
    EV_T_RIGHTBADGE,
    EV_T_QUESTIONBADGE,
    EV_T_NOQBADGE,
    EV_T_CONCERN,
    EV_T_NOCONCERN,
    EV_T_RDNAME,
    EV_T_EARTHP,
    EV_T_UNIP,
    EV_T_PEGASUSP,
    EV_T_NOPONY,
    EV_T_BADGUESS,
    EV_T_ACE,
    EV_T_EQ500,
    EV_T_DONTWORRY,
    EV_T_HOWDIE,
    EV_T_BELIEVE,
    EV_T_ARREST,
    EV_T_MAKESURE,
    EV_T_CHECKDASH,
    EV_T_WHYTHERE,
    EV_T_FSEE,
    EV_T_FBEG,
    EV_T_FWORK,
    EV_T_INVEST,
    EV_T_DARK,

    EV_T_IN1_SC1,       // investigation 1 screen 1
    EV_T_I11_4,         // select square 4
    EV_T_I11_5,         // select square 5
    EV_T_I11_NOTHING,   // all other squares
    EV_T_IN1_SC2,       // investigation 1 screen 2
    EV_T_I12_4,         // select square 4
    EV_T_I12_NOTHING,   // all other squares
    EV_T_IN1_SC3,       // investigation 1 screen 3
    EV_T_IN1_SC3b,      // screen 3 after introduction text
    EV_T_I13_7,         // select square 7
    EV_T_I13_NOTHING,   // all other squares
    EV_T_IN1_DONE,

    EV_T_ISMAGIC,
    EV_T_ABOUTACE,
    EV_T_HOWDO,
    EV_T_RD500,
    EV_T_BED,
    EV_T_BREAKFAST,
    EV_T_NERVOUS,
    EV_T_WHINING,
    EV_T_TELLRD,
    EV_T_ASKTS,
    EV_T_WHOTRIX,
    EV_T_KNOWTRIX,
    EV_T_TRIXGRUDGE,
    EV_T_COURT,
    EV_T_EVIDENCE,
    EV_T_YESMAG,
    EV_T_NOMAG,
    EV_T_ALLMAG,
    EV_T_ASKHELP,
    EV_T_WINGIT,
    EV_T_OBJCLOUD,
    EV_T_ACCCLOUD,
    EV_T_WHOCALLED,
    EV_T_ABCLOUD,
    EV_T_3RDBOLT,
    EV_T_SUREBOLT,

    // apple bloom testimony
    EV_P_ZECORA,        // push on zecora line
    EV_P_WALKHOME,      // push on walk home line
    EV_P_LIGHT840,      // push on lightning at 8:40 line
    EV_P_WENTHOME,      // push on went home line
    EV_P_BUMPED,        // push on bumped into something
    EV_P_OUTSIDE,       // push on outside the forest

    EV_O_BADBLOOM,      // bad objection
    EV_O_BADBLOOM2,     // bad objection
    EV_O_BADBLOOM3,     // bad objection
    EV_O_GOODBLOOM,     // good objection

    EV_T_BLOOMTEST,     // jump target post testimony
    EV_T_BLOOMCROSS,    // jump target if cross examine wraps around
    EV_T_BLOOMCROSS2,   // jump target if cross examine wraps around
    EV_T_PRESEF,        // present everfree map for cloud ballistics times

    EV_T_PRESSBLOOM,
    EV_T_NOPRESSBL,
    EV_T_WHATCUTIE,
    EV_T_NOCUTIE,
    EV_T_LOOPBLOOM,
    EV_T_FEEL,
    EV_T_REACT,
    EV_T_YESFOOL,
    EV_T_NOFOOL,

    EV_T_YESSCHED,
    EV_T_NOSCHED,
    EV_T_QMOTIVE,
    EV_T_PTHEORY,

    EV_T_TRIXIECROSS1,  // jump target if cross examine wraps around
    EV_P_RDEVERFREE,
    EV_P_RDSEEACE,
    EV_P_RDZAPACE,
    EV_O_GOODTRIXIE1,
    EV_O_BADTRIXIE1,

    EV_T_SHOWEATHER,
    EV_T_WETLOOP,
    EV_T_YESAPONY,
    EV_T_NOAPONY,
    EV_T_WHYSHOW,
    EV_T_WHYHAVE,

    EV_P_FNIGHTCHICKENS,
    EV_P_FLIGHTNING,
    EV_P_FSAWDASH,
    EV_P_FNOFOLLOW,
    EV_P_FPOLICE,
    EV_P_FNOTHINGELSE,

    EV_O_GOODFLUT,
    EV_O_BADFLUT,
    EV_O_BADFLUT2,
    EV_T_FLUTTEST,
    EV_T_FLUTCROSS,
    EV_T_FLUTCROSS2,

    EV_T_FHARDWORK,
    EV_T_FHOWLONG,
    EV_T_FCORRECTL,
    EV_T_FNOCORRECTL,
    EV_T_FGOTANIMALS,

    EV_T_FSEEAB,
    EV_T_FSEEPW,
    EV_T_FSEETS,
    EV_T_FSEERD,
    EV_T_LOOPFWHO,
    EV_T_SKIPSUIT,
    EV_T_NOSKIPSUIT,

    EV_T_LOOPFWHO2,
    EV_T_FACCFS,
    EV_T_FACCTR,
    EV_T_FACCRD,
    EV_T_JUDGERETRY,

    EV_T_LOOPFSHOW,
    EV_T_FFEATHER,

    EV_T_FMISSOUT,
    EV_T_LOOPFSND,
    EV_T_FBOLT2,
    EV_T_FQ1,
    EV_T_FQ2,
    EV_T_FQ3,

    EV_MAX,

    // people are just special evidence, so I need them in the same list
    // they need to be in the MSB anyway, and PP_FIRST is used for the '??????' person
    // note that we will have more than 256 evidences including all the flags and story tags (probably), so
    // EV_xxx is legal up to 0x7FFF
    PP_FIRST      = 0x8000,
    PP_UNKNOWN    = 0x8100,

    PP_PHOENIX    = 0x8200,         // That's me, attorney at law! I seem to have been called to Equestria via magic.
    PP_TWILIGHT   = 0x8300,         // Unicorn disciple of Princess Celestia. Summoned the 'Greatest Defense Attorney' to Equestria.
    PP_GUARD      = 0x8400,         // guard / police
    PP_RAINBOW    = 0x8500,         // Pegsus racer, the 'best flier in Equestria'. Accused of the murder of Ace Swift.
    PP_ACE2       = 0x8600,         // The victim, a professional pegasus racer. Found dead in the Everfree Forest. (partial information)
    PP_ACE        = 0x8700,         // The victim, a professional pegasus racer. Never lost an event. Found dead in the Everfree Forest.
    PP_FLUTTERSHY = 0x8800,         // Pegasus friend of Rainbow Dash. Witness who lives near the Everfree Forest.
    PP_TRIXIE     = 0x8900,         // The Great and Powerful Trixie, unicorn magician and prosecutor. Has a grudge against Twilight.
    PP_JUDGE      = 0x8a00,         // The Judge also seems to have been called! He's fair, though easily confused.
    PP_BLOOM      = 0x8b00,         // Earth pony child, Cutie Mark Crusader. Witness who was in the Everfree Forest the night of the crime.
    PP_PINKIE     = 0x8c00,         // Earth pony Party Thrower Extraordinaire. Friend of Rainbow Dash.
    PP_SONATA     = 0x8d00,         // Unicorn manager of Ace Swift. Resembles Mia from my own realm.

    // if we need room in the savefile, we can make the savefile stop recording at PP_EDGEWORTH instead of PP_LAST
    
    PP_EDGEWORTH  = 0x8e00,         // never used in game, but we need it for his name in a flashback
    PP_TESTIMONY  = 0x8f00,         // used for the name only
    PP_CROSSEXAM  = 0x9000,         // used for the name only
    PP_GALLERY    = 0x9100,         // audience gallery
    PP_LAST       = 0x9200
};
#define PP_MAX ((PP_LAST>>8)-(PP_FIRST>>8))
#define PP_NONE PP_FIRST

// Location structure - each location is a separate app on the TI side
// Since each location is a separate app, we don't need to store the type,
// we can define it and use #ifdefs instead
typedef struct {
    const char *name;   // Location display name
    unsigned int introStory;     // id of intro story text, or 0 if none
//  int type;           // investigation, interrogation, story/testimony, cross-examination
    unsigned int indexes[8];     // depends on type:
                        // - investigation, text identifier at each screen location (divided into 8 squares) for evidence
                        // - interrogation: line of questioning (up to 8) (each is a mini crossexam)
                        // - story/testimony: start of text out (only 1 entry)
                        // - cross-examination: similar to interrogation, but lines are sequential
    unsigned int destinations[4]; // locations you can move to
    unsigned int locks[4];        // evidence needed for each location
} Location_t;

// examination structure - start at 0
typedef struct {
    int lock;           // the evidence needed to unlock this item
    const char *name;   // name of line of questioning (only used for interrogation)
    unsigned int story;          // the story id for this line
    unsigned int nextid;         // next exam id if we pass
    unsigned int pressid;        // exam id to go to if we press, 0 if can't
    unsigned int evidenceid;     // the correct evidence if we object, 0 if can't
    unsigned int objectid;       // exam id to go to if we object successfully
    unsigned int badobjectid;    // exam id to go to if we object incorrectly
} CrossExam_t;

// story structure - start at 0
// used for all modes, but the mode might restrict what you can do
typedef struct {
    unsigned int evidence;        // evidence awarded for this line (else 0)
    unsigned int frame;           // image frame
    unsigned int cmdwho; // additional command in LSB - see enum, and id of speaker in MSB
    const char* text;    // frame text
} Story_t;

// commands all need to be in the LSB
enum {
    CMD_NONE = 0    ,

    CMD_FLASH       , // draw a white flash and play boom - ignore frame
    CMD_BLACK       , // draw a black screen - ignore frame (but clear last frame so we know to load again)
    CMD_WHITE       , // draw a white screen with inverse crash sound
    CMD_STOPMUS     , // stop music
    CMD_MISS        , // count down misses. If 0 (or less), jump to missesTarget
    CMD_CLEARMISS   , // resets the missesLeft to 0, which turns off the display (does NOT jump to missesTarget) (have to use RESETMISS to start it)
    CMD_STOREMISS   , // resets missesLeft to 0 to turn off the display, but remembers the old value
    CMD_RECALLMISS  , // recalls a stored count back into missesLeft to reactivate the display

    // Testimony commands allowed as jump targets (they don't use evidence field otherwise)
    CMD_CLEARTEST   , // clear testimony array - testimony lines should NOT branch
                    
    CMD_SFXSTARTLIST, // find SFXs

    CMD_HAMMERSFX   , // play hammer sound
    CMD_CHIMESFX    , // play chime sound (mostly meant for cmd_stopmus)
    CMD_BOOMSFX     , // play boom sound
    CMD_LOCKSFX     , // play 3 booms for psychelocks
    CMD_BREAKSFX    , // play break psychlock sfx
    CMD_PARTYSFX    , // play party horn sfx
    CMD_JOKESFX     , // play rimshot sfx
    CMD_CRASHSFX    , // play crash sfx
    CMD_ICRASHSFX   , // play inverted crash sfx (used by CMD_WHITE)
    CMD_RIPSFX      , // play rip sfx
    CMD_WHOOSHSFX   , // play whoosh sfx
    CMD_FALLSFX     , // play falling sfx
    CMD_MAGICSFX    , // play magic sfx
    CMD_BADMAGSFX   , // play bad magic sfx
    CMD_SQUEAKSFX   , // play squeak sfx

    CMD_SFXENDLIST  , // end SFX list
                    
    CMD_VOICESTARTLIST, // find voice commands

    CMD_TRIXIEOBJ   , // play trixie objection      S0
    CMD_PHOENIXOBJ  , // play phoenix objection     S1
    CMD_TWIOBJ      , // play twilight objection    S2
    CMD_FLUTTEROBJ  , // play fluttershy objection  S3
    CMD_JUDGEOBJ    , // play judge objection       S4
    CMD_GROUPOBJ    , // play group objection       S5
    CMD_TRIXIEHOLD  , // play trixie holdit         S6
    CMD_PHOENIXHOLD , // play phoenix holdit        S7
    CMD_PHOENIXTAKE , // play phoenix take that!    S8

    CMD_VOICEENDLIST, // end of voice commands - this is also used as a differentiator for label jump targets!

// --- Above is okay for jump targets, below is not

    CMD_JUMP        , // always jump to label specified in evidence
    
    CMD_SHOWEV      , // request show evidence, text will say why. Next lines will jump based on what is selected
    CMD_JUMPIFSHOW  , // jump if we showed evidence (requires previous CMD_SHOWEV). Evidence in evidence, skip tag in picture id
    
    CMD_INVESTIGATE , // load investigation with scene number. Return as though evidence provided, with EV_I_1 through 8 (4 across)

    CMD_REMOVEEV    , // remove evidence from inventory (evidence field) and go to next line
    CMD_ADDEV       , // add evidence (evidence field) and go to next line IF text field is empty.
    CMD_JUMPIFEV    , // skip to this tag if we have a certain evidence - evidence in evidence, skip tag in picture id
    CMD_JUMPIFNOEV  , // skip to this tag if we do not have a certain evidence - evidence in evidence, skip tag in picture id
    
    CMD_CLRPROMPT   , // clear all prompts (new conversation tree)
    CMD_ADDPROMPT   , // Add this string and EV_I_name to the conversation prompts (and skip to the next one) - EV is how we find it
    CMD_CHANGEPROMPT, // update the tag and/or text of a prompt (if NONE or empty, no change)
    CMD_SELPROMPT   , // go back to the prompt selection list (after this line)

    CMD_ENDSTORY    , // end this story sequence and return to main loop. Story stores new location in evidence field and will jump to it.
                        
    CMD_ADDTEST     , // add this line to testimony and go to next line - current is set to the new line
    CMD_OBJECTHERE  , // this is the line to object on (also acts as ADDTEST)
    CMD_BADOBJECT   , // set the target for bad objection to the tag in evidence
    CMD_GOODOBJECT  , // set the target for good objection to the tag in evidence
    CMD_STARTTEST   , // playback testimony as registered - post-testimony tag in evidence
    CMD_STARTCROSS  , // start crossexamination at first testimony line, post-cross tag in evidence
    CMD_CONCROSS    , // continue cross examination at current line, post-cross tag in evidence

    CMD_RESETMISS   , // reset miss count to default (makes it display), evidence becomes missesTarget

    // downloaded - do not reorder the song list!! Indented comment means it is done and uploaded
    CMD_MUSTARTLIST , // just to find the music block

    CMD_MUSSTEEL    , //    Steel Samurai Ringtone
    CMD_MUSSTART    , // Apollo Justice - Start of a New Trial! - Apollo Justice Ace Attorney (AJ-1)
    CMD_MUSEXAM     , //    Cross Examination - Moderate 2007 - Apollo Justice Ace Attorney
    CMD_MUSCROSS    , //    Cross Examination - Moderato 2002 - Phoenix Wright Justice For All (JFA-72)
    CMD_MUSTRICK    , //    Magic and Tricks - Phoenix Wright: Justice for All
    CMD_MUSMLP      , //    My Little Pony - Friendship is Magic Theme (8-bit) - RainbowCrash88 - used random Midi
    CMD_MUSTROUPE   , //    Gramarye Troupe - Apollo Justice Ace Attorney
    CMD_MUSTRIAL    , //    Ace Attorney 4 - Trial - Apollo Justice Ace Attorney - Court is now in session
    CMD_MUSTRANCE   , //    Trance Logic - Apollo Justice Ace Attorney
    CMD_MUSPEARLY   , //    With Pearly - Phoenix Wright Justice for All
    CMD_MUSSISTER   , //    Turnabout Sisters - Capcom
    CMD_MUSSMILE    , // Smile Instrumental - Hasbro
    CMD_MUSLOCK     , // Lock on the Heart - Capcom - Justice for All Psyche-Lock (JFA-85)
    CMD_MUSTRIALS   , //    Trials and Tribulation WiiWare Rips - HoodieD
    CMD_MUSPROLOG   , //    Apollo Justice - Prologue
    CMD_MUSECHESS   , //    Logic Chess End - Moderato - Ace Attorney Investigations 2 (AAI2-53)
    CMD_MUSOBJECT   , //    Objection! 2009 - Ace Attorney Investigations (AAI-11)
    CMD_MUSTHRILL   , //    Thrill Theme - Suspense (AJ-35)
    CMD_MUSINTEREST , //    Interesting People - Ace Attorney Investigations (AAI-49)
    CMD_MUSKLAVIER  , // Klavier? Might have intended to delete this...
    CMD_MUSTRAGIC   , // Interview Tragicomedy - Capcom (AJ-17)
    CMD_MUSMIDDLE   , //    Investigation Middlegame - Capcom - Ace Attorney Investigations
    CMD_MUSKG8      , // KG-8 Case - Capcom (AAI-53)
    CMD_MUSLYING    , // Lying Coldly - Capcom (AAI-12)
    CMD_MUSMOON     , // Moonlight Sonata - The Orchard Music
    CMD_MUSWINTER   , // Winter Wrap Up - David Larson
    CMD_MUSLOUNGE   , //    Courtroom Lounge - Overture again
    CMD_MUSHOTLINE  , // Hotline to Destiny - Capcom - Hotline of Fate (JFA-86)
    CMD_MUSSUSPENSE , //    Suspense - Phoenix Wright Ace Attorney
    CMD_MUSBEGIN    , // Court Begins - Capcom (AJ-45?)
    CMD_MUSTRUTH    , //    Tell the Truth 2002 - Capcom - The Truth Revealed 2002
    CMD_MUSPURSUIT  , // Pursuit - Questioned - Capcom (JFA-74)
    CMD_MUSEND      , // Ace Attorney ~ End - Capcom (PW-7?)
    CMD_MUSCORNERED , //    Pursuit Cornered 2001 - Capcom
    CMD_MUSSWEPT    , // Sweptaway Turnabout - Tragedy of the Horror House (AAI-54 or AAI-55)
    CMD_MUSCORE     , //    Investigation Core 2001 - Cadenza
    CMD_MUSPRELUDE  , // Unending Prelude - Capcom - Defendant Lobby - So it Begins (PW-8)
    CMD_MUSGIGGLE   , // Giggle at the Ghosties - Hasbro - starts with so many wonders - need to cut beginning off
    CMD_MUSCOURT    , // Court Begins Orchestrated - Capcom - TAT Court is now in session (PW-13? Or we might have a midi downloaded)
    CMD_MUSWON      , // Won the Lawsuit - Magical Trick Society - Victory - Our First Win (PW-20)
    CMD_MUSAJ       , // Applejack's Theme - AcousticBrony
    CMD_MUSRARITY   , // Rarity's Theme - MandoPony - Using FIM Rarity MIDI instead
    CMD_MUSTRUCY    , //    Trucy's Theme - Child of Magic (Chords 0/1/2, 4/5/6, 7/8)
    CMD_MUSELEGY    , //    Guard's elegy - Capcom
    CMD_MUSGUILTY   , //    Guilty love - Capcom (using ringtone version)
    CMD_MUSRECALL   , //    Recollation - Elementary School Trial
    CMD_MUSCRUSADE  , //    Crusading (Apple Bloom) - SoloAcapello (using Apples to the Core by DJDelta0)

    // Do not reorder the song list!!
    // not available yet - will probably need to replace - how can I reach SoloAcapello?    
    // This site has MLP MIDIs we can probably use: https://www.weimtime.org/midis
    // Also for Gilda I was considering Shiru's covers/star_dust_mix, if it fits the theme (A lot of nice tracks in there)
    CMD_MUSCLOCK    , // Like Clockwork (Sonata) - SoloAcapello
    CMD_MUSSPECIAL  , // Special Delivery! (Derpy) - SoloAcapello
    CMD_MUSCOOL     , // Too Cool For You, Dweeb (Gilda) - SoloAcapello
    CMD_MUSMEMORY   , // Memories (Gilda confession) - SoloAcapello

    CMD_MUSSCHESS   , //    Logic Chess Start - Moderato - Ace Attorney Investigations 2 (AAI2-16)
    CMD_MUSOBJECT2  , //    Objection! 2011 - Ace Attorney Investigations 2 (AAI2-12)
    CMD_MUSOBJECT3  , //    Objection! 2002 - Justice for All (JFA-70)

    // not listed in the game credits but downloaded anyway
    // testimony-allegro (apparently no tracks are called that... might already have it then)

    CMD_MUSENDLIST  , // just to find the end
};

extern const Story_t story[];
extern int nStorySize;

// everyone has CHIMESFX (used in stop music)
#define HAS_CHIMESFX

// and here for every location we define the type - Locations will define the story data

// loader has all voices for voice test, but doesn't load any until needed
#ifdef LOCATION_IS_LOADER
// Just the loader file, save game not valid here
#define LOCATION_NUMBER 0
// sfx
#define HAS_VOICE
#define HAS_TRIXIEOBJ
#define HAS_PHOENIXOBJ  
#define HAS_TWIOBJ      
#define HAS_FLUTTEROBJ  
#define HAS_JUDGEOBJ    
#define HAS_GROUPOBJ    
#define HAS_TRIXIEHOLDIT
#define HAS_PHOENIXHOLDIT
#define HAS_PHOENIXTAKE 
// music
#endif

#ifdef LOCATION_IS_0
// intro story
#define LOCATION_NUMBER 0
#define LOCATION_TYPE_STORY
// sfx
#define HAS_BOOMSFX
// music
#define HAS_MUSPROLOG
#define HAS_MUSSTEEL
#define HAS_MUSSUSPENSE
#endif

#ifdef LOCATION_IS_1
// library, question Twilight
#define LOCATION_NUMBER 1
#define LOCATION_TYPE_STORY
// sfx
#define HAS_BOOMSFX
// music
#define HAS_MUSTRUCY    // Twilight
#endif

#ifdef LOCATION_IS_2
// outside detention center
#define LOCATION_NUMBER 2
#define LOCATION_TYPE_STORY
// sfx
// none
// music
// none (expect a switch..case default warning)
#endif

#ifdef LOCATION_IS_3
// interview dash
#define LOCATION_NUMBER 3
#define LOCATION_TYPE_STORY
// sfx
#define HAS_LOCKSFX
#define HAS_BOOMSFX
#define HAS_CRASHSFX
// music
#define HAS_MUSGUILTY   // Dash
#define HAS_MUSELEGY
#endif

#ifdef LOCATION_IS_4
// post interview talk to twilight
#define LOCATION_NUMBER 4
#define LOCATION_TYPE_STORY
// sfx
// music
#define HAS_MUSRECALL
#define HAS_MUSSISTER
#endif

#ifdef LOCATION_IS_5
// fluttershy's cottage
#define LOCATION_NUMBER 5
#define LOCATION_TYPE_STORY
// sfx
#define HAS_CRASHSFX
#define HAS_FALLSFX
#define HAS_BOOMSFX
// music
#define HAS_MUSPEARLY   // Fluttershy
#endif

#ifdef LOCATION_IS_6
// everfree forest
#define LOCATION_NUMBER 6
#define LOCATION_TYPE_STORY
#define LOCATION_TYPE_INVESTIGATION
// sfx
#define HAS_MAGICSFX
// music
#define HAS_MUSMIDDLE
#define HAS_MUSCORE
#endif

// I'm not sure if the skip makes sense... guess it doesn't matter

#ifdef LOCATION_IS_10
// outside courtroom
#define LOCATION_NUMBER 10
#define LOCATION_TYPE_STORY
// sfx
#define HAS_CRASHSFX
#define HAS_BADMAGSFX   // kind of a ringing sound
#define HAS_ICRASHSFX
// music
#define HAS_MUSLOUNGE
#define HAS_MUSMLP
#define HAS_MUSTROUPE   // Trixie
#endif

#ifdef LOCATION_IS_11
// court introductions
#define LOCATION_NUMBER 11
#define LOCATION_TYPE_STORY
// sfx
#define HAS_HAMMERSFX
#define HAS_CRASHSFX
#define HAS_FALLSFX
// voices
#define HAS_VOICE
#define HAS_TRIXIEOBJ
// music
#define HAS_MUSTRIAL
#endif

#ifdef LOCATION_IS_12
// Trixie's case
#define LOCATION_NUMBER 12
#define LOCATION_TYPE_STORY
// sfx
#define HAS_BOOMSFX
// voices
#define HAS_VOICE
#define HAS_TRIXIEOBJ
#define HAS_PHOENIXOBJ
// music
#define HAS_MUSTRIAL
#define HAS_MUSTRANCE
#define HAS_MUSCORNERED
#define HAS_MUSTRICK
#endif

#ifdef LOCATION_IS_13
// AppleBloom's testimony and cross examine p1
#define LOCATION_NUMBER 13
#define LOCATION_TYPE_STORY
#define LOCATION_TYPE_CROSSEXAM
// sfx
#define HAS_BOOMSFX
#define HAS_FALLSFX
#define HAS_CHIMESFX
#define HAS_CRASHSFX
// voices
#define HAS_VOICE
#define HAS_TRIXIEHOLDIT
#define HAS_TRIXIEOBJ
#define HAS_PHOENIXHOLDIT
#define HAS_PHOENIXOBJ
// music
#define HAS_MUSEXAM
#define HAS_MUSCRUSADE
#endif

#ifdef LOCATION_IS_14
// AppleBloom cross examination p2
#define LOCATION_NUMBER 14
#define LOCATION_TYPE_STORY
#define LOCATION_TYPE_CROSSEXAM
// sfx
#define HAS_BOOMSFX
#define HAS_CRASHSFX
#define HAS_FALLSFX
#define HAS_CHIMESFX
// voices
#define HAS_VOICE
#define HAS_TRIXIEOBJ
#define HAS_PHOENIXHOLDIT
#define HAS_PHOENIXOBJ
#define HAS_PHOENIXTAKE
// music - missing exam part 2 and the actual music at 35:03, using TRUTH instead
#define HAS_MUSEXAM
#define HAS_MUSTRUTH
#endif

#ifdef LOCATION_IS_15
// Trixie and Dash's motive
#define LOCATION_NUMBER 15
#define LOCATION_TYPE_STORY
#define LOCATION_TYPE_CROSSEXAM
// sfx
#define HAS_BOOMSFX
#define HAS_CHIMESFX
#define HAS_HAMMERSFX
// voice
#define HAS_VOICE
#define HAS_TRIXIEOBJ
#define HAS_PHOENIXHOLDIT
#define HAS_PHOENIXOBJ
#define HAS_PHOENIXTAKE
// music
#define HAS_MUSTHRILL
#define HAS_MUSOBJECT2
#define HAS_MUSSCHESS
#define HAS_MUSECHESS
#define HAS_MUSOBJECT
#define HAS_MUSINTEREST
#endif

#ifdef LOCATION_IS_16
// Fluttershy's testimony
#define LOCATION_NUMBER 16
#define LOCATION_TYPE_STORY
#define LOCATION_TYPE_CROSSEXAM
// sfx
#define HAS_CHIMESFX
#define HAS_FALLSFX
#define HAS_BOOMSFX
#define HAS_SQUEAKSFX
// voice
#define HAS_VOICE
#define HAS_TRIXIEOBJ
#define HAS_PHOENIXHOLDIT
#define HAS_PHOENIXOBJ
#define HAS_PHOENIXTAKE
// music
#define HAS_MUSPEARLY
#define HAS_MUSCROSS
#endif

#ifdef LOCATION_IS_17
// Fluttershy cross-examination
#define LOCATION_NUMBER 17
#define LOCATION_TYPE_STORY
#define LOCATION_TYPE_CROSSEXAM
#define LOCATION_TYPE_MISSES
// sfx
#define HAS_CHIMESFX
#define HAS_BOOMSFX
#define HAS_SQUEAKSFX
#define HAS_HAMMERSFX
// voice
#define HAS_VOICE
#define HAS_TRIXIEOBJ
#define HAS_PHOENIXHOLDIT
#define HAS_PHOENIXOBJ
#define HAS_PHOENIXTAKE
#define HAS_TWIOBJ
// music
#define HAS_MUSOBJECT3
#endif

#ifdef LOCATION_IS_18
// flashback - Fey law offices
#define LOCATION_NUMBER 18
#define LOCATION_TYPE_STORY
// sfx
// music
#endif

#ifdef LOCATION_IS_19
// outside courtroom, talk to Pinkie
#define LOCATION_NUMBER 19
#define LOCATION_TYPE_STORY
// sfx
// music
#endif

#ifdef LOCATION_IS_20
// detention center with Dash
#define LOCATION_NUMBER 20
#define LOCATION_TYPE_STORY
// sfx
// music
//*>*<*>*<>*<>*<>*<*>*<*>*<*> LAST LOCATION - ALWAYS MOVE TO LAST ONE DEFINED
#define LAST_LOCATION
//*>*<*>*<>*<>*<>*<*>*<*>*<*> LAST LOCATION
#endif

#ifdef LOCATION_IS_21
// on the street with Pinkie
#define LOCATION_NUMBER 21
#define LOCATION_TYPE_STORY
// sfx
// music
#endif

#ifdef LOCATION_IS_22
// Ace's room
#define LOCATION_NUMBER 22
#define LOCATION_TYPE_INVESTIGATION
// sfx
// music
#endif

#ifdef LOCATION_IS_23
// Caught by Sonata
#define LOCATION_NUMBER 23
#define LOCATION_TYPE_STORY
// sfx
// music
#endif



// make sure voice samples include crash
// any location with a sample should also have CRASHSFX for non-AMS users
#ifdef HAS_VOICE
#ifndef HAS_CRASHSFX
#define HAS_CRASHSFX
#endif
#endif

#endif

