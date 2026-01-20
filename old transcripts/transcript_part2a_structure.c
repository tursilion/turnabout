/*
? Perfect! I've successfully reorganized the transcript_part2a_structure.c file with comprehensive comments that break down the logical story
  segments and cross-examination structure. Here's a summary of what I've added:

  Story Structure Comments Added:

  Major Segments:

  1. WITNESS INTRODUCTION AND INITIAL QUESTIONING - Setup and character introductions
  2. FLUTTERSHY'S INITIAL TESTIMONY - The witness testimony presentation
  3. CROSS-EXAMINATION SEGMENT: ROUND 1 - First round of pressing and objections
  4. CROSS-EXAMINATION SEGMENT: ROUND 2 - Expanded testimony with the key contradiction
  5. PHOENIX'S DESPERATE GAMBIT - Accusing Fluttershy to buy time
  6. THE FEATHER EVIDENCE AND TRIAL CONCLUSION - Final evidence presentation
  7. TRIAL END - Fluttershy's arrest and Phoenix's regret

  Cross-Examination Details:

  For each testimony statement, I've added:
  - PRESS options with explanatory comments about what they reveal
  - OBJECTION points showing the correct path forward
  - Suggested alternative objections in commented blocks with amusing failed attempts

  Key Interactive Elements Highlighted:

  - Statement 1: Press reveals exotic animals (crucial for later feather evidence)
  - Statement 2: Press establishes timeline and Fluttershy's lightning phobia
  - Statement 3: Press reveals Fluttershy's whisper-soft "yelling"
  - Statement 4: Contains the main contradiction about not seeing Applebloom leave

  Suggested Alternative Dialogue:

  I've included humorous alternative objection attempts like:
  - Presenting Attorney's Badge inappropriately
  - Trying to use the Large Feather for unrelated objections
  - Using the Weather Schedule incorrectly

  The structure now clearly shows both the single correct path through the cross-examination and provides amusing alternatives for incorrect choices,
   making it perfect for implementing an interactive Phoenix Wright-style game experience.
*/   


// Generated from transcript part 2a.txt
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
#define PP_TRIXIE 8
#define PP_FLUTTERSHY 9
#define PP_JUDGE 10

#define CMD_NONE 0
#define CMD_BLACK 1
#define CMD_WHOOSH 2
#define CMD_CRASH 3
#define CMD_RIP 4
#define CMD_BADUMTISH 5
#define CMD_BREAKLOCK 6
#define CMD_PARTY_HORN 7
#define CMD_BOOMSFX 8
#define CMD_PHOENIX_HOLDIT 9
#define CMD_TRIXIE_OBJECTION 10
#define CMD_PHOENIX_OBJECTION 11
#define CMD_TWILIGHT_OBJECTION 12
#define CMD_HAMMERSFX 13

// =============================================================================
// STORY SEGMENT: WITNESS INTRODUCTION AND INITIAL QUESTIONING
// =============================================================================
ConversationEntry transcript_part2a[] = {
    {EV_NONE, 0, PP_NONE | CMD_BLACK, ""},
    {EV_NONE, 127, PP_TRIXIE | CMD_NONE, "Witness, state your name and occupation."},
    {EV_NONE, 187, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 135, PP_TRIXIE | CMD_NONE, "Witness! Get out from under there and state your name and occupation!"},
    {EV_NONE, 188, PP_FLUTTERSHY | CMD_NONE, "(*whispers*)"},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "Can you please repeat that, young lady? I couldn't hear you."},
    {EV_NONE, 188, PP_FLUTTERSHY | CMD_NONE, "(*whispers*)"},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "Nope... still couldn't hear you..."},
    {EV_NONE, 132, PP_PHOENIX | CMD_NONE, "Maybe I can milk this situation to our advantage."},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "What do you mean?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Your Honor! This witness clearly doesn't have the ability to testify. Perhaps we should suspend the proceedings of this trial for another-"},
    {EV_NONE, 189, PP_FLUTTERSHY | CMD_NONE, "Oh, Mr Phoenix, you're here! You haven't died yet?"},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "There must be something very wrong... you look so frail and seem to be suffering more than ever right now."},
    {EV_NONE, 134, PP_PHOENIX | CMD_NONE, "You got the last part right..."},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Mr Wright, tell her to state her name and occupation, please."},
    {EV_NONE, 128, PP_PHOENIX | CMD_NONE, "But that's the prosecution's job. It's her witness..."},
    {EV_NONE, 141, PP_TRIXIE | CMD_NONE, "This witness was being difficult when Trixie was preparing her earlier as well."},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Given the circumstances... just do it, Mr Wright."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "Fluttershy - I mean, witness - state your name and occupation, please."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "(Never thought I'd be saying that line.)"},
    {EV_NONE, 189, PP_FLUTTERSHY | CMD_NONE, "I'm Fluttershy. I'm an animal caretaker."},
    {EV_NONE, 127, PP_TRIXIE | CMD_NONE, "Is it true you saw Rainbow Dash leave the Everfree Forest two nights ago?"},
    {EV_NONE, 187, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Mr Wright..."},
    {EV_NONE, 134, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 134, PP_PHOENIX | CMD_NONE, "Is it true you saw Rainbow Dash leave the Everfree Forest two nights ago?"},
    {EV_NONE, 134, PP_PHOENIX | CMD_NONE, "(This kind of backfired on me...)"},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "Yes, she seemed to be in a hurry."},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "So the defendant was indeed at the scene of the crime on the night of the murder."},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Witness! You will-"},
    {EV_NONE, 187, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Mr Wright, tell her she has to testify."},
    {EV_NONE, 134, PP_PHOENIX | CMD_NONE, "(Now I have to do your job too, Your Honor?)"},
    {EV_NONE, 134, PP_PHOENIX | CMD_NONE, "Fluttershy..."},
    {EV_NONE, 189, PP_FLUTTERSHY | CMD_NONE, "Yes, Mr Phoenix?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Can you please testify as to what you saw two nights ago when you saw Rainbow Dash leaving the forest?"},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "Umm... I don't know what 'testify' means..."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "It just means tell us what you saw that night."},
    {EV_NONE, 189, PP_FLUTTERSHY | CMD_NONE, "Oh yes, I can do that! Anything for you, Mr Phoenix!"},

