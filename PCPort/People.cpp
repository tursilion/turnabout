#include "structures.h"

// people are just special evidence, but sometimes we need them separately
// remember to subtract PP_FIRST!
Evidence_t people[PP_MAX] = {
    //                         Discovered At this image
    { 0, "                ",            ""    },  // PP_NONE
    { 0, "?????",	            /*0*/	""    },  // PP_UNKNOWN

    { 0, "Phoenix Wright",	    /*0*/	"That's me, attorney at law! I seem to have been called to Equestria via magic."      },
    { 0, "Twilight Sparkle",	/*10*/	"Unicorn disciple of Princess Celestia. Summoned the 'Greatest Defense Attorney' to Equestria."      },
    { 0, "Rainbow Dash",	    /*39*/	"Pegsus racer, the 'best flier in Equestria'. Accused of the murder of Ace Swift."      },
    { 0, "Ace Swift",	        /*40*/	"The victim, a professional pegasus racer. Never lost an event. Found dead in the Everfree Forest."      },
    { 0, "Fluttershy",	        /*65*/	"Pegasus friend of Rainbow Dash. Witness who lives near the Everfree Forest."      },
    { 0, "Trixie",	            /*114*/	"The Great and Powerful Trixie, unicorn magician and prosecutor. Has a grudge against Twilight."      },
    { 0, "Judge",	            /*126*/ "The Judge also seems to have been called! He's fair, though easily confused."      },
    { 0, "Apple Bloom",	        /*157*/	"Earth pony child, Cutie Mark Crusader. Witness who was in the Everfree Forest the night of the crime."      },
    { 0, "Pinkie Pie",	        /*211*/	"Earth pony Party Thrower Extraordinaire. Friend of Rainbow Dash."      },
    { 0, "Sonata",	            /*287*/	"Unicorn manager of Ace Swift. Resembles Mia from my own realm."      }

    // TODO: need to fill the appearence field in to the story 'add evidence' field as they are reached
};

