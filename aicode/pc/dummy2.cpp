#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*
 * Phoenix Wright Style Game Framework
 * Two-phase gameplay: Investigation and Courtroom
 */

#define MAX_CLUES 20
#define MAX_LOCATIONS 10
#define MAX_STORY_BLOCKS 50
#define MAX_TEXT_LENGTH 1000
#define MAX_NAME_LENGTH 50

/* Game states */
typedef enum {
    STATE_INVESTIGATION,
    STATE_COURTROOM,
    STATE_GAME_OVER
} GameState;

/* Clue structure */
typedef struct {
    int id;                              /* Unique clue identifier */
    char name[MAX_NAME_LENGTH];          /* Display name */
    char description[MAX_TEXT_LENGTH];   /* Text shown when examined */
    int updates_state;                   /* 1 if finding this clue advances progress */
    int found;                           /* 1 if player has discovered this clue */
    int location_id;                     /* Which location contains this clue */
} Clue;

/* Location structure */
typedef struct {
    int id;                              /* Unique location identifier */
    char name[MAX_NAME_LENGTH];          /* Location display name */
    char description[MAX_TEXT_LENGTH];   /* Location description text */
    int clue_ids[9];                     /* Up to 9 clues per location (1-9 keys) */
    int clue_count;                      /* Number of clues in this location */
} Location;

/* Story block for courtroom phase */
typedef struct {
    int id;                              /* Unique block identifier */
    char text[MAX_TEXT_LENGTH];          /* Story text to display */
    int can_question;                    /* 1 if this block allows questioning */
    int required_clue_id;                /* Clue ID needed to question successfully */
    int next_block_id;                   /* Next block after proceeding */
    int question_success_block_id;       /* Block to go to on successful questioning */
    int advances_to_investigation;       /* 1 if this block returns to investigation */
} StoryBlock;

/* Game data structure */
typedef struct {
    GameState current_state;
    int current_location_id;
    int current_story_block_id;
    int investigation_complete;          /* 1 when all state-updating clues found */
    
    Clue clues[MAX_CLUES];
    int clue_count;
    
    Location locations[MAX_LOCATIONS];
    int location_count;
    
    StoryBlock story_blocks[MAX_STORY_BLOCKS];
    int story_block_count;
} GameData;

/* Function prototypes */
void init_game(GameData* game);
void main_loop(GameData* game);
void handle_investigation(GameData* game);
void handle_courtroom(GameData* game);
void display_location(GameData* game);
void display_story_block(GameData* game);
void examine_clue(GameData* game, int clue_index);
void check_investigation_complete(GameData* game);
int get_player_input(void);
void clear_screen(void);
void show_inventory(GameData* game);
int select_clue_from_inventory(GameData* game);

/*
 * Initialize game data structures
 * This is where you would load your game content
 */
