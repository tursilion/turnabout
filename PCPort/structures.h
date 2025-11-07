#ifndef STRUCTURES_H
#define STRUCTURES_H

// NOTE: max text is 8*32 = 256 bytes. And we lose more with word wrap.
// We'd get 320 if we switched to 40 column text mode... ah, but we don't control the CPU during TIPI calls.
// F18A could do it, but then we'd need two different copies. Still, F18A conversions of the graphics would be nice.

#ifdef CLASSIC99
// define what we are building for here - this will be external on the build line for the makefile builds
//#define LOCATION_IS_LOADER
//#define LOCATION_IS_0
//#define LOCATION_IS_1
//#define LOCATION_IS_2
//#define LOCATION_IS_3
#define LOCATION_IS_4
#endif

// one of these for every location - see bottom of file
//#define LOCATION_TYPE_INVESTIGATION
//#define LOCATION_TYPE_STORY  -- also covers interrogation
//#define LOCATION_TYPE_CROSSEXAM

// some types
#ifndef NULL
#define NULL (0)
#endif

/* Evidence structure - const side */
typedef struct {
    const char *name;          /* Display name */
    const char *description;   /* Text shown when examined */
} Evidence_t;

// evidence - remember anything dealing with people needs to be UNSIGNED
enum {
    EV_NONE,

    EV_BADGE,                       // Nobody would believe I was an attorney without this.
    EV_MAGATAMA,                    // A gift from Maya. Allows me to see if anyone is hiding any deep secret in their heart from me.
    EV_FILLIES,                     // Earth Ponies founded Land. Unicorns use magic. Pegasi soar through the air.
    EV_E_BADGE,                     // A heart shaped badge that gives all the privileges of an Equestrian defense Attorney
    EV_PHOTO1,                      // Charred and blackened grass around body.
    EV_BURNT,                       // A metal object that was severely burned by something. It is unidentifiable now.
    EV_PHOTO2,                      // An imprint of what seems to be something long. Next to it some markings indicating someone had scuffled the dirt around.
    EV_FEATHER,                     // A suspicious brown feather that doesn't belong to a bird or a pony.
    EV_AUTOPSY,                     // Estimated time of death: 8:30pm - 9:00pm. Cause: died instantly due to severe electrocution. Burn mark on the back of neck: unknown cause.
    EV_EVERFREE1,                   // A diagram of the scene of the crime and where lightning struck that night. (#154)
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
    EV_I_NOQUESTIONCLOUD,           // did not question the storm cloud evidence (for example)

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

    EV_MAX,

    // people are just special evidence, so I need them in the same list
    // they need to be in the MSB anyway, and PP_FIRST is used for the '??????' person
    // note that we will have more than 256 evidences including all the flags and story tags (probably), so
    // EV_xxx is legal up to 0x7FFF
    PP_FIRST      = 0x8000,
    PP_UNKNOWN    = 0x8100,

    PP_PHOENIX    = 0x8200,         // That's me, attorney at law! I seem to have been called to Equestria via magic.
    PP_TWILIGHT   = 0x8300,         // Unicorn disciple of Princess Celestia. Summoned the 'Greatest Defense Attorney' to Equestria.
    PP_RAINBOW    = 0x8400,         // Pegsus racer, the 'best flier in Equestria'. Accused of the murder of Ace Swift.
    PP_ACE        = 0x8500,         // The victim, a professional pegasus racer. Never lost an event. Found dead in the Everfree Forest.
    PP_FLUTTERSHY = 0x8600,         // Pegasus friend of Rainbow Dash. Witness who lives near the Everfree Forest.
    PP_TRIXIE     = 0x8700,         // The Great and Powerful Trixie, unicorn magician and prosecutor. Has a grudge against Twilight.
    PP_JUDGE      = 0x8800,         // The Judge also seems to have been called! He's fair, though easily confused.
    PP_APPLEBLOOM = 0x8900,         // Earth pony child, Cutie Mark Crusader. Witness who was in the Everfree Forest the night of the crime.
    PP_PINKIE     = 0x8a00,         // Earth pony Party Thrower Extraordinaire. Friend of Rainbow Dash.
    PP_SONATA     = 0x8b00,         // Unicorn manager of Ace Swift. Resembles Mia from my own realm.
    PP_GUARD      = 0x8c00,         // guard / police