// =============================================================================
// TESTIMONY SEGMENT: FLUTTERSHY'S INITIAL TESTIMONY
// =============================================================================
    {EV_NONE, 192, PP_NONE | CMD_BOOMSFX, "-- I'll tell you all what I saw! ... if it's okay with you... --"},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "It was during the night hours. I went outside to feed the chickens and the other ones..."},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "When I was near my chicken coop, I heard a lightning bolt in the distance and it scared me."},
    {EV_NONE, 193, PP_FLUTTERSHY | CMD_NONE, "After I finished feeding my chickens, I saw Rainbow Dash flying away from the forest like something was chasing her. I called out to her, but I don't think she heard me."},
    {EV_NONE, 193, PP_FLUTTERSHY | CMD_NONE, "I looked up but saw nothing following her."},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "That was when the police ponies arrived. They spoke with me, and I went off to bed at 10:30PM."},
    {EV_NONE, 176, PP_TRIXIE | CMD_NONE, "Hahaha! Is that isn't an airtight testimony, Trixie doesn't know what is! By Rainbow Trash's own friend no less."},
    {EV_NONE, 191, PP_RAINBOW | CMD_NONE, "FLUTTERSHY!"},
    {EV_NONE, 189, PP_FLUTTERSHY | CMD_NONE, "Hi Rainbow Dash."},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Very well, Mr Wright, your cross-examination, if you please."},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "Did you see anything odd in there, Phoenix?"},
    {EV_NONE, 132, PP_PHOENIX | CMD_NONE, "Not really... Trixie is right.. it's kind of airtight..."},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "Then what do we do?"},
    {EV_NONE, 132, PP_PHOENIX | CMD_NONE, "Poke holes in it until it isn't airtight anymore."},
    {EV_NONE, 133, PP_TWILIGHT | CMD_NONE, "That's the spirit! I just hope Fluttershy isn't lying about anything."},
    {EV_NONE, 132, PP_PHOENIX | CMD_NONE, "(I actually hope she is lying so I have something to work off of.)"},