void init_game(GameData* game) {
    game->current_state = STATE_INVESTIGATION;
    game->current_location_id = 0;
    game->current_story_block_id = 0;
    game->investigation_complete = 0;
    game->clue_count = 0;
    game->location_count = 0;
    game->story_block_count = 0;
    
    /* Initialize all clues as not found */
    for (int i = 0; i < MAX_CLUES; i++) {
        game->clues[i].found = 0;
    }
    
    /* Load locations, clues, and story blocks from data files */
    /* Example data setup would go here */

    // clues
    int i = 0;

    game->clues[i].id = i;
    strcpy(game->clues[i].name, "fingerprint");
    strcpy(game->clues[i].description, "the suspect's fingerprint on the counter");
    game->clues[i].updates_state = 1;
    game->clues[i].found = 0;
    game->clues[i].location_id = 0;
    ++i;

    game->clues[i].id = i;
    strcpy(game->clues[i].name, "bullet");
    strcpy(game->clues[i].description, "the bullet from the victim");
    game->clues[i].updates_state = 1;
    game->clues[i].found = 0;
    game->clues[i].location_id = 1;
    ++i;

    game->clues[i].id = i;
    strcpy(game->clues[i].name, "gun");
    strcpy(game->clues[i].description, "the suspect's gun matches the bullet");
    game->clues[i].updates_state = 1;
    game->clues[i].found = 0;
    game->clues[i].location_id = 2;
    ++i;

    game->clues[i].id = i;
    strcpy(game->clues[i].name, "red herring");
    strcpy(game->clues[i].description, "it's a fish");
    game->clues[i].updates_state = 0;
    game->clues[i].found = 0;
    game->clues[i].location_id = 0;
    ++i;

    game->clue_count = 4;
    i=0;

    game->locations[i].id = i;
    strcpy(game->locations[i].name, "bar");
    strcpy(game->locations[i].description, "scene of the crime");
    game->locations[i].clue_ids[0] = 3;
    game->locations[i].clue_ids[1] = 0;
    game->locations[i].clue_count = 2;
    ++i;

    game->locations[i].id = i;
    strcpy(game->locations[i].name, "morgue");
    strcpy(game->locations[i].description, "the victim's body is here");
    game->locations[i].clue_ids[0] = 1;
    game->locations[i].clue_count = 1;
    ++i;

    game->locations[i].id = i;
    // TODO: we should block this one without the fingerprint and bullet
    strcpy(game->locations[i].name, "suspect's home");
    strcpy(game->locations[i].description, "where the suspect lives");
    game->locations[i].clue_ids[0] = 2;
    game->locations[i].clue_count = 1;
    ++i;

    game->location_count=3;
    i=0;

    game->story_blocks[i].id=i;
    strcpy(game->story_blocks[i].text, "The suspect says they have never been to the scene.");
    game->story_blocks[i].can_question = 1;
    game->story_blocks[i].required_clue_id = 0;
    game->story_blocks[i].next_block_id = 1;
    game->story_blocks[i].question_success_block_id = 2;
    game->story_blocks[i].advances_to_investigation = 0;
    ++i;

    game->story_blocks[i].id=i;
    strcpy(game->story_blocks[i].text, "The suspect wants to go home now.");
    game->story_blocks[i].can_question = 0;
    game->story_blocks[i].required_clue_id = 0;
    game->story_blocks[i].next_block_id = 0;
    game->story_blocks[i].question_success_block_id = 0;
    game->story_blocks[i].advances_to_investigation = 0;
    ++i;

    game->story_blocks[i].id=i;
    strcpy(game->story_blocks[i].text, "The suspect says they don't like guns.");
    game->story_blocks[i].can_question = 2;
    game->story_blocks[i].required_clue_id = 0;
    game->story_blocks[i].next_block_id = 1;
    game->story_blocks[i].question_success_block_id = 3;
    game->story_blocks[i].advances_to_investigation = 0;
    ++i;

    game->story_blocks[i].id=i;
    strcpy(game->story_blocks[i].text, "The suspect says they didn't do it.");
    game->story_blocks[i].can_question = 2;
    game->story_blocks[i].required_clue_id = 1;
    game->story_blocks[i].next_block_id = 1;
    game->story_blocks[i].question_success_block_id = 3;
    game->story_blocks[i].advances_to_investigation = 1;
    ++i;

    game->story_block_count = i;
}

/*
 * Main game loop - handles state transitions and input
 */
void main_loop(GameData* game) {
    while (game->current_state != STATE_GAME_OVER) {
        switch (game->current_state) {
            case STATE_INVESTIGATION:
                handle_investigation(game);
                break;
            case STATE_COURTROOM:
                handle_courtroom(game);
                break;
            default:
                game->current_state = STATE_GAME_OVER;
                break;
        }
    }
}

/*
 * Investigation phase handler
 * Player moves between locations and examines clues
 */
