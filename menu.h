/**
* @file menu.h
* @author Emanuel Pinto
* @date 27-12-2023
* @version 1
*
* @copyright Copyright (C) Emanuel 2023. All Rights MIT Licensed.
*
* @brief A header file providing utility functions for the main menu.
*
* This  file contains a collection of functions designed to make the menu and interact with it
* in a C or C++ program. It includes functions for all the menu
*/

#ifndef TP_LP_MENU_H
#define TP_LP_MENU_H
#include "company.h"
#include "businessLines.h"
#include "search.h"
#include "user.h"

void mainMenu(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings);
void adminMenu(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings);
void manageComp(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings);
void manageBusLine(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings);
void userMenu(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings);
void searchMenu(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings);
void reportMenu(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings);
#endif //TP_LP_MENU_H
