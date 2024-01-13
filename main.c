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


#include "stdlib.h"
#include "company.h"
#include "menu.h"
#include "businessLines.h"
#include "general.h"

int main() {

    COMPANIES *companies;
    companies = (COMPANIES*)malloc(sizeof(COMPANIES) * INITIAL_SIZE);
    companies->company = (COMPANY*)malloc(sizeof(COMPANY) * INITIAL_SIZE);
    companies->count = 0;

    BUSINESS *business;
    business = (BUSINESS*)malloc(sizeof(BUSINESS) * INITIAL_SIZE);
    business->business = (BUS_LINE*)malloc(sizeof(BUS_LINE) * INITIAL_SIZE);
    business->count = 0;

    COMMENTS *comments;
    comments = (COMMENTS*)malloc(sizeof(COMMENTS) * INITIAL_SIZE);
    comments->comment = (COMMENT*)malloc(sizeof(COMMENT) * INITIAL_SIZE);
    comments->count = 0;

    RATINGS *ratings;
    ratings = (RATINGS*)malloc(sizeof(RATINGS) * INITIAL_SIZE);
    ratings->rating = (RATING*)malloc(sizeof(RATING) * INITIAL_SIZE);
    ratings->count = 0;
     importCompanies( companies);
     importBl(business);
     importComments(comments);

    mainMenu(companies, business, comments, ratings);



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