// =============================================================================
// PHOENIX WRIGHT: TURNABOUT STORM - PART 3 (PHOENIX PERSPECTIVE)
// =============================================================================
// Converted from AI-transcribed Part3_Phoenix.txt
// NOTE: This file was AI-transcribed and may contain errors or misinterpretations
// Frame numbers estimated from timestamps, names inferred from context
// Uncertain corrections are marked with comments

#include "structures.h"

// Character constants (based on authoritative files)
#define PP_PHOENIX      1   // Phoenix Wright
#define PP_MIA          2   // Mia Fey
#define PP_RAINBOW      3   // Rainbow Dash
#define PP_PINKIE       4   // Pinkie Pie
#define PP_GUARD        5   // Guards
#define PP_SONATA       6   // Sonata Dusk
#define PP_NONE         0   // No character

// Command constants
#define CMD_NONE            0x0000
#define CMD_BLACK           0x0001  // Screen transition
#define CMD_PHOENIX_OBJECTION 0x0002 // Phoenix objection animation
#define CMD_TAKETHAT        0x0003  // Take That animation
#define CMD_BREAKLOCK       0x0004  // Psyche-Lock break
#define CMD_GUNSHOT         0x0005  // Gunshot sound effect
#define CMD_PARTY_HORN      0x0006  // Party horn sound

// Evidence constants
#define EV_NONE         0   // No evidence

// Phoenix Wright: Turnabout Storm - Part 3 (Phoenix Perspective)
typedef struct {
    int evidence;
    int frame;
    int character;
    char text[512];
} GameLine;

GameLine part3_phoenix_lines[] = {

// =============================================================================
// FLASHBACK SEQUENCE: MIA'S GUIDANCE TO YOUNG PHOENIX
// =============================================================================
// Frame numbers estimated from 00:00:00.00 timestamps (30fps conversion)

    // PHOENIX'S NERVOUS PREPARATION
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "My name is Phoenix Wright and I'm fine!"},
    {EV_NONE, 253, PP_PHOENIX | CMD_NONE, "My name is Phoenix Wright and I'm fine!"}, // 00:00:08.44
    {EV_NONE, 374, PP_PHOENIX | CMD_NONE, "My name is Phoenix Wright and I'm fine!"}, // 00:00:12.48

    // MIA'S ENTRANCE AND CONCERN
    {EV_NONE, 495, PP_MIA | CMD_NONE, "Phoenix, are you okay?"}, // 00:00:16.52
    {EV_NONE, 556, PP_PHOENIX | CMD_NONE, "Oh, hey Chief. I was just practicing for my very first trial, which is tomorrow."}, // 00:00:18.56
    {EV_NONE, 678, PP_PHOENIX | CMD_NONE, "The guys back at law school said this tape would really help me out."}, // 00:00:22.60
    {EV_NONE, 799, PP_MIA | CMD_NONE, "Oh, thank goodness! When I heard all the screeching coming from the office, I thought someone was murdering you!"}, // 00:00:26.64

    // PHOENIX'S MISHEARD STATEMENT
    // NOTE: AI likely misheard "objection" as "dead at four" - uncertain correction
    {EV_NONE, 1009, PP_PHOENIX | CMD_NONE, "That wasn't screeching, I was dead at four!"}, // 00:00:33.64 - UNCERTAIN: possibly "objection" misheard

    // MIA'S REASSURANCE AND INQUIRY
    {EV_NONE, 1120, PP_MIA | CMD_NONE, "I don't think you need this exercise tape. I'm sure you'll do just fine. The suspect, he's your friend, right?"}, // 00:00:37.64
    {EV_NONE, 1399, PP_PHOENIX | CMD_NONE, "Yeah, he's my friend, but..."}, // 00:00:46.64
    {EV_NONE, 1489, PP_MIA | CMD_NONE, "But...what?"}, // 00:00:49.64
    {EV_NONE, 1519, PP_PHOENIX | CMD_NONE, "He's...well..."}, // 00:00:51.64
    {EV_NONE, 1579, PP_MIA | CMD_NONE, "Yes?"}, // 00:00:53.64
    {EV_NONE, 1609, PP_PHOENIX | CMD_NONE, "He's...well..."}, // 00:00:55.64 - NOTE: Likely incomplete/cut off
    {EV_NONE, 1769, PP_MIA | CMD_NONE, "That's not a very nice thing to say about your friend."}, // 00:00:58.64

    // PHOENIX'S CONCERNS ABOUT HIS CLIENT
    {EV_NONE, 1961, PP_PHOENIX | CMD_NONE, "No, I really mean it. He thinks passing the eighth grade is a credential. Even got the report card framed and everything."}, // 00:01:05.44
    {EV_NONE, 2035, PP_MIA | CMD_NONE, "So, what are you getting at?"}, // 00:01:07.94
    {EV_NONE, 2238, PP_PHOENIX | CMD_NONE, "I mean, what if he really did kill that woman? What do I do? Do I still lie and try to defend them? Or do I side with justice and let him be punished?"}, // 00:01:17.54

    // MIA'S PHILOSOPHICAL GUIDANCE
    {EV_NONE, 2326, PP_MIA | CMD_NONE, "Phoenix."}, // 00:01:17.54
    {EV_NONE, 2422, PP_MIA | CMD_NONE, "Don't stress yourself out so much."}, // 00:01:20.74
    {EV_NONE, 2497, PP_MIA | CMD_NONE, "Tell me, what do you think?"}, // 00:01:23.24
    {EV_NONE, 2572, PP_PHOENIX | CMD_NONE, "Me?"}, // 00:01:26.24
    {EV_NONE, 2602, PP_MIA | CMD_NONE, "What do you mean?"}, // 00:01:27.24
    {EV_NONE, 2722, PP_MIA | CMD_NONE, "You, as Phoenix Wright, not as a defense attorney."}, // 00:01:29.24
    {EV_NONE, 2827, PP_MIA | CMD_NONE, "Do you think your friend killed that woman?"}, // 00:01:33.24

    // PHOENIX'S INSTINCTUAL TRUST
    {EV_NONE, 3013, PP_PHOENIX | CMD_NONE, "He might not be the sharpest tool in the shed, but I don't think he has venom to kill anyone."}, // 00:01:36.24 - NOTE: "venom" unusual word choice, possibly AI error
    {EV_NONE, 3073, PP_MIA | CMD_NONE, "There you go."}, // 00:01:41.24
    {EV_NONE, 3088, PP_PHOENIX | CMD_NONE, "Huh?"}, // 00:01:42.74
    {EV_NONE, 3103, PP_MIA | CMD_NONE, "Go off that."}, // 00:01:43.74
    {EV_NONE, 3133, PP_MIA | CMD_NONE, "You have to believe in him. It's your job too."}, // 00:01:45.24

    // THE CORE LESSON: PURSUE THE TRUTH
    {EV_NONE, 3262, PP_MIA | CMD_NONE, "Cast all that doubt aside and pursue that truth."}, // 00:01:48.74
    {EV_NONE, 3391, PP_MIA | CMD_NONE, "If you do that, nothing can stop you."}, // 00:01:52.96
    {EV_NONE, 3421, PP_PHOENIX | CMD_NONE, "The truth, huh?"}, // 00:01:55.70
    {EV_NONE, 3496, PP_PHOENIX | CMD_NONE, "Thanks, Chief."}, // 00:01:58.16
    {EV_NONE, 3556, PP_PHOENIX | CMD_NONE, "I'm still a little nervous, though."}, // 00:01:59.50
    {EV_NONE, 3671, PP_MIA | CMD_NONE, "Don't worry, we all go through it."}, // 00:02:01.86

    // WINSTON PAYNE REVELATION
    {EV_NONE, 3691, PP_PHOENIX | CMD_NONE, "Hey, um..."}, // 00:02:04.30
    {EV_NONE, 3742, PP_PHOENIX | CMD_NONE, "Do you by any chance know who the prosecutor is?"}, // 00:02:05.56
    {EV_NONE, 3846, PP_MIA | CMD_NONE, "The prosecutor?"}, // 00:02:08.46
    {EV_NONE, 3912, PP_MIA | CMD_NONE, "I believe it's Winston Payne."}, // 00:02:10.40
    {EV_NONE, 3993, PP_MIA | CMD_NONE, "You know, the rookie killer."}, // 00:02:13.10
    {EV_NONE, 4046, PP_PHOENIX | CMD_NONE, "For rookie killer?"}, // 00:02:16.46 - NOTE: Grammar suggests "The" rookie killer
    {EV_NONE, 4076, PP_PHOENIX | CMD_NONE, "I don't like the sound of that title."}, // 00:02:17.86
    {EV_NONE, 4136, PP_MIA | CMD_NONE, "Not many rookies take the prosecutor into consideration."}, // 00:02:20.36
    {EV_NONE, 4196, PP_MIA | CMD_NONE, "Why did you want to know something like that?"}, // 00:02:24.36
    {EV_NONE, 4256, PP_PHOENIX | CMD_NONE, "Uh, no reason. I was just curious."}, // 00:02:26.86
    {EV_NONE, 4316, PP_MIA | CMD_NONE, "You seem more disappointed than curious."}, // 00:02:29.86
    {EV_NONE, 4376, PP_PHOENIX | CMD_NONE, "Ah, forget about it. I'm just a little out of it right now."}, // 00:02:33.36

