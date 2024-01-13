/**
* @file menu.c
* @author Emanuel Pinto
* @date 21-12-2023
* @version 1
*
* @brief Implementation of menu-related functions for program navigation.
*
* This file contains the implementation of functions related to program menus and user interactions.
*/

#include "stdio.h"
#include "stdlib.h"
#include "menu.h"

/**
 * @brief Displays the main menu and allows the user to navigate to different sections.
 *
 * @param company A pointer to the COMPANIES structure.
 * @param business A pointer to the BUSINESS structure.
 * @param comments A pointer to the COMMENTS structure.
 * @param ratings A pointer to the RATINGS structure.
 */
void mainMenu(COMPANIES *company, BUSINESS *business, COMMENTS *comments, RATINGS *ratings) {
    int op;

    do {
        printf("\nMAIN MENU\n");
        printf("1. USER\n");
        printf("2. ADMIN\n");
        printf("0. EXIT\n");
        printf("CHOOSE OPTION: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                userMenu(company, business, comments, ratings);
                break;
            case 2:
                adminMenu(company, business, comments, ratings);
                break;
            default:
                puts(ERROR);
        }
    } while (op != 0);
    exportComments(*comments);
    exportBline(*business);
    exportCompanies(*company);
    exit(1);
}

/**
 * @brief Displays the admin menu and allows the admin to manage companies, business lines, and generate reports.
 *
 * @param company A pointer to the COMPANIES structure.
 * @param business A pointer to the BUSINESS structure.
 * @param comments A pointer to the COMMENTS structure.
 * @param ratings A pointer to the RATINGS structure.
 */
void adminMenu(COMPANIES *company, BUSINESS *business, COMMENTS *comments, RATINGS *ratings) {
    int op = 0;

    do {
        printf("\nADMIN MENU\n");
        printf("1. Manage companies\n");
        printf("2. Manage business lines\n");
        printf("3. Reports\n");
        printf("5. Go back\n");
        printf("CHOOSE OPTION: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                manageComp(company, business, comments, ratings);
                break;
            case 2:
                manageBusLine(company, business, comments, ratings);
                break;
            case 3:
                reportMenu(company, business, comments, ratings);
                break;
            case 5:
                mainMenu(company, business, comments, ratings);
                break;
            default:
                puts(ERROR);
        }
    } while (op != 0);

}

/**
 * @brief Displays the report menu and allows the admin to generate different types of reports.
 *
 * @param company A pointer to the COMPANIES structure.
 * @param business A pointer to the BUSINESS structure.
 * @param comments A pointer to the COMMENTS structure.
 * @param ratings A pointer to the RATINGS structure.
 */
void reportMenu(COMPANIES *company, BUSINESS *business, COMMENTS *comments, RATINGS *ratings) {
    int op = 0;

    do {
        printf("\nMANAGE COMPANY\n");
        printf("1. Last Comments\n");
        printf("2. Best companies\n");
        printf("3. Go back\n");
        printf("CHOOSE OPTION: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                lastComment(*company, *comments);
                reportMenu(company, business, comments, ratings);
                break;
            case 2:
                printTopComp(company);
                reportMenu(company, business, comments, ratings);
                break;
            case 3:
                adminMenu(company, business, comments, ratings);
                break;
            default:
                puts(ERROR);
        }
    } while (op != 0);

}

/**
 * @brief Displays the menu for managing companies and allows the admin to insert, update, list, and delete companies.
 *
 * @param company A pointer to the COMPANIES structure.
 * @param business A pointer to the BUSINESS structure.
 * @param comments A pointer to the COMMENTS structure.
 * @param ratings A pointer to the RATINGS structure.
 */
void manageComp(COMPANIES *company, BUSINESS *business, COMMENTS *comments, RATINGS *ratings) {
    int op = 0;

    do {
        printf("\nMANAGE COMPANY\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. List\n");
        printf("4. Delete\n");
        printf("5. Go back\n");
        printf("CHOOSE OPTION: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                insertComp(company, business, ratings);
                manageComp(company, business, comments, ratings);
                break;
            case 2:
                updateComps(company, business);
                manageComp(company, business, comments, ratings);
                break;
            case 3:
                listComp(*company, *business, *comments);
                manageComp(company, business, comments, ratings);
                break;
            case 4:
                deleteComp(company, comments);
                manageComp(company, business, comments, ratings);
                break;
            case 5:
                adminMenu(company, business, comments, ratings);
                break;
            default:
                puts(ERROR);
        }
    } while (op != 0);

}

