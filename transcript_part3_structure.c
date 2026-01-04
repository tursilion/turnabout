/*
Analysis of transcript part 3.txt structure with interactive game elements:

Story Structure Overview:
1. FLASHBACK - Phoenix's first case advice from Mia
2. COURTROOM AFTERMATH - Phoenix's failure and isolation
3. INVESTIGATION SEGMENT - Meeting Pinkie Pie and exploring
4. PSYCHE-LOCK INTERROGATION - Breaking Rainbow Dash's secrets
5. INVESTIGATION CONTINUATION - Hotel room exploration with Pinkie
6. CHARACTER ENCOUNTER - Meeting Sonata Dusk (suspicious manager)

Interactive Elements:
- USER CHOICE MENUS: Multiple dialogue trees and investigation paths
- PSYCHE-LOCK SYSTEM: Evidence-based questioning to reveal secrets
- INVESTIGATION CHOICES: Where to go, who to talk to, what to examine
- EVIDENCE PRESENTATION: Strategic use of items during conversations

Suggested Generic Objection Failures:
- Random evidence presentation with humorous dismissals
- Overly dramatic objections to mundane statements
- Misunderstanding basic concepts and being corrected
- Trying to present irrelevant items as "proof"


? Perfect! I've successfully enhanced the transcript_part3_structure.c file with comprehensive story segmentation and interactive gameplay
  commentary. The file now includes:

  Story Segments Added:

  1. FLASHBACK - MIA'S ADVICE TO YOUNG PHOENIX - Character development setup
  2. COURTROOM AFTERMATH - PHOENIX'S ISOLATION AND DESPAIR - Emotional low point
  3. FIRST INVESTIGATION - MEETING PINKIE PIE - Comic relief introduction
  4. DETENTION CENTER - RAINBOW DASH'S BREAKDOWN - Character interaction
  5. PSYCHE-LOCK INVESTIGATION SEGMENT - Core gameplay mechanics with 3 lock system
  6. HOTEL INVESTIGATION SEGMENT - Evidence gathering with Pinkie Pie
  7. HOTEL ROOM SEARCH - Evidence discovery
  8. DRAMATIC ENCOUNTER: SONATA DUSK REVEALED - Major plot twist

  Interactive Gameplay Elements Added:

  - Psyche-Lock system with specific evidence requirements for each lock
  - User choice menus for emotional responses and investigation routes
  - Generic alternative responses for failed interactions
  - Evidence presentation opportunities clearly marked
  - User interaction opportunities for character development

  Features Implemented:

  ? Story segmentation with clear section headers
  ? Interactive gameplay commentary with user choice menus
  ? Generic alternative responses instead of evidence-specific ones
  ? Detailed Phoenix Wright gameplay mechanics (Psyche-Locks, evidence presentation)
  ? Character development opportunities marked for player choices
  ? Investigation progression clearly structured

  The file maintains the same comprehensive commenting style as transcript_part2a_structure.c, providing developers with a clear roadmap for
  implementing interactive Phoenix Wright-style gameplay elements while preserving the narrative structure of the visual novel/game.

*/

// Generated from transcript part 3.txt
// Structure definition for conversation entries
typedef struct {
    int evidence;
    int frame;
    int NameAndCommand;
    char* szText;
} ConversationEntry;

// Define constants
#define EV_NONE 0
#define PP_NONE 0
#define PP_PHOENIX 1
#define PP_MIA 2
#define PP_TWILIGHT 3
#define PP_PINKIE 4
#define PP_RAINBOW 5
#define PP_SONATA 6
#define PP_GUARD 7

#define CMD_NONE 0
#define CMD_BLACK 1
#define CMD_WHOOSH 2
#define CMD_CRASH 3
#define CMD_RIP 4
#define CMD_BADUMTISH 5
#define CMD_BREAKLOCK 6
#define CMD_PARTY_HORN 7

// =============================================================================
// STORY SEGMENT: FLASHBACK - MIA'S ADVICE TO YOUNG PHOENIX
// =============================================================================
ConversationEntry transcript_part3[] = {
    // Phoenix practicing for his first trial - sets up his character development
    {evidence: EV_NONE, frame: 203, cmdwho: PP_NONE | CMD_NONE, text: "Fey Law Offices" },
    {evidence: EV_NONE, frame: 203, cmdwho: PP_PHOENIX | CMD_NONE, text: "My name is Phoenix Wright, AND I'M FINE!" },
    {evidence: EV_NONE, frame: 203, cmdwho: PP_PHOENIX | CMD_NONE, text: "My name is Phoenix Wright, AND I'M FINE!!" },
    {evidence: EV_NONE, frame: 203, cmdwho: PP_PHOENIX | CMD_NONE, text: "My name is Phoenix Wright, AND I'M FINE!!!" },
    {evidence: EV_NONE, frame: 204, cmdwho: PP_MIA | CMD_NONE, text: "Phoenix, are you okay!?" },
    {evidence: EV_NONE, frame: 204, cmdwho: PP_PHOENIX | CMD_NONE, text: "Oh, hey Chief. I was just practicing for my very first trial, which is tomorrow." },
    {evidence: EV_NONE, frame: 204, cmdwho: PP_PHOENIX | CMD_NONE, text: "The guys back at law school said this tape would really help me out." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_MIA | CMD_NONE, text: "Thank goodness..." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_MIA | CMD_NONE, text: "When I heard all the screeching coming from the office, I thought someone was murdering you." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_PHOENIX | CMD_NONE, text: "(That wasn't screeching, that was step four!)" },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_MIA | CMD_NONE, text: "Haha, I don't think you need this exercise tape." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_MIA | CMD_NONE, text: "I'm sure you'll do just fine. The suspect -- he's your friend, right?" },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_PHOENIX | CMD_NONE, text: "Yeah, he's my friend... but..." },
    {evidence: EV_NONE, frame: 203, cmdwho: PP_MIA | CMD_NONE, text: "But what?" },
    {evidence: EV_NONE, frame: 203, cmdwho: PP_PHOENIX | CMD_NONE, text: "He's, well..." },
    {evidence: EV_NONE, frame: 203, cmdwho: PP_MIA | CMD_NONE, text: "Yes?" },
    {evidence: EV_NONE, frame: 203, cmdwho: PP_PHOENIX | CMD_NONE, text: "He's kind of an idiot." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_MIA | CMD_NONE, text: "That's not a very nice thing to say about your friend." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_PHOENIX | CMD_NONE, text: "No, I really mean it. He thinks passing the 8th grade is a credential; he even got the report card framed and everything." },
    // Mia's crucial advice about believing in clients and pursuing truth
    {evidence: EV_NONE, frame: 206, cmdwho: PP_MIA | CMD_NONE, text: "So? What are you getting at?" },
    {evidence: EV_NONE, frame: 206, cmdwho: PP_PHOENIX | CMD_NONE, text: "I mean, what if he really did kill that woman?" },
    {evidence: EV_NONE, frame: 206, cmdwho: PP_PHOENIX | CMD_NONE, text: "What do I do?" },
    {evidence: EV_NONE, frame: 206, cmdwho: PP_PHOENIX | CMD_NONE, text: "Do I still lie and try to defend him, or do I side with justice and let him be punished...?" },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_MIA | CMD_NONE, text: "Phoenix..." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_PHOENIX | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_MIA | CMD_NONE, text: "Don't stress yourself out so much." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_MIA | CMD_NONE, text: "Tell me, what do you think?" },
    {evidence: EV_NONE, frame: 206, cmdwho: PP_PHOENIX | CMD_NONE, text: "Me? What do you mean?" },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_MIA | CMD_NONE, text: "You, as Phoenix Wright, not as a defense attorney." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_MIA | CMD_NONE, text: "Do you think your friend killed that woman?" },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_PHOENIX | CMD_NONE, text: "He might not be the sharpest tool in the shed, but I don't think he has it in him to kill anyone." },
    {evidence: EV_NONE, frame: 206, cmdwho: PP_MIA | CMD_NONE, text: "There you go." },
    {evidence: EV_NONE, frame: 206, cmdwho: PP_PHOENIX | CMD_NONE, text: "Huh?" },
    {evidence: EV_NONE, frame: 206, cmdwho: PP_MIA | CMD_NONE, text: "Go off that. You have to believe in him; it's your job to." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_MIA | CMD_NONE, text: "Cast all that doubt aside and pursue the truth. If you do that, nothing can stop you." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_PHOENIX | CMD_NONE, text: "The truth, huh..." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_PHOENIX | CMD_NONE, text: "Thanks, Chief. I'm still a little nervous, though..." },
    {evidence: EV_NONE, frame: 206, cmdwho: PP_MIA | CMD_NONE, text: "Don't worry, we all go through it." },
    {evidence: EV_NONE, frame: 206, cmdwho: PP_PHOENIX | CMD_NONE, text: "Hey, umm... do you by any chance know who the prosecutor is?" },
    {evidence: EV_NONE, frame: 204, cmdwho: PP_MIA | CMD_NONE, text: "The prosecutor?" },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_MIA | CMD_NONE, text: "I believe it's Winston Payne. You know, \"The Rookie Killer.\"" },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_PHOENIX | CMD_NONE, text: "R-rookie killer..." },
    {evidence: EV_NONE, frame: 205, cmdwho: PP_PHOENIX | CMD_NONE, text: "(I don't like the sound of that title.)" },
    {evidence: EV_NONE, frame: 204, cmdwho: PP_MIA | CMD_NONE, text: "Not many rookies take the prosecutor into consideration." },
    {evidence: EV_NONE, frame: 204, cmdwho: PP_MIA | CMD_NONE, text: "Why did you want to know something like that?" },
    {evidence: EV_NONE, frame: 204, cmdwho: PP_PHOENIX | CMD_NONE, text: "No reason, I was just curious." },
    {evidence: EV_NONE, frame: 204, cmdwho: PP_MIA | CMD_NONE, text: "You seem more disappointed than curious." },
    {evidence: EV_NONE, frame: 204, cmdwho: PP_PHOENIX | CMD_NONE, text: "Ah, forget about it. I'm just a little out of it right now." },
    {evidence: EV_NONE, frame: 206, cmdwho: PP_NONE | CMD_NONE, text: "" },
    {evidence: EV_NONE, frame: 206, cmdwho: PP_NONE | CMD_BLACK, text: "" },

    // Phoenix's reflection on failing Mia's teachings
    {evidence: EV_NONE, frame: 206, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'll never forget what you taught me." },
    {evidence: EV_NONE, frame: 206, cmdwho: PP_PHOENIX | CMD_NONE, text: "But somehow, I highly doubt you're looking down on me smiling after what I did today..." },

// =============================================================================
// STORY SEGMENT: COURTROOM AFTERMATH - PHOENIX'S ISOLATION AND DESPAIR
// =============================================================================
    // The crushing reality of Phoenix's courtroom failure
    {evidence: EV_NONE, frame: 100, cmdwho: PP_NONE | CMD_NONE, text: "Ponyville District Court, June 10th, 11:55AM" },
    {evidence: EV_NONE, frame: 207, cmdwho: PP_TWILIGHT | CMD_NONE, text: "Phoenix... I was wrong about you..." },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "Twilight, wait, I-..." },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "She's gone..." },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "Who am I kidding?" },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "She's right. I did absolutely terrible in there..." },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "Now two of her friends are suspects. What do I do now?" },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "I don't have any leads at all, nobody to turn to. I'm all by myself..." },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "Which means... I can't even get back home..." },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "No, I can't think that way. I've got to stay diligent." },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "I said I'd clear Rainbow Dash's name, and I bought her another day." },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "I can't let it go to waste... but where do I start...?" },