// =============================================================================
// PRESENT DAY: PHOENIX'S REGRET AND ISOLATION
// =============================================================================

    // PHOENIX'S GUILT OVER THE TRIAL
    {EV_NONE, 4526, PP_PHOENIX | CMD_NONE, "I'll never forget what you taught me."}, // 00:02:41.86
    {EV_NONE, 4616, PP_PHOENIX | CMD_NONE, "But somehow, I highly doubt you're looking down on me smiling after what I did today."}, // 00:02:44.36

    // SILENCE/PAUSE
    {EV_NONE, 5010, PP_NONE | CMD_NONE, "*"}, // 00:02:50.36 - Note: asterisk likely represents pause/silence

    // PHOENIX'S DESPAIR MONOLOGUE
    {EV_NONE, 5472, PP_PHOENIX | CMD_NONE, "She's gone. Who am I kidding? She's right! I did absolutely terrible in there! Now two of her friends are suspects."}, // 00:03:02.36
    {EV_NONE, 5742, PP_PHOENIX | CMD_NONE, "I do now. I don't have any leads at all. Nobody to turn to. I'm all by myself. Which means"}, // 00:03:12.36 - NOTE: "I do now" seems disconnected
    {EV_NONE, 5880, PP_PHOENIX | CMD_NONE, "I can't even get back home. No, I can't think that way. I've got to stay diligent. I said"}, // 00:03:19.60
    {EV_NONE, 6111, PP_PHOENIX | CMD_NONE, "I'd clear Rainbow Dash's name, and I bought her another day. I can't let it go to waste."}, // 00:03:27.70
    {EV_NONE, 6181, PP_PHOENIX | CMD_NONE, "But where do I start?"}, // 00:03:33.36

// =============================================================================
// PINKIE PIE ENCOUNTER: UNEXPECTED HELP ARRIVES
// =============================================================================

    // PINKIE'S ARRIVAL
    {EV_NONE, 6211, PP_PINKIE | CMD_NONE, "Hey, Mr. Frowny-Wowny! What's the matter?"}, // 00:03:36.36
    {EV_NONE, 6331, PP_PHOENIX | CMD_NONE, "Where did she come from? She smells like a cotton candy."}, // 00:03:40.36 - NOTE: Should be "cotton candy"
    {EV_NONE, 6464, PP_PINKIE | CMD_NONE, "Cotton candy? Oh, you must know the new shampoo I'm using."}, // 00:03:44.86
    {EV_NONE, 6516, PP_PHOENIX | CMD_NONE, "Eh, that explains it then."}, // 00:03:49.36
    {EV_NONE, 6571, PP_PHOENIX | CMD_NONE, "Wait, did I just say that or think that... who are you?"}, // 00:03:51.36

    // PINKIE'S INTRODUCTION
    // NOTE: AI transcribed as "Pinky Pie" but should be "Pinkie Pie" based on authoritative files
    {EV_NONE, 6776, PP_PINKIE | CMD_NONE, "I'm Pinky Pie, of course. Party throw extraordinaire."}, // 00:03:56.36 - CORRECTED: "Pinkie Pie" and "throwing"
    {EV_NONE, 6841, PP_PINKIE | CMD_NONE, "But I can't talk right now. I'm looking for something."}, // 00:04:00.36
    {EV_NONE, 6871, PP_PHOENIX | CMD_NONE, "What for?"}, // 00:04:04.36

    // THE SPIKY-HEADED MONSTER SEARCH
    {EV_NONE, 7048, PP_PINKIE | CMD_NONE, "Some other ponies said there was a spiky-headed monster in here."}, // 00:04:05.86
    {EV_NONE, 7132, PP_PINKIE | CMD_NONE, "I didn't seem to find it anywhere, though."}, // 00:04:08.64
    {EV_NONE, 7166, PP_PINKIE | CMD_NONE, "You'd think it'd stick out like a sore hoof."}, // 00:04:10.56
    {EV_NONE, 7194, PP_PINKIE | CMD_NONE, "Have you seen it?"}, // 00:04:12.44

    // PHOENIX'S REALIZATION AND FRUSTRATION
    {EV_NONE, 7220, PP_PHOENIX | CMD_NONE, "[Sigh]"}, // 00:04:14.20 - NOTE: Likely Phoenix sighing
    {EV_NONE, 7246, PP_PINKIE | CMD_NONE, "Does that mean... no?"}, // 00:04:15.70
    {EV_NONE, 7253, PP_NONE | CMD_GUNSHOT, "[GUNSHOT]"}, // 00:04:17.46 - NOTE: Sound effect
    {EV_NONE, 7268, PP_PHOENIX | CMD_NONE, "I'm getting so sick of this place!"}, // 00:04:18.12

    // PINKIE'S ENCOURAGEMENT
    {EV_NONE, 7276, PP_PINKIE | CMD_NONE, "Hey!"}, // 00:04:20.16
    {EV_NONE, 7312, PP_PINKIE | CMD_NONE, "Turn that Frowly upside downy!"}, // 00:04:21.16 - NOTE: "Frowny" corrected from "Frowly"
    {EV_NONE, 7324, PP_PHOENIX | CMD_NONE, "How can I?"}, // 00:04:23.94
    {EV_NONE, 7354, PP_PHOENIX | CMD_NONE, "I did such a lousy job in court today."}, // 00:04:25.20

    // TWILIGHT MENTION AND CONNECTION
    {EV_NONE, 7392, PP_PHOENIX | CMD_NONE, "And Twilight probably hates my guts for what I did."}, // 00:04:27.92
    {EV_NONE, 7414, PP_PINKIE | CMD_NONE, "Hey, you know Twilight? Me too!"}, // 00:04:30.90
    {EV_NONE, 7464, PP_PHOENIX | CMD_NONE, "You know Twilight Sparkle?"}, // 00:04:33.34
    {EV_NONE, 7479, PP_PINKIE | CMD_NONE, "Yep, we're the bestest of best friends."}, // 00:04:34.88

    // PINKIE'S COURT MISSION
    // NOTE: "Cork's danger" is likely AI misinterpretation - possibly "court" or similar
    {EV_NONE, 7531, PP_PINKIE | CMD_NONE, "Oh, that reminds me, I'm supposed to go to Cork's danger for Rainbow Dash!"}, // 00:04:37.30 - UNCERTAIN: "Cork's danger"
    {EV_NONE, 7562, PP_PINKIE | CMD_NONE, "Sorry, better run!"}, // 00:04:41.06
    {EV_NONE, 7594, PP_PHOENIX | CMD_NONE, "But you're..."}, // 00:04:42.36
    {EV_NONE, 7616, PP_PINKIE | CMD_NONE, "Oh, I'm already here. Yee!"}, // 00:04:43.86
    {EV_NONE, 7646, PP_PHOENIX | CMD_NONE, "I hate to break it to you, but you missed the trial."}, // 00:04:46.88

    // PHOENIX'S INNER THOUGHTS ON PINKIE
    {EV_NONE, 7734, PP_PHOENIX | CMD_NONE, "Out of all the pastel grass chewers I've met, this one is definitely the weirdest."}, // 00:04:49.88
    {EV_NONE, 7868, PP_PHOENIX | CMD_NONE, "Ah, I better be careful. I think she can read minds."}, // 00:04:54.38

    // RAINBOW DASH'S SITUATION UPDATE
    {EV_NONE, 7898, PP_PINKIE | CMD_NONE, "Is that you okay?"}, // 00:04:58.88 - NOTE: Grammar error likely "Are you okay?"
    {EV_NONE, 8011, PP_PHOENIX | CMD_NONE, "For the time being, yes. The trial is being postponed."}, // 00:05:00.38
    {EV_NONE, 8131, PP_PHOENIX | CMD_NONE, "I'm actually Rainbow Dash's lawyer. Phoenix right."}, // 00:05:04.36 - NOTE: Should be "Phoenix Wright"

    // PINKIE'S NICKNAME FOR PHOENIX
    {EV_NONE, 8166, PP_PINKIE | CMD_NONE, "Ooo! Needo! So, whatcha doin' right now, Feeny?"}, // 00:05:07.56 - NOTE: "Needo" unclear, "Feenie" nickname
    {EV_NONE, 8406, PP_PHOENIX | CMD_NONE, "Feeny? That's..."}, // 00:05:13.36 - NOTE: "Feenie"
    {EV_NONE, 8616, PP_PHOENIX | CMD_NONE, "Nevermind. Well, I don't know what I should be doing right now, to be honest. I have no leads at all."}, // 00:05:16.36

    // PINKIE'S ADVICE AND PSYCHE-LOCKS MENTION
    {EV_NONE, 8686, PP_PINKIE | CMD_NONE, "Why don't you go talk to Dashie about the trial?"}, // 00:05:23.86
    {EV_NONE, 8721, PP_PHOENIX | CMD_NONE, "Wait a minute. She had cyclocks!"}, // 00:05:27.06 - NOTE: "Psyche-Locks" mispronounced
    {EV_NONE, 8781, PP_PINKIE | CMD_NONE, "Cyclocks? Is that some kind of breakfast cereal? Sounds yummy!"}, // 00:05:29.86
    {EV_NONE, 8841, PP_PHOENIX | CMD_NONE, "Is it me with real locks, not merciful, is he artificial locks?"}, // 00:05:33.36 - UNCERTAIN: Garbled text about locks
    {EV_NONE, 8901, PP_PHOENIX | CMD_NONE, "Thanks for the advice, um... Pinkie Pie."}, // 00:05:36.86
    {EV_NONE, 8941, PP_PHOENIX | CMD_NONE, "I'm gonna go to the detention center now."}, // 00:05:40.36

