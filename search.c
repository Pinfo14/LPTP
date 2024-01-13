/**
* @file search.c
* @author Emanuel Pinto
* @date 11-01-2024
* @version 1
*
* @brief Implementation of functions for searching and retrieving company information.
*
* This file contains the implementation of functions designed to search and retrieve information
* about companies based on different criteria such as name, business line, and postal code.
*/

#include "search.h"

/**
 * @brief Searches for the state of a company based on its NIF.
 *
 * @param companies A COMPANIES structure
 * @param nif The NIF of the company to search for.
 * @return The state of the company (company state if found, 0 if not found).
 */
int searchCompstate(COMPANIES companies, int nif) {
    int i;
    int state = 0;
    for (i = 0; i < companies.count; i++) {
        if (companies.company[i].nif == nif) {
            state = companies.company[i].state;
        }
    }
    return state;
}

/**
 * @brief Searches for the position of a company based on its NIF .
 *
 * @param companies A COMPANIES structure .
 * @param nif The NIF of the company to search for.
 * @return The position of the company in the array (-1 if not found).
 */
int searchComps(COMPANIES companies, int nif) {
    int i;
    for (i = 0; i < companies.count; i++) {
        if (companies.company[i].nif == nif) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Searches for a company by its NIF and prints its details.
 *
 * @param companies A COMPANIES structure .
 * @param business A pointer to the BUSINESS s.
 * @param comments A COMMENTS structure .
 */
void searchComp(COMPANIES companies, BUSINESS *business, COMMENTS comments) {
    int nif = getInt(NIF_MIN, NIF_MAX, NIF_MSG);
    int position = searchComps(companies, nif);

    if (position != -1) {
        printComp(companies.company[position], business, &comments);
    } else {
        puts(ERROR);
    }
}

/**
 * @brief Searches for companies based on their name and prints the details of the matching companies.
 *
 * @param companies A pointer to the COMPANIES.
 * @param business A pointer to the BUSINESS .
 */
void searchCompByName(COMPANIES *companies, BUSINESS *business) {
    char name[CHAR_MAX];

    printf("Insert company name: ");
    scanf("%s", name);

    for (int i = 0; i < companies->count; i++) {
        if (strstr(companies->company[i].name, name) && companies->company[i].state != 0) {
            printf("\nCompany found:\n");
            printf("NIF: %d\n", companies->company[i].nif);
            printf("Name: %s\n", companies->company[i].name);
            printf("Category: %s\n", showCatg(companies->company[i].category));
            printf("Business line: %s\n", showBLine(companies->company[i].business_line, &business));
        }
    }
}

/**
 * @brief Searches for companies based on their business line and prints the details of the matching companies.
 *
 * @param companies A pointer to the COMPANIES .
 * @param business A pointer to the BUSINESS .
 */
void searchComByBl(COMPANIES *companies, BUSINESS *business) {
    char name[CHAR_MAX];

    printf("Insert Business line name: ");
    scanf("%s", name);

    for (int i = 0; i < companies->count; i++) {
        if (strstr(business->business[i].name, name) && companies->company[i].state != 0) {
            printf("\nCompany found:\n");
            printf("NIF: %d\n", companies->company[i].nif);
            printf("Name: %s\n", companies->company[i].name);
            printf("Category: %s\n", showCatg(companies->company[i].category));
            printf("Business line: %s\n", showBLine(companies->company[i].business_line, &business));
        }
    }
}

/**
 * @brief Searches for companies based on their postal code and prints the details of the matching companies.
 *
 * @param companies A pointer to the COMPANIES .
 * @param business A pointer to the BUSINESS .
 */
void searchCompByCP(COMPANIES *companies, BUSINESS *business) {
    char postalCode[CHAR_MAX];

    printf("Insert company postal code: ");
    scanf("%s", postalCode);

    for (int i = 0; i < companies->count; i++) {
        if (strstr(companies->company[i].address.cp, postalCode) && companies->company[i].state != 0) {
            printf("\nCompany found:\n");
            printf("NIF: %d\n", companies->company[i].nif);
            printf("Name: %s\n", companies->company[i].name);
            printf("Category: %s\n", showCatg(companies->company[i].category));
            printf("Business line: %s\n", showBLine(companies->company[i].business_line, &business));
        }
    }
}