    PP_LAST       = 0x8d00
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
                    
    CMD_SFXSTARTLIST, // find SFXs

    CMD_CROWDSFX    , // play crowd noise
    CMD_HAMMERSFX   , // play hammer sound
    CMD_CHIMESFX    , // play chime sound (mostly meant for cmd_stopmus)
    CMD_BOOMSFX     , // play boom sound
    CMD_LOCKSFX     , // play 3 booms for psychelocks
    CMD_LAUGHSFX    , // play crowd laughter
    CMD_BREAKSFX    , // play break psychlock sfx
    CMD_PARTYSFX    , // play party horn sfx
    CMD_JOKESFX     , // play rimshot sfx
    CMD_CRASHSFX    , // play crash sfx
    CMD_RIPSFX      , // play rip sfx
    CMD_WHOOSHSFX   , // play whoosh sfx

    CMD_SFXENDLIST  , // end SFX list
                    
    CMD_VOICESTARTLIST, // find voice commands

    CMD_TRIXIEOBJ   , // play trixie objection
    CMD_PHOENIXOBJ  , // play phoenix objection
    CMD_TWIOBJ      , // play twilight objection
    CMD_FLUTTEROBJ  , // play fluttershy objection
    CMD_JUDGEOBJ    , // play judge objection
    CMD_GROUPOBJ    , // play group objection
    CMD_TRIXIEHOLD  , // play trixie holdit
    CMD_PHOENIXHOLD , // play phoenix holdit
    CMD_PHOENIXTAKE , // play phoenix take that!

    CMD_VOICEENDLIST, // end of voice commands

    CMD_JUMP        , // always jump to label specified in evidence
    CMD_SHOWEV      , // request show evidence, text will say why. Next lines will jump based on what is selected
    CMD_JUMPIFSHOW  , // jump if we showed evidence (requires previous CMD_SHOWEV). Evidence in evidence, skip tag in picture id
    CMD_ENDSTORY    , // end this story sequence and return to main loop. Story stores new location in evidence field and will jump to it.
    CMD_REMOVEEV    , // remove evidence from inventory (evidence field) and go to next line
    CMD_ADDEV       , // add evidence (evidence field) and go to next line IF text field is empty.
    CMD_JUMPIFEV    , // skip to this tag if we have a certain evidence - evidence in evidence, skip tag in picture id
    CMD_CLRPROMPT   , // clear all prompts (new conversation tree)
    CMD_ADDPROMPT   , // Add this string and EV_I_name to the conversation prompts (and skip to the next one) - EV is how we find it
    CMD_DELPROMPT   , // delete the EV_xxx prompt from the list (only used if we need to, let the user go back)
    CMD_CHANGEPROMPT, // update the tag and/or text of a prompt (if NONE or empty, no change)
    CMD_SELPROMPT   , // go back to the prompt selection list (after this line)
                    
    CMD_STOPMUS     , // stop music

    // downloaded
    CMD_MUSTARTLIST , // just to find the music block