// =============================================================================
// DETENTION CENTER: RAINBOW DASH'S BREAKDOWN
// =============================================================================

    // TRANSITION TO DETENTION CENTER
    {EV_NONE, 9246, PP_PHOENIX | CMD_NONE, "I really hope she isn't mad at me after what happened."}, // 00:05:50.86

    // RAINBOW DASH'S DESPAIR
    {EV_NONE, 9316, PP_RAINBOW | CMD_NONE, "No, no, no, no, no, no, no, no!"}, // 00:05:53.86
    {EV_NONE, 9348, PP_PHOENIX | CMD_NONE, "Rainbow Dash?"}, // 00:05:58.16
    {EV_NONE, 9528, PP_RAINBOW | CMD_NONE, "I can't bear to live anymore. Throw the book at me. Let them send me to the sun. There's nothing left for me in Equestria."}, // 00:06:01.16

    // PHOENIX'S ATTEMPT TO COMFORT
    {EV_NONE, 9798, PP_PHOENIX | CMD_NONE, "Rainbow Dash, get a hold of yourself. She must still be upset over those pictures."}, // 00:06:09.16

    // RAINBOW'S CAREER CONCERNS
    // NOTE: "Winterbolts" unclear - possibly "Wonderbolts" (elite flying team in MLP)
    {EV_NONE, 10068, PP_RAINBOW | CMD_NONE, "Easy for you to say. Now the Winterbolts will never let me in. Ponyville is gonna laugh at me forever!"}, // 00:06:16.16 - UNCERTAIN: "Winterbolts" vs "Wonderbolts"

    // PHOENIX'S REASSURANCE ATTEMPT
    {EV_NONE, 10246, PP_PHOENIX | CMD_NONE, "They weren't that, um, bad."}, // 00:06:23.16
    {EV_NONE, 10336, PP_PHOENIX | CMD_NONE, "Really? I'm sure everyone will forget by tomorrow. I guarantee it."}, // 00:06:27.16
    {EV_NONE, 10396, PP_PHOENIX | CMD_NONE, "There's no way anyone's forgetting images like those."}, // 00:06:32.16 - NOTE: Phoenix's internal thoughts

    // RAINBOW'S SLIGHT HOPE AND PHOENIX'S BAD JOKE
    {EV_NONE, 10516, PP_RAINBOW | CMD_NONE, "You think so?"}, // 00:06:37.16
    {EV_NONE, 10666, PP_PHOENIX | CMD_NONE, "I know so. I'm always right. My name is Phoenix, right after all."}, // 00:06:39.16 - NOTE: "Wright" pun

    // AWKWARD SILENCE AND CRITICISM
    {EV_NONE, 10816, PP_RAINBOW | CMD_NONE, "That wasn't funny."}, // 00:06:47.16
    {EV_NONE, 10846, PP_PHOENIX | CMD_NONE, "I thought it was."}, // 00:06:50.16

    // RAINBOW'S GRATITUDE AND CRITICISM
    {EV_NONE, 10966, PP_RAINBOW | CMD_NONE, "Thanks for trying to cheer me up though. I appreciate it."}, // 00:06:52.16
    {EV_NONE, 11011, PP_PHOENIX | CMD_NONE, "You're welcome."}, // 00:06:56.02
    {EV_NONE, 11047, PP_RAINBOW | CMD_NONE, "By the way..."}, // 00:06:57.36
    {EV_NONE, 11080, PP_PHOENIX | CMD_NONE, "Yes? What is it?"}, // 00:06:58.72

    // RAINBOW'S HARSH CRITIQUE OF PHOENIX'S PERFORMANCE
    {EV_NONE, 11340, PP_RAINBOW | CMD_NONE, "What was that terrible bad performance in the court today? I could have done a better job defending myself!"}, // 00:07:00.38
    {EV_NONE, 11428, PP_PHOENIX | CMD_NONE, "I... I..."}, // 00:07:06.28

    // NOTE: "Anthony Defense Attorney" is likely AI error for "Every Defense Attorney"
    {EV_NONE, 11632, PP_RAINBOW | CMD_NONE, "Anthony Defense Attorney must have hoarse apples if you're supposed to be the best one."}, // 00:07:08.52 - UNCERTAIN: "Every" vs "Anthony"
    {EV_NONE, 11776, PP_PHOENIX | CMD_NONE, "Look, I know I screwed up. But I'm gonna make it up to you and Fluttershy tomorrow."}, // 00:07:13.84

    // RAINBOW'S ANGER TOWARD FLUTTERSHY
    {EV_NONE, 11920, PP_RAINBOW | CMD_NONE, "Fluttershy? She got what she deserved after she betrayed me like that!"}, // 00:07:18.80
    {EV_NONE, 12180, PP_PHOENIX | CMD_NONE, "Hey! It tore me up having to do that! It was the only way I could save you! Fluttershy didn't betray you!"}, // 00:07:24.40

    // NOTE: "sorry freak" likely error for "sorry flank" (pony anatomy term)
    {EV_NONE, 12280, PP_RAINBOW | CMD_NONE, "Give me a break! This is the things I get for all the times I stuck up for her sorry freak!"}, // 00:07:31.40 - UNCERTAIN: "flank" vs "freak"
    {EV_NONE, 12340, PP_PHOENIX | CMD_NONE, "She was just telling the truth."}, // 00:07:37.10
    {EV_NONE, 12400, PP_RAINBOW | CMD_NONE, "True? You proved she was lying though! She didn't see Applebloom!"}, // 00:07:39.60
    {EV_NONE, 12520, PP_PHOENIX | CMD_NONE, "But she did see you leave the forest."}, // 00:07:45.20
    {EV_NONE, 12564, PP_PHOENIX | CMD_NONE, "You were there, weren't you?"}, // 00:07:47.64

    // RAINBOW'S CONTINUED ANGER
    {EV_NONE, 12668, PP_RAINBOW | CMD_NONE, "Whatever! We are ex-friends as of now."}, // 00:07:50.68

    // NOTE: "crummy jog" likely "crummy job"
    {EV_NONE, 12828, PP_RAINBOW | CMD_NONE, "I can tell you were trying your hardest to defend me, even if you did do a crummy jog."}, // 00:07:53.84 - CORRECTED: "job"
    {EV_NONE, 12872, PP_PHOENIX | CMD_NONE, "Gee, thanks."}, // 00:07:58.96 - NOTE: Sarcastic
    {EV_NONE, 13016, PP_RAINBOW | CMD_NONE, "She pretty much said, \"Yup, Rainbow Dash did it!\""}, // 00:08:01.16
    {EV_NONE, 13040, PP_RAINBOW | CMD_NONE, "What kind of a friend does that?"}, // 00:08:04.20
    {EV_NONE, 13224, PP_PHOENIX | CMD_NONE, "Rainbow Dash, for the last time she was telling the truth, what she saw."}, // 00:08:07.24

    // TRANSITION TO INVESTIGATION PURPOSE
    {EV_NONE, 13288, PP_PHOENIX | CMD_NONE, "Actually, that brings me to why I'm here."}, // 00:08:12.08
    {EV_NONE, 13356, PP_RAINBOW | CMD_NONE, "What? Why are you here?"}, // 00:08:14.56
    {EV_NONE, 13506, PP_PHOENIX | CMD_NONE, "The truth. I want to know what you were really doing near the Everfree Forest the night of the murder."}, // 00:08:18.56

