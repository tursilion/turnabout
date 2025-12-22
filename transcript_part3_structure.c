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
    {EV_NONE, 203, PP_NONE | CMD_NONE, "Fey Law Offices"},
    {EV_NONE, 203, PP_PHOENIX | CMD_NONE, "My name is Phoenix Wright, AND I'M FINE!"},
    {EV_NONE, 203, PP_PHOENIX | CMD_NONE, "My name is Phoenix Wright, AND I'M FINE!!"},
    {EV_NONE, 203, PP_PHOENIX | CMD_NONE, "My name is Phoenix Wright, AND I'M FINE!!!"},
    {EV_NONE, 204, PP_MIA | CMD_NONE, "Phoenix, are you okay!?"},
    {EV_NONE, 204, PP_PHOENIX | CMD_NONE, "Oh, hey Chief. I was just practicing for my very first trial, which is tomorrow."},
    {EV_NONE, 204, PP_PHOENIX | CMD_NONE, "The guys back at law school said this tape would really help me out."},
    {EV_NONE, 205, PP_MIA | CMD_NONE, "Thank goodness..."},
    {EV_NONE, 205, PP_MIA | CMD_NONE, "When I heard all the screeching coming from the office, I thought someone was murdering you."},
    {EV_NONE, 205, PP_PHOENIX | CMD_NONE, "(That wasn't screeching, that was step four!)"},
    {EV_NONE, 205, PP_MIA | CMD_NONE, "Haha, I don't think you need this exercise tape."},
    {EV_NONE, 205, PP_MIA | CMD_NONE, "I'm sure you'll do just fine. The suspect -- he's your friend, right?"},
    {EV_NONE, 205, PP_PHOENIX | CMD_NONE, "Yeah, he's my friend... but..."},
    {EV_NONE, 203, PP_MIA | CMD_NONE, "But what?"},
    {EV_NONE, 203, PP_PHOENIX | CMD_NONE, "He's, well..."},
    {EV_NONE, 203, PP_MIA | CMD_NONE, "Yes?"},
    {EV_NONE, 203, PP_PHOENIX | CMD_NONE, "He's kind of an idiot."},
    {EV_NONE, 205, PP_MIA | CMD_NONE, "That's not a very nice thing to say about your friend."},
    {EV_NONE, 205, PP_PHOENIX | CMD_NONE, "No, I really mean it. He thinks passing the 8th grade is a credential; he even got the report card framed and everything."},
    // Mia's crucial advice about believing in clients and pursuing truth
    {EV_NONE, 206, PP_MIA | CMD_NONE, "So? What are you getting at?"},
    {EV_NONE, 206, PP_PHOENIX | CMD_NONE, "I mean, what if he really did kill that woman?"},
    {EV_NONE, 206, PP_PHOENIX | CMD_NONE, "What do I do?"},
    {EV_NONE, 206, PP_PHOENIX | CMD_NONE, "Do I still lie and try to defend him, or do I side with justice and let him be punished...?"},
    {EV_NONE, 205, PP_MIA | CMD_NONE, "Phoenix..."},
    {EV_NONE, 205, PP_PHOENIX | CMD_NONE, "..."},
    {EV_NONE, 205, PP_MIA | CMD_NONE, "Don't stress yourself out so much."},
    {EV_NONE, 205, PP_MIA | CMD_NONE, "Tell me, what do you think?"},
    {EV_NONE, 206, PP_PHOENIX | CMD_NONE, "Me? What do you mean?"},
    {EV_NONE, 205, PP_MIA | CMD_NONE, "You, as Phoenix Wright, not as a defense attorney."},
    {EV_NONE, 205, PP_MIA | CMD_NONE, "Do you think your friend killed that woman?"},
    {EV_NONE, 205, PP_PHOENIX | CMD_NONE, "He might not be the sharpest tool in the shed, but I don't think he has it in him to kill anyone."},
    {EV_NONE, 206, PP_MIA | CMD_NONE, "There you go."},
    {EV_NONE, 206, PP_PHOENIX | CMD_NONE, "Huh?"},
    {EV_NONE, 206, PP_MIA | CMD_NONE, "Go off that. You have to believe in him; it's your job to."},
    {EV_NONE, 205, PP_MIA | CMD_NONE, "Cast all that doubt aside and pursue the truth. If you do that, nothing can stop you."},
    {EV_NONE, 205, PP_PHOENIX | CMD_NONE, "The truth, huh..."},
    {EV_NONE, 205, PP_PHOENIX | CMD_NONE, "Thanks, Chief. I'm still a little nervous, though..."},
    {EV_NONE, 206, PP_MIA | CMD_NONE, "Don't worry, we all go through it."},
    {EV_NONE, 206, PP_PHOENIX | CMD_NONE, "Hey, umm... do you by any chance know who the prosecutor is?"},
    {EV_NONE, 204, PP_MIA | CMD_NONE, "The prosecutor?"},
    {EV_NONE, 205, PP_MIA | CMD_NONE, "I believe it's Winston Payne. You know, \"The Rookie Killer.\""},
    {EV_NONE, 205, PP_PHOENIX | CMD_NONE, "R-rookie killer..."},
    {EV_NONE, 205, PP_PHOENIX | CMD_NONE, "(I don't like the sound of that title.)"},
    {EV_NONE, 204, PP_MIA | CMD_NONE, "Not many rookies take the prosecutor into consideration."},
    {EV_NONE, 204, PP_MIA | CMD_NONE, "Why did you want to know something like that?"},
    {EV_NONE, 204, PP_PHOENIX | CMD_NONE, "No reason, I was just curious."},
    {EV_NONE, 204, PP_MIA | CMD_NONE, "You seem more disappointed than curious."},
    {EV_NONE, 204, PP_PHOENIX | CMD_NONE, "Ah, forget about it. I'm just a little out of it right now."},
    {EV_NONE, 206, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 206, PP_NONE | CMD_BLACK, ""},

    // Phoenix's reflection on failing Mia's teachings
    {EV_NONE, 206, PP_PHOENIX | CMD_NONE, "I'll never forget what you taught me."},
    {EV_NONE, 206, PP_PHOENIX | CMD_NONE, "But somehow, I highly doubt you're looking down on me smiling after what I did today..."},

// =============================================================================
// STORY SEGMENT: COURTROOM AFTERMATH - PHOENIX'S ISOLATION AND DESPAIR
// =============================================================================
    // The crushing reality of Phoenix's courtroom failure
    {EV_NONE, 100, PP_NONE | CMD_NONE, "Ponyville District Court, June 10th, 11:55AM"},
    {EV_NONE, 207, PP_TWILIGHT | CMD_NONE, "Phoenix... I was wrong about you..."},
    {EV_NONE, 100, PP_PHOENIX | CMD_NONE, "Twilight, wait, I-..."},
    {EV_NONE, 100, PP_PHOENIX | CMD_NONE, "She's gone..."},
    {EV_NONE, 100, PP_PHOENIX | CMD_NONE, "Who am I kidding?"},
    {EV_NONE, 100, PP_PHOENIX | CMD_NONE, "She's right. I did absolutely terrible in there..."},
    {EV_NONE, 100, PP_PHOENIX | CMD_NONE, "Now two of her friends are suspects; what do I do now?"},
    {EV_NONE, 100, PP_PHOENIX | CMD_NONE, "I don't have any leads at all, nobody to turn to. I'm all by myself..."},
    {EV_NONE, 100, PP_PHOENIX | CMD_NONE, "Which means... I can't even get back home..."},
    {EV_NONE, 100, PP_PHOENIX | CMD_NONE, "..."},
    {EV_NONE, 100, PP_PHOENIX | CMD_NONE, "No, I can't think that way. I've got to stay diligent."},
    {EV_NONE, 100, PP_PHOENIX | CMD_NONE, "I said I'd clear Rainbow Dash's name, and I bought her another day."},
    {EV_NONE, 100, PP_PHOENIX | CMD_NONE, "I can't let it go to waste... but where do I start...?"},

// =============================================================================
// STORY SEGMENT: FIRST INVESTIGATION - MEETING PINKIE PIE
// =============================================================================
    // USER CHOICE OPPORTUNITY: Phoenix could choose different responses to Pinkie
    // Options could include: Be serious/professional, Play along with her energy, Ask for help directly
    {EV_NONE, 208, PP_NONE | CMD_NONE, "Hey, Mr Frowny-Wowny. What's the matter?"},
    {EV_NONE, 208, PP_PHOENIX | CMD_NONE, "(Huh? Where did she come from? She smells like cotton candy...)"},
    {EV_NONE, 209, PP_NONE | CMD_NONE, "Cotton candy?"},
    {EV_NONE, 210, PP_NONE | CMD_NONE, "Oh! You must smell the new shampoo I'm using."},
    {EV_NONE, 210, PP_PHOENIX | CMD_NONE, "That explains it, then..."},
    {EV_NONE, 208, PP_PHOENIX | CMD_NONE, "Wait, did I say that, or think tha-...?"},
    {EV_NONE, 208, PP_PHOENIX | CMD_NONE, "Who are you!?"},
    {EV_NONE, 211, PP_PINKIE | CMD_NONE, "I'm Pinkie Pie, of course!"},
    {EV_NONE, 211, PP_PINKIE | CMD_NONE, "Party Thrower Extraordinaire!"},
    {EV_NONE, 209, PP_PINKIE | CMD_NONE, "But I can't talk right now! I'm looking for something..."},
    {EV_NONE, 209, PP_PHOENIX | CMD_NONE, "What for?"},
    {EV_NONE, 208, PP_PINKIE | CMD_NONE, "Some other ponies said there was a spiky-headed monster in here."},
    {EV_NONE, 208, PP_PINKIE | CMD_NONE, "I can't seem to find it anywhere, though."},
    {EV_NONE, 209, PP_PINKIE | CMD_NONE, "You'd think it would stick out like a sore hoof."},
    {EV_NONE, 208, PP_PINKIE | CMD_NONE, "Have you seen it?"},
    {EV_NONE, 208, PP_PHOENIX | CMD_NONE, "(* sigh *)"},
    {EV_NONE, 212, PP_PINKIE | CMD_NONE, "...does that mean \"no\"?"},
    {EV_NONE, 212, PP_PHOENIX | CMD_NONE, "I'm getting so sick of this place!"},
    {EV_NONE, 213, PP_PINKIE | CMD_NONE, "Hey! Turn that frowny upside-downy!"},
    {EV_NONE, 213, PP_PHOENIX | CMD_NONE, "How can I? I did such a lousy job in court today, and Twilight probably hates my guts for what I did..."},
    {EV_NONE, 210, PP_PINKIE | CMD_NONE, "Hey, you know Twilight!? Me too!"},
    {EV_NONE, 210, PP_PHOENIX | CMD_NONE, "You know Twilight Sparkle?"},
    {EV_NONE, 213, PP_PINKIE | CMD_NONE, "Yup! We're the bestest of best friends!"},
    {EV_NONE, 214, PP_PINKIE | CMD_NONE, "Oh, that reminds me! I'm supposed to go to court today, and cheer for Rainbow Dash!"},
    {EV_NONE, 100, PP_PINKIE | CMD_NONE, "Sorry, gotta run!"},
    {EV_NONE, 100, PP_PHOENIX | CMD_NONE, "But you're-!"},
    {EV_NONE, 208, PP_PINKIE | CMD_NONE, "Oh, I'm already here."},
    {EV_NONE, 211, PP_PINKIE | CMD_NONE, "Yay!"},
    {EV_NONE, 213, PP_PHOENIX | CMD_NONE, "I hate to break it to you, but you missed the trial."},
    {EV_NONE, 213, PP_PHOENIX | CMD_NONE, "(Out of all the pastel grass-chewers I've met, this one is definitely the weirdest.)"},
    {EV_NONE, 213, PP_PHOENIX | CMD_NONE, "(AH! I better be careful, I think she can read minds.)"},
    {EV_NONE, 212, PP_PINKIE | CMD_NONE, "Is Dashie okay?"},
    {EV_NONE, 212, PP_PHOENIX | CMD_NONE, "For the time being, yes."},
    {EV_NONE, 212, PP_PHOENIX | CMD_NONE, "The trial is being postponed. I'm actually Rainbow Dash's lawyer, Phoenix Wright."},
    {EV_NONE, 210, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 210, PP_PINKIE | CMD_NONE, "Neato! So what'cha doing right now, Feenie?"},
    {EV_NONE, 212, PP_PHOENIX | CMD_NONE, "\"Feenie\"... that's..."},
    {EV_NONE, 212, PP_PHOENIX | CMD_NONE, "..."},
    {EV_NONE, 212, PP_PHOENIX | CMD_NONE, "Never mind..."},
    {EV_NONE, 213, PP_PHOENIX | CMD_NONE, "Well... I don't know what I should be doing right now, to be honest. I have no leads at all."},
    {EV_NONE, 208, PP_PINKIE | CMD_NONE, "Why don't you go talk to Dashie about the trial?"},
    {EV_NONE, 213, PP_PHOENIX | CMD_NONE, "Wait a minute... she had Psyche-locks..."},
    {EV_NONE, 209, PP_PINKIE | CMD_NONE, "Psyche-locks? Is that some kinda breakfast cereal?"},
    {EV_NONE, 210, PP_PINKIE | CMD_NONE, "Sounds yummy!"},
    {EV_NONE, 208, PP_PINKIE | CMD_NONE, "Is it made with real locks and not grossly-wossly artificial locks?"},
    {EV_NONE, 215, PP_PHOENIX | CMD_NONE, "Thanks for the advice, erm, Pinkie Pie."},
    {EV_NONE, 215, PP_PHOENIX | CMD_NONE, "I'm gonna go to the detention center now."},