// =============================================================================
// STORY SEGMENT: FIRST INVESTIGATION - MEETING PINKIE PIE
// =============================================================================
    // USER CHOICE OPPORTUNITY: Phoenix could choose different responses to Pinkie
    // Options could include: Be serious/professional, Play along with her energy, Ask for help directly
    {evidence: EV_NONE, frame: 208, cmdwho: PP_NONE | CMD_NONE, text: "Hey, Mr Frowny-Wowny. What's the matter?" },
    {evidence: EV_NONE, frame: 208, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Huh? Where did she come from? She smells like cotton candy...)" },
    {evidence: EV_NONE, frame: 209, cmdwho: PP_NONE | CMD_NONE, text: "Cotton candy?" },
    {evidence: EV_NONE, frame: 210, cmdwho: PP_NONE | CMD_NONE, text: "Oh! You must smell the new shampoo I'm using." },
    {evidence: EV_NONE, frame: 210, cmdwho: PP_PHOENIX | CMD_NONE, text: "That explains it, then..." },
    {evidence: EV_NONE, frame: 208, cmdwho: PP_PHOENIX | CMD_NONE, text: "Wait, did I say that, or think tha-...?" },
    {evidence: EV_NONE, frame: 208, cmdwho: PP_PHOENIX | CMD_NONE, text: "Who are you!?" },
    {evidence: EV_NONE, frame: 211, cmdwho: PP_PINKIE | CMD_NONE, text: "I'm Pinkie Pie, of course!" },
    {evidence: PP_PINKIE, frame: 211, cmdwho: PP_PINKIE | CMD_ADDEV, text: "Party Thrower Extraordinaire!" },
    {evidence: EV_NONE, frame: 209, cmdwho: PP_PINKIE | CMD_NONE, text: "But I can't talk right now! I'm looking for something..." },

what are you looking for?

    {evidence: EV_NONE, frame: 209, cmdwho: PP_PHOENIX | CMD_NONE, text: "What are you looking for?" },
    {evidence: EV_NONE, frame: 208, cmdwho: PP_PINKIE | CMD_NONE, text: "Some other ponies said there was a spiky-headed monster in here." },
    {evidence: EV_NONE, frame: 208, cmdwho: PP_PINKIE | CMD_NONE, text: "I can't seem to find it anywhere, though." },
    {evidence: EV_NONE, frame: 209, cmdwho: PP_PINKIE | CMD_NONE, text: "You'd think it would stick out like a sore hoof." },
    {evidence: EV_NONE, frame: 208, cmdwho: PP_PINKIE | CMD_NONE, text: "Have you seen it?" },
    {evidence: EV_NONE, frame: 208, cmdwho: PP_PHOENIX | CMD_NONE, text: "(* sigh *)" },
    {evidence: EV_NONE, frame: 212, cmdwho: PP_PINKIE | CMD_NONE, text: "...does that mean \"no\"?" },
    {evidence: EV_NONE, frame: 212, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'm getting so sick of this place!" },
    {evidence: EV_NONE, frame: 212, cmdwho: PP_PHOENIX | CMD_SELPROMPT, text: "" },
    
express frustration
    
    {evidence: EV_NONE, frame: 213, cmdwho: PP_PINKIE | CMD_NONE, text: "Hey! Turn that frowny upside-downy!" },
    {evidence: EV_NONE, frame: 213, cmdwho: PP_PHOENIX | CMD_NONE, text: "How can I? I did such a lousy job in court today, and Twilight probably hates my guts for what I did..." },
    {evidence: EV_NONE, frame: 210, cmdwho: PP_PINKIE | CMD_NONE, text: "Hey, you know Twilight!? Me too!" },
    {evidence: EV_NONE, frame: 210, cmdwho: PP_PHOENIX | CMD_NONE, text: "You know Twilight Sparkle?" },
    {evidence: EV_NONE, frame: 213, cmdwho: PP_PINKIE | CMD_NONE, text: "Yup! We're the bestest of best friends!" },
    {evidence: EV_NONE, frame: 214, cmdwho: PP_PINKIE | CMD_NONE, text: "Oh, that reminds me! I'm supposed to go to court today, and cheer for Rainbow Dash!" },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PINKIE | CMD_NONE, text: "Sorry, gotta run!" },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "But you're-!" },
    {evidence: EV_NONE, frame: 208, cmdwho: PP_PINKIE | CMD_NONE, text: "Oh, I'm already here." },
    {evidence: EV_NONE, frame: 211, cmdwho: PP_PINKIE | CMD_NONE, text: "Yay!" },
    {evidence: EV_NONE, frame: 213, cmdwho: PP_PHOENIX | CMD_NONE, text: "I hate to break it to you, but you missed the trial." },
    {evidence: EV_NONE, frame: 213, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Out of all the pastel grass-chewers I've met, this one is definitely the weirdest.)" },
    {evidence: EV_NONE, frame: 213, cmdwho: PP_PHOENIX | CMD_NONE, text: "(AH! I better be careful, I think she can read minds.)" },
    {evidence: EV_NONE, frame: 212, cmdwho: PP_PINKIE | CMD_NONE, text: "Is Dashie okay?" },
    {evidence: EV_NONE, frame: 212, cmdwho: PP_PHOENIX | CMD_NONE, text: "For the time being, yes." },
    {evidence: EV_NONE, frame: 212, cmdwho: PP_PHOENIX | CMD_NONE, text: "The trial is being postponed. I'm actually Rainbow Dash's lawyer, Phoenix Wright." },
    {evidence: EV_ ((continue)), frame: 212, cmdwho: PP_PHOENIX | CMD_JUMP, text: "" },

introduce self

    {evidence: EV_NONE, frame: 212, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'm Rainbow Dash's lawyer, Phoenix Wright." },
    {evidence: EV_NONE, frame: 214, cmdwho: PP_PINKIE | CMD_NONE, text: "Oh, that reminds me! I'm supposed to go to court today, and cheer for Rainbow Dash!" },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PINKIE | CMD_NONE, text: "Sorry, gotta run!" },
    {evidence: EV_NONE, frame: 100, cmdwho: PP_PHOENIX | CMD_NONE, text: "But you're-!" },
    {evidence: EV_NONE, frame: 208, cmdwho: PP_PINKIE | CMD_NONE, text: "Oh, I'm already here." },
    {evidence: EV_NONE, frame: 211, cmdwho: PP_PINKIE | CMD_NONE, text: "Yay!" },
    {evidence: EV_NONE, frame: 213, cmdwho: PP_PHOENIX | CMD_NONE, text: "I hate to break it to you, but you missed the trial." },
    {evidence: EV_NONE, frame: 213, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Out of all the pastel grass-chewers I've met, this one is definitely the weirdest.)" },
    {evidence: EV_NONE, frame: 213, cmdwho: PP_PHOENIX | CMD_NONE, text: "(AH! I better be careful, I think she can read minds.)" },
    {evidence: EV_NONE, frame: 212, cmdwho: PP_PINKIE | CMD_NONE, text: "Is Dashie okay?" },
    {evidence: EV_NONE, frame: 212, cmdwho: PP_PHOENIX | CMD_NONE, text: "For the time being, yes." },

continue

    {evidence: EV_NONE, frame: 210, cmdwho: PP_NONE | CMD_NONE, text: "" },
    {evidence: EV_NONE, frame: 210, cmdwho: PP_PINKIE | CMD_NONE, text: "Neato! So what'cha doing right now, Feenie?" },
    {evidence: EV_NONE, frame: 212, cmdwho: PP_PHOENIX | CMD_NONE, text: "\"Feenie\"... that's... ... never mind..." },
    {evidence: EV_NONE, frame: 213, cmdwho: PP_PHOENIX | CMD_NONE, text: "Well... I don't know what I should be doing right now, to be honest. I have no leads at all." },
    {evidence: EV_NONE, frame: 208, cmdwho: PP_PINKIE | CMD_NONE, text: "Why don't you go talk to Dashie about the trial?" },
    {evidence: EV_NONE, frame: 213, cmdwho: PP_PHOENIX | CMD_NONE, text: "Wait a minute... she had Psyche-locks..." },
    {evidence: EV_NONE, frame: 209, cmdwho: PP_PINKIE | CMD_NONE, text: "Psyche-locks? Is that some kinda breakfast cereal?" },
    {evidence: EV_NONE, frame: 210, cmdwho: PP_PINKIE | CMD_NONE, text: "Sounds yummy!" },
    {evidence: EV_NONE, frame: 208, cmdwho: PP_PINKIE | CMD_NONE, text: "Is it made with real locks and not grossly-wossly artificial locks?" },
    {evidence: EV_NONE, frame: 215, cmdwho: PP_PHOENIX | CMD_NONE, text: "Thanks for the advice, erm, Pinkie Pie." },
    {evidence: EV_NONE, frame: 215, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'm gonna go to the detention center now." },

// =============================================================================
// STORY SEGMENT: DETENTION CENTER - RAINBOW DASH'S BREAKDOWN
// =============================================================================
    // USER CHOICE OPPORTUNITY: How to approach Rainbow Dash's emotional state
    // Options could include: Comfort her, Be direct about the case, Address her anger
    {evidence: EV_NONE, frame: 34, cmdwho: PP_NONE | CMD_NONE, text: "Ponyville Detention Center, June 10th, 12:00PM" },
    {evidence: EV_NONE, frame: 34, cmdwho: PP_PHOENIX | CMD_NONE, text: "(I really hope she isn't mad at me after what happened...)" },
    {evidence: EV_NONE, frame: 216, cmdwho: PP_RAINBOW | CMD_NONE, text: "No no no no! No! No! No!" },
    {evidence: EV_NONE, frame: 217, cmdwho: PP_PHOENIX | CMD_NONE, text: "R-Rainbow Dash?" },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_RAINBOW | CMD_NONE, text: "I-I can't bear to live anymore!" },
    {evidence: EV_NONE, frame: 216, cmdwho: PP_RAINBOW | CMD_NONE, text: "Throw the book at me! L-let them send me to the sun, there's nothing left for me in Equestria!" },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_PHOENIX | CMD_NONE, text: "Rainbow Dash, get a hold of yourself!" },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_PHOENIX | CMD_NONE, text: "(She must still be upset over those... pictures.)" },
    {evidence: EV_NONE, frame: 218, cmdwho: PP_RAINBOW | CMD_NONE, text: "Easy for you to say! Now the Wonderbolts will NEVER let me in! Ponyville is going to laugh at me forever!" },
    {evidence: EV_NONE, frame: 218, cmdwho: PP_PHOENIX | CMD_NONE, text: "They weren't... that... um... bad... r-really. I'm sure everyone will forget it by tomorrow. I guarantee it." },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_PHOENIX | CMD_NONE, text: "(There's no way anyone's forgetting images like those...)" },
    {evidence: EV_NONE, frame: 44, cmdwho: PP_RAINBOW | CMD_NONE, text: "You think so?" },
    {evidence: EV_NONE, frame: 44, cmdwho: PP_PHOENIX | CMD_NONE, text: "I know so! I'm always right: my name is Phoenix WRIGHT after all..." },
    {evidence: EV_NONE, frame: 219, cmdwho: PP_NONE | CMD_NONE, text: "" },
    {evidence: EV_NONE, frame: 219, cmdwho: PP_RAINBOW | CMD_NONE, text: "That wasn't funny..." },
    {evidence: EV_NONE, frame: 219, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Ack! ... I thought it was! ...)" },

    /*
    // SUGGESTED GENERIC ALTERNATIVE RESPONSES:
    // Option 1: "Don't worry, I'll get you out of this mess!"
    // Option 2: "Look, we need to focus on finding the real killer."
    // Option 3: "Actually, those pictures weren't that embarrassing..." (gets angry reaction)
    */

    /*
    // USER INTERACTION OPPORTUNITY: COMFORT RAINBOW DASH
    // Present 3-choice menu:
    // A) "I believe in your innocence completely."
    // B) "We'll figure this out together."
    // C) "Those photos don't define who you are." (emotional route)
    */

    // Building trust before the Psyche-Lock investigation
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "Thanks for trying to cheer me up though, I appreciate it." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "You're welcome." },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_RAINBOW | CMD_NONE, text: "By the way..." },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_PHOENIX | CMD_NONE, text: "Yes? What is it?" },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_RAINBOW | CMD_NONE, text: "What was that terri-bad performance in court today!?" },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_RAINBOW | CMD_NONE, text: "I could have done a better job defending myself!" },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_PHOENIX | CMD_NONE, text: "I-I..." },
    {evidence: EV_NONE, frame: 220, cmdwho: PP_RAINBOW | CMD_NONE, text: "Every defense attorney must suck horse apples, if you're supposed to be the best one!" },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_PHOENIX | CMD_NONE, text: "Look, I know I screwed up, but I'm going to make it up to you and Fluttershy tomorrow." },
    {evidence: EV_NONE, frame: 221, cmdwho: PP_RAINBOW | CMD_NONE, text: "Fluttershy?! Ha!" },
    {evidence: EV_NONE, frame: 221, cmdwho: PP_RAINBOW | CMD_NONE, text: "She got what she deserved! After she betrayed me like that!" },
    {evidence: EV_NONE, frame: 221, cmdwho: PP_PHOENIX | CMD_NONE, text: "Hey! It tore me up having to do that! It was the only way I could save you. Fluttershy didn't betray you." },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_RAINBOW | CMD_NONE, text: "Give me a break! This is the thanks I get for all the times I stuck up for her sorry flank?" },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_PHOENIX | CMD_NONE, text: "She was just telling the truth." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "Truth? You proved she was lying though, she didn't see Applebloom!" },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_PHOENIX | CMD_NONE, text: "But she did see you leave the forest... you were there, weren't you?" },
    {evidence: EV_NONE, frame: 38, cmdwho: PP_RAINBOW | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 221, cmdwho: PP_RAINBOW | CMD_NONE, text: "Whatever! We are ex-friends as of now!" },
    {evidence: EV_NONE, frame: 38, cmdwho: PP_RAINBOW | CMD_NONE, text: "I could tell you were trying your hardest to defend me, even if you did do a crummy job." },
    {evidence: EV_NONE, frame: 38, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Gee, thanks.)" },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_RAINBOW | CMD_NONE, text: "She pretty much said:" },
    {evidence: EV_NONE, frame: 222, cmdwho: PP_RAINBOW | CMD_NONE, text: "\"Yup! Rainbow Dash did it!\"" },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_RAINBOW | CMD_NONE, text: "What kind of a friend does that?" },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_PHOENIX | CMD_NONE, text: "Rainbow Dash, for the last time, she was telling the truth. What she saw..." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "Actually, that brings me to why I'm here." },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_RAINBOW | CMD_NONE, text: "What? Why are you here?" },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_PHOENIX | CMD_NONE, text: "The truth. I want to know what you were really doing near the Everfree Forest the night of the murder." },