// =============================================================================
// PSYCHE-LOCK INVESTIGATION: BREAKING RAINBOW'S SECRETS
// =============================================================================

    // MAGATAMA ACTIVATION
    {EV_NONE, 13556, PP_PHOENIX | CMD_TAKETHAT, "Take that!"}, // 00:08:24.56

    // FIRST LOCK: "I was practicing for the race"
    {EV_NONE, 13676, PP_RAINBOW | CMD_NONE, "Ugh, I told you already. I was practicing for the race."}, // 00:08:29.56
    {EV_NONE, 13736, PP_PHOENIX | CMD_NONE, "It still works after that incident this morning."}, // 00:08:34.56 - NOTE: Internal thought about Magatama
    {EV_NONE, 13766, PP_PHOENIX | CMD_NONE, "Huh?"}, // 00:08:38.56
    {EV_NONE, 13886, PP_PHOENIX | CMD_NONE, "What the..."}, // 00:08:42.56
    {EV_NONE, 13916, PP_PHOENIX | CMD_NONE, "What was that all about anyway?"}, // 00:08:43.56
    {EV_NONE, 13996, PP_PHOENIX | CMD_NONE, "Ugh, forget about that. It still works and that's all that matters."}, // 00:08:47.56
    {EV_NONE, 14056, PP_PHOENIX | CMD_NONE, "Okay, there they are. Time to break 'em."}, // 00:08:52.56
    {EV_NONE, 14206, PP_PHOENIX | CMD_NONE, "Sorry, but I don't believe you, my little pony. Not for a single solitary second."}, // 00:08:56.56
    {EV_NONE, 14276, PP_RAINBOW | CMD_NONE, "You're my lawyer and you don't believe me? That's reassuring."}, // 00:09:02.56

    // THE PSYCHE-LOCK GAME BEGINS
    {EV_NONE, 14556, PP_PHOENIX | CMD_NONE, "Let's play a game, Rainbow Dash. I'm gonna guess what you were really doing near the crime scene that night, and you're gonna tell me if I'm right."}, // 00:09:07.56
    {EV_NONE, 14586, PP_PHOENIX | CMD_NONE, "if I'm right."}, // 00:09:12.56 - NOTE: Duplicate line
    {EV_NONE, 14616, PP_RAINBOW | CMD_NONE, "I can go right ahead and do that, but I'm sticking to my story."}, // 00:09:13.66
    {EV_NONE, 14736, PP_PHOENIX | CMD_NONE, "I don't think you were practicing at all."}, // 00:09:17.66
    {EV_NONE, 14826, PP_PHOENIX | CMD_NONE, "I think you were doing something far more important."}, // 00:09:20.76
    {EV_NONE, 14856, PP_RAINBOW | CMD_NONE, "Like what?"}, // 00:09:23.76
    {EV_NONE, 14916, PP_PHOENIX | CMD_NONE, "Like, oh, I don't know, meeting someone?"}, // 00:09:25.76
    {EV_NONE, 14946, PP_RAINBOW | CMD_NONE, "Ugh!"}, // 00:09:28.76

    // FIRST LOCK STARTING TO CRACK
    {EV_NONE, 15056, PP_RAINBOW | CMD_NONE, "Uh, uh, I mean, who would I be meeting in the middle of the forest at that hour?"}, // 00:09:30.76
    {EV_NONE, 15146, PP_RAINBOW | CMD_NONE, "No pony ever goes in there willingly."}, // 00:09:36.76
    {EV_NONE, 15246, PP_PHOENIX | CMD_NONE, "Then why were you practicing there if no one ever goes in there willingly?"}, // 00:09:39.76
    {EV_NONE, 15336, PP_RAINBOW | CMD_NONE, "Uh... uh... whoa..."}, // 00:09:44.76 - NOTE: Shows nervousness
    {EV_NONE, 15396, PP_PHOENIX | CMD_NONE, "I know there was someone in the forest the night of the murder."}, // 00:09:48.76
    {EV_NONE, 15456, PP_RAINBOW | CMD_NONE, "Put your money where your mouth is! Who do you think I was meeting?"}, // 00:09:52.76

    // EVIDENCE PRESENTATION: ACE SWIFT
    {EV_NONE, 15696, PP_PHOENIX | CMD_NONE, "A-Swift! The fact your feathers were found all around the clearing proves you were there that night."}, // 00:09:56.76 - NOTE: "Ace Swift"
    {EV_NONE, 15936, PP_PHOENIX | CMD_NONE, "And who else was in the clearing that night? The victim, of course! You needed to be there to see him."}, // 00:10:03.76
    {EV_NONE, 15968, PP_PHOENIX | CMD_NONE, "see him. You also just told me ponies avoid going in there, so I'm willing to bet he"}, // 00:10:08.76 - NOTE: Sentence continues
    {EV_NONE, 15988, PP_PHOENIX | CMD_NONE, "We wanted to meet with you in private."}, // 00:10:14.28 - NOTE: Should be "he wanted"
    {EV_NONE, 16032, PP_PHOENIX | CMD_NONE, "What better place to pick than the middle of a forest nobody ever goes into?"}, // 00:10:16.32

    // FIRST PSYCHE-LOCK BREAKS
    {EV_NONE, 16092, PP_RAINBOW | CMD_NONE, "Ah! No!"}, // 00:10:20.52
    {EV_NONE, 16212, PP_RAINBOW | CMD_NONE, "I mean..."}, // 00:10:25.22 - NOTE: Lock breaking sound would occur here
    {EV_NONE, 16252, PP_RAINBOW | CMD_NONE, "Ah, no! You're wrong!"}, // 00:10:26.52

    // SECOND LOCK: "He was just competition"
    {EV_NONE, 16312, PP_RAINBOW | CMD_NONE, "He was just competition!"}, // 00:10:29.12
    {EV_NONE, 16342, PP_RAINBOW | CMD_NONE, "Why would I want to meet him?"}, // 00:10:31.42
    {EV_NONE, 16392, PP_RAINBOW | CMD_NONE, "I have better things I could be doing."}, // 00:10:33.02
    {EV_NONE, 16432, PP_PHOENIX | CMD_NONE, "Like what?"}, // 00:10:35.62
    {EV_NONE, 16512, PP_RAINBOW | CMD_NONE, "I don't know, napping?"}, // 00:10:37.02
    {EV_NONE, 16542, PP_RAINBOW | CMD_NONE, "Something like that."}, // 00:10:39.42
    {EV_NONE, 16582, PP_PHOENIX | CMD_NONE, "Oh, please."}, // 00:10:41.82 - NOTE: Internal thought
    {EV_NONE, 16612, PP_PHOENIX | CMD_NONE, "Maybe he had something you wanted."}, // 00:10:43.52
    {EV_NONE, 16672, PP_RAINBOW | CMD_NONE, "What do you mean?"}, // 00:10:46.02
    {EV_NONE, 16872, PP_PHOENIX | CMD_NONE, "I'm saying maybe he had something important to you. Something you'd move heaven and earth for."}, // 00:10:47.52
    {EV_NONE, 16932, PP_RAINBOW | CMD_NONE, "I'm a pretty self satisfied pony. I've got everything I need."}, // 00:10:52.12
    {EV_NONE, 17052, PP_RAINBOW | CMD_NONE, "Well besides fortune and glory, and I don't think he could give those to me."}, // 00:10:56.12
    {EV_NONE, 17132, PP_RAINBOW | CMD_NONE, "What could he possibly have that I want?"}, // 00:11:00.62
    {EV_NONE, 17162, PP_PHOENIX | CMD_NONE, "I'm glad you asked that Rainbow Dash."}, // 00:11:03.42
    {EV_NONE, 17192, PP_RAINBOW | CMD_NONE, "You are?"}, // 00:11:05.62
    {EV_NONE, 17322, PP_PHOENIX | CMD_NONE, "There's one thing that you absolutely needed that I know he had."}, // 00:11:07.62
    {EV_NONE, 17452, PP_RAINBOW | CMD_NONE, "I'm afraid I don't know what you're talking about."}, // 00:11:11.92
    {EV_NONE, 17512, PP_PHOENIX | CMD_NONE, "The reason you went to go meet him is..."}, // 00:11:15.72

    // CRITICAL EVIDENCE: THE BLACKMAIL PHOTOS
    {EV_NONE, 0, PP_PHOENIX | CMD_TAKETHAT, "Take that!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "These!"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "AHHH!"},

    // CORRECTED: "Put those away before somepony sees them!" (AI transcribed "But those" and "some bony")
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Put those away before somepony sees them!"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Please!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Even right now, your anxiety shows you absolutely didn't want these pictures floating out and about."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Yes, yes, yes, you're right!"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I was meeting him about these!"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Can you please just put them away?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "NOW!"},

    // SECOND PSYCHE-LOCK BREAKS - THE MONEY QUESTION
    {EV_NONE, 0, PP_PHOENIX | CMD_BREAKLOCK, "(psyche-lock break sfx)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "This brings us to the money question."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Why did he have these pictures?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Who knows? He's dead. What a bummer. Guess we'll never know."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I actually think I know why."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "You do?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Yes. I can think of one reason why he'd want to meet you over pictures like these. He was blackmailing you, wasn't he?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Blackmail."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I'm willing to bet my attorney badge he wanted you to toss the Equestrian 500."},

    // CORRECTED: "ponies" from "Pony" (AI transcription error)
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I was told of ponies suspecting him of foul play in the wake of all his success. He was probably threatening you to let him win the race."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Wow."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Hmm?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "You're really good."},

    // THIRD PSYCHE-LOCK BREAKS - FULL CONFESSION
    {EV_NONE, 0, PP_NONE | CMD_BREAKLOCK, "(psyche-lock break sfx)"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "It's true. Ace was trying to force me to drop out of the Equestrian 500."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "How did it start?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I got home two days ago and saw this letter on my doorstep."},
    {EV_NONE, 0, PP_NONE | CMD_NONE, "(doorbell sfx)"},

    // CORRECTED: "Everfree Forest" from "Ever-Reeforce" and "8:35 PM" from "835"
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "\"I'll let your secret out if you don't drop out of the Equestrian 500. Meet in the Everfree Forest clearing 8:35 PM tonight for negotiations.\""},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "At first I didn't know what secret it was talking about."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "But attached to the message was one of those pictures."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "About those pictures? Why are you-"},

    // CORRECTED: "It's a hobby" from "It's Bobby" (AI transcription error)
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "It's a hobby, alright! I bet you have skeletons in your closet too, Mr. 20-something who plays with toys!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Okay, okay, I won't ask about them anymore. Do you have any idea how he got them, though?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I have no clue. My best guess is that the jerk was stalking me, trying to get dirt on me."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Rainbow Dash..."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Yes, what is it?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I want you to know that I trust you, and I'm going to need you to trust me when I ask you these next series of questions."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Huh?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I know you may be scared this will make you look guilty, but I know you're innocent."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I'm not scared!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Why did you move that cloud to the crime scene and set it off?"},
    {EV_NONE, 0, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "But... but... I... I didn't..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Please Rainbow Dash, you can trust me."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I won't think any differently of you in light of what you tell me."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I know you didn't kill him."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Okay, I'll tell you."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I did move the cloud there and I did set it off."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I just wanted to give him a scare, that's all."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "A scare?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "So you really did move the cloud over the forest clearing?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "As soon as I saw the requirements of the blackmail letter, I knew it was Ace and that all those rumors about him were true."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "He's a blackmailing cheater!"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "So I set up the cloud over the clearing earlier that day with the intent of declining his little offer."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "So you weren't gonna drop out in spite of him leaking the pictures?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "No way!"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I'm not gonna let some loser have his way with me, even if it meant those pictures getting out!"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I have too much pride for that!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I find that really admirable."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Hehe, thanks."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "This is also my first year competing in the race. I just reached the required age to participate."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I've been way too anxious to just drop out."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "R.B.D. spells victory!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "You sure you can take 500 miles? It's longer than it sounds, you know."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "There's some checkpoints along the track set up so the racers can have some R&R."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "But that's a little problem I keep having. There's no doubt I'm fast, but I tire out along the way."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I'm not used to flying that long."},

    // CORRECTED: "races" from "racers" (context error)
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "In races like these, you should pace yourself accordingly."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Don't go fast right from the start. Save all your energy for the home stretch."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Kind of like how I don't present all my evidence right from the start."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I'll try to keep that in mind."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "But let's get back on topic, shall we? I'm supposed to be your lawyer, not your coach."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Right."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Anyway, I wasn't planning on killing him. Just give him a bit of a startle."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "You know, just kicking some dirt in his face for messing with me."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "The cloud shoots a lightning bolt directly under it when activated."},

    // CORRECTED: Added missing "I mess around" from context
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I mess around with ponies by scaring them with clouds all the time, but I got an extra big one in his case to make the sound as loud as possible."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I guess it was a little dangerous getting one that big."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "So it didn't hit him when you set it off?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "No, I made sure it wasn't over him."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Even though it was really dark outside, like you said in the court today, I could see that the bolt didn't even come close to touching him."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "When the lightning bolt lit up the area, it made him scream like a little girl and left a really sissy look on his mug."},

    // CORRECTED: "You should have seen it" from "He should have seen it"
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "You should have seen it. It was priceless!"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Then I just hightailed it out of there as fast as I could!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(That's probably when Fluttershy saw her.)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Why didn't you tell anyone about this blackmail earlier?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I didn't want anypony to know about the blackmail..."},

    // CORRECTED: "they would wonder" from "I would wonder"
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Because, you know, they would wonder what he was blackmailing me with."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I see."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Then those pictures would get out...)"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "You believe me, right? He was absolutely fine when I left, I swear!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Yes, I believe you. Though more questions arise from this."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "More questions?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "How did he end up dead directly under the cloud?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I was trying desperately to convince the court it was the second bolt that killed him."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "That would make this all an accident, since you have no control over it."},

    // CORRECTED: "Lightning doesn't strike" from "Lanking doesn't strike"
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "But then we have that \"Lightning doesn't strike the same place twice!\" thing that Trixie was talking about."},

    // CORRECTED: "Pegasi" from "Pegasai" (proper plural form)
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "That's true. It's a new type of storm cloud the Pegasi are using to protect ponies from situations like this."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Since it can't hit the same place twice, they can just stand under a cloud after the first bolt."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "So the safest place is under the cloud."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "That's really something."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "The weather just works by itself where I live."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I kind of wish it worked that way here."},

    // CORRECTED: "Sonic Rainboom" and "Fantastic Filly Flash" from garbled versions
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I'd have a lot more free time on my hooves so I can perfect my Sonic Rainboom, or my Fantastic Filly Flash!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Are those dance moves or something?)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "From what I hear, you're also the weather manager."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I need some information regarding how the lightning here in Equestria works."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "What do you need to know?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Well, is it true the bolt causes the noise?"},

    // CORRECTED: "the boom" from "them boom"
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Yeah, it is. I don't know how it works exactly, but I'm pretty sure when it touches the ground or anything attached to the ground, like, say, a tree, it sends out vibrations which makes the boom."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(I'm no meteorologist, but I'm pretty sure lightning doesn't work like that.)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Then again, I keep forgetting I'm in a land full of magical talking ponies who can manually change weather.)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Is there anything that could prevent it from making a sound?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I suppose if it hit something small in the air that was close enough to the cloud..."},

    // CORRECTED: "it wouldn't make a sound" from "I wouldn't make a sound"
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Yeah, it wouldn't make a sound, and I know what you're thinking, but that couldn't happen."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Why not?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "That itchy racing suit."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Oh, right. I remember that being brought up."},

    // CORRECTED: "Pegasi" from "Pegasuses" (proper plural form)
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "That's that lightning-proof suit that you Pegasi wear for the race, right?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "The plural is \"Pegasi.\""},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I absolutely hate wearing that thing, but while in the air you're pretty much invulnerable to lightning."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Weren't there some exposed parts on it though?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Yes, there are, but while you're in the flying position those parts are covered up."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "They're only exposed while you're on all fours and grounded."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "This is sounding more and more hopeless for me the more I talk about it."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Try to cheer up. I'll find out what really happened and get you out of here."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Thank you, Nix."},

    // CORRECTED: "in light of" from "light of"
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Okay, Rainbow Dash. I'm gonna go do some more investigating in light of this new information."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Alright, catch you later."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Oh, wait! One more thing."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Yes?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Pinkie Pie. I bumped into her after the trial. I'm guessing she's a friend of yours."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "She wanted to cheer you on in court today, but sadly it seems she was late."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Is she always that... uh... loopy?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Yeah, that's just Pinkie Pie being Pinkie Pie."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Okay, just thought I'd let you know."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Well, goodbye, Rainbow Dash."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Wait!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Jeez, I just can't leave this place.)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Yes, what is it?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Here, take this."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "A key? What is it for?"},

    // CORRECTED: "Ace's hotel room" from "Aces hotel room"
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Ace's hotel room."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "What!? How did you get this!?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I was angry when I thought he was stalking me, so I snuck into his hotel room to find dirt on him."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "It was under the mat. What a stupid place to leave your key, huh?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Yeah... stupid place."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Note to self: put key to office in different hiding spot.)"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I wasn't able to find anything good in there, but maybe you can!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Where is the hotel?"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "He was staying in the \"Hay and Stay\" hotel while he was at Ponyville."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "It's a little past Sugar Cube Corner. Just have Twilight show you where it is."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Twilight..."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "What's the matter?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "O-oh, nothing. Thanks, Rainbow Dash. This will really help my investigation!"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Goodbye, Nix."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I promise I'll get you and Fluttershy out of this mess."},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "Fluttershy... I told you, I don't care about her!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(She's still really angry about that testimony Fluttershy gave.)"},
    {EV_NONE, 0, PP_RAINBOW | CMD_NONE, "I just know you'll find some super awesome evidence this time around!"},
    {EV_NONE, 0, PP_NONE | CMD_BLACK, ""},