// =============================================================================
// STORY SEGMENT: DETENTION CENTER - RAINBOW DASH'S BREAKDOWN
// =============================================================================
    // USER CHOICE OPPORTUNITY: How to approach Rainbow Dash's emotional state
    // Options could include: Comfort her, Be direct about the case, Address her anger
    {EV_NONE, 34, PP_NONE | CMD_NONE, "Ponyville Detention Center, June 10th, 12:00PM"},
    {EV_NONE, 34, PP_PHOENIX | CMD_NONE, "(I really hope she isn't mad at me after what happened...)"},
    {EV_NONE, 216, PP_RAINBOW | CMD_NONE, "No no no no! No! No! No!"},
    {EV_NONE, 217, PP_PHOENIX | CMD_NONE, "R-Rainbow Dash?"},
    {EV_NONE, 45, PP_RAINBOW | CMD_NONE, "I-I can't bear to live anymore!"},
    {EV_NONE, 216, PP_RAINBOW | CMD_NONE, "Throw the book at me! L-let them send me to the sun, there's nothing left for me in Equestria!"},
    {EV_NONE, 45, PP_PHOENIX | CMD_NONE, "Rainbow Dash, get a hold of yourself!"},
    {EV_NONE, 45, PP_PHOENIX | CMD_NONE, "(She must still be upset over those... pictures.)"},
    {EV_NONE, 218, PP_RAINBOW | CMD_NONE, "Easy for you to say! Now the Wonderbolts will NEVER let me in! Ponyville is going to laugh at me forever!"},
    {EV_NONE, 218, PP_PHOENIX | CMD_NONE, "They weren't... that... um... bad... r-really. I'm sure everyone will forget it by tomorrow. I guarantee it."},
    {EV_NONE, 45, PP_PHOENIX | CMD_NONE, "(There's no way anyone's forgetting images like those...)"},
    {EV_NONE, 44, PP_RAINBOW | CMD_NONE, "You think so?"},
    {EV_NONE, 44, PP_PHOENIX | CMD_NONE, "I know so! I'm always right: my name is Phoenix WRIGHT after all..."},
    {EV_NONE, 219, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 219, PP_RAINBOW | CMD_NONE, "That wasn't funny..."},
    {EV_NONE, 219, PP_PHOENIX | CMD_NONE, "(Ack! ... I thought it was! ...)"},

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
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "Thanks for trying to cheer me up though, I appreciate it."},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "You're welcome."},
    {EV_NONE, 40, PP_RAINBOW | CMD_NONE, "By the way..."},
    {EV_NONE, 40, PP_PHOENIX | CMD_NONE, "Yes? What is it?"},
    {EV_NONE, 35, PP_RAINBOW | CMD_NONE, "What was that terri-bad performance in court today!?"},
    {EV_NONE, 35, PP_RAINBOW | CMD_NONE, "I could have done a better job defending myself!"},
    {EV_NONE, 35, PP_PHOENIX | CMD_NONE, "I-I..."},
    {EV_NONE, 220, PP_RAINBOW | CMD_NONE, "Every defense attorney must suck horse apples, if you're supposed to be the best one!"},
    {EV_NONE, 35, PP_PHOENIX | CMD_NONE, "Look, I know I screwed up, but I'm going to make it up to you and Fluttershy tomorrow."},
    {EV_NONE, 221, PP_RAINBOW | CMD_NONE, "Fluttershy?! Ha!"},
    {EV_NONE, 221, PP_RAINBOW | CMD_NONE, "She got what she deserved! After she betrayed me like that!"},
    {EV_NONE, 221, PP_PHOENIX | CMD_NONE, "Hey! It tore me up having to do that! It was the only way I could save you. Fluttershy didn't betray you."},
    {EV_NONE, 35, PP_RAINBOW | CMD_NONE, "Give me a break! This is the thanks I get for all the times I stuck up for her sorry flank?"},
    {EV_NONE, 35, PP_PHOENIX | CMD_NONE, "She was just telling the truth."},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "Truth? You proved she was lying though, she didn't see Applebloom!"},
    {EV_NONE, 35, PP_PHOENIX | CMD_NONE, "But she did see you leave the forest... you were there, weren't you?"},
    {EV_NONE, 38, PP_RAINBOW | CMD_NONE, "..."},
    {EV_NONE, 221, PP_RAINBOW | CMD_NONE, "Whatever! We are ex-friends as of now!"},
    {EV_NONE, 38, PP_RAINBOW | CMD_NONE, "I could tell you were trying your hardest to defend me, even if you did do a crummy job."},
    {EV_NONE, 38, PP_PHOENIX | CMD_NONE, "(Gee, thanks.)"},
    {EV_NONE, 35, PP_RAINBOW | CMD_NONE, "She pretty much said:"},
    {EV_NONE, 222, PP_RAINBOW | CMD_NONE, "\"Yup! Rainbow Dash did it!\""},
    {EV_NONE, 35, PP_RAINBOW | CMD_NONE, "What kind of a friend does that?"},
    {EV_NONE, 35, PP_PHOENIX | CMD_NONE, "Rainbow Dash, for the last time, she was telling the truth. What she saw..."},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "Actually, that brings me to why I'm here."},
    {EV_NONE, 40, PP_RAINBOW | CMD_NONE, "What? Why are you here?"},
    {EV_NONE, 40, PP_PHOENIX | CMD_NONE, "The truth. I want to know what you were really doing near the Everfree Forest the night of the murder."},

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

    {EV_NONE, 223, PP_PHOENIX | CMD_NONE, "(phoenix takethat sfx)"},
    {EV_NONE, 224, PP_RAINBOW | CMD_NONE, "Ugh..."},
    {EV_NONE, 225, PP_RAINBOW | CMD_NONE, "I told you already, I was practicing for the race!"},
    {EV_NONE, 225, PP_PHOENIX | CMD_NONE, "(Phew... it still works after that incident this morning...)"},
    {EV_NONE, 225, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 227, PP_PHOENIX | CMD_NONE, "(What was that all about anyway?)"},
    {EV_NONE, 227, PP_PHOENIX | CMD_NONE, "(Ugh, forget about that! It still works, and that's all that matters!)"},
    {EV_NONE, 227, PP_PHOENIX | CMD_NONE, "(Okay, there they are. Time to break 'em!)"},
    {EV_NONE, 227, PP_PHOENIX | CMD_NONE, "Sorry, but I don't believe you, my little pony. Not for a single solitary second."},
    {EV_NONE, 224, PP_RAINBOW | CMD_NONE, "You're my lawyer and you don't believe me? THAT'S reassuring..."},
    {EV_NONE, 224, PP_PHOENIX | CMD_NONE, "Let's play a game, Rainbow Dash..."},
    {EV_NONE, 224, PP_PHOENIX | CMD_NONE, "I'm going to guess what you were really doing near the crime scene that night, and you're going to tell me if I'm right."},
    {EV_NONE, 228, PP_RAINBOW | CMD_NONE, "You can go right ahead and do that, but I'm sticking to my story."},
    {EV_NONE, 228, PP_PHOENIX | CMD_NONE, "I don't think you were practicing at all; I think you were doing something FAR more important."},
    {EV_NONE, 225, PP_RAINBOW | CMD_NONE, "L-like WHAT!?"},
    {EV_NONE, 225, PP_PHOENIX | CMD_NONE, "Like, oh, I don't know... meeting someone?"},
    {EV_NONE, 229, PP_RAINBOW | CMD_NONE, "Ah! Uh-I-I mean-..."},
    {EV_NONE, 225, PP_RAINBOW | CMD_NONE, "Who would I be meeting in the middle of the forest at that hour?"},
    {EV_NONE, 225, PP_RAINBOW | CMD_NONE, "Nopony ever goes in there willingly."},
    {EV_NONE, 225, PP_PHOENIX | CMD_NONE, "Then why were YOU \"practicing\" there if no one ever goes in there willingly?"},
    {EV_NONE, 229, PP_RAINBOW | CMD_NONE, "U-uh... w-well..."},
    {EV_NONE, 227, PP_PHOENIX | CMD_NONE, "I know there was someone in the forest the night of the murder."},
    {EV_NONE, 225, PP_RAINBOW | CMD_NONE, "Put your money where your mouth is! Who do you think I was meeting?"},

    // EVIDENCE PRESENTATION: Rainbow's Feathers + Victim Location Logic
    {EV_NONE, 223, PP_PHOENIX | CMD_NONE, "(phoenix takethat sfx)"},
    {EV_NONE, 227, PP_PHOENIX | CMD_NONE, "Ace Swift!"},
    {EV_NONE, 227, PP_PHOENIX | CMD_NONE, "The fact that your feathers were found all around the clearing proves you were there that night."},
    {EV_NONE, 229, PP_RAINBOW | CMD_NONE, "!!??"},
    {EV_NONE, 229, PP_PHOENIX | CMD_NONE, "And who else was in the clearing that night...? The victim, of course!"},
    {EV_NONE, 229, PP_PHOENIX | CMD_NONE, "You needed to be there to see him."},
    {EV_NONE, 229, PP_PHOENIX | CMD_NONE, "You also just told me, ponies avoid going in there."},
    {EV_NONE, 229, PP_PHOENIX | CMD_NONE, "So I'm willing to bet he wanted to meet with you in private, and what better place to pick than the middle of a forest nobody ever goes into?"},
    {EV_NONE, 230, PP_RAINBOW | CMD_NONE, "AHH! NOOOOO!"},
    {EV_NONE, 231, PP_NONE | CMD_BREAKLOCK, "(breaklock sfx)"},

    // PSYCHE-LOCK 2/3: "He was just competition"
    /*
    // EVIDENCE NEEDED TO BREAK: Blackmail Photos
    // This reveals the real motive for the meeting
    */
    {EV_NONE, 232, PP_RAINBOW | CMD_NONE, "I-I mean-... \"Ah, no, you're wrong!\""},
    {EV_NONE, 233, PP_RAINBOW | CMD_NONE, "H-he was just competition!"},
    {EV_NONE, 233, PP_RAINBOW | CMD_NONE, "Why would I want to meet him? I have better things I could be doing."},
    {EV_NONE, 233, PP_PHOENIX | CMD_NONE, "Like what?"},
    {EV_NONE, 234, PP_RAINBOW | CMD_NONE, "I don't know, napping? Something like that..."},
    {EV_NONE, 234, PP_PHOENIX | CMD_NONE, "(Oh, please...)"},
    {EV_NONE, 234, PP_PHOENIX | CMD_NONE, "Maybe he had something you wanted."},
    {EV_NONE, 235, PP_RAINBOW | CMD_NONE, "What do you mean?"},
    {EV_NONE, 235, PP_PHOENIX | CMD_NONE, "I'm saying maybe he had somehting important to you, something you'd move heaven and earth for."},
    {EV_NONE, 233, PP_RAINBOW | CMD_NONE, "I'm a pretty self-satisfied pony."},
    {EV_NONE, 233, PP_RAINBOW | CMD_NONE, "I've got everything I need, well, besides fortune and glory, and I don't think he could give those to me."},
    {EV_NONE, 236, PP_RAINBOW | CMD_NONE, "What could he possibly have that I'd want?"},
    {EV_NONE, 236, PP_PHOENIX | CMD_NONE, "I'm glad you asked that, Rainbow Dash..."},
    {EV_NONE, 235, PP_RAINBOW | CMD_NONE, "Y-you are?"},
    {EV_NONE, 235, PP_PHOENIX | CMD_NONE, "There's one thing that you absolutely needed that I know he had."},
    {EV_NONE, 234, PP_RAINBOW | CMD_NONE, "I'm afraid I don't know what you're talking about..."},
    {EV_NONE, 234, PP_PHOENIX | CMD_NONE, "The reason you went to go meet him is..."},

    // CRITICAL EVIDENCE PRESENTATION: The Blackmail Photos
    {EV_NONE, 223, PP_PHOENIX | CMD_NONE, "(phoenix takethat sfx)"},
    {EV_NONE, 223, PP_PHOENIX | CMD_NONE, "These!"},
    {EV_NONE, 237, PP_RAINBOW | CMD_NONE, "AHH! Put those away before somepony sees them! PLEASE!"},
    {EV_NONE, 238, PP_PHOENIX | CMD_NONE, "Even right now, your anxiety shows you absolutely didn't want these pictures floating out and about!"},
    {EV_NONE, 232, PP_RAINBOW | CMD_NONE, "Yes, yes, yes, you're right!"},
    {EV_NONE, 232, PP_RAINBOW | CMD_NONE, "I was meeting him about these! Can you please just put them away? NOW!?"},
    {EV_NONE, 239, PP_NONE | CMD_BREAKLOCK, "(breaklock sfx)"},

    // PSYCHE-LOCK 3/3: The true nature of the meeting
    /*
    // EVIDENCE NEEDED TO BREAK: Race information + Logic about Ace's behavior
    // This reveals the blackmail scheme
    */
    {EV_NONE, 240, PP_PHOENIX | CMD_NONE, "This brings us to the money question... why did he have these pictures?"},
    {EV_NONE, 240, PP_RAINBOW | CMD_NONE, "Who knows, he's dead, what a bummer, guess we'll never know!"},
    {EV_NONE, 240, PP_PHOENIX | CMD_NONE, "I actually think I know why."},
    {EV_NONE, 241, PP_RAINBOW | CMD_NONE, "You do?"},
    {EV_NONE, 241, PP_PHOENIX | CMD_NONE, "Yes. I can think of one reason why he'd want to meet you over pictures like these..."},
    {EV_NONE, 241, PP_PHOENIX | CMD_NONE, "He was blackmailing you, wasn't he?"},
    {EV_NONE, 242, PP_RAINBOW | CMD_NONE, "Blackmail..."},
    {EV_NONE, 242, PP_PHOENIX | CMD_NONE, "I'm willing to bet my attorney badge that he wanted you to toss the Equestrian 500."},
    {EV_NONE, 242, PP_RAINBOW | CMD_NONE, "..."},
    {EV_NONE, 242, PP_PHOENIX | CMD_NONE, "I was told of ponies suspecting him of foul play in the wake of all his success."},
    {EV_NONE, 242, PP_PHOENIX | CMD_NONE, "He was probably threatening you to let him win the race."},
    {EV_NONE, 241, PP_RAINBOW | CMD_NONE, "Wow..."},
    {EV_NONE, 241, PP_PHOENIX | CMD_NONE, "Hmm?"},
    {EV_NONE, 243, PP_RAINBOW | CMD_NONE, "You're really good..."},
    {EV_NONE, 244, PP_NONE | CMD_BREAKLOCK, "(breaklock sfx)"},

    // FULL TRUTH REVEALED
    {EV_NONE, 245, PP_RAINBOW | CMD_NONE, "It's true... Ace was trying to force me to drop out of the Equestrian 500..."},
    {EV_NONE, 245, PP_PHOENIX | CMD_NONE, "How did it start?"},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "I got home two days ago and saw this letter on my doorstep."},
    {EV_NONE, 246, PP_NONE | CMD_NONE, "A letter blackmailing Rainbow Dash that she found on her doorstep."},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "\"I'll let your secret out if you don't drop out of the Equestrian 500. Meet in the Everfree Forest clearing 8:35PM tonight for negotiations.\""},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "At first I didn't know what secret it was talking about..."},
    {EV_NONE, 45, PP_RAINBOW | CMD_NONE, "But attached to the message was one of those pictures..."},
    {EV_NONE, 45, PP_PHOENIX | CMD_NONE, "About those pictures..."},
    {EV_NONE, 45, PP_PHOENIX | CMD_NONE, "Why are you-"},
    {EV_NONE, 247, PP_RAINBOW | CMD_NONE, "IT'S A HOBBY, ALRIGHT!?"},
    {EV_NONE, 247, PP_RAINBOW | CMD_NONE, "I BET YOU HAVE SKELETONS IN YOUR CLOSET TOO, MR 20-SOMETHING WHO PLAYS WITH TOYS!"},
    {EV_NONE, 247, PP_PHOENIX | CMD_NONE, "Okay, okay, I won't ask about them anymore."},
    {EV_NONE, 35, PP_PHOENIX | CMD_NONE, "Do you have any idea how he got them, though?"},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "I have no clue; my best guess is that the jerk was stalking me, trying to get dirt on me."},
    {EV_NONE, 35, PP_PHOENIX | CMD_NONE, "Rainbow Dash..."},
    {EV_NONE, 38, PP_RAINBOW | CMD_NONE, "Yes? What is it?"},
    {EV_NONE, 38, PP_PHOENIX | CMD_NONE, "I want you to know that I trust you, and I'm going to need you to trust me when I ask you these next series of questions."},
    {EV_NONE, 40, PP_RAINBOW | CMD_NONE, "Huh?"},
    {EV_NONE, 40, PP_PHOENIX | CMD_NONE, "I know you may be scared this will make you look guilty, but I know you're innocent."},
    {EV_NONE, 248, PP_RAINBOW | CMD_NONE, "I-I'm not scared...!"},
    {EV_NONE, 248, PP_PHOENIX | CMD_NONE, "Why did you move that cloud to the crime scene and set it off?"},
    {EV_NONE, 245, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 245, PP_RAINBOW | CMD_NONE, "B-but... I-I... I didn't-"},
    {EV_NONE, 245, PP_PHOENIX | CMD_NONE, "Please, Rainbow Dash, you can trust me. I won't think any differently of you in light of what you tell me. I know you didn't kill him."},
    {EV_NONE, 245, PP_RAINBOW | CMD_NONE, "..."},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "Okay... I'll tell you..."},
    {EV_NONE, 245, PP_RAINBOW | CMD_NONE, "I did move the cloud there and I did set it off..."},
    {EV_NONE, 45, PP_RAINBOW | CMD_NONE, "I just wanted to give him a scare, that's all."},
    {EV_NONE, 45, PP_PHOENIX | CMD_NONE, "A scare?"},
    {EV_NONE, 45, PP_PHOENIX | CMD_NONE, "So you really did move the cloud over the forest clearing?"},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "As soon as I saw the requirements of the blackmail letter, I knew it was Ace, and that all those rumors about him were true."},
    {EV_NONE, 35, PP_RAINBOW | CMD_NONE, "He's a blackmailing cheater."},
    {EV_NONE, 35, PP_RAINBOW | CMD_NONE, "So, I set up the cloud over the clearing earlier that day with the intent of declining his little offer."},
    {EV_NONE, 35, PP_PHOENIX | CMD_NONE, "So you weren't going to drop out in spite of him leaking the pictures?"},
    {EV_NONE, 247, PP_RAINBOW | CMD_NONE, "No way!"},
    {EV_NONE, 35, PP_RAINBOW | CMD_NONE, "I'm not going to let some loser have his way with me even if it meant those pictures getting out..."},
    {EV_NONE, 35, PP_RAINBOW | CMD_NONE, "I have too much pride for that."},
    {EV_NONE, 35, PP_PHOENIX | CMD_NONE, "I find that really admirable."},
    {EV_NONE, 37, PP_RAINBOW | CMD_NONE, "Heh, thanks..."},
    {EV_NONE, 37, PP_RAINBOW | CMD_NONE, "This is also my first year competing in the race; I just reached the required age to participate."},
    {EV_NONE, 37, PP_RAINBOW | CMD_NONE, "I've been way too anxious to just drop out."},
    {EV_NONE, 39, PP_RAINBOW | CMD_NONE, "R-B-D spells VIC-TOR-Y!"},
    {EV_NONE, 39, PP_PHOENIX | CMD_NONE, "You sure you can take 500 miles? It's longer than it sounds, you know."},
    {EV_NONE, 40, PP_RAINBOW | CMD_NONE, "There's some checkpoints along the track set up so the racers can have some R&R, but that's a little problem I keep having."},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "There's no doubt I'm fast, but I tire out along the way. I'm not used to flying that long."},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "In races like these, you should pace yourself accordingly."},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "Don't go fast right from the start - save all your energy for the home stretch."},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "Kind of like how I don't present all my evidence right from the start."},
    {EV_NONE, 37, PP_RAINBOW | CMD_NONE, "I'll try to keep that in mind."},
    {EV_NONE, 37, PP_PHOENIX | CMD_NONE, "But let's get back on topic, shall we?"},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "I'm supposed to be your lawyer, not your coach."},
    {EV_NONE, 40, PP_RAINBOW | CMD_NONE, "Right..."},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "Anyway, I wasn't planning on killing him, just give him a bit of a startle..."},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "You know, just kicking some dirt in his face for messing with me."},
    {EV_NONE, 249, PP_RAINBOW | CMD_NONE, "The cloud shoots a lightning bolt directly under it when activated."},
    {EV_NONE, 37, PP_RAINBOW | CMD_NONE, "I mess around with ponies by scaring them with clouds all the time, but I got an extra big one in his case, to make the sound as loud as possible."},
    {EV_NONE, 245, PP_RAINBOW | CMD_NONE, "I guess it was a little dangerous getting one that big."},
    {EV_NONE, 245, PP_PHOENIX | CMD_NONE, "So it didn't hit him when you set it off?"},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "No, I made sure it wasn't over him."},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "Even though it was really dark outside, like you said in the court today, I could see that the bolt didn't even come close to touching him."},
    {EV_NONE, 37, PP_RAINBOW | CMD_NONE, "When the lightning bolt lit up the area, it made him scream like a little girl and left a really sissy look on his mug."},
    {EV_NONE, 37, PP_RAINBOW | CMD_NONE, "You should have seen it; it was priceless!"},
    {EV_NONE, 40, PP_RAINBOW | CMD_NONE, "Then I just hightailed it out of there as fast as I could."},
    {EV_NONE, 40, PP_PHOENIX | CMD_NONE, "(That's probably when Fluttershy saw her.)"},
    {EV_NONE, 40, PP_PHOENIX | CMD_NONE, "Why didn't you tell anyone about this blackmail earlier?"},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "I didn't want anypony to know about the blackmail... because..."},
    {EV_NONE, 45, PP_RAINBOW | CMD_NONE, "You know... they would wonder what he was blackmailing me with..."},
    {EV_NONE, 45, PP_PHOENIX | CMD_NONE, "I see..."},
    {EV_NONE, 45, PP_PHOENIX | CMD_NONE, "(Then those pictures would get out...)"},
    {EV_NONE, 45, PP_RAINBOW | CMD_NONE, "You believe me, right? He was absolutely fine when I left, I swear!"},
    {EV_NONE, 45, PP_PHOENIX | CMD_NONE, "Yes, I believe you, though more questions arise from this."},
    {EV_NONE, 248, PP_RAINBOW | CMD_NONE, "More questions?"},
    {EV_NONE, 248, PP_PHOENIX | CMD_NONE, "How did he end up dead directly under the cloud?"},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "I was trying desperately to convince the court it was the second bolt that killed him. That would make this all an accident, since you have no control over it."},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "But then we have that \"Lightning doesn't strike the same place twice\" thing that Trixie was talking about."},
    {EV_NONE, 40, PP_RAINBOW | CMD_NONE, "That's true, it's a new type of storm cloud the pegasi are using to protect ponies from situations like this."},
    {EV_NONE, 249, PP_RAINBOW | CMD_NONE, "Since it can't hit the same place twice, they can just stand under a cloud after the first bolt."},
    {EV_NONE, 249, PP_PHOENIX | CMD_NONE, "So the safest place is under the cloud..."},
    {EV_NONE, 249, PP_PHOENIX | CMD_NONE, "That's really something; the weather just works by itself where I live."},
    {EV_NONE, 39, PP_RAINBOW | CMD_NONE, "I kind of wish it worked that way here; I'd have a lot more free time on my hooves so I could perfect my \"Sonic Rainboom\" or my \"Fantastic Filly Flash\"."},
    {EV_NONE, 39, PP_PHOENIX | CMD_NONE, "(Are those dance moves or something?)"},
    {EV_NONE, 39, PP_PHOENIX | CMD_NONE, "From what I hear, you're also the weather manager."},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "I need some information regarding how the lightning here in Equestria works."},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "What do you need to know?"},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "Well, is it true the bolt causes the noise?"},
    {EV_NONE, 40, PP_RAINBOW | CMD_NONE, "Yeah, it is."},
    {EV_NONE, 249, PP_RAINBOW | CMD_NONE, "I don't know how it works exactly, but I'm pretty sure when it touches the ground or anything attached to the ground, like, say, a tree... it sends out vibrations which makes the 'boom'."},
    {EV_NONE, 249, PP_PHOENIX | CMD_NONE, "(I'm no meteorologist, but I'm pretty sure lightning doesn't work like that...)"},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "(Then again, I keep forgetting I'm in a land full of magical talking ponies who can manually change weather...)"},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "Is there anything that could prevent it from making a sound?"},
    {EV_NONE, 249, PP_RAINBOW | CMD_NONE, "I suppose if it hit something small in the air that was close enough to the cloud... yeah, it wouldn't make a sound..."},
    {EV_NONE, 248, PP_RAINBOW | CMD_NONE, "And I know what you're thinking, but that couldn't happen..."},
    {EV_NONE, 248, PP_PHOENIX | CMD_NONE, "Why not?"},
    {EV_NONE, 35, PP_RAINBOW | CMD_NONE, "That itchy racing suit."},
    {EV_NONE, 35, PP_PHOENIX | CMD_NONE, "Oh, right. I remember that being brought up."},
    {EV_NONE, 250, PP_PHOENIX | CMD_NONE, "That's that lightning-proof suit you pegasuses wear for the race, right?"},
    {EV_NONE, 250, PP_RAINBOW | CMD_NONE, "The plural is \"pegasi\"..."},
    {EV_NONE, 250, PP_RAINBOW | CMD_NONE, "I absolutely hate wearing that thing, but while in the air you're pretty much invulnerable to lightning."},
    {EV_NONE, 250, PP_PHOENIX | CMD_NONE, "Weren't there some exposed parts on it, though?"},
    {EV_NONE, 250, PP_RAINBOW | CMD_NONE, "Yes, there are, but while you're in the flying position those parts are covered up. They're only exposed while you're on all fours and grounded."},
    /*
    // USER INTERACTION OPPORTUNITY: LIGHTNING SUIT UNDERSTANDING
    // Technical exposition about the protective gear and its vulnerabilities
    // This information is crucial for understanding the murder method later
    */
    {EV_NONE, 245, PP_RAINBOW | CMD_NONE, "This is sounding more and more hopeless for me the more I talk about it..."},
    {EV_NONE, 245, PP_PHOENIX | CMD_NONE, "Try to cheer up. I'll find out what really happened and get you out of here."},
    {EV_NONE, 44, PP_RAINBOW | CMD_NONE, "Thank you, Nix..."},
    {EV_NONE, 44, PP_PHOENIX | CMD_NONE, "Okay, Rainbow Dash, I'm gonna go do some more investigating in light of this new information."},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "Alright, catch you later."},

    // IMPORTANT EVIDENCE ACQUISITION: Hotel Room Key
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "Oh, wait! One more thing..."},
    {EV_NONE, 40, PP_RAINBOW | CMD_NONE, "Yes?"},
    {EV_NONE, 40, PP_PHOENIX | CMD_NONE, "Pinkie Pie. I bumped into her after the trial..."},
    {EV_NONE, 40, PP_PHOENIX | CMD_NONE, "I'm guessing she's a friend of yours. She wanted to cheer you on in court today, but sadly, it seems she was late."},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "Is she always that... uh... loopy?"},
    {EV_NONE, 37, PP_RAINBOW | CMD_NONE, "Heh, yeah. That's just Pinkie Pie being Pinkie Pie."},
    {EV_NONE, 37, PP_PHOENIX | CMD_NONE, "Okay, just thought I'd let you know."},
    {EV_NONE, 37, PP_PHOENIX | CMD_NONE, "Well, goodbye Rainbow Dash."},
    {EV_NONE, 251, PP_RAINBOW | CMD_NONE, "Wait!"},
    {EV_NONE, 251, PP_PHOENIX | CMD_NONE, "(Geez, I just can't leave this place...)"},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "Yes, what is it?"},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "Here, take this..."},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "A key? What is it for?"},
    {EV_NONE, 252, PP_RAINBOW | CMD_NONE, "Ace's hotel room."},
    {EV_NONE, 252, PP_PHOENIX | CMD_NONE, "What!? How did you get this!?"},
    {EV_NONE, 253, PP_RAINBOW | CMD_NONE, "I was angry when I thought he was stalking me, so I snuck into his hotel room to find dirt on him..."},
    {EV_NONE, 254, PP_RAINBOW | CMD_NONE, "It was under the mat... what a stupid place to leave your key, huh?"},
    {EV_NONE, 254, PP_PHOENIX | CMD_NONE, "..."},
    {EV_NONE, 37, PP_PHOENIX | CMD_NONE, "Yeah... stupid place..."},
    {EV_NONE, 37, PP_PHOENIX | CMD_NONE, "(Note to self: put key to office in different hiding spot.)"},
    {EV_NONE, 255, PP_NONE | CMD_NONE, "A key to the hotel Ace Swift was staying in while in Ponyville."},
    {EV_NONE, 37, PP_RAINBOW | CMD_NONE, "I wasn't able to find anything good in there, but maybe you can!"},
    {EV_NONE, 37, PP_PHOENIX | CMD_NONE, "Where is the hotel?"},
    {EV_NONE, 249, PP_RAINBOW | CMD_NONE, "He was staying in the \"Hay and Stay Hotel\" while he was at Ponyville. It's a little past Sugar Cube Corner."},
    {EV_NONE, 36, PP_RAINBOW | CMD_NONE, "Just have Twilight show you where it is."},
    {EV_NONE, 36, PP_PHOENIX | CMD_NONE, "Twilight..."},
    {EV_NONE, 248, PP_RAINBOW | CMD_NONE, "What's the matter?"},
    {EV_NONE, 248, PP_PHOENIX | CMD_NONE, "O-oh, nothing. Thanks Rainbow Dash. This will really help my investigation!"},
    {EV_NONE, 37, PP_RAINBOW | CMD_NONE, "Goodbye, Nix."},
    {EV_NONE, 37, PP_PHOENIX | CMD_NONE, "I promise I'll get you and Fluttershy out of this mess."},
    {EV_NONE, 35, PP_RAINBOW | CMD_NONE, "Fluttershy... "},
    {EV_NONE, 35, PP_RAINBOW | CMD_NONE, "I told you, I don't care about her."},
    {EV_NONE, 35, PP_PHOENIX | CMD_NONE, "(She's still really angry about that testimony Fluttershy gave...)"},
    {EV_NONE, 37, PP_RAINBOW | CMD_NONE, "I just know you'll find some super awesome evidence this time around!"},
    {EV_NONE, 37, PP_NONE | CMD_BLACK, ""},