    CMD_MUSSTEEL    , // Steel Samurai Ringtone
    CMD_MUSSTART    , // Apollo Justice - Start of a New Trial! - Apollo Justice Ace Attorney - Objection 2007 (used Objection 2011)
    CMD_MUSEXAM     , // Cross Examination - Moderate 2007 - Apollo Justice Ace Attorney
    CMD_MUSCROSS    , // Cross Examination - Moderato 2002 - Phoenix Wright Justice For All
    CMD_MUSTRICK    , // Trick and Magic - Phoenix Wright: Justice for All
    CMD_MUSMLP      , // My Little Pony - Friendship is Magic Theme (8-bit) - RainbowCrash88 - used random Midi
    CMD_MUSTROUPE   , // Gramarye Troupe - Apollo Justice Ace Attorney
    CMD_MUSTRIAL    , // Ace Attorney 4 - Trial - Apollo Justice Ace Attorney - Court is now in session
    CMD_MUSTRACE    , // Trance Logic - Apollo Justice Ace Attorney
    CMD_MUSPEARLY   , // With Pearly - Phoenix Wright Justice for All
    CMD_MUSSISTER   , // Turnabout Sisters - Capcom
    CMD_MUSSMILE    , // Smile Instrumental - Hasbro
    CMD_MUSLOCK     , // Lock on the Heart - Capcom - Justice for All Psyche-Lock
    CMD_MUSTRIALS   , // Trials and Tribulation WiiWare Rips - HoodieD
    CMD_MUSPROLOG   , // Apollo Justice - Prologue
    CMD_MUSCHESS    , // Logic Chess - Moderato - Ace Attorney Investigations 2
    CMD_MUSOBJECT   , // Objection! 2009 - Ace Attorney Investigations
    CMD_MUSTHRILL   , // Thrill Theme - Suspense
    CMD_MUSINTEREST , // Interesting People - Ace Attorney Investigations
    CMD_MUSKLAVIER  , // Klavier's Theme - Capcom
    CMD_MUSTRAGIC   , // Interview Tragicomedy - Capcom
    CMD_MUSINVEST   , // Investigation Middle - Capcom
    CMD_MUSKG8      , // KG-8 Case - Capcom
    CMD_MUSLYING    , // Lying Coldly - Capcom
    CMD_MUSMOON     , // Moonlight Sonata - The Orchard Music
    CMD_MUSWINTER   , // Winter Wrap Up - David Larson
    CMD_MUSLOUNGE   , // Courtroom Lounge - Another Prelude - Phoenix Wright: Justice for All - So it begins again
    CMD_MUSHOTLINE  , // Hotline to Destiny - Capcom - Hotline of Fate
    CMD_MUSSUSPENSE , // Suspense - Phoenix Wright Ace Attorney
    CMD_MUSBEGIN    , // Court Begins - Capcom
    CMD_MUSTRUTH    , // Tell the Truth 2002 - Capcom - The Truth Revealed 2002
    CMD_MUSPURSUIT  , // Pursuit - Questioned - Capcom
    CMD_MUSEND      , // Ace Attorney ~ End - Capcom
    CMD_MUSCORNERED , // Pursuit Cornered 2001 - Capcom
    CMD_MUSSWEPT    , // Sweptaway Turnabout - Tragedy of the Horror House
    CMD_MUSCORE     , // Investigation Core 2001 - Cadenza
    CMD_MUSPRELUDE  , // Unending Prelude - Capcom - Defendant Lobby - So it Begins
    CMD_MUSGIGGLE   , // Giggle at the Ghosties - Hasbro - starts with so many wonders - need to cut
    CMD_MUSCOURT    , // Court Begins Orchestrated - Capcom - TAT Court is now in session
    CMD_MUSWON      , // Won the Lawsuit - Magical Trick Society - Victory - Our First Win
    CMD_MUSAJ       , // Applejack's Theme - AcousticBrony
    CMD_MUSRARITY   , // Rarity's Theme - MandoPony - Using FIM Rarity MIDI instead
    CMD_MUSTRUCY    , // Trucy's Theme - Child of Magic (Chords 0/1/2, 4/5/6, 7/8)
    CMD_MUSELEGY    , // Guard's elegy - Capcom
    CMD_MUSGUILTY   , // Guilty love - Capcom (using ringtone version)
    CMD_MUSRECALL   , // Recollation - Elementary School Trial

