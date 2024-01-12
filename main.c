/**
 * @file main.c
 * @author Emanuel Pinto
 * @date 16-12-2023
 * @version 1
 *
 * @brief Main file for the program.
 *
 * This file contains the main function.
 * It initializes the data structures, displays the main menu, and exports data before exiting.
 */

#include <stdio.h>
#include "stdlib.h"
#include "company.h"
#include "menu.h"
#include "businessLines.h"
#include "general.h"

/**
 * @brief The main function of the program.
 */
int main() {
    // Initialize companies structure
    COMPANIES *companies;
    companies = (COMPANIES*)malloc(sizeof(COMPANIES) * INITIAL_SIZE);
    companies->company = (COMPANY*)malloc(sizeof(COMPANY) * INITIAL_SIZE);
    companies->count = 0;

    // Initialize business structure
    BUSINESS *business;
    business = (BUSINESS*)malloc(sizeof(BUSINESS) * INITIAL_SIZE);
    business->business = (BUS_LINE*)malloc(sizeof(BUS_LINE) * INITIAL_SIZE);
    business->count = 0;

    // Initialize comments structure
    COMMENTS *comments;
    comments = (COMMENTS*)malloc(sizeof(COMMENTS) * INITIAL_SIZE);
    comments->comment = (COMMENT*)malloc(sizeof(COMMENT) * INITIAL_SIZE);
    comments->count = 0;

    // Initialize ratings structure
    RATINGS *ratings;
    ratings = (RATINGS*)malloc(sizeof(RATINGS) * INITIAL_SIZE);
    ratings->rating = (RATING*)malloc(sizeof(RATING) * INITIAL_SIZE);
    ratings->count = 0;

    // Initialize program data
    initializeProgram(companies, business, comments);

    // Display main menu
    mainMenu(companies, business, comments, ratings);

    // Export data before exiting
    exportData(companies, business, comments);

    // Free allocated memory
    free(companies->company);
    free(companies);
    free(business->business);
    free(business);
    free(comments->comment);
    free(comments);
    free(ratings->rating);
    free(ratings);

    return 0;
}