// =============================================================================
// HOTEL INVESTIGATION SEGMENT: PARTNERSHIP WITH PINKIE PIE
// =============================================================================
    // LOCATION TRANSITION: Investigation continues
    {EV_NONE, 256, PP_NONE | CMD_NONE, "Ponyville, June 10th, 12:30PM"},

    /*
    // USER INTERACTION OPPORTUNITY: INVESTIGATION CHOICE
    // Present 2-choice menu before Pinkie arrives:
    // A) "Let's return to the forest and look for more clues." (thorough investigation route)
    // B) "I should check out Ace's hotel room with this key." (direct evidence route)
    // This choice affects player agency but both lead to the same outcome with Pinkie's arrival
    */

    {EV_NONE, 256, PP_PHOENIX | CMD_NONE, "Okay, where should I go first? ... back to the forest, or to the hotel room?"},
    {EV_NONE, 256, PP_NONE | CMD_NONE, "Hello again!"},
    {EV_NONE, 256, PP_PHOENIX | CMD_NONE, "It would be a lot easier to go to the forest, since I know the general direction and I might find some new clues with the sun out..."},
    {EV_NONE, 256, PP_NONE | CMD_NONE, "Hello?"},
    {EV_NONE, 256, PP_PHOENIX | CMD_NONE, "Then again, I already found a lot of evidence in the forest already..."},
    {EV_NONE, 256, PP_NONE | CMD_NONE, "Knock, knock... Feenie!"},
    {EV_NONE, 256, PP_PHOENIX | CMD_NONE, "Though, would going into his hotel room be considered breaking and entering?"},
    {EV_NONE, 256, PP_PHOENIX | CMD_NONE, "I'll have a bit of trouble finding it without someone guiding me, anyway..."},

    // PINKIE PIE'S DRAMATIC ENTRANCE
    {EV_NONE, 257, PP_NONE | CMD_PARTY_HORN, "(party horn sfx)"},
    {EV_NONE, 257, PP_PHOENIX | CMD_NONE, "AH!?"},
    {EV_NONE, 258, PP_PINKIE | CMD_NONE, "Got your attention now!"},
    {EV_NONE, 258, PP_PHOENIX | CMD_NONE, "Oh, you're... Pinkie Pie."},
    {EV_NONE, 257, PP_PINKIE | CMD_NONE, "Yup-a-roonie! That's my name!"},
    {EV_NONE, 257, PP_PHOENIX | CMD_NONE, "What are you doing here?"},
    {EV_NONE, 259, PP_PINKIE | CMD_NONE, "I followed you! The guards wouldn't let me in though, so I just talked with them while I waited for you!"},
    {EV_NONE, 260, PP_PINKIE | CMD_NONE, "Right boys?"},
    {EV_NONE, 261, PP_GUARD | CMD_NONE, "Oh, for the love of all things holy... please..."},
    {EV_NONE, 261, PP_GUARD | CMD_NONE, "Take her away..."},

    // PINKIE'S MYSTERIOUS REQUEST
    /*
    // NARRATIVE NOTE: This setup creates intrigue about what Pinkie lost
    // Her secret will be revealed later in the hotel investigation
    */
    {EV_NONE, 262, PP_PHOENIX | CMD_NONE, "Uh... why were you following me?"},
    {EV_NONE, 262, PP_PINKIE | CMD_NONE, "Cause I need help finding something..."},
    {EV_NONE, 263, PP_PHOENIX | CMD_NONE, "Look, the spiky-headed monster they were talking about is-"},
    {EV_NONE, 257, PP_PINKIE | CMD_NONE, "Oh! I gave up trying to find that a looooooong time ago, it's probably just somepony's overactive imagination!"},
    {EV_NONE, 262, PP_PINKIE | CMD_NONE, "I need to find something I lost about a week ago."},
    {EV_NONE, 262, PP_PHOENIX | CMD_NONE, "What did you lose?"},
    {EV_NONE, 264, PP_PINKIE | CMD_NONE, "It's a secret!"},
    {EV_NONE, 264, PP_PHOENIX | CMD_NONE, "So you want me to help you find something... but you won't tell me what it is...?"},
    {EV_NONE, 258, PP_PINKIE | CMD_NONE, "Correct-a-mundo!"},
    {EV_NONE, 258, PP_PHOENIX | CMD_NONE, "That makes no sense!"},
    {EV_NONE, 258, PP_PHOENIX | CMD_NONE, "(Wait a minute...)"},

    // MUTUAL BENEFIT ARRANGEMENT
    {EV_NONE, 258, PP_PHOENIX | CMD_NONE, "Actually, uh, Pinkie Pie..."},
    {EV_NONE, 262, PP_PINKIE | CMD_NONE, "Yes?"},
    {EV_NONE, 262, PP_PHOENIX | CMD_NONE, "Do you know where \"Sugar Cube Corner\" is?"},

    // PINKIE'S CUPCAKE RECIPE MONOLOGUE (comic relief)
    {EV_NONE, 257, PP_PINKIE | CMD_NONE, "You want to go bake cupcakes with me at Sugar Cube Corner!"},
    {EV_NONE, 257, PP_PINKIE | CMD_NONE, "Mr and Mrs Cake always let me help out, now I have an assistant! Yay!"},
    {EV_NONE, 257, PP_PINKIE | CMD_NONE, "You know how to make cupcakes, right?"},
    {EV_NONE, 257, PP_PINKIE | CMD_NONE, "It's okay if you can't, I can teach you if you don't know, it's really really REALLY easy."},
    {EV_NONE, 258, PP_PINKIE | CMD_NONE, "First-you-preheat-the-oven-to-350-degrees-and-line-the-cupcake-pans-with-paper-liners."},
    {EV_NONE, 259, PP_PINKIE | CMD_NONE, "Then-you-toss-flour-sugar-baking-powder-and-salt-in-a-mixing-bowl."},
    {EV_NONE, 259, PP_PINKIE | CMD_NONE, "Add-shortening-milk-and-vanilla-for-flavor-and-taste;"},
    {EV_NONE, 257, PP_PINKIE | CMD_NONE, "I-personally-put-in-a-little-bit-of-candy-as-well-to-make-them-sweeter."},
    {EV_NONE, 257, PP_PINKIE | CMD_NONE, "Beat-for-1-minute-then-scrape-the-side-of-the-bowl-with-a-spatula;"},
    {EV_NONE, 259, PP_PINKIE | CMD_NONE, "we-want-to-salvage-as-many-cupcakes-as-we-can-from-the-mix!"},
    {EV_NONE, 259, PP_PHOENIX | CMD_NONE, "..."},
    {EV_NONE, 259, PP_PHOENIX | CMD_NONE, "That's not what I meant..."},
    {EV_NONE, 259, PP_PHOENIX | CMD_NONE, "I was wondering if you knew where the \"Hay and Stay\" is. It's a hotel? I heard it was by there."},
    {EV_NONE, 259, PP_PHOENIX | CMD_NONE, "(Of course I know how to make cupcakes; what does she think I am, a hobo?)"},
    {EV_NONE, 257, PP_PINKIE | CMD_NONE, "Yessiree! I know where it is!"},

    // NEGOTIATION FOR ASSISTANCE
    {EV_NONE, 257, PP_PHOENIX | CMD_NONE, "I need someone to escort me; would you be willing to do that for me if I help you find your missing... thing?"},
    {EV_NONE, 262, PP_PINKIE | CMD_NONE, "Okie-dokie-loki! On one other condition!"},
    {EV_NONE, 262, PP_PHOENIX | CMD_NONE, "Name it."},
    {EV_NONE, 262, PP_PHOENIX | CMD_NONE, "(This is going to be easier than I thought.)"},
    {EV_NONE, 262, PP_PINKIE | CMD_NONE, "You have to tell me..."},
    {EV_NONE, 258, PP_PINKIE | CMD_NONE, "a funny joke!"},

    /*
    // USER INTERACTION OPPORTUNITY: JOKE SELECTION
    // Present 3-choice menu for Phoenix's joke:
    // A) "Why did the chicken cross the road?" (classic, safe choice)
    // B) "What do you call a pegasus who can't fly?" (pony-themed joke)
    // C) "My legal career." (self-deprecating humor about recent court performance)
    // Different choices get different reactions from Pinkie
    */

    {EV_NONE, 258, PP_PHOENIX | CMD_NONE, "W-what!? Why do I have to do that!?"},
    {EV_NONE, 265, PP_PINKIE | CMD_NONE, "I don't want to hang out with some big party-pooper-frowny-stick-in-the-mud!"},
    {EV_NONE, 262, PP_PINKIE | CMD_NONE, "Show me you have a sense of humor, Feenie-weenie!"},
    {EV_NONE, 262, PP_PHOENIX | CMD_NONE, "Do I really have to do this?"},
    {EV_NONE, 260, PP_PINKIE | CMD_NONE, "Mmmm-hhhmmmmm!"},
    {EV_NONE, 262, PP_PHOENIX | CMD_NONE, "(Well, she seems really easy to impress anyway...)"},
    // PHOENIX'S TERRIBLE JOKE ATTEMPTS (comic relief sequence)
    /*
    // GENERIC ALTERNATIVE JOKES (if user chooses different options):
    // Bad Option 1: "What did the judge say to the lawyer? Order in the court!"
    // Bad Option 2: "Why don't lawyers go to the beach? Because cats keep trying to bury them!"
    // Bad Option 3: "How many lawyers does it take to change a lightbulb? How many can you afford?"
    */
    {EV_NONE, 262, PP_PHOENIX | CMD_NONE, "Okay. This is a really good one, Pinkie Pie!"},
    {EV_NONE, 257, PP_PINKIE | CMD_NONE, "Tell me! Tell me!"},
    {EV_NONE, 257, PP_PHOENIX | CMD_NONE, "Here goes! Why do they call me Phoenix Wright?"},
    {EV_NONE, 262, PP_PINKIE | CMD_NONE, "Hmmmm... I don't know. Why?"},
    {EV_NONE, 262, PP_PHOENIX | CMD_NONE, "Because..."},
    {EV_NONE, 262, PP_PHOENIX | CMD_NONE, "I'M ALWAYS \"WRIGHT\"!"},
    {EV_NONE, 262, PP_NONE | CMD_BADUMTISH, "(badumtish sfx)"},
    {EV_NONE, 263, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 263, PP_PINKIE | CMD_NONE, "That wasn't funny..."},
    {EV_NONE, 263, PP_PHOENIX | CMD_NONE, "..."},
    {EV_NONE, 262, PP_PINKIE | CMD_NONE, "So... do you have any better ones?"},
    {EV_NONE, 262, PP_PHOENIX | CMD_NONE, "... well, uh... This one time I cross-examined a parakeet! What's the deal with that!?"},
    {EV_NONE, 263, PP_PINKIE | CMD_NONE, "..."},
    {EV_NONE, 263, PP_PHOENIX | CMD_NONE, "(This is a lot harder than I thought... I'm a lawyer, not a comedian!)"},
    {EV_NONE, 263, PP_PHOENIX | CMD_NONE, "Ummm... Did you know I had the entire left side of my body cut off once? Don't worry, I'm all \"Wright\" now..."},
    {EV_NONE, 263, PP_PINKIE | CMD_NONE, "..."},

    // PINKIE'S "DISCOVERY" OF THE BADGE (accidental comedy success)
    {EV_NONE, 266, PP_PINKIE | CMD_NONE, "Oh hey, what's that!?"},
    {EV_NONE, 267, PP_PHOENIX | CMD_NONE, "This? It's my Equestria Attorney Badge. That's how I got in that detention center."},
    {EV_NONE, 258, PP_PINKIE | CMD_NONE, "Wow, that is the girliest thing I've ever seen!"},
    {EV_NONE, 257, PP_PINKIE | CMD_NONE, "That must have been why you were pretending to be so bad at telling a good joke!"},
    {EV_NONE, 257, PP_PINKIE | CMD_NONE, "To build up to flashing that ridiculous-looking thing!"},
    {EV_NONE, 258, PP_PINKIE | CMD_NONE, "You sure are a knee-slapper, Feenie!"},
    {EV_NONE, 258, PP_PHOENIX | CMD_NONE, "(I really feel like sobbing to myself in a dark corner right now...)"},
    {EV_NONE, 258, PP_PHOENIX | CMD_NONE, "So, will you show me where this hotel is, now?"},
    {EV_NONE, 258, PP_PINKIE | CMD_NONE, "(* giggling uncontrollably *)"},
    {EV_NONE, 258, PP_PHOENIX | CMD_NONE, "Pinkie?"},
    {EV_NONE, 262, PP_PINKIE | CMD_NONE, "Oh right! The hotel is THIS way!!"},
    {EV_NONE, 256, PP_PHOENIX | CMD_NONE, "Hey! Wait up!"},