// =============================================================================
// PSYCHE-LOCK INVESTIGATION SEGMENT: BREAKING RAINBOW DASH'S SECRETS
// =============================================================================
    // THE MAGATAMA ACTIVATION - Key interactive gameplay element
    // PSYCHE-LOCK 1/3: "I was just practicing for the race"
    /*
    // EVIDENCE NEEDED TO BREAK: Rainbow's Feathers, Victim's Location
    // WRONG EVIDENCE EXAMPLES:
    // - Present Attorney's Badge: "My badge won't reveal her secrets!"
    // - Present Court Record: "This isn't going to make her talk..."
    // - Present Photos: "She's already embarrassed enough about those!"
    */

    {evidence: EV_NONE, frame: 223, cmdwho: PP_PHOENIX | CMD_NONE, text: "(phoenix takethat sfx)" },
    {evidence: EV_NONE, frame: 224, cmdwho: PP_RAINBOW | CMD_NONE, text: "Ugh..." },
    {evidence: EV_NONE, frame: 225, cmdwho: PP_RAINBOW | CMD_NONE, text: "I told you already, I was practicing for the race!" },
    {evidence: EV_NONE, frame: 225, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Phew... it still works after that incident this morning...)" },
    {evidence: EV_NONE, frame: 225, cmdwho: PP_NONE | CMD_NONE, text: "" },
    {evidence: EV_NONE, frame: 227, cmdwho: PP_PHOENIX | CMD_NONE, text: "(What was that all about anyway?)" },
    {evidence: EV_NONE, frame: 227, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Ugh, forget about that! It still works, and that's all that matters!)" },
    {evidence: EV_NONE, frame: 227, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Okay, there they are. Time to break 'em!)" },
    {evidence: EV_NONE, frame: 227, cmdwho: PP_PHOENIX | CMD_NONE, text: "Sorry, but I don't believe you, my little pony. Not for a single solitary second." },
    {evidence: EV_NONE, frame: 224, cmdwho: PP_RAINBOW | CMD_NONE, text: "You're my lawyer and you don't believe me? THAT'S reassuring..." },
    {evidence: EV_NONE, frame: 224, cmdwho: PP_PHOENIX | CMD_NONE, text: "Let's play a game, Rainbow Dash..." },
    {evidence: EV_NONE, frame: 224, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'm going to guess what you were really doing near the crime scene that night, and you're going to tell me if I'm right." },
    {evidence: EV_NONE, frame: 228, cmdwho: PP_RAINBOW | CMD_NONE, text: "You can go right ahead and do that, but I'm sticking to my story." },
    {evidence: EV_NONE, frame: 228, cmdwho: PP_PHOENIX | CMD_NONE, text: "I don't think you were practicing at all; I think you were doing something FAR more important." },
    {evidence: EV_NONE, frame: 225, cmdwho: PP_RAINBOW | CMD_NONE, text: "L-like WHAT!?" },
    {evidence: EV_NONE, frame: 225, cmdwho: PP_PHOENIX | CMD_NONE, text: "Like, oh, I don't know... meeting someone?" },
    {evidence: EV_NONE, frame: 229, cmdwho: PP_RAINBOW | CMD_NONE, text: "Ah! Uh-I-I mean-..." },
    {evidence: EV_NONE, frame: 225, cmdwho: PP_RAINBOW | CMD_NONE, text: "Who would I be meeting in the middle of the forest at that hour?" },
    {evidence: EV_NONE, frame: 225, cmdwho: PP_RAINBOW | CMD_NONE, text: "Nopony ever goes in there willingly." },
    {evidence: EV_NONE, frame: 225, cmdwho: PP_PHOENIX | CMD_NONE, text: "Then why were YOU \"practicing\" there if no one ever goes in there willingly?" },
    {evidence: EV_NONE, frame: 229, cmdwho: PP_RAINBOW | CMD_NONE, text: "U-uh... w-well..." },
    {evidence: EV_NONE, frame: 227, cmdwho: PP_PHOENIX | CMD_NONE, text: "I know there was someone in the forest the night of the murder." },
    {evidence: EV_NONE, frame: 225, cmdwho: PP_RAINBOW | CMD_NONE, text: "Put your money where your mouth is! Who do you think I was meeting?" },

    // EVIDENCE PRESENTATION: Rainbow's Feathers + Victim Location Logic
    {evidence: EV_NONE, frame: 223, cmdwho: PP_PHOENIX | CMD_NONE, text: "(phoenix takethat sfx)" },
    {evidence: EV_NONE, frame: 227, cmdwho: PP_PHOENIX | CMD_NONE, text: "Ace Swift!" },
    {evidence: EV_NONE, frame: 227, cmdwho: PP_PHOENIX | CMD_NONE, text: "The fact that your feathers were found all around the clearing proves you were there that night." },
    {evidence: EV_NONE, frame: 229, cmdwho: PP_RAINBOW | CMD_NONE, text: "!!??" },
    {evidence: EV_NONE, frame: 229, cmdwho: PP_PHOENIX | CMD_NONE, text: "And who else was in the clearing that night...? The victim, of course!" },
    {evidence: EV_NONE, frame: 229, cmdwho: PP_PHOENIX | CMD_NONE, text: "You needed to be there to see him." },
    {evidence: EV_NONE, frame: 229, cmdwho: PP_PHOENIX | CMD_NONE, text: "You also just told me, ponies avoid going in there." },
    {evidence: EV_NONE, frame: 229, cmdwho: PP_PHOENIX | CMD_NONE, text: "So I'm willing to bet he wanted to meet with you in private, and what better place to pick than the middle of a forest nobody ever goes into?" },
    {evidence: EV_NONE, frame: 230, cmdwho: PP_RAINBOW | CMD_NONE, text: "AHH! NOOOOO!" },
    {evidence: EV_NONE, frame: 231, cmdwho: PP_NONE | CMD_BREAKLOCK, text: "(breaklock sfx)" },

    // PSYCHE-LOCK 2/3: "He was just competition"
    /*
    // EVIDENCE NEEDED TO BREAK: Blackmail Photos
    // This reveals the real motive for the meeting
    */
    {evidence: EV_NONE, frame: 232, cmdwho: PP_RAINBOW | CMD_NONE, text: "I-I mean-... \"Ah, no, you're wrong!\"" },
    {evidence: EV_NONE, frame: 233, cmdwho: PP_RAINBOW | CMD_NONE, text: "H-he was just competition!" },
    {evidence: EV_NONE, frame: 233, cmdwho: PP_RAINBOW | CMD_NONE, text: "Why would I want to meet him? I have better things I could be doing." },
    {evidence: EV_NONE, frame: 233, cmdwho: PP_PHOENIX | CMD_NONE, text: "Like what?" },
    {evidence: EV_NONE, frame: 234, cmdwho: PP_RAINBOW | CMD_NONE, text: "I don't know, napping? Something like that..." },
    {evidence: EV_NONE, frame: 234, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Oh, please...)" },
    {evidence: EV_NONE, frame: 234, cmdwho: PP_PHOENIX | CMD_NONE, text: "Maybe he had something you wanted." },
    {evidence: EV_NONE, frame: 235, cmdwho: PP_RAINBOW | CMD_NONE, text: "What do you mean?" },
    {evidence: EV_NONE, frame: 235, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'm saying maybe he had somehting important to you, something you'd move heaven and earth for." },
    {evidence: EV_NONE, frame: 233, cmdwho: PP_RAINBOW | CMD_NONE, text: "I'm a pretty self-satisfied pony." },
    {evidence: EV_NONE, frame: 233, cmdwho: PP_RAINBOW | CMD_NONE, text: "I've got everything I need, well, besides fortune and glory, and I don't think he could give those to me." },
    {evidence: EV_NONE, frame: 236, cmdwho: PP_RAINBOW | CMD_NONE, text: "What could he possibly have that I'd want?" },
    {evidence: EV_NONE, frame: 236, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'm glad you asked that, Rainbow Dash..." },
    {evidence: EV_NONE, frame: 235, cmdwho: PP_RAINBOW | CMD_NONE, text: "Y-you are?" },
    {evidence: EV_NONE, frame: 235, cmdwho: PP_PHOENIX | CMD_NONE, text: "There's one thing that you absolutely needed that I know he had." },
    {evidence: EV_NONE, frame: 234, cmdwho: PP_RAINBOW | CMD_NONE, text: "I'm afraid I don't know what you're talking about..." },
    {evidence: EV_NONE, frame: 234, cmdwho: PP_PHOENIX | CMD_NONE, text: "The reason you went to go meet him is..." },

    // CRITICAL EVIDENCE PRESENTATION: The Blackmail Photos
    {evidence: EV_NONE, frame: 223, cmdwho: PP_PHOENIX | CMD_NONE, text: "(phoenix takethat sfx)" },
    {evidence: EV_NONE, frame: 223, cmdwho: PP_PHOENIX | CMD_NONE, text: "These!" },
    {evidence: EV_NONE, frame: 237, cmdwho: PP_RAINBOW | CMD_NONE, text: "AHH! Put those away before somepony sees them! PLEASE!" },
    {evidence: EV_NONE, frame: 238, cmdwho: PP_PHOENIX | CMD_NONE, text: "Even right now, your anxiety shows you absolutely didn't want these pictures floating out and about!" },
    {evidence: EV_NONE, frame: 232, cmdwho: PP_RAINBOW | CMD_NONE, text: "Yes, yes, yes, you're right!" },
    {evidence: EV_NONE, frame: 232, cmdwho: PP_RAINBOW | CMD_NONE, text: "I was meeting him about these! Can you please just put them away? NOW!?" },
    {evidence: EV_NONE, frame: 239, cmdwho: PP_NONE | CMD_BREAKLOCK, text: "(breaklock sfx)" },

    // PSYCHE-LOCK 3/3: The true nature of the meeting
    /*
    // EVIDENCE NEEDED TO BREAK: Race information + Logic about Ace's behavior
    // This reveals the blackmail scheme
    */
    {evidence: EV_NONE, frame: 240, cmdwho: PP_PHOENIX | CMD_NONE, text: "This brings us to the money question... why did he have these pictures?" },
    {evidence: EV_NONE, frame: 240, cmdwho: PP_RAINBOW | CMD_NONE, text: "Who knows, he's dead, what a bummer, guess we'll never know!" },
    {evidence: EV_NONE, frame: 240, cmdwho: PP_PHOENIX | CMD_NONE, text: "I actually think I know why." },
    {evidence: EV_NONE, frame: 241, cmdwho: PP_RAINBOW | CMD_NONE, text: "You do?" },
    {evidence: EV_NONE, frame: 241, cmdwho: PP_PHOENIX | CMD_NONE, text: "Yes. I can think of one reason why he'd want to meet you over pictures like these..." },
    {evidence: EV_NONE, frame: 241, cmdwho: PP_PHOENIX | CMD_NONE, text: "He was blackmailing you, wasn't he?" },
    {evidence: EV_NONE, frame: 242, cmdwho: PP_RAINBOW | CMD_NONE, text: "Blackmail..." },
    {evidence: EV_NONE, frame: 242, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'm willing to bet my attorney badge that he wanted you to toss the Equestrian 500." },
    {evidence: EV_NONE, frame: 242, cmdwho: PP_RAINBOW | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 242, cmdwho: PP_PHOENIX | CMD_NONE, text: "I was told of ponies suspecting him of foul play in the wake of all his success." },
    {evidence: EV_NONE, frame: 242, cmdwho: PP_PHOENIX | CMD_NONE, text: "He was probably threatening you to let him win the race." },
    {evidence: EV_NONE, frame: 241, cmdwho: PP_RAINBOW | CMD_NONE, text: "Wow..." },
    {evidence: EV_NONE, frame: 241, cmdwho: PP_PHOENIX | CMD_NONE, text: "Hmm?" },
    {evidence: EV_NONE, frame: 243, cmdwho: PP_RAINBOW | CMD_NONE, text: "You're really good..." },
    {evidence: EV_NONE, frame: 244, cmdwho: PP_NONE | CMD_BREAKLOCK, text: "(breaklock sfx)" },

    // FULL TRUTH REVEALED
    {evidence: EV_NONE, frame: 245, cmdwho: PP_RAINBOW | CMD_NONE, text: "It's true... Ace was trying to force me to drop out of the Equestrian 500..." },
    {evidence: EV_NONE, frame: 245, cmdwho: PP_PHOENIX | CMD_NONE, text: "How did it start?" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "I got home two days ago and saw this letter on my doorstep." },
    {evidence: EV_NONE, frame: 246, cmdwho: PP_NONE | CMD_NONE, text: "A letter blackmailing Rainbow Dash that she found on her doorstep." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "\"I'll let your secret out if you don't drop out of the Equestrian 500. Meet in the Everfree Forest clearing 8:35PM tonight for negotiations.\"" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "At first I didn't know what secret it was talking about..." },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_RAINBOW | CMD_NONE, text: "But attached to the message was one of those pictures..." },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_PHOENIX | CMD_NONE, text: "About those pictures..." },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_PHOENIX | CMD_NONE, text: "Why are you-" },
    {evidence: EV_NONE, frame: 247, cmdwho: PP_RAINBOW | CMD_NONE, text: "IT'S A HOBBY, ALRIGHT!?" },
    {evidence: EV_NONE, frame: 247, cmdwho: PP_RAINBOW | CMD_NONE, text: "I BET YOU HAVE SKELETONS IN YOUR CLOSET TOO, MR 20-SOMETHING WHO PLAYS WITH TOYS!" },
    {evidence: EV_NONE, frame: 247, cmdwho: PP_PHOENIX | CMD_NONE, text: "Okay, okay, I won't ask about them anymore." },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_PHOENIX | CMD_NONE, text: "Do you have any idea how he got them, though?" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "I have no clue; my best guess is that the jerk was stalking me, trying to get dirt on me." },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_PHOENIX | CMD_NONE, text: "Rainbow Dash..." },
    {evidence: EV_NONE, frame: 38, cmdwho: PP_RAINBOW | CMD_NONE, text: "Yes? What is it?" },
    {evidence: EV_NONE, frame: 38, cmdwho: PP_PHOENIX | CMD_NONE, text: "I want you to know that I trust you, and I'm going to need you to trust me when I ask you these next series of questions." },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_RAINBOW | CMD_NONE, text: "Huh?" },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_PHOENIX | CMD_NONE, text: "I know you may be scared this will make you look guilty, but I know you're innocent." },
    {evidence: EV_NONE, frame: 248, cmdwho: PP_RAINBOW | CMD_NONE, text: "I-I'm not scared...!" },
    {evidence: EV_NONE, frame: 248, cmdwho: PP_PHOENIX | CMD_NONE, text: "Why did you move that cloud to the crime scene and set it off?" },
    {evidence: EV_NONE, frame: 245, cmdwho: PP_NONE | CMD_NONE, text: "" },
    {evidence: EV_NONE, frame: 245, cmdwho: PP_RAINBOW | CMD_NONE, text: "B-but... I-I... I didn't-" },
    {evidence: EV_NONE, frame: 245, cmdwho: PP_PHOENIX | CMD_NONE, text: "Please, Rainbow Dash, you can trust me. I won't think any differently of you in light of what you tell me. I know you didn't kill him." },
    {evidence: EV_NONE, frame: 245, cmdwho: PP_RAINBOW | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "Okay... I'll tell you..." },
    {evidence: EV_NONE, frame: 245, cmdwho: PP_RAINBOW | CMD_NONE, text: "I did move the cloud there and I did set it off..." },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_RAINBOW | CMD_NONE, text: "I just wanted to give him a scare, that's all." },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_PHOENIX | CMD_NONE, text: "A scare?" },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_PHOENIX | CMD_NONE, text: "So you really did move the cloud over the forest clearing?" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "As soon as I saw the requirements of the blackmail letter, I knew it was Ace, and that all those rumors about him were true." },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_RAINBOW | CMD_NONE, text: "He's a blackmailing cheater." },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_RAINBOW | CMD_NONE, text: "So, I set up the cloud over the clearing earlier that day with the intent of declining his little offer." },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_PHOENIX | CMD_NONE, text: "So you weren't going to drop out in spite of him leaking the pictures?" },
    {evidence: EV_NONE, frame: 247, cmdwho: PP_RAINBOW | CMD_NONE, text: "No way!" },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_RAINBOW | CMD_NONE, text: "I'm not going to let some loser have his way with me even if it meant those pictures getting out..." },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_RAINBOW | CMD_NONE, text: "I have too much pride for that." },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_PHOENIX | CMD_NONE, text: "I find that really admirable." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_RAINBOW | CMD_NONE, text: "Heh, thanks..." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_RAINBOW | CMD_NONE, text: "This is also my first year competing in the race; I just reached the required age to participate." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_RAINBOW | CMD_NONE, text: "I've been way too anxious to just drop out." },
    {evidence: EV_NONE, frame: 39, cmdwho: PP_RAINBOW | CMD_NONE, text: "R-B-D spells VIC-TOR-Y!" },
    {evidence: EV_NONE, frame: 39, cmdwho: PP_PHOENIX | CMD_NONE, text: "You sure you can take 500 miles? It's longer than it sounds, you know." },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_RAINBOW | CMD_NONE, text: "There's some checkpoints along the track set up so the racers can have some R&R, but that's a little problem I keep having." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "There's no doubt I'm fast, but I tire out along the way. I'm not used to flying that long." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "In races like these, you should pace yourself accordingly." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "Don't go fast right from the start - save all your energy for the home stretch." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "Kind of like how I don't present all my evidence right from the start." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_RAINBOW | CMD_NONE, text: "I'll try to keep that in mind." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_PHOENIX | CMD_NONE, text: "But let's get back on topic, shall we?" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'm supposed to be your lawyer, not your coach." },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_RAINBOW | CMD_NONE, text: "Right..." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "Anyway, I wasn't planning on killing him, just give him a bit of a startle..." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "You know, just kicking some dirt in his face for messing with me." },
    {evidence: EV_NONE, frame: 249, cmdwho: PP_RAINBOW | CMD_NONE, text: "The cloud shoots a lightning bolt directly under it when activated." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_RAINBOW | CMD_NONE, text: "I mess around with ponies by scaring them with clouds all the time, but I got an extra big one in his case, to make the sound as loud as possible." },
    {evidence: EV_NONE, frame: 245, cmdwho: PP_RAINBOW | CMD_NONE, text: "I guess it was a little dangerous getting one that big." },
    {evidence: EV_NONE, frame: 245, cmdwho: PP_PHOENIX | CMD_NONE, text: "So it didn't hit him when you set it off?" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "No, I made sure it wasn't over him." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "Even though it was really dark outside, like you said in the court today, I could see that the bolt didn't even come close to touching him." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_RAINBOW | CMD_NONE, text: "When the lightning bolt lit up the area, it made him scream like a little girl and left a really sissy look on his mug." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_RAINBOW | CMD_NONE, text: "You should have seen it; it was priceless!" },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_RAINBOW | CMD_NONE, text: "Then I just hightailed it out of there as fast as I could." },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_PHOENIX | CMD_NONE, text: "(That's probably when Fluttershy saw her.)" },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_PHOENIX | CMD_NONE, text: "Why didn't you tell anyone about this blackmail earlier?" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "I didn't want anypony to know about the blackmail... because..." },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_RAINBOW | CMD_NONE, text: "You know... they would wonder what he was blackmailing me with..." },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_PHOENIX | CMD_NONE, text: "I see..." },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Then those pictures would get out...)" },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_RAINBOW | CMD_NONE, text: "You believe me, right? He was absolutely fine when I left, I swear!" },
    {evidence: EV_NONE, frame: 45, cmdwho: PP_PHOENIX | CMD_NONE, text: "Yes, I believe you, though more questions arise from this." },
    {evidence: EV_NONE, frame: 248, cmdwho: PP_RAINBOW | CMD_NONE, text: "More questions?" },
    {evidence: EV_NONE, frame: 248, cmdwho: PP_PHOENIX | CMD_NONE, text: "How did he end up dead directly under the cloud?" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "I was trying desperately to convince the court it was the second bolt that killed him. That would make this all an accident, since you have no control over it." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "But then we have that \"Lightning doesn't strike the same place twice\" thing that Trixie was talking about." },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_RAINBOW | CMD_NONE, text: "That's true, it's a new type of storm cloud the pegasi are using to protect ponies from situations like this." },
    {evidence: EV_NONE, frame: 249, cmdwho: PP_RAINBOW | CMD_NONE, text: "Since it can't hit the same place twice, they can just stand under a cloud after the first bolt." },
    {evidence: EV_NONE, frame: 249, cmdwho: PP_PHOENIX | CMD_NONE, text: "So the safest place is under the cloud..." },
    {evidence: EV_NONE, frame: 249, cmdwho: PP_PHOENIX | CMD_NONE, text: "That's really something; the weather just works by itself where I live." },
    {evidence: EV_NONE, frame: 39, cmdwho: PP_RAINBOW | CMD_NONE, text: "I kind of wish it worked that way here; I'd have a lot more free time on my hooves so I could perfect my \"Sonic Rainboom\" or my \"Fantastic Filly Flash\"." },
    {evidence: EV_NONE, frame: 39, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Are those dance moves or something?)" },
    {evidence: EV_NONE, frame: 39, cmdwho: PP_PHOENIX | CMD_NONE, text: "From what I hear, you're also the weather manager." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "I need some information regarding how the lightning here in Equestria works." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "What do you need to know?" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "Well, is it true the bolt causes the noise?" },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_RAINBOW | CMD_NONE, text: "Yeah, it is." },
    {evidence: EV_NONE, frame: 249, cmdwho: PP_RAINBOW | CMD_NONE, text: "I don't know how it works exactly, but I'm pretty sure when it touches the ground or anything attached to the ground, like, say, a tree... it sends out vibrations which makes the 'boom'." },
    {evidence: EV_NONE, frame: 249, cmdwho: PP_PHOENIX | CMD_NONE, text: "(I'm no meteorologist, but I'm pretty sure lightning doesn't work like that...)" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Then again, I keep forgetting I'm in a land full of magical talking ponies who can manually change weather...)" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "Is there anything that could prevent it from making a sound?" },
    {evidence: EV_NONE, frame: 249, cmdwho: PP_RAINBOW | CMD_NONE, text: "I suppose if it hit something small in the air that was close enough to the cloud... yeah, it wouldn't make a sound..." },
    {evidence: EV_NONE, frame: 248, cmdwho: PP_RAINBOW | CMD_NONE, text: "And I know what you're thinking, but that couldn't happen..." },
    {evidence: EV_NONE, frame: 248, cmdwho: PP_PHOENIX | CMD_NONE, text: "Why not?" },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_RAINBOW | CMD_NONE, text: "That itchy racing suit." },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_PHOENIX | CMD_NONE, text: "Oh, right. I remember that being brought up." },
    {evidence: EV_NONE, frame: 250, cmdwho: PP_PHOENIX | CMD_NONE, text: "That's that lightning-proof suit you pegasuses wear for the race, right?" },
    {evidence: EV_NONE, frame: 250, cmdwho: PP_RAINBOW | CMD_NONE, text: "The plural is \"pegasi\"..." },
    {evidence: EV_NONE, frame: 250, cmdwho: PP_RAINBOW | CMD_NONE, text: "I absolutely hate wearing that thing, but while in the air you're pretty much invulnerable to lightning." },
    {evidence: EV_NONE, frame: 250, cmdwho: PP_PHOENIX | CMD_NONE, text: "Weren't there some exposed parts on it, though?" },
    {evidence: EV_NONE, frame: 250, cmdwho: PP_RAINBOW | CMD_NONE, text: "Yes, there are, but while you're in the flying position those parts are covered up. They're only exposed while you're on all fours and grounded." },
    /*
    // USER INTERACTION OPPORTUNITY: LIGHTNING SUIT UNDERSTANDING
    // Technical exposition about the protective gear and its vulnerabilities
    // This information is crucial for understanding the murder method later
    */
    {evidence: EV_NONE, frame: 245, cmdwho: PP_RAINBOW | CMD_NONE, text: "This is sounding more and more hopeless for me the more I talk about it..." },
    {evidence: EV_NONE, frame: 245, cmdwho: PP_PHOENIX | CMD_NONE, text: "Try to cheer up. I'll find out what really happened and get you out of here." },
    {evidence: EV_NONE, frame: 44, cmdwho: PP_RAINBOW | CMD_NONE, text: "Thank you, Nix..." },
    {evidence: EV_NONE, frame: 44, cmdwho: PP_PHOENIX | CMD_NONE, text: "Okay, Rainbow Dash, I'm gonna go do some more investigating in light of this new information." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "Alright, catch you later." },

    // IMPORTANT EVIDENCE ACQUISITION: Hotel Room Key
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "Oh, wait! One more thing..." },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_RAINBOW | CMD_NONE, text: "Yes?" },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_PHOENIX | CMD_NONE, text: "Pinkie Pie. I bumped into her after the trial..." },
    {evidence: EV_NONE, frame: 40, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'm guessing she's a friend of yours. She wanted to cheer you on in court today, but sadly, it seems she was late." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "Is she always that... uh... loopy?" },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_RAINBOW | CMD_NONE, text: "Heh, yeah. That's just Pinkie Pie being Pinkie Pie." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_PHOENIX | CMD_NONE, text: "Okay, just thought I'd let you know." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_PHOENIX | CMD_NONE, text: "Well, goodbye Rainbow Dash." },
    {evidence: EV_NONE, frame: 251, cmdwho: PP_RAINBOW | CMD_NONE, text: "Wait!" },
    {evidence: EV_NONE, frame: 251, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Geez, I just can't leave this place...)" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "Yes, what is it?" },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "Here, take this..." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "A key? What is it for?" },
    {evidence: EV_NONE, frame: 252, cmdwho: PP_RAINBOW | CMD_NONE, text: "Ace's hotel room." },
    {evidence: EV_NONE, frame: 252, cmdwho: PP_PHOENIX | CMD_NONE, text: "What!? How did you get this!?" },
    {evidence: EV_NONE, frame: 253, cmdwho: PP_RAINBOW | CMD_NONE, text: "I was angry when I thought he was stalking me, so I snuck into his hotel room to find dirt on him..." },
    {evidence: EV_NONE, frame: 254, cmdwho: PP_RAINBOW | CMD_NONE, text: "It was under the mat... what a stupid place to leave your key, huh?" },
    {evidence: EV_NONE, frame: 254, cmdwho: PP_PHOENIX | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_PHOENIX | CMD_NONE, text: "Yeah... stupid place..." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Note to self: put key to office in different hiding spot.)" },
    {evidence: EV_NONE, frame: 255, cmdwho: PP_NONE | CMD_NONE, text: "A key to the hotel Ace Swift was staying in while in Ponyville." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_RAINBOW | CMD_NONE, text: "I wasn't able to find anything good in there, but maybe you can!" },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_PHOENIX | CMD_NONE, text: "Where is the hotel?" },
    {evidence: EV_NONE, frame: 249, cmdwho: PP_RAINBOW | CMD_NONE, text: "He was staying in the \"Hay and Stay Hotel\" while he was at Ponyville. It's a little past Sugar Cube Corner." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_RAINBOW | CMD_NONE, text: "Just have Twilight show you where it is." },
    {evidence: EV_NONE, frame: 36, cmdwho: PP_PHOENIX | CMD_NONE, text: "Twilight..." },
    {evidence: EV_NONE, frame: 248, cmdwho: PP_RAINBOW | CMD_NONE, text: "What's the matter?" },
    {evidence: EV_NONE, frame: 248, cmdwho: PP_PHOENIX | CMD_NONE, text: "O-oh, nothing. Thanks Rainbow Dash. This will really help my investigation!" },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_RAINBOW | CMD_NONE, text: "Goodbye, Nix." },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_PHOENIX | CMD_NONE, text: "I promise I'll get you and Fluttershy out of this mess." },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_RAINBOW | CMD_NONE, text: "Fluttershy... " },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_RAINBOW | CMD_NONE, text: "I told you, I don't care about her." },
    {evidence: EV_NONE, frame: 35, cmdwho: PP_PHOENIX | CMD_NONE, text: "(She's still really angry about that testimony Fluttershy gave...)" },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_RAINBOW | CMD_NONE, text: "I just know you'll find some super awesome evidence this time around!" },
    {evidence: EV_NONE, frame: 37, cmdwho: PP_NONE | CMD_BLACK, text: "" },