/**
 * @brief Displays the menu for managing business lines and allows the admin to insert, update, list, and delete business lines.
 *
 * @param company A pointer to the COMPANIES structure.
 * @param business A pointer to the BUSINESS structure.
 * @param comments A pointer to the COMMENTS structure.
 * @param ratings A pointer to the RATINGS structure.
 */
void manageBusLine(COMPANIES *company, BUSINESS *business, COMMENTS *comments, RATINGS *ratings) {
    int op = 0;

    do {
        printf("\nMANAGE BUSINESS LINES\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. List\n");
        printf("4. Delete\n");
        printf("5. Go back\n");
        printf("CHOOSE OPTION: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                insertBusLine(business);
                manageBusLine(company, business, comments, ratings);
                break;
            case 2:
                updateBusLine(business);
                manageBusLine(company, business, comments, ratings);
                break;
            case 3:
                listBusLine(business);
                manageBusLine(company, business, comments, ratings);
                break;
            case 4:
                deleteBusLine(business,company);
                manageBusLine(company, business, comments, ratings);
                break;
            case 5:
                adminMenu(company, business, comments, ratings);
                break;
            default:
                puts(ERROR);
        }
    } while (op != 0);

}

/**
 * @brief Displays the user menu and allows the user to search for companies.
 *
 * @param company A pointer to the COMPANIES structure.
 * @param business A pointer to the BUSINESS structure.
 * @param comments A pointer to the COMMENTS structure.
 * @param ratings A pointer to the RATINGS structure.
 */
void userMenu(COMPANIES *company, BUSINESS *business, COMMENTS *comments, RATINGS *ratings) {
    int userOp;
    do {
        printf("\nUSER MENU\n");
        printf("1. Search company\n");
        printf("2. Go back\n");
        printf("CHOOSE OPTION: ");
        scanf("%d", &userOp);

        switch (userOp) {
            case 1:
                searchMenu(company, business, comments, ratings);
                break;
            case 2:
                mainMenu(company, business, comments, ratings);
                break;
            default:
                puts(ERROR);
        }
    } while (userOp != 0);

}

/**
 * @brief Displays the rating and comment menu for a company and allows the user to rate or comment on a company.
 *
 * @param company A pointer to the COMPANIES structure.
 * @param business A pointer to the BUSINESS structure.
 * @param comments A pointer to the COMMENTS structure.
 * @param ratings A pointer to the RATINGS structure.
 */
void rateComMenu(COMPANIES *company, BUSINESS *business, COMMENTS *comments, RATINGS *ratings) {
    int userOp;
    do {
        printf("\nSEARCH MENU\n");
        printf("1. Rate company\n");
        printf("2. Comment company\n");
        printf("3. Go back\n");
        printf("CHOOSE OPTION: ");
        scanf("%d", &userOp);
        switch (userOp) {
            case 1:
                insertRating(*company, ratings);
                rateComMenu(company, business, comments, ratings);
                break;
            case 2:
                insertComm(comments, *company);
                rateComMenu(company, business, comments, ratings);
                break;
            case 3:
                searchMenu(company, business, comments, ratings);
                break;
            default:
                puts(ERROR);
        }
    } while (userOp != 0);

}

/**
 * @brief Displays the search menu for a user and allows them to search for companies by name, business line, or postal code.
 *
 * @param company A pointer to the COMPANIES structure.
 * @param business A pointer to the BUSINESS structure.
 * @param comments A pointer to the COMMENTS structure.
 * @param ratings A pointer to the RATINGS structure.
 */
void searchMenu(COMPANIES *company, BUSINESS *business, COMMENTS *comments, RATINGS *ratings) {
    int userOp;
    do {
        printf("\nSEARCH MENU\n");
        printf("1. Name\n");
        printf("2. Business Line\n");
        printf("3. Postal Code\n");
        printf("4. Go Back\n");
        printf("CHOOSE OPTION: ");
        scanf("%d", &userOp);
        switch (userOp) {
            case 1:
                searchCompByName(company, business);
                rateComMenu(company, business, comments, ratings);
                break;
            case 2:
                searchComByBl(company, business);
                rateComMenu(company, business, comments, ratings);
                break;
            case 3:
                searchCompByCP(company, business);
                rateComMenu(company, business, comments, ratings);
                break;
            case 4:
                userMenu(company, business, comments, ratings);
                break;
            default:
                puts(ERROR);
        }
    } while (userOp != 0);

}