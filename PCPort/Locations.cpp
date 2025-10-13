#include "structures.h"

#ifdef LOCATION_IS_0
// just story                                 //  0                               1                               2                               3                               4                               5                               6                               7
Story_t story[] =  {                          //  0123456789012345678901234567890101234567890123456789012345678901012345678901234567890123456789010123456789012345678901234567890101234567890123456789012345678901012345678901234567890123456789010123456789012345678901234567890101234567890123456789012345678901
{   -PP_PHOENIX, 0,  PP_NONE    | CMD_MUSPROLOG, "?????? ??????? June 9th, 8:??PM"  },
{   -EV_BADGE,   0,  PP_NONE    | CMD_NONE,      "Time for negotiations..."  },
{   EV_NONE,     0,  PP_NONE    | CMD_NONE,      "Forget it, I'm not doing it!"  },
{   EV_NONE,     0,  PP_NONE    | CMD_NONE,      "Do it or else!"  },
{   EV_NONE,     0,  PP_NONE    | CMD_NONE,      "I don't care about that anymore..."  },
{   EV_NONE,     0,  PP_NONE    | CMD_NONE,      "Besides... I have a better idea..."  },
{   EV_NONE,     0,  PP_NONE    | CMD_NONE,      "WHAT?!"  },
{   EV_NONE,     0,  PP_NONE    | CMD_NONE,      "Enjoy the parting gift!"  },
{   -EV_MAGATAMA,1,  PP_NONE    | CMD_NONE,      ""  },
{   EV_NONE,     1,  PP_NONE    | CMD_FLASH,     ""  },
{   EV_NONE,     1,  PP_NONE    | CMD_BLACK,     "June 9th, 9:43PM Wright and Co. Law Offices" },
{   EV_NONE,     2,  PP_NONE    | CMD_NONE,      ""  },
{   EV_NONE,     3,  PP_NONE    | CMD_MUSSTEEL,  "(*ring*)"  },
{   EV_NONE,     3,  PP_PHOENIX | CMD_STOPMUS,   "Phoenix Wright and Co. Office. \"Defending YOU like it's nuttin', baby\"!"   },
{   EV_NONE,     3,  PP_PHOENIX | CMD_NONE,      "...No ...sorry... I-I don't need a vegetable dicer..." },
{   EV_NONE,     3,  PP_PHOENIX | CMD_NONE,      "I'm sure that...ugh..." },
{   EV_NONE,     2,  PP_NONE    | CMD_NONE,      ""  },
{   EV_NONE,     2,  PP_PHOENIX | CMD_NONE,      "That silly slogan Maya came up with must be what's making business this slow, I should really have it revised..." },
{   EV_NONE,     2,  PP_PHOENIX | CMD_NONE,      "Scratch that! I NEED to have it revised! What a ridiculous slogan! Who are we trying to attract, grade school students?" },
{   EV_NONE,     2,  PP_PHOENIX | CMD_NONE,      "I guess it is a good sign though..." },
{   EV_NONE,     2,  PP_PHOENIX | CMD_NONE,      "The fewer people who need an attorney the fewer problems there are in the world." },
{   EV_NONE,     2,  PP_PHOENIX | CMD_NONE,      "Unfortunately sunshine and smiles don't pay the bills." },
{   EV_NONE,     2,  PP_PHOENIX | CMD_NONE,      "Guess I can at least call it in early tonight." },
{   EV_NONE,     2,  PP_PHOENIX | CMD_BOOMSFX,   "ARGH!" },
{   EV_NONE,     2,  PP_PHOENIX | CMD_MUSSUSPENSE,"W-what's going on!?"},
{   EV_NONE,     2,  PP_PHOENIX | CMD_FLASH,     "I can't move my body!" },
{   EV_NONE,     2,  PP_PHOENIX | CMD_NONE,      "(Wait, is my hand fading away?!)" },
{   EV_NONE,     2,  PP_PHOENIX | CMD_NONE,      "Getting...Dizzy... am I... dying...?" },
{   1,           2,  PP_PHOENIX | CMD_ENDSTORY,  "" }   // go to location 1 (negative value to flag)
};
#endif