// =============================================================================
// CROSS-EXAMINATION SEGMENT: FLUTTERSHY'S TESTIMONY - ROUND 1
// =============================================================================
    {EV_NONE, 194, PP_NONE | CMD_NONE, ""},

    // STATEMENT 1: "It was during the night hours. I went outside to feed the chickens and the other ones..."
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "It was during the night hours. I went outside to feed the chickens and the other ones..."},

    // PRESS: Asking about the "other ones" - reveals exotic animals (KEY EVIDENCE for later)
    {EV_NONE, 164, PP_NONE | CMD_PHOENIX_HOLDIT, "(phoenix holdit sfx)"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "So, you say you went outside to feed your chickens, and \"the other ones\". What do you mean by that?"},
    {EV_NONE, 189, PP_FLUTTERSHY | CMD_NONE, "I'm... taking care of a lot of exotic animals right now."},
    {EV_NONE, 136, PP_PHOENIX | CMD_NONE, "I see. How did you acquire them?"},
    {EV_NONE, 189, PP_FLUTTERSHY | CMD_NONE, "A zoo in Fillydelphia is, well, renovating, and they needed a place for all the animals to stay while they do it."},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "They... heard about my talent with animals, somehow, and they came to me and asked me to take care of them."},
    {EV_NONE, 189, PP_FLUTTERSHY | CMD_NONE, "O-of course I said 'yes', since they had lots of birdies and critters that I've never seen before, and I always like to meet new animals..."},
    {EV_NONE, 136, PP_PHOENIX | CMD_NONE, "How long have you had these animals?"},
    {EV_NONE, 189, PP_FLUTTERSHY | CMD_NONE, "Three days now."},
    {EV_NONE, 136, PP_PHOENIX | CMD_NONE, "Is it hard work taking care of them all?"},
    {EV_NONE, 138, PP_NONE | CMD_TRIXIE_OBJECTION, "(trixie objection sfx)"},
    {EV_NONE, 135, PP_TRIXIE | CMD_NONE, "What, pray tell, does this have to do with murder?"},
    {EV_NONE, 137, PP_PHOENIX | CMD_NONE, "Well... I kind of like animals too, and..."},
    {EV_NONE, 135, PP_TRIXIE | CMD_NONE, "Stop going off topic, you incompetent fool!"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "(I really hate you Trixie, you know that?)"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "(I better keep note of these exotic animals, though, something about it...)"},

    /*
    // SUGGESTED ALTERNATIVE OBJECTION: Present Attorney's Badge
    {EV_NONE, 138, PP_NONE | CMD_PHOENIX_OBJECTION, "(phoenix objection sfx)"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "I object to the witness feeding chickens at 8:40PM!"},
    {EV_NONE, 135, PP_TRIXIE | CMD_NONE, "What's wrong with that, Mr Wrong?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "My attorney's badge proves that... uh... lawyers don't feed chickens at night?"},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Mr Wright, that makes absolutely no sense whatsoever."},
    {EV_NONE, 134, PP_PHOENIX | CMD_NONE, "Yeah, I thought that was weak even for me..."},
    */

    // STATEMENT 2: "When I was near my chicken coop, I heard a lightning bolt in the distance and it scared me."
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "When I was near my chicken coop, I heard a lightning bolt in the distance and it scared me."},

    // PRESS: Time details and Fluttershy's fear (establishes timeline and her phobia)
    {EV_NONE, 164, PP_NONE | CMD_PHOENIX_HOLDIT, "(phoenix holdit sfx)"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "You heard thunder while you were in your chicken coop?"},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "Well, it was lightning..."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "No, Fluttershy, thunder produces the sound, not lightning."},
    {EV_NONE, 143, PP_TRIXIE | CMD_NONE, "Wrong again, Mr Wrong..."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "For the last time, Trixie, it's \"Wright\". Would you please stop calling me that?"},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "Actually, here in Equestria, lightning is what produces the noise when it strikes the ground."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "That wasn't what I wanted to say, anyway. What time was it when you heard it?"},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "8:40PM, on the dot."},
    {EV_NONE, 136, PP_PHOENIX | CMD_NONE, "That's quite exact. How are you so sure?"},
    {EV_NONE, 189, PP_FLUTTERSHY | CMD_NONE, "It's the time I feed my chickens every night."},
    {EV_NONE, 134, PP_PHOENIX | CMD_NONE, "Feeding chickens... at night...?"},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "Midnight snack! I couldn't send them to bed without one, what if they starved to death while they were sleeping!?"},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "Oh my! I never realized the importance of midnight snacking!"},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "That's our naive Fluttershy..."},
    {EV_NONE, 132, PP_PHOENIX | CMD_NONE, "(And that's my clueless Judge...)"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Are you positive it was the lightning you heard, and not something else?"},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "I'm sure it was lightning, because the sound of lightning really frightens me!"},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "I remember getting scared when I heard it. I nearly dropped all of my chicken feed!"},
    {EV_NONE, 127, PP_TRIXIE | CMD_NONE, "This lines up with the time of death, and when the initial lightning bolt was set off."},

    /*
    // SUGGESTED ALTERNATIVE OBJECTION: Present Large Feather
    {EV_NONE, 138, PP_NONE | CMD_PHOENIX_OBJECTION, "(phoenix objection sfx)"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "I object! This feather proves you couldn't have heard lightning!"},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "Mr Wright, how does a feather prove anything about hearing?"},
    {EV_NONE, 134, PP_PHOENIX | CMD_NONE, "(Hmm, that sounded better in my head...)"},
    {EV_NONE, 176, PP_TRIXIE | CMD_NONE, "Perhaps Mr Wrong should stick to defending instead of... whatever that was."},
    */

    // STATEMENT 3: "After I finished feeding my chickens, I saw Rainbow Dash flying away from the forest like something was chasing her. I called out to her, but I don't think she heard me."
    {EV_NONE, 193, PP_FLUTTERSHY | CMD_NONE, "After I finished feeding my chickens, I saw Rainbow Dash flying away from the forest like something was chasing her. I called out to her, but I don't think she heard me."},

    // PRESS: Timeline and Fluttershy's "loud" calling (reveals her whisper-soft voice)
    {EV_NONE, 164, PP_NONE | CMD_PHOENIX_HOLDIT, "(phoenix holdit sfx)"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "How long did it take you to feed your chickens, Fluttershy?"},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "Um, about 15 minutes."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "And you're saying you saw Rainbow Dash fleeing from the forest at that time?"},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "Yes. I thought there was a ferocious creature chasing her, judging by how fast she was flying."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "What did you do then?"},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "I called out to her at the top of my lungs so I could see what the problem was."},
    {EV_NONE, 136, PP_PHOENIX | CMD_NONE, "And she just ignored you?"},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "Yes, I don't know why... I yelled so loud, at the top of my lungs, like this..."},
    {EV_NONE, 195, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 196, PP_FLUTTERSHY | CMD_NONE, "(softly) \"Rainbow Dash, what's wrong!?\""},
    {EV_NONE, 134, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 134, PP_PHOENIX | CMD_NONE, "Yeah... I haven't the faintest idea how she didn't hear that..."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "So, you didn't see anything chasing Rainbow Dash?"},

    /*
    // SUGGESTED ALTERNATIVE OBJECTION: Present Weather Schedule
    {EV_NONE, 138, PP_NONE | CMD_PHOENIX_OBJECTION, "(phoenix objection sfx)"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "I object! Rainbow Dash wasn't being chased - she was just following her weather schedule!"},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Mr Wright, fleeing in terror and following a schedule are very different things."},
    {EV_NONE, 134, PP_PHOENIX | CMD_NONE, "Well... maybe she's just really punctual?"},
    {EV_NONE, 135, PP_TRIXIE | CMD_NONE, "Mr Wrong, that's the most ridiculous thing Trixie has ever heard."},
    */

    // STATEMENT 4: "I looked up but saw nothing following her." - THE CONTRADICTION!
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "I didn't see or hear anything else come out of the forest that night."},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "Yes. I watched the forest until the police arrived, but I didn't see or hear anything come out of it after Rainbow Dash."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "!!??"},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "What is it, Phoenix?"},
    {EV_NONE, 132, PP_PHOENIX | CMD_NONE, "I think I just found a contradiction..."},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "You mean, Fluttershy is lying?"},
    {EV_NONE, 132, PP_PHOENIX | CMD_NONE, "I don't know why, but something she said is impossible."},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "Impossible?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Your Honor, can you please have the witness amend that statement to her testimony?"},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Hmmm... I don't see why not. Witness, please add your previous statement to your testimony."},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "Um... okay..."},