void handle_investigation(GameData* game) {
    clear_screen();
    display_location(game);
    
    printf("\nCommands: 1-9 (examine clue), L (list locations), M (move), I (inventory), Q (quit)\n");
    printf("Enter command: ");
    
    int input = get_player_input();
    
    switch (input) {
        case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9': {
            int clue_index = input - '1';
            examine_clue(game, clue_index);
            break;
        }
        case 'L': case 'l':
            /* Display available locations */
            printf("\nAvailable locations:\n");
            for (int i = 0; i < game->location_count; i++) {
                printf("%d. %s\n", i, game->locations[i].name);
            }
            printf("Press any key to continue...");
            _getch();
            break;
        case 'M': case 'm':
            printf("Enter location number: ");
            input = get_player_input();
            if (input >= '0' && input < '0' + game->location_count) {
                game->current_location_id = input - '0';
            }
            break;
        case 'I': case 'i':
            show_inventory(game);
            break;
        case 'Q': case 'q':
            game->current_state = STATE_GAME_OVER;
            break;
    }
    
    check_investigation_complete(game);
}

/*
 * Courtroom phase handler
 * Player reads story blocks and can question with evidence
 */
void handle_courtroom(GameData* game) {
    clear_screen();
    display_story_block(game);
    
    StoryBlock* current_block = &game->story_blocks[game->current_story_block_id];
    
    printf("\nCommands: ");
    if (current_block->can_question) {
        printf("Q (question), ");
    }
    printf("P (proceed), X (quit)\n");
    printf("Enter command: ");
    
    int input = get_player_input();
    
    switch (input) {
        case 'Q': case 'q':
            if (current_block->can_question) {
                printf("\nSelect evidence to support your question:\n");
                int selected_clue = select_clue_from_inventory(game);
                
                if (selected_clue == current_block->required_clue_id) {
                    printf("\nCorrect! Your evidence supports the question.\n");
                    game->current_story_block_id = current_block->question_success_block_id;
                } else {
                    printf("\nThat evidence doesn't support your question.\n");
                }
                printf("Press any key to continue...");
                _getch();
            }
            break;
        case 'P': case 'p':
            if (current_block->advances_to_investigation) {
                game->current_state = STATE_INVESTIGATION;
                game->investigation_complete = 0; /* Reset for new investigation phase */
            } else {
                game->current_story_block_id = current_block->next_block_id;
            }
            break;
        case 'X': case 'x':
            game->current_state = STATE_GAME_OVER;
            break;
    }
}

/*
 * Display current location and available clues
 */
void display_location(GameData* game) {
    Location* loc = &game->locations[game->current_location_id];
    
    printf("=== %s ===\n", loc->name);
    printf("%s\n\n", loc->description);
    
    printf("Available clues to examine:\n");
    for (int i = 0; i < loc->clue_count; i++) {
        int clue_id = loc->clue_ids[i];
        /* Find the clue in the clues array */
        for (int j = 0; j < game->clue_count; j++) {
            if (game->clues[j].id == clue_id) {
                char status = game->clues[j].found ? '*' : ' ';
                printf("%d. %c%s\n", i + 1, status, game->clues[j].name);
                break;
            }
        }
    }
    printf("\n(* indicates clue already found)\n");
}

/*
 * Display current story block text
 */
void display_story_block(GameData* game) {
    StoryBlock* block = &game->story_blocks[game->current_story_block_id];
    
    printf("=== COURTROOM ===\n");
    printf("%s\n", block->text);
}

/*
 * Handle clue examination
 */
void examine_clue(GameData* game, int clue_index) {
    Location* loc = &game->locations[game->current_location_id];
    
    if (clue_index >= loc->clue_count) {
        printf("No clue at that number.\n");
        printf("Press any key to continue...");
        _getch();
        return;
    }
    
    int clue_id = loc->clue_ids[clue_index];
    
    /* Find and examine the clue */
    for (int i = 0; i < game->clue_count; i++) {
        if (game->clues[i].id == clue_id) {
            printf("\n%s\n", game->clues[i].description);
            
            if (!game->clues[i].found) {
                game->clues[i].found = 1;
                printf("\n[Added to evidence collection]\n");
            }
            
            printf("Press any key to continue...");
            _getch();
            break;
        }
    }
}