// =============================================================================
// HOTEL ROOM SEARCH: EVIDENCE GATHERING WITH PINKIE PIE
// =============================================================================
    {EV_NONE, 256, PP_NONE | CMD_BLACK, "Hay and Stay Hotel, June 10th, 12:53PM"},
    {EV_NONE, 256, PP_PINKIE | CMD_NONE, "(* humming Phoenix Wright's theme *)"},
    {EV_NONE, 256, PP_PHOENIX | CMD_NONE, "(That song she's humming sounds really, really familiar...)"},
    {EV_NONE, 256, PP_PINKIE | CMD_NONE, "Lookie! Here's that room!"},
    {EV_NONE, 256, PP_PHOENIX | CMD_NONE, "Hmm... Do you think we'll get in trouble for going into his room without asking?"},
    {EV_NONE, 256, PP_PINKIE | CMD_NONE, "Don't be such a chicken, Feenie! Gimme that key!"},
    {EV_NONE, 256, PP_PHOENIX | CMD_NONE, "H-hey! We can't just-"},
    {EV_NONE, 256, PP_PINKIE | CMD_NONE, "We just stick it in here aaaand..."},
    {EV_NONE, 268, PP_PINKIE | CMD_NONE, "We're in!"},
    {EV_NONE, 269, PP_PINKIE | CMD_NONE, "Pinkie Pie, master of unlocking!"},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "(I really hope I don't get sent to the sun for this...)"},
    {EV_NONE, 270, PP_PHOENIX | CMD_NONE, "So, this is Ace's room."},
    {EV_NONE, 270, PP_PHOENIX | CMD_NONE, "Seeing as he's dead, surely he won't mind if we look around?"},
    {EV_NONE, 271, PP_PINKIE | CMD_NONE, "My name is Pinkie, not Shirley."},
    {EV_NONE, 272, PP_PINKIE | CMD_NONE, "What are we trying to find here anyway, Feenie? A magical stone? A secret chamber? A prisoner? A cup? Maybe something you ordered? Oatmeal?"},
    {EV_NONE, 273, PP_PHOENIX | CMD_NONE, "Oatmeal? Why would anybody want to find oatmeal?"},
    {EV_NONE, 268, PP_PINKIE | CMD_NONE, "Duh... when they're hungry!"},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "No, Pinkie Pie, we're trying to find clues that relate to the crime."},
    {EV_NONE, 274, PP_PINKIE | CMD_NONE, "So... no oatmeal?"},
    {EV_NONE, 274, PP_PHOENIX | CMD_NONE, "No oatmeal."},
    {EV_NONE, 275, PP_PHOENIX | CMD_NONE, "I want to try and be out of here as fast as humanly possible, okay? I don't want to be caught by anyone."},
    {EV_NONE, 268, PP_PINKIE | CMD_NONE, "Alright! I'll try to be as fast as PONY-ly possible then!"},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "(Maybe it was a mistake, taking her in here with me...)"},
    {EV_NONE, 273, PP_PINKIE | CMD_NONE, "Look Feenie, a step-ladder! Is that a clue?"},
    {EV_NONE, 273, PP_PHOENIX | CMD_NONE, "One, that's not a clue."},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "Two, that's not a step-ladder, it's a ladder."},
    {EV_NONE, 274, PP_PINKIE | CMD_NONE, "There's a difference?"},
    {EV_NONE, 274, PP_PHOENIX | CMD_NONE, "There's a BIG difference!"},
    {EV_NONE, 274, PP_PHOENIX | CMD_NONE, "A step-ladder has an A-frame that folds while a ladder is flat like that one."},
    {EV_NONE, 272, PP_PINKIE | CMD_NONE, "I still don't see what the difference is... I mean, you still step on it, right? Wouldn't it be a STEP-ladder then?"},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "How can I put this in a way you'll understand...?"},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "It's like cupcakes and muffins."},
    {EV_NONE, 272, PP_PINKIE | CMD_NONE, "Cupcakes and muffins?"},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "Exactly. Both look kind of the same, but they're totally different, like ladders and step-ladders."},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "Cupcakes have frosting on them, like how step-ladders have a folding frame, while muffins are usually plain, like the ladder is flat."},
    {EV_NONE, 268, PP_PINKIE | CMD_NONE, "OOHHH! I think I get it now! Like hacksaws and saws?"},
    {EV_NONE, 274, PP_PINKIE | CMD_NONE, "Why do they call it a hacksaw anyway?"},
    {EV_NONE, 274, PP_PHOENIX | CMD_NONE, "!!??"},
    {EV_NONE, 268, PP_PINKIE | CMD_NONE, "I don't get it... it doesn't hack; hacking is what you do with daggers and axes."},
    {EV_NONE, 273, PP_PINKIE | CMD_NONE, "And knives!"},
    {EV_NONE, 273, PP_PHOENIX | CMD_NONE, "Uhh... yeah..."},
    {EV_NONE, 273, PP_PHOENIX | CMD_NONE, "(Okay, seriously, she's freaking me out now.)"},
    {EV_NONE, 268, PP_PINKIE | CMD_NONE, "But you sure know a lot about ladders, Feenie! Are you sure you're a lawyer and not actually a ladder connoisseur?"},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "It's just common sense!"},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "I find it annoying that a lot of people don't know the difference between the two."},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "Wait a minute, wasn't the victim a Pegasus?"},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "Why would he need a ladder anyway?"},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "He could just fly up and get the things he would need a ladder for."},
    {EV_NONE, 268, PP_PINKIE | CMD_NONE, "Maybe he was superstitious and didn't want bad luck."},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "Keeping a ladder doesn't prevent bad luck..."},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "You GET bad luck for walking under a ladder."},
    {EV_NONE, 276, PP_PINKIE | CMD_NONE, "What about this? Is ripped-up paper good luck?"},
    {EV_NONE, 276, PP_PHOENIX | CMD_NONE, "It's a piece of ripped up paper..."},
    {EV_NONE, 276, PP_PHOENIX | CMD_NONE, "Why would it be good luck?"},
    {EV_NONE, 276, PP_PHOENIX | CMD_NONE, "(I need an aspirin...)"},
    {EV_NONE, 274, PP_PINKIE | CMD_NONE, "Guess you're right, it just says a bunch of mumbo-jumbo on it anyway."},
    {EV_NONE, 274, PP_PHOENIX | CMD_NONE, "\"Mumbo-jumbo?\" Let me see it..."},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "\"This is a letter stating my permanent Leave of Absence. After the Equestrian 500 is over, I can no longer work with you.\""},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "\"We made quite the team, but I-\""},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "Then it cuts off. The rest must be on the other half!"},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "Pinkie, you found a clue!"},
    {EV_NONE, 273, PP_PINKIE | CMD_NONE, "Is that good luck?"},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "No!"},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "Well... yes!"},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "Kinda!"},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "Good job, Pinkie!"},
    {EV_NONE, 277, PP_PINKIE | CMD_NONE, "Yay!!"},
    {EV_NONE, 278, PP_NONE | CMD_NONE, "Someone was planning on quitting something after the Equestrian 500. The other half is missing."},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "It would only make sense that Ace wrote this, since it's his room, but who was he writing it to?"},
    {EV_NONE, 268, PP_PINKIE | CMD_NONE, "Maybe he-"},
    {EV_NONE, 279, PP_PINKIE | CMD_NONE, "OH NO!"},
    {EV_NONE, 279, PP_PHOENIX | CMD_NONE, "Shh! We aren't supposed to be in here, remember?"},
    {EV_NONE, 279, PP_PHOENIX | CMD_NONE, "What's the problem?"},
    {EV_NONE, 279, PP_PINKIE | CMD_NONE, "My tail's twitching!"},
    {EV_NONE, 279, PP_PHOENIX | CMD_NONE, "So, my foot fell asleep. You don't see me freaking out."},
    {EV_NONE, 270, PP_PHOENIX | CMD_NONE, "(Why is she hiding under that table?)"},
    {EV_NONE, 270, PP_PHOENIX | CMD_NONE, "Pinkie Pie, stop fooling around and-"},
    {EV_NONE, 270, PP_NONE | CMD_CRASH, "(crash sfx)"},
    {EV_NONE, 270, PP_PHOENIX | CMD_NONE, "OW!"},
    {EV_NONE, 279, PP_PINKIE | CMD_NONE, "See? I warned you!"},
    {EV_NONE, 279, PP_PHOENIX | CMD_NONE, "W-what?!"},
    {EV_NONE, 279, PP_PHOENIX | CMD_NONE, "You didn't say anything was going to fall on my head!"},
    {EV_NONE, 274, PP_PINKIE | CMD_NONE, "Sure I did! I said my tail was twitching."},
    {EV_NONE, 274, PP_PINKIE | CMD_NONE, "That means something's gonna fall."},
    {EV_NONE, 274, PP_PHOENIX | CMD_NONE, "That's ridiculous! You can't tell me you can make predictions like that based off body spasms."},
    {EV_NONE, 268, PP_PINKIE | CMD_NONE, "So what's that book say?"},
    {EV_NONE, 268, PP_PHOENIX | CMD_NONE, "You mean the thing that fell on my head?"},
    {EV_NONE, 270, PP_PHOENIX | CMD_NONE, "It seems like it's some sort of advanced spell book."},
    {EV_NONE, 273, PP_PINKIE | CMD_NONE, "Hey Feenie! Do you think that you can cast a spell!?"},
    {EV_NONE, 274, PP_PINKIE | CMD_NONE, "I can't since I'm an earth pony."},
    {EV_NONE, 274, PP_PHOENIX | CMD_NONE, "Of course not! I'm not a magician!"},
    {EV_NONE, 274, PP_PHOENIX | CMD_NONE, "I can't even read it anyway."},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "I only know it's an advanced spell book because I saw Twilight reading a book just like it this morning, and I asked her what it was."},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "The text isn't in English. The characters are in weird hieroglyphics like Twilight's book."},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "Huh? Look at this..."},
    {EV_NONE, 281, PP_PINKIE | CMD_NONE, "\"Continue from here, third line.\""},
    {EV_NONE, 281, PP_PHOENIX | CMD_NONE, "Seems someone scribbled a note here."},
    {EV_NONE, 281, PP_PINKIE | CMD_NONE, "You can get in big trouble for writing in hotel's books like that!"},
    {EV_NONE, 281, PP_PHOENIX | CMD_NONE, "No, I don't think this is the hotel's book."},
    {EV_NONE, 281, PP_PHOENIX | CMD_NONE, "Twilight said these advanced spell books are only available in Ca..."},
    {EV_NONE, 281, PP_PHOENIX | CMD_NONE, "Can..."},
    {EV_NONE, 281, PP_PHOENIX | CMD_NONE, "I forget the name, starts with a hard \"C\" if I recall..."},
    {EV_NONE, 281, PP_PINKIE | CMD_NONE, "Cookie?"},
    {EV_NONE, 281, PP_PHOENIX | CMD_NONE, "No."},
    {EV_NONE, 281, PP_PINKIE | CMD_NONE, "Carrot?"},
    {EV_NONE, 281, PP_PHOENIX | CMD_NONE, "No..."},
    {EV_NONE, 281, PP_PINKIE | CMD_NONE, "Corkscrew?"},
    {EV_NONE, 281, PP_PHOENIX | CMD_NONE, "No... just stop guessing. The point is, this must be someone's personal book..."},
    {EV_NONE, 282, PP_NONE | CMD_NONE, "A book found in the victim's hotel room. Small note scribbled on one of the pages."},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "I better put it back on the shelf."},
    {EV_NONE, 272, PP_PINKIE | CMD_NONE, "It was all the way up there."},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "I can reach it."},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "Almost got it."},
    {EV_NONE, 272, PP_NONE | CMD_RIP, "(rip sfx)"},
    {EV_NONE, 279, PP_PHOENIX | CMD_NONE, "AH!!!!!!"},
    {EV_NONE, 279, PP_PHOENIX | CMD_NONE, "NOOOOOOOOOOoooOOO!"},
    {EV_NONE, 274, PP_PINKIE | CMD_NONE, "Didn't you just tell me to be quiet a second ago?"},
    {EV_NONE, 274, PP_PINKIE | CMD_NONE, "Practice what you preach!"},
    {EV_NONE, 274, PP_PHOENIX | CMD_NONE, "I ripped my suit!"},
    {EV_NONE, 276, PP_PINKIE | CMD_NONE, "You're right; you have a big hole in your armpit!"},
    {EV_NONE, 276, PP_PINKIE | CMD_NONE, "Should have used the stepladder instead of reaching so high."},
    {EV_NONE, 276, PP_PHOENIX | CMD_NONE, "It's a ladder!"},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "You don't realize how bad this is!"},
    {EV_NONE, 272, PP_PHOENIX | CMD_NONE, "I can't walk around with a big rip in my suit!"},
    {EV_NONE, 268, PP_PINKIE | CMD_NONE, "No use crying over spilled milk! Or ripped armpits!"},
    {EV_NONE, 273, PP_PINKIE | CMD_NONE, "Lookie! It's Rainbow Dash!"},
    {EV_NONE, 273, PP_PHOENIX | CMD_NONE, "Huh? Where?"},
    {EV_NONE, 273, PP_PINKIE | CMD_NONE, "Right here on the table!"},
    {EV_NONE, 283, PP_PHOENIX | CMD_NONE, "Well, it's her name alright..."},
    {EV_NONE, 283, PP_PHOENIX | CMD_NONE, "What is this? It looks like some kind of list."},
    {EV_NONE, 283, PP_PINKIE | CMD_NONE, "Maybe it's a party invite!"},
    {EV_NONE, 283, PP_PHOENIX | CMD_NONE, "Do you know who these other names are, Pinkie?"},
    {EV_NONE, 283, PP_PINKIE | CMD_NONE, "Nope, doesn't ring any bells."},
    {EV_NONE, 283, PP_PINKIE | CMD_NONE, "\"Rainbow Dash\" is the only name on here I recognize..."},
    {EV_NONE, 283, PP_PINKIE | CMD_NONE, "Uh oh! I have to find out who these other ponies are!"},
    {EV_NONE, 283, PP_PHOENIX | CMD_NONE, "Why?"},
    {EV_NONE, 283, PP_PINKIE | CMD_NONE, "I throw a party for every new pony in Ponyville..."},
    {EV_NONE, 283, PP_PINKIE | CMD_NONE, "(gasp!) That reminds me! I haven't thrown a welcome party for you yet!"},
    {EV_NONE, 283, PP_PINKIE | CMD_NONE, "I'm sorry Feenie, I just haven't had the time today!"},
    {EV_NONE, 283, PP_PHOENIX | CMD_NONE, "Uh... that's alright..."},
    {EV_NONE, 283, PP_PHOENIX | CMD_NONE, "(She seems so upset about it...)"},
    {EV_NONE, 283, PP_PHOENIX | CMD_NONE, "Look next to Rainbow Dash's name, it's a time: \"8:35\""},
    {EV_NONE, 283, PP_PINKIE | CMD_NONE, "I was right! It's a party invite!"},
    {EV_NONE, 283, PP_PINKIE | CMD_NONE, "\"Rainbow Dash party at 8:35\". I'll try not to be late this time."},
    {EV_NONE, 283, PP_PHOENIX | CMD_NONE, "I don't think so. I think I know what this is now..."},
    {EV_NONE, 284, PP_NONE | CMD_NONE, "A list with several names including Rainbow Dash."},
    {EV_NONE, 273, PP_PINKIE | CMD_NONE, "You know? Tell me! Tell me!"},
    {EV_NONE, 273, PP_PHOENIX | CMD_NONE, "I'm not completely positive, but I think this is a-"},
