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

// 42:34

// Number of entries in the array
#define TRANSCRIPT_PART3_SIZE (sizeof(transcript_part3) / sizeof(ConversationEntry))