// =============================================================================
// CROSS-EXAMINATION SEGMENT: EXPANDED TESTIMONY - ROUND 2
// =============================================================================
    // NEW STATEMENT: "I didn't see or hear anything else come out of the forest that night."
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "I didn't see or hear anything else come out of the forest that night."},

    // PRESS: Double-checking her certainty (builds tension before objection)
    {EV_NONE, 164, PP_NONE | CMD_PHOENIX_HOLDIT, "(phoenix holdit sfx)"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Fluttershy, are you absolutely sure about this?"},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "I'm sure. Not a peep or pony came out of that forest until the police came and spoke with me... then I went to sleep at 10:30PM."},

    // OBJECTION: THE BIG CONTRADICTION - She should have seen Applebloom!
    {EV_NONE, 138, PP_NONE | CMD_PHOENIX_OBJECTION, "(phoenix objection sfx)"},
    {EV_NONE, 187, PP_FLUTTERSHY | CMD_NONE, "!!!"},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Mr Wright, please don't frighten the witness."},
    {EV_NONE, 137, PP_PHOENIX | CMD_NONE, "Right... sorry, but there is a contradiction in this testimony."},
    {EV_NONE, 141, PP_TRIXIE | CMD_NONE, "What contradiction? Everything she has said meshes with the evidence to a T!"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "No, there's one thing that isn't right. Fluttershy, you said you watched the forest until the police force arrived, correct?"},
    {EV_NONE, 187, PP_FLUTTERSHY | CMD_NONE, "Y-yes... did I do something wrong? I'm so sorry if I did..."},
    {EV_NONE, 134, PP_PHOENIX | CMD_NONE, "Uh... no need to be sorry..."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "But you didn't hear or see ANYTHING come out from the forest?"},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "I didn't see or hear anything else come out of the forest that night."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "Then there's clearly a contradiction here... actually two!"},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Please explain what these contradictions are, Mr Wright."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Fluttershy should have seen someone leave the forest..."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "The previous witness, Applebloom!"},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "Oh! That's right!"},
    {EV_NONE, 161, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "But I-I didn't see Applebloom... I-I promise!"},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "You see, Fluttershy... you HAD to have seen Applebloom if you were really watching the forest all night..."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "The prosecution even confirmed that there's only one way in and out of that forest... and that entrance is right by your cottage!"},
    {EV_NONE, 172, PP_TRIXIE | CMD_NONE, "Ngh!"},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "...I don't understand, why would Fluttershy lie like this...?"},
    {EV_NONE, 132, PP_PHOENIX | CMD_NONE, "I don't know either. We've got to pursue this issue, otherwise we're cooked."},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "I-I don't know why, but I didn't see her..."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "It's not just that; there is another thing, Fluttershy --"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "You also stated you HEARD nothing as well. Earlier I was told lightning makes a noise when it hits the ground in Equestria."},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "Yes, that is right, Mr Wright."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "Then why didn't Fluttershy mention hearing the second bolt of lightning?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Fluttershy says she watched the forest until the police arrived, and they witnessed the third bolt take down a tree firsthand."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "The second lightning bolt is unaccounted for."},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "I only heard one bolt of lightning, though..."},
    {EV_NONE, 138, PP_NONE | CMD_TRIXIE_OBJECTION, "(trixie objection sfx)"},
    {EV_NONE, 135, PP_TRIXIE | CMD_NONE, "Maybe she just forgot about it."},
    {EV_NONE, 138, PP_NONE | CMD_PHOENIX_OBJECTION, "(phoenix objection sfx)"},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "She stated the first bolt of lightning scared her, from which we can conclude that every bolt of lightning could have been heard from Fluttershy's cottage."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "It's very clear this witness is afraid of lightning."},
    {EV_NONE, 134, PP_PHOENIX | CMD_NONE, "(And everything, for that matter.)"},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "Yes, it's true, lightning scares me! It is so loud and scary -- "},
    {EV_NONE, 187, PP_FLUTTERSHY | CMD_NONE, "like that voice you just did, Mr Phoenix."},
    {EV_NONE, 149, PP_PHOENIX | CMD_NONE, "There you go, Trixie, she would have remembered the second bolt of lightning frightening her if she had heard it."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Also, let's not forget, Applebloom didn't mention seeing or hearing this lightning either, now that we know that the lightning could've been heard from that far away."},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "The defense has a point."},
    {EV_NONE, 143, PP_TRIXIE | CMD_NONE, "Heh, and Trixie thinks the defense has nothing."},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "Excuse me?"},
    {EV_NONE, 176, PP_TRIXIE | CMD_NONE, "So what, she didn't see Applebloom; what does that prove? Do tell, Mr Wrong, Trixie is all ears..."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "It questions the credibility of your witnesses! You said it yourself; there's only one way in and out of that forest!"},
    {EV_NONE, 141, PP_TRIXIE | CMD_NONE, "Remember another thing! Anything beyond what Applebloom said after the time she heard the lightning bolt is irrelevant!"},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "You can't say that this is irrelevant information when your witness didn't see your other witness leave the forest!"},
    {EV_NONE, 135, PP_TRIXIE | CMD_NONE, "Then tell the GREAT and POWERFUL Trixie WHAT it means!"},
    {EV_NONE, 176, PP_TRIXIE | CMD_NONE, "Trixie knows one possibility, but that's up to you to say what it is, Mr Wrong. That is, if you have the guts to..."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "I... I... can't..."},
    {EV_NONE, 176, PP_TRIXIE | CMD_NONE, "Heh, thought so..."},
    {EV_NONE, 197, PP_TWILIGHT | CMD_NONE, "What is she talking about, Phoenix? You know a reason why Fluttershy didn't see Applebloom?"},
    {EV_NONE, 197, PP_PHOENIX | CMD_NONE, "I do, but I can't say it..."},
    {EV_NONE, 197, PP_TWILIGHT | CMD_NONE, "Why not?"},
    {EV_NONE, 197, PP_PHOENIX | CMD_NONE, "I just can't, Twilight. I'll be safe and just use the other contradiction as my stead for now."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Fine, forget that! We can't overlook this second bolt of lightning, though. It could have been the real cause of death, making all this just an accident."},
    {EV_NONE, 141, PP_TRIXIE | CMD_NONE, "Didn't you hear Trixie earlier?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Huh?"},
    {EV_NONE, 141, PP_TRIXIE | CMD_NONE, "Lightning doesn't strike the same spot twice in Equestria, just as you can't divide by zero. The body was found directly under where the first bolt had struck."},
    {EV_NONE, 143, PP_TRIXIE | CMD_NONE, "Not to mention the odds of a stray bolt of lightning hitting the victim by chance are highly improbable, especially since he was wearing a lightning-proof suit."},
    {EV_NONE, 132, PP_PHOENIX | CMD_NONE, "I remember her bringing up this 'lightning-proof suit'..."},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "It's what the pegasi wear when working with weather."},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "Or in this case, a modified version designed for large scale races where they may encounter dangerous weather conditions."},
    {EV_NONE, 132, PP_PHOENIX | CMD_NONE, "How exactly does the suit work?"},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "It's a two piece suit, worn on the head and body. The fabric is made up of an effective insulator that protects pegasi from being harmed by lightning."},
    {EV_NONE, 132, PP_PHOENIX | CMD_NONE, "Then how did he die if he was wearing this suit?"},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "There are some parts of the body that the suit does not cover, namely certain parts of the head and neck. A precise, aimed bolt could still hit him in the sweet spots, which is what Trixie is basing her claims on..."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "But it's still possible for a random bolt to hit him in one of the exposed spots!"},
    {EV_NONE, 143, PP_TRIXIE | CMD_NONE, "I'm surprised you haven't realized it yet, Mr Wrong..."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Huh?"},
    {EV_NONE, 135, PP_TRIXIE | CMD_NONE, "You have been babbling about Trixie's witnesses not seeing the second bolt of lightning so much that you seem to have forgotten..."},
    {EV_NONE, 172, PP_TRIXIE | CMD_NONE, "The second bolt seems to not exist at all. Trixie will be sure to have a chat with the pegasi who gave her these cloud ballistics to confirm it, Trixie assures you."},
    {EV_NONE, 143, PP_TRIXIE | CMD_NONE, "Even if we take your silly theory into consideration, the odds of him being struck down by a random bolt of lightning are too low to be believable without having some sort of concrete proof!"},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "The prosecution's logic is very sound."},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "The chances of a lightning bolt hitting the victim by chance are too small to hold water in this court without any proof, considering the protection he was wearing."},
    {EV_NONE, 151, PP_JUDGE | CMD_NONE, "Objection overruled!"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "No!"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "(Every time I make an objection she has it refuted just like that!)"},
    {EV_NONE, 143, PP_TRIXIE | CMD_NONE, "Hah! Too bad, Mr Wrong."},