// =============================================================================
// DRAMATIC ENCOUNTER: SONATA DUSK REVEALED
// =============================================================================
    // CAUGHT IN THE ACT!
    /*
    // PLOT TWIST: The appearance of someone who looks exactly like Phoenix's mentor Mia
    // This creates emotional conflict and character development opportunity
    */
    {EV_NONE, 279, PP_NONE | CMD_NONE, "And just who are you two?!"},
    {EV_NONE, 279, PP_PHOENIX | CMD_NONE, "(OH NO! We're caught!!)"},
    {EV_NONE, 285, PP_MIA | CMD_NONE, "Why are you snooping around my room?"},
    {EV_NONE, 285, PP_PHOENIX | CMD_NONE, "Ch-Chief!?"},
    {EV_NONE, 285, PP_MIA | CMD_NONE, "I should have the police book you two and have you thrown in jail for breaking and entering."},
    {EV_NONE, 285, PP_PHOENIX | CMD_NONE, "(This can't be Mia, it just can't be!)"},

    // PINKIE'S DESPERATE LIE ATTEMPT
    {EV_NONE, 273, PP_PINKIE | CMD_NONE, "We're room service!"},
    {EV_NONE, 273, PP_PHOENIX | CMD_NONE, "(Do you honestly think she's going to fall for that?)"},
    {EV_NONE, 285, PP_MIA | CMD_NONE, "Do you honestly think I'm going to fall for-!"},

    // IDENTITY REVELATION
    {EV_NONE, 286, PP_MIA | CMD_NONE, "Wait a minute..."},
    {EV_NONE, 286, PP_MIA | CMD_NONE, "I know who you are..."},
    {EV_NONE, 285, PP_PHOENIX | CMD_NONE, "It's me, Mia..."},
    {EV_NONE, 286, PP_MIA | CMD_NONE, "Mia?"},
    {EV_NONE, 285, PP_MIA | CMD_NONE, "My name is Sonata."},
    {EV_NONE, 285, PP_PHOENIX | CMD_NONE, "Sonata...?"},
    {EV_NONE, 287, PP_SONATA | CMD_NONE, "Did I stutter? Yes, that's my name."},

    /*
    // USER INTERACTION OPPORTUNITY: EMOTIONAL RESPONSE CHOICE
    // Present 3-choice menu for Phoenix's reaction to seeing Mia's lookalike:
    // A) "You look exactly like someone I knew..." (honest/emotional route)
    // B) "Sorry, mistook you for someone else." (diplomatic route)
    // C) "Are you related to Mia Fey?" (direct investigation route)
    // Each choice leads to different character development paths
    */

    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "(It's not her... but the resemblance... it's uncanny...)"},
    {EV_NONE, 289, PP_SONATA | CMD_NONE, "Name. Now."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "Phoenix Wright..."},
    {EV_NONE, 268, PP_PINKIE | CMD_NONE, "Pinkamena Dianne Pie, Party Thrower Extraordinaire!"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "As I thought. You're that human lawyer from the trial earlier..."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "(I can't get over this... it looks exactly like her... if she were a pony.)"},
    {EV_NONE, 287, PP_SONATA | CMD_NONE, "Can you stop staring at me like that, please."},
    {EV_NONE, 272, PP_PINKIE | CMD_NONE, "What's the matter Feenie, cat got your tongue?"},

