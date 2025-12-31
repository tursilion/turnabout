// Phoenix Wright: Turnabout Storm - Story Data
// Story data ported from Locations.cpp (python updateStory.py ../Locations.cpp locations.js)
//
// HOW TO UPDATE STORY DATA:
// 1. Each location is a numbered key in STORY_DATA object (0, 1, 2, etc.)
// 2. Each location contains an array of story lines
// 3. Each story line has: evidence, frame, cmdwho, text
// 4. Constants (EV_*, PP_*, CMD_*) must match those defined in the main HTML file
//
// EXAMPLE STORY LINE:
// {evidence: EV_NONE, frame: 5, cmdwho: PP_PHOENIX | CMD_NONE, text: "Hello world!"}

const STORY_DATA = {
    0: [
        {evidence: PP_PHOENIX, frame: 0, cmdwho: PP_NONE    | CMD_ADDEV, text: "?????? ??????? June 9th, 8:??PM"},
        {evidence: EV_NONE, frame: 0, cmdwho: PP_NONE    | CMD_MUSPROLOG, text: "Time for negotiations..."},
        {evidence: EV_BADGE, frame: 0, cmdwho: PP_NONE    | CMD_ADDEV, text: "Forget it, I'm not doing it!"},
        {evidence: EV_NONE, frame: 0, cmdwho: PP_NONE    | CMD_NONE, text: "Do it or else!"},
        {evidence: EV_NONE, frame: 0, cmdwho: PP_NONE    | CMD_NONE, text: "I don't care about that anymore..."},
        {evidence: EV_NONE, frame: 0, cmdwho: PP_NONE    | CMD_NONE, text: "Besides... I have a better idea..."},
        {evidence: EV_NONE, frame: 0, cmdwho: PP_NONE    | CMD_NONE, text: "WHAT?!"},
        {evidence: EV_MAGATAMA, frame: 0, cmdwho: PP_NONE    | CMD_ADDEV, text: "Enjoy the parting gift!"},
        {evidence: EV_NONE, frame: 1, cmdwho: PP_NONE    | CMD_STOPMUS, text: ""},
        {evidence: EV_NONE, frame: 1, cmdwho: PP_NONE    | CMD_FLASH, text: ""},
        {evidence: EV_NONE, frame: 1, cmdwho: PP_NONE    | CMD_BLACK, text: "June 9th, 9:43PM Wright and Co. Law Offices"},
        {evidence: EV_NONE, frame: 3, cmdwho: PP_NONE    | CMD_MUSSTEEL, text: "(*ring*)"},
        {evidence: EV_NONE, frame: 3, cmdwho: PP_PHOENIX | CMD_STOPMUS, text: "Phoenix Wright and Co. Office. \"Defending YOU like it's nuttin', baby\"!"},
        {evidence: EV_NONE, frame: 3, cmdwho: PP_PHOENIX | CMD_NONE, text: "...No ...sorry... I-I don't need a vegetable dicer..."},
        {evidence: EV_NONE, frame: 3, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'm sure that...ugh..."},
        {evidence: EV_NONE, frame: 2, cmdwho: PP_PHOENIX | CMD_NONE, text: "That silly slogan Maya came up with must be what's making business this slow, I should really have it revised..."},
        {evidence: EV_NONE, frame: 2, cmdwho: PP_PHOENIX | CMD_NONE, text: "Scratch that! I NEED to have it revised! What a ridiculous slogan! Who are we trying to attract, grade school students?"},
        {evidence: EV_NONE, frame: 2, cmdwho: PP_PHOENIX | CMD_NONE, text: "I guess it is a good sign though..."},
        {evidence: EV_NONE, frame: 2, cmdwho: PP_PHOENIX | CMD_NONE, text: "The fewer people who need an attorney the fewer problems there are in the world."},
        {evidence: EV_NONE, frame: 2, cmdwho: PP_PHOENIX | CMD_NONE, text: "Unfortunately sunshine and smiles don't pay the bills."},
        {evidence: EV_NONE, frame: 2, cmdwho: PP_PHOENIX | CMD_NONE, text: "Guess I can at least call it early tonight."},
        {evidence: EV_NONE, frame: 2, cmdwho: PP_PHOENIX | CMD_BOOMSFX, text: "ARGH!"},
        {evidence: EV_NONE, frame: 2, cmdwho: PP_PHOENIX | CMD_MUSSUSPENSE, text: "W-what's going on!?"},
        {evidence: EV_NONE, frame: 2, cmdwho: PP_PHOENIX | CMD_FLASH, text: "I can't move my body!"},
        {evidence: EV_NONE, frame: 2, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Wait, is my hand fading away?!)"},
        {evidence: EV_NONE, frame: 2, cmdwho: PP_PHOENIX | CMD_NONE, text: "Getting...Dizzy... am I... dying...?"},
        {evidence: 1, frame: 2, cmdwho: PP_PHOENIX | CMD_ENDSTORY, text: ""}
    ],
    1: [
        {evidence: EV_NONE, frame: 4, cmdwho: PP_NONE    | CMD_BLACK, text: "?????????????? June 9th, 9:45PM"},
        {evidence: EV_NONE, frame: 4, cmdwho: PP_PHOENIX | CMD_BLACK, text: "Ughhhhh..."},
        {evidence: EV_NONE, frame: 4, cmdwho: PP_UNKNOWN | CMD_BLACK, text: "Hey! Who the heck are you?!"},
        {evidence: EV_NONE, frame: 4, cmdwho: PP_PHOENIX | CMD_BLACK, text: "(...Whose voice is that?)"},
        {evidence: EV_NONE, frame: 4, cmdwho: PP_UNKNOWN | CMD_BLACK, text: "For that matter WHAT the heck are you?"},
        {evidence: EV_NONE, frame: 4, cmdwho: PP_PHOENIX | CMD_BLACK, text: "(\"What am I?\" What kind of question is that, does she mean my profession?)"},
        {evidence: EV_NONE, frame: 4, cmdwho: PP_UNKNOWN | CMD_BLACK, text: "I wanted the best Defense Attorney in Equestria, not some... porcupine thing."},
        {evidence: EV_NONE, frame: 4, cmdwho: PP_PHOENIX | CMD_BLACK, text: "(*Sigh* Does my hair really look like a porcupine...?)"},
        {evidence: EV_NONE, frame: 4, cmdwho: PP_PHOENIX | CMD_BLACK, text: "(My muscles are coming to, I think I can open my eyes.)"},
        {evidence: EV_NONE, frame: 4, cmdwho: PP_PHOENIX | CMD_NONE, text: "Huh? Where am I?"},
        {evidence: EV_NONE, frame: 5, cmdwho: PP_UNKNOWN | CMD_NONE, text: "Hey! You're a human, aren't you?"},
        {evidence: EV_NONE, frame: 5, cmdwho: PP_PHOENIX | CMD_NONE, text: "Yeah... I'm a human..."},
        {evidence: EV_NONE, frame: 5, cmdwho: PP_PHOENIX | CMD_FLASH, text: "WAIT WHAT?!"},
        {evidence: EV_NONE, frame: 6, cmdwho: PP_UNKNOWN | CMD_MUSTRUCY, text: "A human in Equestria, that's amazing!"},
        {evidence: EV_NONE, frame: 6, cmdwho: PP_PHOENIX | CMD_NONE, text: "Y-YOU'RE A TALKING HORSE!"}
    ]
};

// Export for use in the main game
if (typeof module !== 'undefined' && module.exports) {
    module.exports = STORY_DATA;
}