// =============================================================================
// HOTEL INVESTIGATION SEGMENT: PARTNERSHIP WITH PINKIE PIE
// =============================================================================
    // LOCATION TRANSITION: Investigation continues
    {evidence: EV_NONE, frame: 256, cmdwho: PP_NONE | CMD_NONE, text: "Ponyville, June 10th, 12:30PM" },

    /*
    // USER INTERACTION OPPORTUNITY: INVESTIGATION CHOICE
    // Present 2-choice menu before Pinkie arrives:
    // A) "Let's return to the forest and look for more clues." (thorough investigation route)
    // B) "I should check out Ace's hotel room with this key." (direct evidence route)
    // This choice affects player agency but both lead to the same outcome with Pinkie's arrival
    */

    {evidence: EV_NONE, frame: 256, cmdwho: PP_PHOENIX | CMD_NONE, text: "Okay, where should I go first? ... back to the forest, or to the hotel room?" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_NONE | CMD_NONE, text: "Hello again!" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_PHOENIX | CMD_NONE, text: "It would be a lot easier to go to the forest, since I know the general direction and I might find some new clues with the sun out..." },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_NONE | CMD_NONE, text: "Hello?" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_PHOENIX | CMD_NONE, text: "Then again, I already found a lot of evidence in the forest already..." },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_NONE | CMD_NONE, text: "Knock, knock... Feenie!" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_PHOENIX | CMD_NONE, text: "Though, would going into his hotel room be considered breaking and entering?" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'll have a bit of trouble finding it without someone guiding me, anyway..." },

    // PINKIE PIE'S DRAMATIC ENTRANCE
    {evidence: EV_NONE, frame: 257, cmdwho: PP_NONE | CMD_PARTY_HORN, text: "(party horn sfx)" },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PHOENIX | CMD_NONE, text: "AH!?" },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PINKIE | CMD_NONE, text: "Got your attention now!" },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PHOENIX | CMD_NONE, text: "Oh, you're... Pinkie Pie." },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PINKIE | CMD_NONE, text: "Yup-a-roonie! That's my name!" },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PHOENIX | CMD_NONE, text: "What are you doing here?" },
    {evidence: EV_NONE, frame: 259, cmdwho: PP_PINKIE | CMD_NONE, text: "I followed you! The guards wouldn't let me in though, so I just talked with them while I waited for you!" },
    {evidence: EV_NONE, frame: 260, cmdwho: PP_PINKIE | CMD_NONE, text: "Right boys?" },
    {evidence: EV_NONE, frame: 261, cmdwho: PP_GUARD | CMD_NONE, text: "Oh, for the love of all things holy... please..." },
    {evidence: EV_NONE, frame: 261, cmdwho: PP_GUARD | CMD_NONE, text: "Take her away..." },

    // PINKIE'S MYSTERIOUS REQUEST
    /*
    // NARRATIVE NOTE: This setup creates intrigue about what Pinkie lost
    // Her secret will be revealed later in the hotel investigation
    */
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PHOENIX | CMD_NONE, text: "Uh... why were you following me?" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PINKIE | CMD_NONE, text: "Cause I need help finding something..." },
    {evidence: EV_NONE, frame: 263, cmdwho: PP_PHOENIX | CMD_NONE, text: "Look, the spiky-headed monster they were talking about is-" },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PINKIE | CMD_NONE, text: "Oh! I gave up trying to find that a looooooong time ago, it's probably just somepony's overactive imagination!" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PINKIE | CMD_NONE, text: "I need to find something I lost about a week ago." },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PHOENIX | CMD_NONE, text: "What did you lose?" },
    {evidence: EV_NONE, frame: 264, cmdwho: PP_PINKIE | CMD_NONE, text: "It's a secret!" },
    {evidence: EV_NONE, frame: 264, cmdwho: PP_PHOENIX | CMD_NONE, text: "So you want me to help you find something... but you won't tell me what it is...?" },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PINKIE | CMD_NONE, text: "Correct-a-mundo!" },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PHOENIX | CMD_NONE, text: "That makes no sense!" },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Wait a minute...)" },

    // MUTUAL BENEFIT ARRANGEMENT
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PHOENIX | CMD_NONE, text: "Actually, uh, Pinkie Pie..." },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PINKIE | CMD_NONE, text: "Yes?" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PHOENIX | CMD_NONE, text: "Do you know where \"Sugar Cube Corner\" is?" },

    // PINKIE'S CUPCAKE RECIPE MONOLOGUE (comic relief)
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PINKIE | CMD_NONE, text: "You want to go bake cupcakes with me at Sugar Cube Corner!" },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PINKIE | CMD_NONE, text: "Mr and Mrs Cake always let me help out, now I have an assistant! Yay!" },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PINKIE | CMD_NONE, text: "You know how to make cupcakes, right?" },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PINKIE | CMD_NONE, text: "It's okay if you can't, I can teach you if you don't know, it's really really REALLY easy." },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PINKIE | CMD_NONE, text: "First-you-preheat-the-oven-to-350-degrees-and-line-the-cupcake-pans-with-paper-liners." },
    {evidence: EV_NONE, frame: 259, cmdwho: PP_PINKIE | CMD_NONE, text: "Then-you-toss-flour-sugar-baking-powder-and-salt-in-a-mixing-bowl." },
    {evidence: EV_NONE, frame: 259, cmdwho: PP_PINKIE | CMD_NONE, text: "Add-shortening-milk-and-vanilla-for-flavor-and-taste;" },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PINKIE | CMD_NONE, text: "I-personally-put-in-a-little-bit-of-candy-as-well-to-make-them-sweeter." },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PINKIE | CMD_NONE, text: "Beat-for-1-minute-then-scrape-the-side-of-the-bowl-with-a-spatula;" },
    {evidence: EV_NONE, frame: 259, cmdwho: PP_PINKIE | CMD_NONE, text: "we-want-to-salvage-as-many-cupcakes-as-we-can-from-the-mix!" },
    {evidence: EV_NONE, frame: 259, cmdwho: PP_PHOENIX | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 259, cmdwho: PP_PHOENIX | CMD_NONE, text: "That's not what I meant..." },
    {evidence: EV_NONE, frame: 259, cmdwho: PP_PHOENIX | CMD_NONE, text: "I was wondering if you knew where the \"Hay and Stay\" is. It's a hotel? I heard it was by there." },
    {evidence: EV_NONE, frame: 259, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Of course I know how to make cupcakes; what does she think I am, a hobo?)" },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PINKIE | CMD_NONE, text: "Yessiree! I know where it is!" },

    // NEGOTIATION FOR ASSISTANCE
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PHOENIX | CMD_NONE, text: "I need someone to escort me; would you be willing to do that for me if I help you find your missing... thing?" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PINKIE | CMD_NONE, text: "Okie-dokie-loki! On one other condition!" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PHOENIX | CMD_NONE, text: "Name it." },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PHOENIX | CMD_NONE, text: "(This is going to be easier than I thought.)" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PINKIE | CMD_NONE, text: "You have to tell me..." },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PINKIE | CMD_NONE, text: "a funny joke!" },

    /*
    // USER INTERACTION OPPORTUNITY: JOKE SELECTION
    // Present 3-choice menu for Phoenix's joke:
    // A) "Why did the chicken cross the road?" (classic, safe choice)
    // B) "What do you call a pegasus who can't fly?" (pony-themed joke)
    // C) "My legal career." (self-deprecating humor about recent court performance)
    // Different choices get different reactions from Pinkie
    */

    {evidence: EV_NONE, frame: 258, cmdwho: PP_PHOENIX | CMD_NONE, text: "W-what!? Why do I have to do that!?" },
    {evidence: EV_NONE, frame: 265, cmdwho: PP_PINKIE | CMD_NONE, text: "I don't want to hang out with some big party-pooper-frowny-stick-in-the-mud!" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PINKIE | CMD_NONE, text: "Show me you have a sense of humor, Feenie-weenie!" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PHOENIX | CMD_NONE, text: "Do I really have to do this?" },
    {evidence: EV_NONE, frame: 260, cmdwho: PP_PINKIE | CMD_NONE, text: "Mmmm-hhhmmmmm!" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Well, she seems really easy to impress anyway...)" },
    // PHOENIX'S TERRIBLE JOKE ATTEMPTS (comic relief sequence)
    /*
    // GENERIC ALTERNATIVE JOKES (if user chooses different options):
    // Bad Option 1: "What did the judge say to the lawyer? Order in the court!"
    // Bad Option 2: "Why don't lawyers go to the beach? Because cats keep trying to bury them!"
    // Bad Option 3: "How many lawyers does it take to change a lightbulb? How many can you afford?"
    */
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PHOENIX | CMD_NONE, text: "Okay. This is a really good one, Pinkie Pie!" },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PINKIE | CMD_NONE, text: "Tell me! Tell me!" },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PHOENIX | CMD_NONE, text: "Here goes! Why do they call me Phoenix Wright?" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PINKIE | CMD_NONE, text: "Hmmmm... I don't know. Why?" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PHOENIX | CMD_NONE, text: "Because..." },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'M ALWAYS \"WRIGHT\"!" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_NONE | CMD_BADUMTISH, text: "(badumtish sfx)" },
    {evidence: EV_NONE, frame: 263, cmdwho: PP_NONE | CMD_NONE, text: "" },
    {evidence: EV_NONE, frame: 263, cmdwho: PP_PINKIE | CMD_NONE, text: "That wasn't funny..." },
    {evidence: EV_NONE, frame: 263, cmdwho: PP_PHOENIX | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PINKIE | CMD_NONE, text: "So... do you have any better ones?" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PHOENIX | CMD_NONE, text: "... well, uh... This one time I cross-examined a parakeet! What's the deal with that!?" },
    {evidence: EV_NONE, frame: 263, cmdwho: PP_PINKIE | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 263, cmdwho: PP_PHOENIX | CMD_NONE, text: "(This is a lot harder than I thought... I'm a lawyer, not a comedian!)" },
    {evidence: EV_NONE, frame: 263, cmdwho: PP_PHOENIX | CMD_NONE, text: "Ummm... Did you know I had the entire left side of my body cut off once? Don't worry, I'm all \"Wright\" now..." },
    {evidence: EV_NONE, frame: 263, cmdwho: PP_PINKIE | CMD_NONE, text: "..." },

    // PINKIE'S "DISCOVERY" OF THE BADGE (accidental comedy success)
    {evidence: EV_NONE, frame: 266, cmdwho: PP_PINKIE | CMD_NONE, text: "Oh hey, what's that!?" },
    {evidence: EV_NONE, frame: 267, cmdwho: PP_PHOENIX | CMD_NONE, text: "This? It's my Equestria Attorney Badge. That's how I got in that detention center." },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PINKIE | CMD_NONE, text: "Wow, that is the girliest thing I've ever seen!" },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PINKIE | CMD_NONE, text: "That must have been why you were pretending to be so bad at telling a good joke!" },
    {evidence: EV_NONE, frame: 257, cmdwho: PP_PINKIE | CMD_NONE, text: "To build up to flashing that ridiculous-looking thing!" },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PINKIE | CMD_NONE, text: "You sure are a knee-slapper, Feenie!" },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PHOENIX | CMD_NONE, text: "(I really feel like sobbing to myself in a dark corner right now...)" },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PHOENIX | CMD_NONE, text: "So, will you show me where this hotel is, now?" },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PINKIE | CMD_NONE, text: "(* giggling uncontrollably *)" },
    {evidence: EV_NONE, frame: 258, cmdwho: PP_PHOENIX | CMD_NONE, text: "Pinkie?" },
    {evidence: EV_NONE, frame: 262, cmdwho: PP_PINKIE | CMD_NONE, text: "Oh right! The hotel is THIS way!!" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_PHOENIX | CMD_NONE, text: "Hey! Wait up!" },