/*
 * Check if investigation phase is complete
 * Complete when all state-updating clues are found
 */
void check_investigation_complete(GameData* game) {
    int required_clues_found = 0;
    int total_required_clues = 0;
    
    for (int i = 0; i < game->clue_count; i++) {
        if (game->clues[i].updates_state) {
            total_required_clues++;
            if (game->clues[i].found) {
                required_clues_found++;
            }
        }
    }
    
    if (required_clues_found == total_required_clues && total_required_clues > 0) {
        game->investigation_complete = 1;
        printf("\nInvestigation complete! Moving to courtroom...\n");
        printf("Press any key to continue...");
        _getch();
        game->current_state = STATE_COURTROOM;
    }
}

/*
 * Display player's inventory of found clues
 */
void show_inventory(GameData* game) {
    clear_screen();
    printf("=== EVIDENCE COLLECTION ===\n");
    
    int found_count = 0;
    for (int i = 0; i < game->clue_count; i++) {
        if (game->clues[i].found) {
            printf("%d. %s\n", found_count + 1, game->clues[i].name);
            found_count++;
        }
    }
    
    if (found_count == 0) {
        printf("No evidence collected yet.\n");
    }
    
    printf("\nPress any key to continue...");
    _getch();
}

/*
 * Let player select a clue from inventory
 * Returns clue ID of selected clue, or -1 if cancelled
 */
int select_clue_from_inventory(GameData* game) {
    int found_clues[MAX_CLUES];
    int found_count = 0;
    
    /* Build array of found clues */
    for (int i = 0; i < game->clue_count; i++) {
        if (game->clues[i].found) {
            found_clues[found_count] = game->clues[i].id;
            printf("%d. %s\n", found_count + 1, game->clues[i].name);
            found_count++;
        }
    }
    
    if (found_count == 0) {
        printf("No evidence available.\n");
        return -1;
    }
    
    printf("Enter number (1-%d): ", found_count);
    int input = get_player_input();
    
    if (input >= '1' && input <= '0' + found_count) {
        return found_clues[input - '1'];
    }
    
    return -1;
}

/*
 * Get single character input from player
 */
int get_player_input(void) {
    int ch = _getch();
    printf("%c\n", ch);  /* Echo the character */
    return ch;
}

/*
 * Clear screen using system-specific method
 */
void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*
 * Main function - entry point
 */
int main(void) {
    GameData game;
    
    init_game(&game);
    main_loop(&game);
    
    printf("Game ended.\n");
    return 0;
}

/*
 * DATA STRUCTURE GUIDELINES:
 * 
 * 1. LOCATIONS: Create location data with unique IDs, names, descriptions,
 *    and arrays of clue IDs that can be found there (mapped to number keys 1-9)
 *
 * 2. CLUES: Each clue has ID, name, description, location, and flags for:
 *    - updates_state: Required clues to complete investigation
 *    - found: Tracking if player has discovered it
 *
 * 3. STORY BLOCKS: Courtroom content with:
 *    - Sequential story text
 *    - can_question flag for interactive blocks
 *    - required_clue_id for successful questioning
 *    - next_block_id for story progression
 *    - question_success_block_id for alternate paths
 *    - advances_to_investigation flag to return to investigation
 *
 * 4. GAME FLOW:
 *    - Investigation: Find all update_state clues to proceed
 *    - Courtroom: Progress through story blocks, question with evidence
 *    - Return to investigation when story block sets advances_to_investigation
 *
 * 5. DATA LOADING: Implement file loading in init_game() to populate
 *    locations, clues, and story_blocks arrays from external data files
 */