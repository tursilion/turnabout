#include "structures.h"

// I don't know why, but the Classic99 build HATES these being const...
// the TI version NEEDS it, else the data is doubled up. We can't afford the RAM.
// The PC can, so screw it. ;)

#ifndef CLASSIC99
const
#endif
Evidence_t evidence[EV_MAX_STORED_EV] = {
    // 01234567890123456789012345678
    { "","" },   // EV_NONE               //  0123456789012345678901234567890101234567890123456789012345678901012345678901234567890123456789010123456789012345678901234567890101234567890123456789012345678901012345678901234567890123456789010123456789012345678901234567890101234567890123456789012345678901
    { "Attorney Badge",	              /*0*/  "Nobody would believe I was an attorney without this."    },
    { "Magatama",	                  /*1*/  "A gift from Maya. Allows me to see if anyone is hiding any deep secret in their heart from me."    },
    { "The Fillies Guide to Ponies",  /*15*/ "Earth Ponies founded Land, Unicorns use magic, Pegasi soar through the air."    },
    { "Equestrian Attorney Badge",	  /*30*/ "A heart shaped badge that gives all the privileges of an Equestrian defense Attorney"    },
    { "Equestria 500",                /*  */ "A gruelling 500 mile race around Equestria for pegasi. Ace Swift was expected to win."     },
    { "Everfree Forest",                     "Location of the crime. Incredibly dark and secluded, especially at night."  },
    { "Photo #1",	                  /*84*/ "Shows charred and blackened grass around body."    },
    { "Burnt Object",	              /*86*/ "A metal object that was severely burned by something. It is unidentifiable now."    },
    { "Photo #2",	                  /*90*/ "An imprint of what seems to be something long. Next to it some markings indicating someone had scuffled the dirt around."    },
    { "Brown Feather",	              /*96*/ "A suspicious brown feather that doesn't belong to a bird or a pony."    },
    { "Ace Swift Autopsy Report",	  /*146*/ "Estimated time of death: 8:30pm - 9:00pm. Died instantly due to severe electrocution. Burn mark on the back of the neck: unknown cause."    },
    { "Diagram of Crime Scene", 	  /*155*/ "Bolt 1 struck at 8:40PM where victim was found. Bolt 2 unknown but struck at 8:50. Bolt 3 took down a tree near the eastern edge of the clearing at 11:35PM."    },
    { "Weather Schedule",	          /*175*/ "Rainbow Dash scheduled to create a thunder storm at 3pm on the eastern side of Ponyville. Everfree Forest is on the west side of town."    },
    { "Missing Cloud Report",	      /*179*/ "A cloud Rainbow Dash was in charge of disappeared at 4:00PM on the night of the murder, and was found above the Everfree Forest Clearing."    },
    { "Embarrassing Pictures",	      /*186*/ "Several pictures of Rainbow Dash... Why in her right mind would she be doing this...? Photos found in a bag on the victim."    },
    { "Blackmail Letter",	          /*246*/ "A letter blackmailing Rainbow Dash that she found on her doorstep."    },
    { "Key to Ace's Hotel",	          /*255*/ "A key to the hotel Ace Swift was staying in while in Ponyville."    },
    { "Torn Resignation Letter",	  /*278*/ "Someone was planning on quitting something after the Equestrian 500. The other half is missing."    },
    { "Advanced Unicorn Spell Book",  /*282*/ "A book found in the victim's hotel room. Small note scribbled on one of the pages."    },
    { "List",	                      /*284*/ "A list with several names including Rainbow Dash."    }

};