// SEGMENT CONTINUES: Further investigation and character development with Sonata
// This sets up important plot threads for the investigation and Phoenix's emotional journey
    {EV_NONE, 268, PP_PINKIE | CMD_NONE, "That would hurt because a cat has claws and your tongue is really sensitive..."},
    {EV_NONE, 279, PP_PINKIE | CMD_NONE, "Ouch!"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "I knew Rainbow Dash was guilty, but it didn't even look like you were trying in court today."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "Who... exactly... are you...?"},
    {EV_NONE, 290, PP_SONATA | CMD_NONE, "I'm the one who should be asking questions here. Seeing as you two are the ones who broke into my room."},
    {EV_NONE, 290, PP_SONATA | CMD_NONE, "I'm betting you're the one who stole the key two days ago."},
    {EV_NONE, 290, PP_PHOENIX | CMD_NONE, "But isn't this Ace Swift's room?"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "You're here about him?"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "I see..."},
    {EV_NONE, 289, PP_PHOENIX | CMD_NONE, "We were just investigating his hotel room for clues. This is his room, is it not?"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Hmm?"},
    {EV_NONE, 289, PP_SONATA | CMD_NONE, "Oh, yes, that is correct."},
    {EV_NONE, 289, PP_PHOENIX | CMD_NONE, "You just said this was your room though. What are you, his girlfriend or something?"},
    {EV_NONE, 290, PP_SONATA | CMD_NONE, "That's strike one, Mr. Wright. I suggest you not strike out anymore."},
    {EV_NONE, 290, PP_PHOENIX | CMD_NONE, "(Ack! Better not get on her bad side.)"},
    {EV_NONE, 290, PP_PHOENIX | CMD_NONE, "Uh... sorry."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Actually I'm-"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Or should I say, WAS, his manager. Given the circumstances."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "His... manager...?"},
    {EV_NONE, 291, PP_NONE | CMD_WHOOSH, "(whoosh sfx)"},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "(This is getting weird...)"},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "I'm sorry about what happened."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Don't worry, I got over it pretty quickly."},
    {EV_NONE, 287, PP_SONATA | CMD_NONE, "Besides, justice will be served. Your client will be punished for her crime."},
    {EV_NONE, 287, PP_PHOENIX | CMD_NONE, "Hey, Rainbow Dash didn't do it!"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Anypony with half a brain can see that she did it, Mr Wright. Look at all the evidence stacked against her."},
    {EV_NONE, 287, PP_SONATA | CMD_NONE, "No matter how you look at it, she was the one who activated that cloud and killed him."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Your little feather theory may have bought some time, but she is going to be found guilty tomorrow morning. I assure it."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "I believe in her, and I'm going to defend her to the very end. No matter what you say."},
    {EV_NONE, 290, PP_SONATA | CMD_NONE, "And that's why you're going to lose."},
    {EV_NONE, 290, PP_SONATA | CMD_NONE, "From what I've gathered, you're not even from Equestria. Why place loyalty in a pony you hardly know?"},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "Did I stutter?"},
    {EV_NONE, 292, PP_PHOENIX | CMD_NONE, "I said, because I believe her. She didn't do it."},
    {EV_NONE, 293, PP_SONATA | CMD_NONE, "Arrogant... just like that prosecutor."},
    {EV_NONE, 287, PP_PHOENIX | CMD_NONE, "Do you mean Trixie?"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Yes. Her."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "What do you have against her?"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "I wished to prosecute for this case, but that pig-headed showmare beat me to it."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "(She does seem a lot more qualified to be a prosecutor than Trixie.)"},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "So wait, you're a prosecutor as well as a manager?"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Ace and I are from Canterlot, Equestria's capital. Most of the unicorns there are \"jacks-of-all-trades,\" so to speak."},
    {EV_NONE, 287, PP_SONATA | CMD_NONE, "We take on as many jobs as we can to flourish our intellect and magical abilites."},
    {EV_NONE, 273, PP_PINKIE | CMD_NONE, "Wow! I didn't even know that! I should take another trade!"},
    {EV_NONE, 294, PP_PINKIE | CMD_NONE, "Maybe bowling?"},
    {EV_NONE, 273, PP_PINKIE | CMD_NONE, "No, creative writing!"},
    {EV_NONE, 280, PP_PINKIE | CMD_NONE, "No! NO! How about SCUBA DIVING??"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "..."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "(Pinkie, it doesn't look like she shares your enthusiasm...)"},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "Trixie is from this \"Canterlot\" place then?"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Yes, she is. I was in Ponyville when the murder took place."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "So there wasn't enough time for me to go to Canterlot and execute the procedures to prosecute this case."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Trixie must have already been there when she heard about it."},
    {EV_NONE, 287, PP_SONATA | CMD_NONE, "How foolish, taking a case over a silly little grudge..."},
    {EV_NONE, 295, PP_SONATA | CMD_NONE, "It's funny really, part of me wants you to best her."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "(Who has the grudge now?)"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "I actually know quite a bit about her... care to listen?"},
    {EV_NONE, 296, PP_PINKIE | CMD_NONE, "A story! I love stories!"},
    {EV_NONE, 294, PP_PINKIE | CMD_NONE, "I'll tell you the one where me and some guy in a blue suit broke into somepony's room and rummaged through their personal belongings!"},
    {EV_NONE, 276, PP_PINKIE | CMD_NONE, "It's a classic!"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "..."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "(Pinkie, for the love of God, shut up!)"},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "If you wouldn't mind... I wasn't told much about Trixie."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "I was classmates with her when I was but a foal. I attended the same magic classes as her."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "Were you friends with her or something?"},
    {EV_NONE, 287, PP_SONATA | CMD_NONE, "No, I kept to myself as I do now. I only consult with those who are worth my time."},
    {EV_NONE, 294, PP_PINKIE | CMD_NONE, "Hey, you know what that means, Feenie!"},
    {EV_NONE, 294, PP_PINKIE | CMD_NONE, "We're both worth her time!"},
    {EV_NONE, 280, PP_PINKIE | CMD_NONE, "Here I thought she wouldn't like us for breaking into her room."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "..."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "(Every time you speak, you make that glare icier and icier...)"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Continuing..."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "The Trixie you saw in court today is how she has been all her life. An arrogant boaster, a show-off."},
    {EV_NONE, 287, PP_SONATA | CMD_NONE, "I hate that type..."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "She was at the top of the class. As much as I hate to say it, she's better than me, despite me being older..."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Well, when it comes to magic, anyway."},
    {EV_NONE, 280, PP_PINKIE | CMD_NONE, "Ah! So you're just jealous then!"},
    {EV_NONE, 280, PP_PHOENIX | CMD_NONE, "P-Pinkie! Is your brain the size of chewed bubble gum!?"},
    {EV_NONE, 271, PP_PINKIE | CMD_NONE, "I don't think so. If it were bubble gum, it would probably stick to the inside of my head, don't you think?"},
    {EV_NONE, 280, PP_PHOENIX | CMD_NONE, "Argh! Pinkie, just stop talking. PLEASE!"},
    {EV_NONE, 272, PP_PINKIE | CMD_NONE, "Okay, I'll stop talking..."},
    {EV_NONE, 279, PP_PINKIE | CMD_NONE, "Ah! Oops, sorry, I spoke!"},
    {EV_NONE, 279, PP_PINKIE | CMD_NONE, "AH! I SPOKE AGAIN!"},
    {EV_NONE, 279, PP_PINKIE | CMD_NONE, "AND AGAIN! AND AGAIN! AND AGAIN!"},
    {EV_NONE, 279, PP_PINKIE | CMD_NONE, "AH!"},
    {EV_NONE, 297, PP_SONATA | CMD_NONE, "Ergh!"},
    {EV_NONE, 297, PP_PHOENIX | CMD_NONE, "Huh!? Are you okay?"},
    {EV_NONE, 293, PP_SONATA | CMD_NONE, "Yes... excuse me..."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Anyway, I'm not jealous..."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "In fact, unlike Trixie, I'm striving to become better with magic."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Not going around town and showing off a bunch a cheap parlor tricks."},
    {EV_NONE, 287, PP_SONATA | CMD_NONE, "You should earn attention and praise for the actions you do, not what you claim you can do."},
    {EV_NONE, 287, PP_PHOENIX | CMD_NONE, "So just because she showed off in school, you hate her?"},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "Sorry, but that's a little shallow if you ask me."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "But is it? Do you think she's qualified to be prosecuting? You saw how she acted."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "No professionalism at all..."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "I've had it worse in the courtroom... toupees, birds, whips..."},
    {EV_NONE, 292, PP_SONATA | CMD_NONE, "Whips?"},
    {EV_NONE, 292, PP_PHOENIX | CMD_NONE, "Uh... don't ask. As long as she's getting the job done, I don't see anything wrong with it."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "Why do you want to prosecute this case so badly, anyway? I know you were his manager, but still..."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Because if things were going my way, the case would have been closed by now."},
    {EV_NONE, 287, PP_SONATA | CMD_NONE, "Cold, hard, swift justice."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "That's the way I work."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "That's not what being a lawyer is about, Sonata."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Then what is it about, Mr Wright?"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Sitting back and letting a dangerous felon off the hook scot-free?"},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "No, it's about finding the truth."},
    {EV_NONE, 292, PP_SONATA | CMD_NONE, "The truth?"},
    {EV_NONE, 292, PP_PHOENIX | CMD_NONE, "Attorneys aren't meant to uphold justice; we're to work to the best of our abilities to guide it, and seek out the truth."},
    {EV_NONE, 290, PP_SONATA | CMD_NONE, "You sure have quite the ideals, Mr Wright. I don't know what kind of trials and tribulations you've been through..."},
    {EV_NONE, 290, PP_SONATA | CMD_NONE, "But you're not changing my opinion."},
    {EV_NONE, 287, PP_SONATA | CMD_NONE, "Rainbow Dash is guilty, and that's all there is to it."},
    {EV_NONE, 287, PP_PHOENIX | CMD_NONE, "If you don't mind me asking, what does that eyeball stand for?"},
    {EV_NONE, 276, PP_PINKIE | CMD_NONE, "It's her cutie mark!"},
    {EV_NONE, 276, PP_PINKIE | CMD_NONE, "It must mean her special talent is poking ponies' eyes out with that horn!"},
    {EV_NONE, 276, PP_PHOENIX | CMD_NONE, "(We are so dead...)"},
    {EV_NONE, 297, PP_SONATA | CMD_NONE, "Mmph!"},
    {EV_NONE, 297, PP_PHOENIX | CMD_NONE, "(What the heck is wrong with her?)"},
    {EV_NONE, 297, PP_PHOENIX | CMD_NONE, "Uh... are you okay? You look like you're in pain..."},
    {EV_NONE, 297, PP_SONATA | CMD_NONE, "Yes, I'm fine..."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "But no..."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "My talent is perceiving and having a keen eye for detail."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "For instance, Mr Wright."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "You're desperately trying to change the subject, hoping I forget about you breaking into my room..."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "Indicated by your nervous breathing patterns and the sweat trickling down your forehead and neck."},
    {EV_NONE, 295, PP_SONATA | CMD_NONE, "You're also trying to cover up that embarrassing rip in your armpit."},
    {EV_NONE, 295, PP_SONATA | CMD_NONE, "I can tell by how firmly your left arm is pressed against your body compared to your right one."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "And her... she's..."},
    {EV_NONE, 280, PP_PINKIE | CMD_NONE, "..."},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "She's thinking about ladders..."},
    {EV_NONE, 279, PP_PINKIE | CMD_NONE, "Wow! How did you know? You must be psychic!"},
    {EV_NONE, 280, PP_PINKIE | CMD_NONE, "But I was actually thinking about step-ladders."},
    {EV_NONE, 280, PP_PHOENIX | CMD_NONE, "It's a ladder! Even I could have gotten that one!"},
    {EV_NONE, 280, PP_PHOENIX | CMD_NONE, "Throughout the whole conversation, you keep looking at it!"},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "But, Sonata, can you tell me a little bit more about Ace?"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "What's there to say?"},
    {EV_NONE, 288, PP_SONATA | CMD_NONE, "He was good at what he did."},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "(Good at what he did? Yeah, sure. That creep was blackmailing Rainbow Dash.)"},
    {EV_NONE, 288, PP_PHOENIX | CMD_NONE, "What about your relationship with him? As his manager, I mean..."},
    {EV_NONE, 293, PP_SONATA | CMD_NONE, "..."},
    {EV_NONE, 293, PP_PHOENIX | CMD_NONE, "Well?"},
    {EV_NONE, 290, PP_SONATA | CMD_NONE, "Th-that's none of your business!"},
    {EV_NONE, 290, PP_PHOENIX | CMD_NONE, "(For a second there she kind of hesitated. Perhaps I should press this further...)"},
    {EV_NONE, 0, PP_NONE | CMD_NONE, ""}
};

// Number of entries in the array
#define TRANSCRIPT_PART3_SIZE (sizeof(transcript_part3) / sizeof(ConversationEntry))