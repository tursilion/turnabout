#include "structures.h"

// Warning: put no variables in here, they won't be initialized

// people are just special evidence, but sometimes we need them separately
// Remember names are stored in the MSB and or'd with 0x80

// I don't know why, but the Classic99 build HATES these being const...
// the TI version NEEDS it, else the data is doubled up. We can't afford the RAM.
// The PC can, so screw it. ;)

#ifndef CLASSIC99
const
#endif
Evidence_t people[PP_MAX] = {
    { "                ",           ""    },    // PP_NONE
    { "(Unknown)",	         /*0*/	""    },    // PP_UNKNOWN

    // 01234567890123456789012345678
    { "Phoenix Wright",	    /*0*/	"That's me, attorney at law!"      },
    { "Twilight Sparkle",	/*10*/	"Unicorn disciple of Princess Celestia. Summoned the 'Greatest Defense Attorney' to Equestria."      },
    { "Royal Guard",        /*17*/  "Royal Equestrian Guard, they appear to handle most police duties here."  },
    { "Rainbow Dash",	    /*39*/	"The Defendent: Pegasus racer, the 'best flier in Equestria'. Accused of the murder of Ace Swift."   },
    { "Ace Swift",	        /*40*/	"The victim, a professional pegasus racer. Found dead in the Everfree Forest."  },
    { "Ace Swift",	        /*40*/	"The victim, a professional pegasus racer. Never lost an event. Found dead in the Everfree Forest."  },
    { "Fluttershy",	        /*65*/	"Pegasus friend of Rainbow Dash. Animal caretaker. Witness who lives near the Everfree Forest."      },
    { "Trixie",	            /*114*/	"The Great and Powerful Trixie, unicorn magician and prosecutor. Has a grudge against Twilight."     },
    { "Judge",	            /*126*/ "The Judge also seems to have been called! He's fair, though easily confused."      },
    { "Apple Bloom",	    /*157*/	"Earth pony child, Cutie Mark Crusader. Witness who was in the Everfree Forest the night of the crime."      },
    { "Pinkie Pie",	        /*211*/	"Earth pony Party Thrower Extraordinaire. Friend of Rainbow Dash."      },
    { "Sonata",	            /*287*/	"Unicorn manager of Ace Swift. Resembles Mia from my own realm."        },

    { "Edgeworth",                  ""     },
    { "TESTIMONY",                  ""     },
    { "CROSS-EXAMINE",              ""     },
    { "Gallery",                    ""     }
    
    // WARNING: This is maximum saved people for the savegame right now - if we need more, figure out how to make the static names above not part of the data
};