    // not available yet - will probably need to replace - how can I reach SoloAcapello? Might be able to ask Mando for Rarity's theme.
    CMD_MUSCRUSADE  , // Crusading (Apple Bloom) - SoloAcapello
    CMD_MUSCLOCK    , // Like Clockwork (Sonata) - SoloAcapello
    CMD_MUSSPECIAL  , // Special Delivery! (Derpy) - SoloAcapello
    CMD_MUSCOOL     , // Too Cool For You, Dweeb (Gilda) - SoloAcapello
    CMD_MUSMEMORY   , // Memories (Gilda confession) - SoloAcapello

    // not listed in the game credits but downloaded anyway
    // testimony-allegro (apparently no tracks are called that... might already have it then)

    CMD_MUSENDLIST  , // just to find the end
};

extern const Story_t story[];
extern int nStorySize;

// everyone has CHIMESFX (used in stop music)
#define HAS_CHIMESFX

// and here for every location we define the type - Locations will define the story data
#ifdef LOCATION_IS_LOADER
// Just the loader file, save game not valid here
#define LOCATION_NUMBER 0
#endif

#ifdef LOCATION_IS_0
// intro story
#define LOCATION_NUMBER 0
#define LOCATION_TYPE_STORY
// sfx - will pretty much need to preload sfx
#define HAS_BOOMSFX
// music - but I think I might need to load music dynamically... 32k isn't much
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
#define HAS_MUSTRUCY
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
#define HAS_MUSGUILTY
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

//*>*<*>*<>*<>*<>*<*>*<*>*<*> LAST LOCATION - ALWAYS MOVE TO LAST ONE DEFINED
#define LAST_LOCATION
//*>*<*>*<>*<>*<>*<*>*<*>*<*> LAST LOCATION
#endif

#ifdef LOCATION_IS_5
// fluttershy's cottage
#define LOCATION_NUMBER 5
#define LOCATION_TYPE_STORY
// sfx
// music
#endif

#ifdef LOCATION_IS_6
// everfree forest
#define LOCATION_NUMBER 6
#define LOCATION_TYPE_INVESTIGATION
// sfx
// music
#endif

// I'm not sure if the skip makes sense...

#ifdef LOCATION_IS_10
// outside courtroom
#define LOCATION_TYPE_STORY
#endif

#ifdef LOCATION_IS_11
// court introductions
#define LOCATION_TYPE_STORY
#endif

#ifdef LOCATION_IS_12
// Trixie's case
#define LOCATION_TYPE_STORY
#endif

#ifdef LOCATION_IS_13
// AppleBloom's testimony
#define LOCATION_TYPE_STORY
#endif

#ifdef LOCATION_IS_14
// AppleBloom cross examination
#define LOCATION_TYPE_CROSSEXAM
#endif

#ifdef LOCATION_IS_15
// Trixie and Dash's motive
#define LOCATION_TYPE_STORY
#endif

#ifdef LOCATION_IS_16
// Fluttershy's testimony
#define LOCATION_TYPE_STORY
#endif

#ifdef LOCATION_IS_17
// Fluttershy cross-examination
#define LOCATION_TYPE_CROSSEXAM
#endif

#ifdef LOCATION_IS_20
// flashback - Fey law offices
#define LOCATION_TYPE_STORY
#endif

#ifdef LOCATION_IS_21
// outside courtroom, talk to Pinkie
#define LOCATION_TYPE_STORY
#endif

#ifdef LOCATION_IS_22
// detention center with Dash
#define LOCATION_TYPE_STORY
#endif

#ifdef LOCATION_IS_23
// on the street with Pinkie
#define LOCATION_TYPE_STORY
#endif

#ifdef LOCATION_IS_24
// Ace's room
#define LOCATION_TYPE_INVESTIGATION
#endif

#ifdef LOCATION_IS_25
// Caught by Sonata
#define LOCATION_TYPE_STORY
#endif



#endif