// =============================================================================
// STORY SEGMENT: PHOENIX'S DESPERATE GAMBIT - ACCUSING FLUTTERSHY
// =============================================================================
    {EV_NONE, 151, PP_JUDGE | CMD_NONE, "Enough! I'm afraid the defense's line has run short. Do you have anything else you would like to say, Mr Wright, before I hand down my verdict?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "(I'm going to lose if I don't do something fast!!)"},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "Phoenix, there has got to be something we can do! It can't end like this!"},
    {EV_NONE, 132, PP_PHOENIX | CMD_NONE, "I know, but I need more time. I need more information!"},
    {EV_NONE, 141, PP_TRIXIE | CMD_NONE, "Please Your Honor, make this quick. Trixie is starting to feel sorry for this hopeless defense team."},
    {EV_NONE, 198, PP_PHOENIX | CMD_NONE, "(There is one thing I can do... I didn't want to do it earlier...)"},
    {EV_NONE, 198, PP_PHOENIX | CMD_NONE, "(But I have no choice...)"},
    {EV_NONE, 199, PP_PHOENIX | CMD_NONE, "(I need more time and evidence... this is the only way...)"},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "Your Honor!"},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "Yes, Mr Wright?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "The defense would like to cast suspicion on another."},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "Another suspect?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Yes, that is correct, Your Honor."},
    {EV_NONE, 197, PP_TWILIGHT | CMD_NONE, "But who?"},
    {EV_NONE, 143, PP_TRIXIE | CMD_NONE, "Is this the last bastion of Mr Wrong? Haha, let's hear it -- who is this mystery suspect?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "I am far from being done, Trixie!"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "The suspect the defense accuses is the witness..."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "Fluttershy!"},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "Huh?"},
    {EV_NONE, 132, PP_TWILIGHT | CMD_NONE, "Mr Wright! What are you doing!?"},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "Fluttershy is a pegasus; therefore she could have tampered with the cloud and the crime scene."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "And let's not forget, there was a very large time frame where Fluttershy was alone;"},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "She even stated she didn't see Applebloom leave the forest when we all know she SHOULD have!"},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "B-but I was watching it the whole time... I'm not lying..."},
    {EV_NONE, 143, PP_TRIXIE | CMD_NONE, "Heh..."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "Fluttershy also has connections with my client;"},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "She could have been the one who took the storm cloud my client was scheduled to set off, as well as gathered loose feathers to spread around the crime scene."},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "I-I didn't do that..."},
    {EV_NONE, 200, PP_TWILIGHT | CMD_NONE, "Phoenix! Stop this! She didn't do it!"},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "But the defendant's hoof marks were on the storm cloud, Mr Wright... how do you explain that?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "I'd be surprised if they WEREN'T there, Your Honor..."},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "Hmm, I don't follow..."},
    {EV_NONE, 171, PP_PHOENIX | CMD_NONE, "Simple. Rainbow Dash was to put those storm clouds at the eastern end of Ponyville, according to this weather schedule."},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "Oh!"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Of course her hoofprints are there -- she was just doing her job!"},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "Fluttershy could have come and taken one of the clouds with marks on it, set it off and removed her own markings from the cloud..."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "That is possible... right?"},
    {EV_NONE, 141, PP_TRIXIE | CMD_NONE, "Yes, one could wipe a cloud... of their hoofmarks..."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "Then all the more reason to suspect her!"},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "I was home all day though..."},
    {EV_NONE, 200, PP_TWILIGHT | CMD_NONE, "Phoenix, you're supposed to be defending my friends!"},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "What about the dark forest, Mr Wright? How would this witness have been able to see in it?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "It must be like a backyard to her."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "She can probably navigate it from memory, just as you can probably navigate your house with your eyes closed."},
    {EV_NONE, 169, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "This is a very bold claim, Mr Wright. This meek little thing looks like she wouldn't harm a fly... why would she frame her friend?"},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "It's true, I have ten pet flies! Michael, Donna, Steven, Eric, Jackie..."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Easy! To cover her own guilt!"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Besides, as the prosecution has stated, why she did it is irrelevant; the fact still stands, she is just as suspicious as Rainbow Dash!"},
    {EV_NONE, 200, PP_TWILIGHT | CMD_NONE, "I-I can't believe you're saying this! I trusted you!"},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "You're going to need more proof to accuse this witness, Mr Wright. Do you have any evidence that can place her on the crime scene?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "In fact I do, Your Honor."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "This!"},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "A feather? Does it belong to her?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "No, I found this feather at the crime scene. It's way too big to belong to any bird or pegasus pony in Ponyville."},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "Just what are you getting at, Mr Wright? How does this relate to the witness?"},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "Fluttershy!"},
    {EV_NONE, 188, PP_FLUTTERSHY | CMD_NONE, "Y-yes, Mr Phoenix...?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "Do you allow any of your exotic animals to go into the Everfree Forest?"},
    {EV_NONE, 191, PP_FLUTTERSHY | CMD_NONE, "Oh no, it is much too dangerous in there. They're kept locked up tightly when I'm not playing with them..."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "As I thought! Fluttershy stated earlier that she's caring for animals not native to Ponyville; this feather could belong to one of them."},
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "It could have been brought there unintentionally by Fluttershy as she framed my client!"},
    {EV_NONE, 138, PP_NONE | CMD_TWILIGHT_OBJECTION, "(twilight objection sfx)"},
    {EV_NONE, 130, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 141, PP_NONE | CMD_NONE, ""},
    {EV_NONE, 202, PP_TWILIGHT | CMD_NONE, "This can't go on!"},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "The.. defense is objecting to..."},
    {EV_NONE, 130, PP_JUDGE | CMD_NONE, "ITSELF!?"},
    {EV_NONE, 202, PP_TWILIGHT | CMD_NONE, "Yes. Mr Wright doesn't know what he's talking about! His words are nothing but slander and lies!"},
    {EV_NONE, 202, PP_PHOENIX | CMD_NONE, "Twilight!"},
    {EV_NONE, 138, PP_NONE | CMD_TRIXIE_OBJECTION, "(trixie objection sfx)"},
    {EV_NONE, 135, PP_TRIXIE | CMD_NONE, "Zip it, Twilight! You're only his co-counsel, and nothing more!"},
    {EV_NONE, 141, PP_TRIXIE | CMD_NONE, "Discrediting an attorney like that will get you held in contempt!"},
    {EV_NONE, 202, PP_TWILIGHT | CMD_NONE, "You're a hypocrit! You've been degrading him all day long!"},
    {EV_NONE, 176, PP_TRIXIE | CMD_NONE, "And that's it. Trixie has just called Mr Wrong names -- "},
    {EV_NONE, 143, PP_TRIXIE | CMD_NONE, "never once has Trixie accused him of lies or slander, which is a serious accusation!"},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "You are right as always, Ms Trixie. "},
    {EV_NONE, 169, PP_JUDGE | CMD_NONE, "Another outburst by the defense's co-council and they will be held in contempt of court."},
    {EV_NONE, 177, PP_TWILIGHT | CMD_NONE, "B-but..."},
    {EV_NONE, 177, PP_PHOENIX | CMD_NONE, "(Trust me, I don't want to do this, Twilight... but it's the only way I can buy more time...)"},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Back to the matter at hand... I still have a hard time believing this little pony would do something like this..."},
