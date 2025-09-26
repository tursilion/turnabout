// let the user see their inventory

#include <raylib.h>

#include "structures.h"
#include "engine.h"
#include <conio.h>

// returns the element selected (might be an item or it might be a person)
int run_inventory() {
    // just a text display - so need a custom draw function
    // arrow keys to move a selector up and down, left and right to page
    // pages move to people when at end of inventory
    // enter to select and exit - no cancel needed
    return EV_NONE;
}
