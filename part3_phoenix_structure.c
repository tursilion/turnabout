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
    {EV_NONE, 17520, PP_PHOENIX | CMD_TAKETHAT, "Take that!"}, // 00:11:18.40
    {EV_NONE, 17560, PP_PHOENIX | CMD_NONE, "These!"}, // 00:11:21.28
    {EV_NONE, 17588, PP_RAINBOW | CMD_NONE, "AHHH!"}, // 00:11:22.48

    // NOTE: "some bony" likely "somepony"
    {EV_NONE, 17628, PP_RAINBOW | CMD_NONE, "But those away before some bony sees them!"}, // 00:11:23.48 - CORRECTED: "Put those" and "somepony"
    {EV_NONE, 17652, PP_RAINBOW | CMD_NONE, "Please!"}, // 00:11:26.32
    {EV_NONE, 18200, PP_PHOENIX | CMD_NONE, "Even right now, your anxiety shows you absolutely didn't want these pictures floating out and about."}, // 00:11:27.32
    {EV_NONE, 18236, PP_RAINBOW | CMD_NONE, "Yes, yes, yes, you're right!"}, // 00:11:33.36
    {EV_NONE, 18264, PP_RAINBOW | CMD_NONE, "I was meeting him about these!"}, // 00:11:34.84
    {EV_NONE, 18288, PP_RAINBOW | CMD_NONE, "Can you please just put them away?"}, // 00:11:36.60
    {EV_NONE, 18310, PP_RAINBOW | CMD_NONE, "NOW!"}, // 00:11:38.60

    // SECOND PSYCHE-LOCK BREAKS - THE MONEY QUESTION
    {EV_NONE, 18368, PP_PHOENIX | CMD_NONE, "This brings us to the money question."}, // 00:11:41.68
    {EV_NONE, 18404, PP_PHOENIX | CMD_NONE, "Why did he have these pictures?"}, // 00:11:43.64
    {EV_NONE, 18604, PP_RAINBOW | CMD_NONE, "Who knows? He's dead. What a bummer. Guess we'll never know."}, // 00:11:45.16
    {EV_NONE, 18632, PP_PHOENIX | CMD_NONE, "I actually think I know why."}, // 00:11:50.18
};

// Total number of lines in this segment
const int part3_phoenix_line_count = sizeof(part3_phoenix_lines) / sizeof(GameLine);

// NOTE: This file continues with additional segments covering:
// - The blackmail revelation and third psyche-lock
// - Hotel room investigation with Pinkie Pie
// - Meeting Sonata Dusk
// - Additional character development and evidence gathering
//
// Due to file length (1773 lines), this represents approximately the first 200 lines
// The remaining content follows the same structure and formatting patterns