// =============================================================================
// STORY SEGMENT: THE FEATHER EVIDENCE AND TRIAL CONCLUSION
// =============================================================================
    // Phoenix presents the large feather as evidence linking Fluttershy to the scene
    {EV_NONE, 148, PP_PHOENIX | CMD_NONE, "The evidence speaks for itself, Your Honor! This feather puts Fluttershy on the scene of the crime!"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "I demand further investigation to find out if this feather belongs to any of Fluttershy's animals!"},
    {EV_NONE, 169, PP_JUDGE | CMD_NONE, "Hmmm..."},

    // Trixie's unexpected agreement - she's happy to have another suspect
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Ms Trixie, what is your opinion on all of this? You have been surprisingly quiet regarding all of Mr Wright's claims."},
    {EV_NONE, 141, PP_TRIXIE | CMD_NONE, "You know what..."},
    {EV_NONE, 143, PP_TRIXIE | CMD_NONE, "Trixie agrees, Fluttershy is suspicious."},
    {EV_NONE, 176, PP_TRIXIE | CMD_NONE, "The investigation team did indeed see this feather on the crime scene; we brushed it off as just a plain old bird feather."},
    {EV_NONE, 141, PP_TRIXIE | CMD_NONE, "But as Trixie's feeble opponent has pointed out, it does seem kind of big up close, and with this information regarding these zoo animals..."},
    {EV_NONE, 190, PP_TRIXIE | CMD_NONE, "... it does seem to cast suspicion over this witness."},

    // Trial postponement and Trixie's gloating victory
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "You are aware we will have to suspend proceedings until tomorrow for further investigation...?"},
    {EV_NONE, 135, PP_TRIXIE | CMD_NONE, "You don't think Trixie knows this?"},
    {EV_NONE, 141, PP_TRIXIE | CMD_NONE, "Another one of Twilight Sparkle's little friends in the slammer is reward enough for Trixie today. \"Two for the price of one\", as they say!"},
    {EV_NONE, 143, PP_TRIXIE | CMD_NONE, "And Trixie has you to thank, Mr Wrong!"},
    {EV_NONE, 143, PP_TRIXIE | CMD_NONE, "You've made this experience much, MUCH more fulfilling. "},
    {EV_NONE, 176, PP_TRIXIE | CMD_NONE, "Perhaps Trixie will give you a voucher for her next performance."},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "..."},