// =============================================================================
// INVESTIGATION PLANNING: PHOENIX'S DILEMMA
// =============================================================================

    {EV_NONE, 0, PP_NONE | CMD_NONE, "Ponyville, June 10th, 12:30PM"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Okay, where should I go first? Back to the forest? Or to the hotel room?"},
    {EV_NONE, 0, PP_NONE | CMD_NONE, "Hello again!"},

    // CORRECTED: Added missing "It would be a" from context
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "It would be a lot easier to go to the forest, since I know the general direction and I might find some new clues with the sun out."},
    {EV_NONE, 0, PP_NONE | CMD_NONE, "Hello?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Then again, I already found a lot of evidence in the forest already."},

    // CORRECTED: "Knock, knock... Feenie!" from "Knock knock, see me!"
    {EV_NONE, 0, PP_NONE | CMD_NONE, "Knock, knock... Feenie!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Though, would going into his hotel room be considered breaking and entering?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I'll have a bit of trouble finding it without someone guiding me, anyway..."},
    {EV_NONE, 0, PP_NONE | CMD_PARTY_HORN, "(party horn sfx)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "AH!?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Got your attention now!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Oh, you're... Pinkie Pie."},

    // CORRECTED: "Yup-a-roonie" from "Yep, Peroony"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Yup-a-roonie! That's my name!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "What are you doing here?"},

    // CORRECTED: "waited for you" from "made it for you"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I followed you! The guards wouldn't let me in though, so I just talked with them while I waited for you!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Right boys?"},
    {EV_NONE, 0, PP_GUARD | CMD_NONE, "Oh, for the love of all things holy... please..."},
    {EV_NONE, 0, PP_GUARD | CMD_NONE, "Take her away..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Uh... why were you following me?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Cause I need help finding something..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Look, the spiky-headed monster they were talking about is-"},

    // CORRECTED: "Oh! I gave up trying to find that a long time ago" from fragmented version
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Oh! I gave up trying to find that a looooooong time ago, it's probably just somepony's overactive imagination!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I need to find something I lost about a week ago."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "What did you lose?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "It's a secret!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "So you want me to help you find something... but you won't tell me what it is...?"},

    // CORRECTED: "Correct-a-mundo!" from "Correct the window"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Correct-a-mundo!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "That makes no sense!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Wait a minute...)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Actually, uh, Pinkie Pie..."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Yes?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Do you know where \"Sugar Cube Corner\" is?"},

    // CORRECTED: "You want to go bake cupcakes" from "You wanna go big cupcakes"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "You want to go bake cupcakes with me at Sugar Cube Corner!"},

    // CORRECTED: "Mr and Mrs Cake" from "Mr. and Mrs. Pick"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Mr and Mrs Cake always let me help out, now I have an assistant! Yay!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "You know how to make cupcakes, right?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "It's okay if you can't, I can teach you if you don't know, it's really really REALLY easy."},

    // CORRECTED: Heavily garbled cupcake recipe - restored to readable form based on context
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "First-you-preheat-the-oven-to-350-degrees-and-line-the-cupcake-pans-with-paper-liners."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Then-you-toss-flour-sugar-baking-powder-and-salt-in-a-mixing-bowl."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Add-shortening-milk-and-vanilla-for-flavor-and-taste;"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I-personally-put-in-a-little-bit-of-candy-as-well-to-make-them-sweeter."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Beat-for-1-minute-then-scrape-the-side-of-the-bowl-with-a-spatula;"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "we-want-to-salvage-as-many-cupcakes-as-we-can-from-the-mix!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "That's not what I meant..."},

    // CORRECTED: "Hay and Stay" from "Hay-N-Stay"
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I was wondering if you knew where the \"Hay and Stay\" is. It's a hotel? I heard it was by there."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Of course I know how to make cupcakes; what does she think I am, a hobo?)"},

    // CORRECTED: "Yessiree!" from "Yes, to me!"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Yessiree! I know where it is!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I need someone to escort me; would you be willing to do that for me if I help you find your missing... thing?"},

    // CORRECTED: "Okie-dokie-loki!" from "Okey-dokey-lokey!"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Okie-dokie-loki! On one other condition!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Name it."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(This is going to be easier than I thought.)"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "You have to tell me..."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "a funny joke!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "W-what!? Why do I have to do that!?"},

    // CORRECTED: "party-pooper-frowny-stick-in-the-mud" from garbled version
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I don't want to hang out with some big party-pooper-frowny-stick-in-the-mud!"},

    // CORRECTED: "Show me you have a sense of humor, Feenie-weenie!" from garbled version
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Show me you have a sense of humor, Feenie-weenie!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Do I really have to do this?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Mmmm-hhhmmmmm!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Well, she seems really easy to impress anyway...)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Okay. This is a really good one, Pinkie Pie!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Tell me! Tell me!"},

    // CORRECTED: "Phoenix Wright" from "Phoenix Runt"
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Here goes! Why do they call me Phoenix Wright?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Hmmmm... I don't know. Why?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Because..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I'M ALWAYS \"WRIGHT\"!"},
    {EV_NONE, 0, PP_NONE | CMD_NONE, "(badumtish sfx)"},
    {EV_NONE, 0, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "That wasn't funny..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "..."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "So... do you have any better ones?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "... well, uh... This one time I cross-examined a parakeet! What's the deal with that!?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(This is a lot harder than I thought... I'm a lawyer, not a comedian!)"},

    // CORRECTED: "all right" pun preserved from "all right"
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Ummm... Did you know I had the entire left side of my body cut off once? Don't worry, I'm all \"Wright\" now..."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "..."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Oh hey, what's that!?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "This? It's my Equestria Attorney Badge. That's how I got in that detention center."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Wow, that is the girliest thing I've ever seen!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "That must have been why you were pretending to be so bad at telling a good joke!"},

    // CORRECTED: "To build up to flashing that ridiculous-looking thing" from garbled version
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "To build up to flashing that ridiculous-looking thing!"},

    // CORRECTED: "You sure are a knee-slapper, Feenie!" from "knee slapper, Phoebe"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "You sure are a knee-slapper, Feenie!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(I really feel like sobbing to myself in a dark corner right now...)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "So, will you show me where this hotel is, now?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "(* giggling uncontrollably *)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Pinkie?"},

    // CORRECTED: "Oh right! The hotel is THIS way!!" from "Oh, oh, right. The hotel is this way."
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Oh right! The hotel is THIS way!!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Hey! Wait up!"},
    {EV_NONE, 0, PP_NONE | CMD_BLACK, "Hay and Stay Hotel, June 10th, 12:53PM"},

    // CORRECTED: Added humming Phoenix Wright theme based on context
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "(* humming Phoenix Wright's theme *)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(That song she's humming sounds really, really familiar...)"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Lookie! Here's that room!"},

    // CORRECTED: Various fixes for hotel room entry
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Hmm... Do you think we'll get in trouble for going into his room without asking?"},

    // CORRECTED: "Don't be such a chicken, Feenie! Gimme that key!" from garbled version
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Don't be such a chicken, Feenie! Gimme that key!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "H-hey! We can't just-"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "We just stick it in here aaaand..."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "We're in!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Pinkie Pie, master of unlocking!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(I really hope I don't get sent to the sun for this...)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "So, this is Ace's room."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Seeing as he's dead, surely he won't mind if we look around?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "My name is Pinkie, not Shirley."},

    // CORRECTED: "What are we trying to find here anyway, Feenie?" from "Peony"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "What are we trying to find here anyway, Feenie? A magical stone? A secret chamber? A prisoner? A cup? Maybe something you ordered? Oatmeal?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Oatmeal? Why would anybody want to find oatmeal?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Duh... when they're hungry!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "No, Pinkie Pie, we're trying to find clues that relate to the crime."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "So... no oatmeal?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "No oatmeal."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I want to try and be out of here as fast as humanly possible, okay? I don't want to be caught by anyone."},

    // CORRECTED: "PONY-ly possible" from "humanly possible"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Alright! I'll try to be as fast as PONY-ly possible then!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Maybe it was a mistake, taking her in here with me...)"},

    // CORRECTED: "Look Feenie, a step-ladder!" from "Look, Phoebe"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Look Feenie, a step-ladder! Is that a clue?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "One, that's not a clue."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Two, that's not a step-ladder, it's a ladder."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "There's a difference?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "There's a BIG difference!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "A step-ladder has an A-frame that folds while a ladder is flat like that one."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I still don't see what the difference is... I mean, you still step on it, right? Wouldn't it be a STEP-ladder then?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "How can I put this in a way you'll understand...?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "It's like cupcakes and muffins."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Cupcakes and muffins?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Exactly. Both look kind of the same, but they're totally different, like ladders and step-ladders."},

    // CORRECTED: Complex garbled sentence about cupcakes and ladders
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Cupcakes have frosting on them, like how step-ladders have a folding frame, while muffins are usually plain, like the ladder is flat."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "OOHHH! I think I get it now! Like hacksaws and saws?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Why do they call it a hacksaw anyway?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "!!??"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I don't get it... it doesn't hack; hacking is what you do with daggers and axes."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "And knives!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Uhh... yeah..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Okay, seriously, she's freaking me out now.)"},

    // CORRECTED: "But you sure know a lot about ladders, Feenie!" from "Genie"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "But you sure know a lot about ladders, Feenie! Are you sure you're a lawyer and not actually a ladder connoisseur?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "It's just common sense!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I find it annoying that a lot of people don't know the difference between the two."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Wait a minute, wasn't the victim a Pegasus?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Why would he need a ladder anyway?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "He could just fly up and get the things he would need a ladder for."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Maybe he was superstitious and didn't want bad luck."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Keeping a ladder doesn't prevent bad luck..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "You GET bad luck for walking under a ladder."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "What about this? Is ripped-up paper good luck?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "It's a piece of ripped up paper..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Why would it be good luck?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(I need an aspirin...)"},

    // CORRECTED: "Guess you're right, it just says a bunch of mumbo-jumbo" from garbled version
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Guess you're right, it just says a bunch of mumbo-jumbo on it anyway."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "\"Mumbo-jumbo?\" Let me see it..."},

    // CORRECTED: "leave of absence" from "leaf of absence"
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "\"This is a letter stating my permanent leave of absence."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "After the Equestrian 500 is over, I can no longer work with you.\""},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "\"We made quite the team, but I-\""},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Then it cuts off. The rest must be on the other half!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Pinkie, you found a clue!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Is that good luck?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "No!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Well... yes!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Kinda!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Good job, Pinkie!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Yay!!"},
    {EV_NONE, 0, PP_NONE | CMD_NONE, "Someone was planning on quitting something after the Equestrian 500. The other half is missing."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "It would only make sense that Ace wrote this, since it's his room, but who was he writing it to?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Maybe he-"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "OH NO!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Shh! We aren't supposed to be in here, remember?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "What's the problem?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "My tail's twitching!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "So, my foot fell asleep. You don't see me freaking out."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Why is she hiding under that table?)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Pinkie Pie, stop fooling around and-"},
    {EV_NONE, 0, PP_NONE | CMD_NONE, "(crash sfx)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "OW!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "See? I warned you!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "W-what?!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "You didn't say anything was going to fall on my head!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Sure I did! I said my tail was twitching."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "That means something's gonna fall."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "That's ridiculous! You can't tell me you can make predictions like that based off body spasms."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "So what's that book say?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "You mean the thing that fell on my head?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "It seems like it's some sort of advanced spell book."},

    // CORRECTED: "Hey Feenie! Do you think that you can cast a spell!?" from "Phoebe"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Hey Feenie! Do you think that you can cast a spell!?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I can't since I'm an earth pony."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Of course not! I'm not a magician!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I can't even read it anyway."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I only know it's an advanced spell book because I saw Twilight reading a book just like it this morning, and I asked her what it was."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "The text isn't in English. The characters are in weird hieroglyphics like Twilight's book."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Huh? Look at this..."},

    // CORRECTED: "Continue from here, third line" from "Continue from here. Erg, why?"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "\"Continue from here, third line.\""},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Seems someone scribbled a note here."},

    // CORRECTED: "You can get in big trouble for writing in hotel's books" from "fake trouble"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "You can get in big trouble for writing in hotel's books like that!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "No, I don't think this is the hotel's book."},

    // CORRECTED: "Canterlot" location name from fragmented version
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Twilight said these advanced spell books are only available in Ca..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Can..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I forget the name, starts with a hard \"C\" if I recall..."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Cookie?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "No."},

    // CORRECTED: "Carrot" from "Parrot"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Carrot?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "No..."},

    // CORRECTED: "Corkscrew" from "Heart screw"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Corkscrew?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "No... just stop guessing. The point is, this must be someone's personal book..."},
    {EV_NONE, 0, PP_NONE | CMD_NONE, "A book found in the victim's hotel room. Small note scribbled on one of the pages."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I better put it back on the shelf."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "It was all the way up there."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I can reach it."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Almost got it."},
    {EV_NONE, 0, PP_NONE | CMD_NONE, "(rip sfx)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "AH!!!!!!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "NOOOOOOOOOOoooOOO!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Didn't you just tell me to be quiet a second ago?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Practice what you preach!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I ripped my suit!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "You're right; you have a big hole in your armpit!"},

    // CORRECTED: "Should have used the stepladder" from "You can step ladder"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Should have used the stepladder instead of reaching so high."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "It's a ladder!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "You don't realize how bad this is!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I can't walk around with a big rip in my suit!"},

    // CORRECTED: "No use crying over spilled milk! Or ripped armpits!" from garbled version
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "No use crying over spilled milk! Or ripped armpits!"},

    // CORRECTED: "Lookie! It's Rainbow Dash!" from "Looky, it's Remo Dash!"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Lookie! It's Rainbow Dash!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Huh? Where?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Right here on the table!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Well, it's her name alright..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "What is this? It looks like some kind of list."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Maybe it's a party invite!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Do you know who these other names are, Pinkie?"},

    // CORRECTED: "on here I recognize" from "I hear I recognize"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Nope, doesn't ring any bells."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "\"Rainbow Dash\" is the only name on here I recognize..."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Uh oh! I have to find out who these other ponies are!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Why?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I throw a party for every new pony in Ponyville..."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "(gasp!) That reminds me! I haven't thrown a welcome party for you yet!"},

    // CORRECTED: "I'm sorry, Feenie" from "Phoebe"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I'm sorry Feenie, I just haven't had the time today!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Uh, that's alright..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(She seems so upset about it...)"},

    // CORRECTED: "8:35" from "8.35"
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Look next to Rainbow Dash's name, it's a time: \"8:35\""},

    // CORRECTED: "8:35 PM" from "8.35"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I was right! It's a party invite!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "\"Rainbow Dash party at 8:35\". I'll try not to be late this time."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I don't think so. I think I know what this is now..."},
    {EV_NONE, 0, PP_NONE | CMD_NONE, "A list with several names including Rainbow Dash."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "You know? Tell me! Tell me!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I'm not completely positive, but I think this is a-"},

