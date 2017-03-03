//
// Created by Angel Zaprianov on 23.2.2017 г..
//

#ifndef ARDUINO_MID_MENU240X64_H
#define ARDUINO_MID_MENU240X64_H

#include <Arduino.h>
#include "../conf.h"
#include "MenuBtn.h"
#include "MenuBase.h"
#include <MenuBackend.h>


#define MENU_NAME_1 "Home"
#define MENU_NAME_11 "Panel"
#define MENU_NAME_12 "Test"

#define MENU_NAME_2 "Fuel"
#define MENU_NAME_3 "Servicing"
#define MENU_NAME_4 "Challenges"


/**
 *
 */
class Menu240x60 : public MenuBase  {


    MenuItem
    //
    // Main menu
            mainMenu,
            dshBoardMenu,
            testingsMenu,
    //
    // Fuel tank
            fuelMenu,
    //
    // States
            statMenu,
    //
    // Sprint
            gamesMenu;
public:

    Menu240x60(MenuBtn *_btn) :
            MenuBase(_btn),//  base menu initialization
            //
            // Main menu
            mainMenu(MenuItem(MENU_NAME_1)),
            dshBoardMenu(MenuItem(MENU_NAME_11)),
            testingsMenu(MenuItem(MENU_NAME_12)),
            //
            // Fuels menu
            fuelMenu(MenuItem(MENU_NAME_3)),
            //
            // Servicing menu
            statMenu(MenuItem(MENU_NAME_3)),
            //
            // Challenges Menu
            gamesMenu(MenuItem(MENU_NAME_4)) {
    }

    void setup(void);

    void menuChanged(MenuChangeEvent change) {
        MenuItem curMenuItem = change.to; //get the destination menu
        const char *curMenuName = curMenuItem.getName();

        if (curMenuName == MENU_NAME_1) {
            MidCursorMenu = 1;
        } else if (curMenuName == MENU_NAME_11) {
            MidCursorMenu = 11;
        } else if (curMenuName == MENU_NAME_12) {
            MidCursorMenu = 12;
        } else if (curMenuName == MENU_NAME_2) {
            //
            // Fuel Menu
        } else if (curMenuName == MENU_NAME_3) {
            MidCursorMenu = 3;
            //
            // Car State Menu
        } else if (curMenuName == MENU_NAME_4) {
            MidCursorMenu = 4;
        }
    }

};


void Menu240x60::setup() {

}

#endif //ARDUINOMID_MENU240X64_H