// =============================================================================
// STORY SEGMENT: TRIAL END - FLUTTERSHY'S ARREST AND PHOENIX'S REGRET
// =============================================================================
    // The devastating conclusion - Phoenix's "victory" feels like defeat
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "All proceedings for this case will be suspended until tomorrow."},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Baliff, please take the suspect into custody for questioning."},
    {EV_NONE, 190, PP_FLUTTERSHY | CMD_NONE, "Wait, w-where are you taking me? I wouldn't do that to anypony... "},
    {EV_NONE, 156, PP_FLUTTERSHY | CMD_NONE, "Twilight, Mr Phoenix, help!"},
    {EV_NONE, 177, PP_TWILIGHT | CMD_NONE, "Phoenix... how could you...?"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "(What have I done...?)"},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "I expect both sides will gather more evidence for tomorrow."},
    {EV_NONE, 176, PP_TRIXIE | CMD_NONE, "Trixie shouldn't need to if they are planning to keep that second rate lawyer over there!"},
    {EV_NONE, 139, PP_PHOENIX | CMD_NONE, "..."},
    {EV_NONE, 126, PP_JUDGE | CMD_NONE, "Court is now adjourned!"},
    {EV_NONE, 125, PP_NONE | CMD_HAMMERSFX, "(hammersfx)"},

// =============================================================================
// END OF TRANSCRIPT PART 2A
// =============================================================================
    // Interactive Elements Summary:
    // - PRESS statements reveal key evidence (exotic animals, timeline, Fluttershy's voice)
    // - OBJECTION on main contradiction (Applebloom not seen leaving forest)
    // - Suggested alternative objections provide humor and failed attempts
    // - Building evidence leads to desperate accusation of Fluttershy
    // - Phoenix's victory is pyrrhic - he saves Rainbow Dash by condemning Fluttershy
// =============================================================================

    {EV_NONE, 0, PP_NONE | CMD_NONE, ""}
};

// Number of entries in the array
#define TRANSCRIPT_PART2A_SIZE (sizeof(transcript_part2a) / sizeof(ConversationEntry))