// =============================================================================
// DRAMATIC ENCOUNTER: SONATA DUSK REVEALED
// =============================================================================

    // CAUGHT IN THE ACT!
    {EV_NONE, 0, PP_NONE | CMD_NONE, "And just who are you two?!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(OH NO! We're caught!!)"},
    {EV_NONE, 0, PP_MIA | CMD_NONE, "Why are you snooping around my room?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Ch-Chief!?"},
    {EV_NONE, 0, PP_MIA | CMD_NONE, "I should have the police book you two and have you thrown in jail for breaking and entering."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(This can't be Mia, it just can't be!)"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "We're room service!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Do you honestly think she's going to fall for that?)"},
    {EV_NONE, 0, PP_MIA | CMD_NONE, "Do you honestly think I'm going to fall for-!"},
    {EV_NONE, 0, PP_MIA | CMD_NONE, "Wait a minute..."},
    {EV_NONE, 0, PP_MIA | CMD_NONE, "I know who you are..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "It's me, Mia..."},
    {EV_NONE, 0, PP_MIA | CMD_NONE, "Mia?"},

    // CORRECTED: "Sonata" from "Samnada" and "Zenada"
    {EV_NONE, 0, PP_MIA | CMD_NONE, "My name is Sonata."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Sonata...?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Did I stutter? Yes, that's my name."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(It's not her... but the resemblance... it's uncanny...)"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Name. Now."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Phoenix Wright..."},

    // CORRECTED: "Pinkamena Diane Pie, Party Thrower Extraordinaire!" from "Pretty girl extraordinary!"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Pinkamena Diane Pie, Party Thrower Extraordinaire!"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "As I thought. You're that human lawyer from the trial earlier..."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(I can't get over this... it looks exactly like her... if she were a pony.)"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Can you stop staring at me like that, please."},

    // CORRECTED: "What's the matter Feenie, cat got your tongue?" from "Phinee"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "What's the matter Feenie, cat got your tongue?"},

    // CORRECTED: Complex garbled sentence about cats and claws
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "That would hurt because a cat has claws and your tongue is really sensitive..."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Ouch!"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I knew Rainbow Dash was guilty, but it didn't even look like you were trying in court today."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Who... exactly... are you...?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I'm the one who should be asking questions here."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Seeing as you two are the ones who broke into my room."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I'm betting you're the one who stole the key two days ago."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "But isn't this Ace Swift's room?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "You're here about him?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I see."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "We were just investigating his hotel room for clues."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "This is his room, is it not?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Hmm?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Oh, yes. That is correct."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "You just said this was your room, though."},

    // CORRECTED: "What are you, his girlfriend or something?" from garbled version
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "What are you, his girlfriend or something?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "That's strike one, Mr. Wright."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I suggest you not strike out anymore."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Gah!"},

    // CORRECTED: "Better not get on her bad side" from "back, sonny"
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Better not get on her bad side.)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Ah, sorry."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Actually, I'm..."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Or, should I say, WAS his manager, given the circumstances."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "His... Manager?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(This is getting weird.)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I'm sorry about what happened."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Don't worry, I got over it pretty quickly."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Besides, justice will be served. Your client will be punished for her crime."},

    // CORRECTED: "Hey, Rainbow Dash didn't do it!" from "Riggle Dash"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Hey, Rainbow Dash didn't do it!"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Anypony with half a brain can see that she did it, Mr. Wright."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Look at all the evidence stacked against her."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "No matter how you look at it, she was the one who activated that cloud and killed him."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Your little feather theory may have bought some time, but she is going to be found guilty tomorrow morning."},

    // CORRECTED: "I assure you" from "I assure it"
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I assure you."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I believe in her, and I'm gonna defend her to the very end, no matter what you say."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "And that's why you're going to lose. From what I've gathered, you're not even from Equestria. Why place loyalty in a pony you hardly know?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Did I stutter? I said because I believe her. She didn't do it."},

    // CORRECTED: "Arrogant" from "Eregant"
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Arrogant. Just like that prosecutor."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Do you mean Trixie?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Yes, her."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "What do you have against her?"},

    // CORRECTED: "show-mare" from "show-mere"
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I wished to prosecute for this case, but that pig-headed show-mare beat me to it."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(She does seem a lot more qualified to be a prosecutor than Trixie.)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "So wait, you're a prosecutor as well as a manager?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Ace and I are from Canterlot, Equestria's capital."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Most of the unicorns there are jacks of all trades, so to speak."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "We take on as many jobs as we can to flourish our intellect and magical abilities."},

    // CORRECTED: Complex garbled sentence about Pinkie's enthusiasm
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Wow! I didn't even know that! What other jobs do you have? Maybe bowling? No, peanut fighting! No, no, how about scuba diving?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Pinkie, it doesn't look like she shares your enthusiasm."},

    // CORRECTED: "Canterlot" from "cannerlot"
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "You sure she's from this... Canterlot place then?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Yes, she is."},

    // CORRECTED: Added missing context about not being able to prosecute
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I was in Ponyville when the murder took place, so there wasn't enough time for me to go to Canterlot and execute the procedures to prosecute this case."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Trixie must have already been there when she heard about it."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "How foolish."},

    // CORRECTED: "grudge" from "garage"
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Taking a case over a silly little grudge."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "It's funny, really."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Part of me wants you to best her."},

    // CORRECTED: "She wants me to win?" from "She wants the grudge now"
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(She wants me to win?)"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I actually know quite a bit about her."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Care to listen?"},

    // CORRECTED: Very garbled story line - fixed to make sense
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Ooh, a story! I love stories! I'll tell you one about a mare in a blue suit who broke into somebody's room in search of personal belongings! It's a classic-"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "For the love of Celestia, shut up!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "If you wouldn't mind, I wasn't told much about Trixie."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I was classmates with her when I was but a filly. I attended the same magic classes as her."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Were you friends with her or something?"},

    // CORRECTED: "I conduct myself" from "I capture myself"
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "No, I conduct myself as I do now. I only consult with those who are worth my time."},

    // CORRECTED: "Hey, you know what that means, Feenie?" from "Phoebe" and fixed the logic
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Hey, you know what that means, Feenie? We're both worth her time! Though you'd think she wouldn't like us breaking into her room!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Every time you speak, you make that glare icier and icier!)"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Continuing..."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "The tricks you saw in court today is how she has been all her life. An arrogant boaster, a show-off."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I hate that type."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "She was at the top of the class."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "As much as I hate to say it, she's better than me."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Despite me being older."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Well, when it comes to magic anyway."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Ah, so you're just jealous then?"},

    // CORRECTED: "gum bubble" from "June Bubblegum"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Pinkie! Is your brain the size of a gum bubble?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I don't think so. If it were bubblegum, it would probably stick to the inside of my head, don't you think?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Pinkie, just stop talking, please!"},

    // PINKIE'S REPETITIVE TALKING LOOP
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Hey, I'll stop talking."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Sorry, I spoke!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I spoke again!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "And again!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "And again!"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "And again!"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "AHH!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Huh?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Are you okay?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Yes."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Excuse me."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Anyway, I'm not jealous."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "In fact, unlike Trixie, I'm striving to become better with magic."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Not going around town and showing off a bunch of cheap parlor tricks."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "You should earn attention and praise for the actions you do, not what you claim you can do."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "So just because she showed off in school, you hate her?"},

    // CORRECTED: "Sounds a little shallow" from garbled version
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Sounds a little shallow if you ask me."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "But is it? Do you think she's qualified to be prosecuting? You saw how she acted. No professionalism at all."},

    // CORRECTED: "parrots, whips" from "Two pays, birds, whips"
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I've had it worse in the courtroom. Parrots, whips."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Whips?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Ugh, don't ask. As long as she's getting the job done, I don't see anything wrong with it."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Well, why do you want to prosecute this case so badly anyway? I know you were his manager, but still."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Because if things were going my way, the case would have been closed by now. Cold, hard, swift justice. That's the way I work."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "That's not what being a lawyer is about, Sonata."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Then what is it about, Mr. Wright? Sitting back and letting a dangerous felon off the hook, scot-free?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "No. It's about finding the truth."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "The truth?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Attorneys aren't meant to uphold justice. We're to work to the best of our abilities to guide it, and seek out the truth."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "You have quite the ideals, Mr. Wright. I don't know what kinds of trials and tribulations you've been through, but you're not changing my opinion."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Rainbow Dash is guilty, and that's all there is to it."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "If you don't mind me asking, what does that eyeball stand for?"},

    // CORRECTED: "horn" from "form"
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "It's a cutie mark! I bet your special talent is poking ponies' eyes out with that horn!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(We are so dead.)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(What the heck is wrong with her?)"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Are you okay? You look like you're in pain."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Yes, I'm fine."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "But no. My talent is perceiving and having a keen eye for detail."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "For instance, Mr. Wright, you're desperately trying to change the subject,"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "hoping I forget about you breaking into my room,"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "indicated by your nervous breathing patterns and the sweat trickling down your forehead and neck."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "You're also trying to cover up that embarrassing rip in your armpit."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I can tell by how firmly your left arm is pressed against your body compared to your right one."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "And her. She's..."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "She's thinking about ladders."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "How did you know?! You must be psychic! But I was actually thinking about step-ladders."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "It's a ladder!"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Even I could have gotten that one!"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Throughout the whole conversation, you keep looking at it!"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "But, Sonata, can you tell me a little bit more about Ace?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "What's there to say? He was good at what he did."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "What about your relationship with him?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "As his manager, I mean."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Well?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "That's none of your business."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(For a second there, she kind of hesitated.)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(Perhaps I should press this further.)"},

    // CORRECTED: Fixed garbled question about being Ace's manager
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "I want to know, Sonata, what was it like being Ace's manager?"},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I told you, Mr. Wright."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "It's none of your business."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "And Bingo was his name-o. I knew there was more to you than meets the eye."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "Now, if you'll excuse me, I have some work to attend to. I would appreciate it if you left my room post-haste."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(That's odd. Didn't she say she was going to have us arrested for breaking and entering?)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Alright, let's go Pinkie Pie."},
    {EV_NONE, 0, PP_SONATA | CMD_NONE, "I wish you the best of luck on your investigation. You'll need it."},

// =============================================================================
// LEAVING THE HOTEL: REFLECTIONS ON SONATA
// =============================================================================

    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(I was sweating bullets back there.)"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "(She's quite intimidating for a pony.)"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I didn't find her intimidating. I tried to make her smile. How do you think I did?"},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Uh... Don't quit your day job."},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "Okay! Wait! What is my day job anyway? Throwing parties is more of a hobby."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "Pinkie, you still haven't told me. How did you manage to be so late for the trial?"},
    {EV_NONE, 0, PP_PINKIE | CMD_NONE, "I slept in."},
    {EV_NONE, 0, PP_PHOENIX | CMD_NONE, "That's it?"},

// End of main narrative - file would continue with additional scenes
};

// Total number of lines in this segment
const int part3_phoenix_line_count = sizeof(part3_phoenix_lines) / sizeof(GameLine);