// =============================================================================
// HOTEL ROOM SEARCH: EVIDENCE GATHERING WITH PINKIE PIE
// =============================================================================
    {evidence: EV_NONE, frame: 256, cmdwho: PP_NONE | CMD_BLACK, text: "Hay and Stay Hotel, June 10th, 12:53PM" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_PINKIE | CMD_NONE, text: "(* humming Phoenix Wright's theme *)" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_PHOENIX | CMD_NONE, text: "(That song she's humming sounds really, really familiar...)" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_PINKIE | CMD_NONE, text: "Lookie! Here's that room!" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_PHOENIX | CMD_NONE, text: "Hmm... Do you think we'll get in trouble for going into his room without asking?" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_PINKIE | CMD_NONE, text: "Don't be such a chicken, Feenie! Gimme that key!" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_PHOENIX | CMD_NONE, text: "H-hey! We can't just-" },
    {evidence: EV_NONE, frame: 256, cmdwho: PP_PINKIE | CMD_NONE, text: "We just stick it in here aaaand..." },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PINKIE | CMD_NONE, text: "We're in!" },
    {evidence: EV_NONE, frame: 269, cmdwho: PP_PINKIE | CMD_NONE, text: "Pinkie Pie, master of unlocking!" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "(I really hope I don't get sent to the sun for this...)" },
    {evidence: EV_NONE, frame: 270, cmdwho: PP_PHOENIX | CMD_NONE, text: "So, this is Ace's room." },
    {evidence: EV_NONE, frame: 270, cmdwho: PP_PHOENIX | CMD_NONE, text: "Seeing as he's dead, surely he won't mind if we look around?" },
    {evidence: EV_NONE, frame: 271, cmdwho: PP_PINKIE | CMD_NONE, text: "My name is Pinkie, not Shirley." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PINKIE | CMD_NONE, text: "What are we trying to find here anyway, Feenie? A magical stone? A secret chamber? A prisoner? A cup? Maybe something you ordered? Oatmeal?" },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PHOENIX | CMD_NONE, text: "Oatmeal? Why would anybody want to find oatmeal?" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PINKIE | CMD_NONE, text: "Duh... when they're hungry!" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "No, Pinkie Pie, we're trying to find clues that relate to the crime." },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PINKIE | CMD_NONE, text: "So... no oatmeal?" },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PHOENIX | CMD_NONE, text: "No oatmeal." },
    {evidence: EV_NONE, frame: 275, cmdwho: PP_PHOENIX | CMD_NONE, text: "I want to try and be out of here as fast as humanly possible, okay? I don't want to be caught by anyone." },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PINKIE | CMD_NONE, text: "Alright! I'll try to be as fast as PONY-ly possible then!" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Maybe it was a mistake, taking her in here with me...)" },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PINKIE | CMD_NONE, text: "Look Feenie, a step-ladder! Is that a clue?" },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PHOENIX | CMD_NONE, text: "One, that's not a clue." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "Two, that's not a step-ladder, it's a ladder." },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PINKIE | CMD_NONE, text: "There's a difference?" },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PHOENIX | CMD_NONE, text: "There's a BIG difference!" },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PHOENIX | CMD_NONE, text: "A step-ladder has an A-frame that folds while a ladder is flat like that one." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PINKIE | CMD_NONE, text: "I still don't see what the difference is... I mean, you still step on it, right? Wouldn't it be a STEP-ladder then?" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "How can I put this in a way you'll understand...?" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "It's like cupcakes and muffins." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PINKIE | CMD_NONE, text: "Cupcakes and muffins?" },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "Exactly. Both look kind of the same, but they're totally different, like ladders and step-ladders." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "Cupcakes have frosting on them, like how step-ladders have a folding frame, while muffins are usually plain, like the ladder is flat." },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PINKIE | CMD_NONE, text: "OOHHH! I think I get it now! Like hacksaws and saws?" },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PINKIE | CMD_NONE, text: "Why do they call it a hacksaw anyway?" },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PHOENIX | CMD_NONE, text: "!!??" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PINKIE | CMD_NONE, text: "I don't get it... it doesn't hack; hacking is what you do with daggers and axes." },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PINKIE | CMD_NONE, text: "And knives!" },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PHOENIX | CMD_NONE, text: "Uhh... yeah..." },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Okay, seriously, she's freaking me out now.)" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PINKIE | CMD_NONE, text: "But you sure know a lot about ladders, Feenie! Are you sure you're a lawyer and not actually a ladder connoisseur?" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "It's just common sense!" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "I find it annoying that a lot of people don't know the difference between the two." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "Wait a minute, wasn't the victim a Pegasus?" },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "Why would he need a ladder anyway?" },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "He could just fly up and get the things he would need a ladder for." },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PINKIE | CMD_NONE, text: "Maybe he was superstitious and didn't want bad luck." },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "Keeping a ladder doesn't prevent bad luck..." },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "You GET bad luck for walking under a ladder." },
    {evidence: EV_NONE, frame: 276, cmdwho: PP_PINKIE | CMD_NONE, text: "What about this? Is ripped-up paper good luck?" },
    {evidence: EV_NONE, frame: 276, cmdwho: PP_PHOENIX | CMD_NONE, text: "It's a piece of ripped up paper..." },
    {evidence: EV_NONE, frame: 276, cmdwho: PP_PHOENIX | CMD_NONE, text: "Why would it be good luck?" },
    {evidence: EV_NONE, frame: 276, cmdwho: PP_PHOENIX | CMD_NONE, text: "(I need an aspirin...)" },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PINKIE | CMD_NONE, text: "Guess you're right, it just says a bunch of mumbo-jumbo on it anyway." },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PHOENIX | CMD_NONE, text: "\"Mumbo-jumbo?\" Let me see it..." },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "\"This is a letter stating my permanent Leave of Absence. After the Equestrian 500 is over, I can no longer work with you.\"" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "\"We made quite the team, but I-\"" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "Then it cuts off. The rest must be on the other half!" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "Pinkie, you found a clue!" },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PINKIE | CMD_NONE, text: "Is that good luck?" },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "No!" },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "Well... yes!" },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "Kinda!" },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "Good job, Pinkie!" },
    {evidence: EV_NONE, frame: 277, cmdwho: PP_PINKIE | CMD_NONE, text: "Yay!!" },
    {evidence: EV_NONE, frame: 278, cmdwho: PP_NONE | CMD_NONE, text: "Someone was planning on quitting something after the Equestrian 500. The other half is missing." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "It would only make sense that Ace wrote this, since it's his room, but who was he writing it to?" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PINKIE | CMD_NONE, text: "Maybe he-" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PINKIE | CMD_NONE, text: "OH NO!" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PHOENIX | CMD_NONE, text: "Shh! We aren't supposed to be in here, remember?" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PHOENIX | CMD_NONE, text: "What's the problem?" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PINKIE | CMD_NONE, text: "My tail's twitching!" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PHOENIX | CMD_NONE, text: "So, my foot fell asleep. You don't see me freaking out." },
    {evidence: EV_NONE, frame: 270, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Why is she hiding under that table?)" },
    {evidence: EV_NONE, frame: 270, cmdwho: PP_PHOENIX | CMD_NONE, text: "Pinkie Pie, stop fooling around and-" },
    {evidence: EV_NONE, frame: 270, cmdwho: PP_NONE | CMD_CRASH, text: "(crash sfx)" },
    {evidence: EV_NONE, frame: 270, cmdwho: PP_PHOENIX | CMD_NONE, text: "OW!" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PINKIE | CMD_NONE, text: "See? I warned you!" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PHOENIX | CMD_NONE, text: "W-what?!" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PHOENIX | CMD_NONE, text: "You didn't say anything was going to fall on my head!" },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PINKIE | CMD_NONE, text: "Sure I did! I said my tail was twitching." },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PINKIE | CMD_NONE, text: "That means something's gonna fall." },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PHOENIX | CMD_NONE, text: "That's ridiculous! You can't tell me you can make predictions like that based off body spasms." },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PINKIE | CMD_NONE, text: "So what's that book say?" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PHOENIX | CMD_NONE, text: "You mean the thing that fell on my head?" },
    {evidence: EV_NONE, frame: 270, cmdwho: PP_PHOENIX | CMD_NONE, text: "It seems like it's some sort of advanced spell book." },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PINKIE | CMD_NONE, text: "Hey Feenie! Do you think that you can cast a spell!?" },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PINKIE | CMD_NONE, text: "I can't since I'm an earth pony." },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PHOENIX | CMD_NONE, text: "Of course not! I'm not a magician!" },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PHOENIX | CMD_NONE, text: "I can't even read it anyway." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "I only know it's an advanced spell book because I saw Twilight reading a book just like it this morning, and I asked her what it was." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "The text isn't in English. The characters are in weird hieroglyphics like Twilight's book." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "Huh? Look at this..." },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PINKIE | CMD_NONE, text: "\"Continue from here, third line.\"" },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PHOENIX | CMD_NONE, text: "Seems someone scribbled a note here." },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PINKIE | CMD_NONE, text: "You can get in big trouble for writing in hotel's books like that!" },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PHOENIX | CMD_NONE, text: "No, I don't think this is the hotel's book." },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PHOENIX | CMD_NONE, text: "Twilight said these advanced spell books are only available in Ca..." },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PHOENIX | CMD_NONE, text: "Can..." },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PHOENIX | CMD_NONE, text: "I forget the name, starts with a hard \"C\" if I recall..." },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PINKIE | CMD_NONE, text: "Cookie?" },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PHOENIX | CMD_NONE, text: "No." },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PINKIE | CMD_NONE, text: "Carrot?" },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PHOENIX | CMD_NONE, text: "No..." },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PINKIE | CMD_NONE, text: "Corkscrew?" },
    {evidence: EV_NONE, frame: 281, cmdwho: PP_PHOENIX | CMD_NONE, text: "No... just stop guessing. The point is, this must be someone's personal book..." },
    {evidence: EV_NONE, frame: 282, cmdwho: PP_NONE | CMD_NONE, text: "A book found in the victim's hotel room. Small note scribbled on one of the pages." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "I better put it back on the shelf." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PINKIE | CMD_NONE, text: "It was all the way up there." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "I can reach it." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "Almost got it." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_NONE | CMD_RIP, text: "(rip sfx)" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PHOENIX | CMD_NONE, text: "AH!!!!!!" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PHOENIX | CMD_NONE, text: "NOOOOOOOOOOoooOOO!" },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PINKIE | CMD_NONE, text: "Didn't you just tell me to be quiet a second ago?" },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PINKIE | CMD_NONE, text: "Practice what you preach!" },
    {evidence: EV_NONE, frame: 274, cmdwho: PP_PHOENIX | CMD_NONE, text: "I ripped my suit!" },
    {evidence: EV_NONE, frame: 276, cmdwho: PP_PINKIE | CMD_NONE, text: "You're right; you have a big hole in your armpit!" },
    {evidence: EV_NONE, frame: 276, cmdwho: PP_PINKIE | CMD_NONE, text: "Should have used the stepladder instead of reaching so high." },
    {evidence: EV_NONE, frame: 276, cmdwho: PP_PHOENIX | CMD_NONE, text: "It's a ladder!" },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "You don't realize how bad this is!" },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PHOENIX | CMD_NONE, text: "I can't walk around with a big rip in my suit!" },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PINKIE | CMD_NONE, text: "No use crying over spilled milk! Or ripped armpits!" },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PINKIE | CMD_NONE, text: "Lookie! It's Rainbow Dash!" },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PHOENIX | CMD_NONE, text: "Huh? Where?" },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PINKIE | CMD_NONE, text: "Right here on the table!" },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PHOENIX | CMD_NONE, text: "Well, it's her name alright..." },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PHOENIX | CMD_NONE, text: "What is this? It looks like some kind of list." },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PINKIE | CMD_NONE, text: "Maybe it's a party invite!" },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PHOENIX | CMD_NONE, text: "Do you know who these other names are, Pinkie?" },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PINKIE | CMD_NONE, text: "Nope, doesn't ring any bells." },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PINKIE | CMD_NONE, text: "\"Rainbow Dash\" is the only name on here I recognize..." },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PINKIE | CMD_NONE, text: "Uh oh! I have to find out who these other ponies are!" },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PHOENIX | CMD_NONE, text: "Why?" },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PINKIE | CMD_NONE, text: "I throw a party for every new pony in Ponyville..." },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PINKIE | CMD_NONE, text: "(gasp!) That reminds me! I haven't thrown a welcome party for you yet!" },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PINKIE | CMD_NONE, text: "I'm sorry Feenie, I just haven't had the time today!" },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PHOENIX | CMD_NONE, text: "Uh... that's alright..." },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PHOENIX | CMD_NONE, text: "(She seems so upset about it...)" },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PHOENIX | CMD_NONE, text: "Look next to Rainbow Dash's name, it's a time: \"8:35\"" },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PINKIE | CMD_NONE, text: "I was right! It's a party invite!" },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PINKIE | CMD_NONE, text: "\"Rainbow Dash party at 8:35\". I'll try not to be late this time." },
    {evidence: EV_NONE, frame: 283, cmdwho: PP_PHOENIX | CMD_NONE, text: "I don't think so. I think I know what this is now..." },
    {evidence: EV_NONE, frame: 284, cmdwho: PP_NONE | CMD_NONE, text: "A list with several names including Rainbow Dash." },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PINKIE | CMD_NONE, text: "You know? Tell me! Tell me!" },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'm not completely positive, but I think this is a-" },
// =============================================================================
// DRAMATIC ENCOUNTER: SONATA DUSK REVEALED
// =============================================================================
    // CAUGHT IN THE ACT!
    /*
    // PLOT TWIST: The appearance of someone who looks exactly like Phoenix's mentor Mia
    // This creates emotional conflict and character development opportunity
    */
    {evidence: EV_NONE, frame: 279, cmdwho: PP_NONE | CMD_NONE, text: "And just who are you two?!" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PHOENIX | CMD_NONE, text: "(OH NO! We're caught!!)" },
    {evidence: EV_NONE, frame: 285, cmdwho: PP_MIA | CMD_NONE, text: "Why are you snooping around my room?" },
    {evidence: EV_NONE, frame: 285, cmdwho: PP_PHOENIX | CMD_NONE, text: "Ch-Chief!?" },
    {evidence: EV_NONE, frame: 285, cmdwho: PP_MIA | CMD_NONE, text: "I should have the police book you two and have you thrown in jail for breaking and entering." },
    {evidence: EV_NONE, frame: 285, cmdwho: PP_PHOENIX | CMD_NONE, text: "(This can't be Mia, it just can't be!)" },

    // PINKIE'S DESPERATE LIE ATTEMPT
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PINKIE | CMD_NONE, text: "We're room service!" },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Do you honestly think she's going to fall for that?)" },
    {evidence: EV_NONE, frame: 285, cmdwho: PP_MIA | CMD_NONE, text: "Do you honestly think I'm going to fall for-!" },

    // IDENTITY REVELATION
    {evidence: EV_NONE, frame: 286, cmdwho: PP_MIA | CMD_NONE, text: "Wait a minute..." },
    {evidence: EV_NONE, frame: 286, cmdwho: PP_MIA | CMD_NONE, text: "I know who you are..." },
    {evidence: EV_NONE, frame: 285, cmdwho: PP_PHOENIX | CMD_NONE, text: "It's me, Mia..." },
    {evidence: EV_NONE, frame: 286, cmdwho: PP_MIA | CMD_NONE, text: "Mia?" },
    {evidence: EV_NONE, frame: 285, cmdwho: PP_MIA | CMD_NONE, text: "My name is Sonata." },
    {evidence: EV_NONE, frame: 285, cmdwho: PP_PHOENIX | CMD_NONE, text: "Sonata...?" },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_SONATA | CMD_NONE, text: "Did I stutter? Yes, that's my name." },

    /*
    // USER INTERACTION OPPORTUNITY: EMOTIONAL RESPONSE CHOICE
    // Present 3-choice menu for Phoenix's reaction to seeing Mia's lookalike:
    // A) "You look exactly like someone I knew..." (honest/emotional route)
    // B) "Sorry, mistook you for someone else." (diplomatic route)
    // C) "Are you related to Mia Fey?" (direct investigation route)
    // Each choice leads to different character development paths
    */

    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "(It's not her... but the resemblance... it's uncanny...)" },
    {evidence: EV_NONE, frame: 289, cmdwho: PP_SONATA | CMD_NONE, text: "Name. Now." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "Phoenix Wright..." },
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PINKIE | CMD_NONE, text: "Pinkamena Dianne Pie, Party Thrower Extraordinaire!" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "As I thought. You're that human lawyer from the trial earlier..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "(I can't get over this... it looks exactly like her... if she were a pony.)" },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_SONATA | CMD_NONE, text: "Can you stop staring at me like that, please." },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PINKIE | CMD_NONE, text: "What's the matter Feenie, cat got your tongue?" },

// SEGMENT CONTINUES: Further investigation and character development with Sonata
// This sets up important plot threads for the investigation and Phoenix's emotional journey
    {evidence: EV_NONE, frame: 268, cmdwho: PP_PINKIE | CMD_NONE, text: "That would hurt because a cat has claws and your tongue is really sensitive..." },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PINKIE | CMD_NONE, text: "Ouch!" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "I knew Rainbow Dash was guilty, but it didn't even look like you were trying in court today." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "Who... exactly... are you...?" },
    {evidence: EV_NONE, frame: 290, cmdwho: PP_SONATA | CMD_NONE, text: "I'm the one who should be asking questions here. Seeing as you two are the ones who broke into my room." },
    {evidence: EV_NONE, frame: 290, cmdwho: PP_SONATA | CMD_NONE, text: "I'm betting you're the one who stole the key two days ago." },
    {evidence: EV_NONE, frame: 290, cmdwho: PP_PHOENIX | CMD_NONE, text: "But isn't this Ace Swift's room?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "You're here about him?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "I see..." },
    {evidence: EV_NONE, frame: 289, cmdwho: PP_PHOENIX | CMD_NONE, text: "We were just investigating his hotel room for clues. This is his room, is it not?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Hmm?" },
    {evidence: EV_NONE, frame: 289, cmdwho: PP_SONATA | CMD_NONE, text: "Oh, yes, that is correct." },
    {evidence: EV_NONE, frame: 289, cmdwho: PP_PHOENIX | CMD_NONE, text: "You just said this was your room though. What are you, his girlfriend or something?" },
    {evidence: EV_NONE, frame: 290, cmdwho: PP_SONATA | CMD_NONE, text: "That's strike one, Mr. Wright. I suggest you not strike out anymore." },
    {evidence: EV_NONE, frame: 290, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Ack! Better not get on her bad side.)" },
    {evidence: EV_NONE, frame: 290, cmdwho: PP_PHOENIX | CMD_NONE, text: "Uh... sorry." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Actually I'm-" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Or should I say, WAS, his manager. Given the circumstances." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "His... manager...?" },
    {evidence: EV_NONE, frame: 291, cmdwho: PP_NONE | CMD_WHOOSH, text: "(whoosh sfx)" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "(This is getting weird...)" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "I'm sorry about what happened." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Don't worry, I got over it pretty quickly." },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_SONATA | CMD_NONE, text: "Besides, justice will be served. Your client will be punished for her crime." },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_PHOENIX | CMD_NONE, text: "Hey, Rainbow Dash didn't do it!" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Anypony with half a brain can see that she did it, Mr Wright. Look at all the evidence stacked against her." },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_SONATA | CMD_NONE, text: "No matter how you look at it, she was the one who activated that cloud and killed him." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Your little feather theory may have bought some time, but she is going to be found guilty tomorrow morning. I assure it." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "I believe in her, and I'm going to defend her to the very end. No matter what you say." },
    {evidence: EV_NONE, frame: 290, cmdwho: PP_SONATA | CMD_NONE, text: "And that's why you're going to lose." },
    {evidence: EV_NONE, frame: 290, cmdwho: PP_SONATA | CMD_NONE, text: "From what I've gathered, you're not even from Equestria. Why place loyalty in a pony you hardly know?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "Did I stutter?" },
    {evidence: EV_NONE, frame: 292, cmdwho: PP_PHOENIX | CMD_NONE, text: "I said, because I believe her. She didn't do it." },
    {evidence: EV_NONE, frame: 293, cmdwho: PP_SONATA | CMD_NONE, text: "Arrogant... just like that prosecutor." },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_PHOENIX | CMD_NONE, text: "Do you mean Trixie?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Yes. Her." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "What do you have against her?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "I wished to prosecute for this case, but that pig-headed showmare beat me to it." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "(She does seem a lot more qualified to be a prosecutor than Trixie.)" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "So wait, you're a prosecutor as well as a manager?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Ace and I are from Canterlot, Equestria's capital. Most of the unicorns there are \"jacks-of-all-trades,\" so to speak." },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_SONATA | CMD_NONE, text: "We take on as many jobs as we can to flourish our intellect and magical abilites." },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PINKIE | CMD_NONE, text: "Wow! I didn't even know that! I should take another trade!" },
    {evidence: EV_NONE, frame: 294, cmdwho: PP_PINKIE | CMD_NONE, text: "Maybe bowling?" },
    {evidence: EV_NONE, frame: 273, cmdwho: PP_PINKIE | CMD_NONE, text: "No, creative writing!" },
    {evidence: EV_NONE, frame: 280, cmdwho: PP_PINKIE | CMD_NONE, text: "No! NO! How about SCUBA DIVING??" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Pinkie, it doesn't look like she shares your enthusiasm...)" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "Trixie is from this \"Canterlot\" place then?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Yes, she is. I was in Ponyville when the murder took place." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "So there wasn't enough time for me to go to Canterlot and execute the procedures to prosecute this case." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Trixie must have already been there when she heard about it." },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_SONATA | CMD_NONE, text: "How foolish, taking a case over a silly little grudge..." },
    {evidence: EV_NONE, frame: 295, cmdwho: PP_SONATA | CMD_NONE, text: "It's funny really, part of me wants you to best her." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Who has the grudge now?)" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "I actually know quite a bit about her... care to listen?" },
    {evidence: EV_NONE, frame: 296, cmdwho: PP_PINKIE | CMD_NONE, text: "A story! I love stories!" },
    {evidence: EV_NONE, frame: 294, cmdwho: PP_PINKIE | CMD_NONE, text: "I'll tell you the one where me and some guy in a blue suit broke into somepony's room and rummaged through their personal belongings!" },
    {evidence: EV_NONE, frame: 276, cmdwho: PP_PINKIE | CMD_NONE, text: "It's a classic!" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Pinkie, for the love of God, shut up!)" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "If you wouldn't mind... I wasn't told much about Trixie." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "I was classmates with her when I was but a foal. I attended the same magic classes as her." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "Were you friends with her or something?" },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_SONATA | CMD_NONE, text: "No, I kept to myself as I do now. I only consult with those who are worth my time." },
    {evidence: EV_NONE, frame: 294, cmdwho: PP_PINKIE | CMD_NONE, text: "Hey, you know what that means, Feenie!" },
    {evidence: EV_NONE, frame: 294, cmdwho: PP_PINKIE | CMD_NONE, text: "We're both worth her time!" },
    {evidence: EV_NONE, frame: 280, cmdwho: PP_PINKIE | CMD_NONE, text: "Here I thought she wouldn't like us for breaking into her room." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Every time you speak, you make that glare icier and icier...)" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Continuing..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "The Trixie you saw in court today is how she has been all her life. An arrogant boaster, a show-off." },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_SONATA | CMD_NONE, text: "I hate that type..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "She was at the top of the class. As much as I hate to say it, she's better than me, despite me being older..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Well, when it comes to magic, anyway." },
    {evidence: EV_NONE, frame: 280, cmdwho: PP_PINKIE | CMD_NONE, text: "Ah! So you're just jealous then!" },
    {evidence: EV_NONE, frame: 280, cmdwho: PP_PHOENIX | CMD_NONE, text: "P-Pinkie! Is your brain the size of chewed bubble gum!?" },
    {evidence: EV_NONE, frame: 271, cmdwho: PP_PINKIE | CMD_NONE, text: "I don't think so. If it were bubble gum, it would probably stick to the inside of my head, don't you think?" },
    {evidence: EV_NONE, frame: 280, cmdwho: PP_PHOENIX | CMD_NONE, text: "Argh! Pinkie, just stop talking. PLEASE!" },
    {evidence: EV_NONE, frame: 272, cmdwho: PP_PINKIE | CMD_NONE, text: "Okay, I'll stop talking..." },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PINKIE | CMD_NONE, text: "Ah! Oops, sorry, I spoke!" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PINKIE | CMD_NONE, text: "AH! I SPOKE AGAIN!" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PINKIE | CMD_NONE, text: "AND AGAIN! AND AGAIN! AND AGAIN!" },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PINKIE | CMD_NONE, text: "AH!" },
    {evidence: EV_NONE, frame: 297, cmdwho: PP_SONATA | CMD_NONE, text: "Ergh!" },
    {evidence: EV_NONE, frame: 297, cmdwho: PP_PHOENIX | CMD_NONE, text: "Huh!? Are you okay?" },
    {evidence: EV_NONE, frame: 293, cmdwho: PP_SONATA | CMD_NONE, text: "Yes... excuse me..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Anyway, I'm not jealous..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "In fact, unlike Trixie, I'm striving to become better with magic." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Not going around town and showing off a bunch a cheap parlor tricks." },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_SONATA | CMD_NONE, text: "You should earn attention and praise for the actions you do, not what you claim you can do." },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_PHOENIX | CMD_NONE, text: "So just because she showed off in school, you hate her?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "Sorry, but that's a little shallow if you ask me." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "But is it? Do you think she's qualified to be prosecuting? You saw how she acted." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "No professionalism at all..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "I've had it worse in the courtroom... toupees, birds, whips..." },
    {evidence: EV_NONE, frame: 292, cmdwho: PP_SONATA | CMD_NONE, text: "Whips?" },
    {evidence: EV_NONE, frame: 292, cmdwho: PP_PHOENIX | CMD_NONE, text: "Uh... don't ask. As long as she's getting the job done, I don't see anything wrong with it." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "Why do you want to prosecute this case so badly, anyway? I know you were his manager, but still..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Because if things were going my way, the case would have been closed by now." },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_SONATA | CMD_NONE, text: "Cold, hard, swift justice." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "That's the way I work." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "That's not what being a lawyer is about, Sonata." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Then what is it about, Mr Wright?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Sitting back and letting a dangerous felon off the hook scot-free?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "No, it's about finding the truth." },
    {evidence: EV_NONE, frame: 292, cmdwho: PP_SONATA | CMD_NONE, text: "The truth?" },
    {evidence: EV_NONE, frame: 292, cmdwho: PP_PHOENIX | CMD_NONE, text: "Attorneys aren't meant to uphold justice; we're to work to the best of our abilities to guide it, and seek out the truth." },
    {evidence: EV_NONE, frame: 290, cmdwho: PP_SONATA | CMD_NONE, text: "You sure have quite the ideals, Mr Wright. I don't know what kind of trials and tribulations you've been through..." },
    {evidence: EV_NONE, frame: 290, cmdwho: PP_SONATA | CMD_NONE, text: "But you're not changing my opinion." },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_SONATA | CMD_NONE, text: "Rainbow Dash is guilty, and that's all there is to it." },
    {evidence: EV_NONE, frame: 287, cmdwho: PP_PHOENIX | CMD_NONE, text: "If you don't mind me asking, what does that eyeball stand for?" },
    {evidence: EV_NONE, frame: 276, cmdwho: PP_PINKIE | CMD_NONE, text: "It's her cutie mark!" },
    {evidence: EV_NONE, frame: 276, cmdwho: PP_PINKIE | CMD_NONE, text: "It must mean her special talent is poking ponies' eyes out with that horn!" },
    {evidence: EV_NONE, frame: 276, cmdwho: PP_PHOENIX | CMD_NONE, text: "(We are so dead...)" },
    {evidence: EV_NONE, frame: 297, cmdwho: PP_SONATA | CMD_NONE, text: "Mmph!" },
    {evidence: EV_NONE, frame: 297, cmdwho: PP_PHOENIX | CMD_NONE, text: "(What the heck is wrong with her?)" },
    {evidence: EV_NONE, frame: 297, cmdwho: PP_PHOENIX | CMD_NONE, text: "Uh... are you okay? You look like you're in pain..." },
    {evidence: EV_NONE, frame: 297, cmdwho: PP_SONATA | CMD_NONE, text: "Yes, I'm fine..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "But no..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "My talent is perceiving and having a keen eye for detail." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "For instance, Mr Wright." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "You're desperately trying to change the subject, hoping I forget about you breaking into my room..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "Indicated by your nervous breathing patterns and the sweat trickling down your forehead and neck." },
    {evidence: EV_NONE, frame: 295, cmdwho: PP_SONATA | CMD_NONE, text: "You're also trying to cover up that embarrassing rip in your armpit." },
    {evidence: EV_NONE, frame: 295, cmdwho: PP_SONATA | CMD_NONE, text: "I can tell by how firmly your left arm is pressed against your body compared to your right one." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "And her... she's..." },
    {evidence: EV_NONE, frame: 280, cmdwho: PP_PINKIE | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "She's thinking about ladders..." },
    {evidence: EV_NONE, frame: 279, cmdwho: PP_PINKIE | CMD_NONE, text: "Wow! How did you know? You must be psychic!" },
    {evidence: EV_NONE, frame: 280, cmdwho: PP_PINKIE | CMD_NONE, text: "But I was actually thinking about step-ladders." },
    {evidence: EV_NONE, frame: 280, cmdwho: PP_PHOENIX | CMD_NONE, text: "It's a ladder! Even I could have gotten that one!" },
    {evidence: EV_NONE, frame: 280, cmdwho: PP_PHOENIX | CMD_NONE, text: "Throughout the whole conversation, you keep looking at it!" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "But, Sonata, can you tell me a little bit more about Ace?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "What's there to say?" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_SONATA | CMD_NONE, text: "He was good at what he did." },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "(Good at what he did? Yeah, sure. That creep was blackmailing Rainbow Dash.)" },
    {evidence: EV_NONE, frame: 288, cmdwho: PP_PHOENIX | CMD_NONE, text: "What about your relationship with him? As his manager, I mean..." },
    {evidence: EV_NONE, frame: 293, cmdwho: PP_SONATA | CMD_NONE, text: "..." },
    {evidence: EV_NONE, frame: 293, cmdwho: PP_PHOENIX | CMD_NONE, text: "Well?" },
    {evidence: EV_NONE, frame: 290, cmdwho: PP_SONATA | CMD_NONE, text: "Th-that's none of your business!" },
    {evidence: EV_NONE, frame: 290, cmdwho: PP_PHOENIX | CMD_NONE, text: "(For a second there she kind of hesitated. Perhaps I should press this further...)" },
    {evidence: EV_NONE, frame: 0, cmdwho: PP_NONE | CMD_NONE, text: "" }
};

// Number of entries in the array
#define TRANSCRIPT_PART3_SIZE (sizeof(transcript_part3) / sizeof(ConversationEntry))