//
// Created by emanuel on 11-01-2024.
//

#include "search.h"


int searchCompstate(COMPANIES companies, int nif) {
    int i;
    int state =0;
    for (i = 0; i < companies.count; i++) {
        if (companies.company[i].nif == nif) {
            state= companies.company[i].state;
        }
    }
    return state;
}

int searchComps(COMPANIES companies, int nif) {
    int i;
    for (i = 0; i < companies.count; i++) {
        if (companies.company[i].nif == nif) {
            return i;
        }
    }
    return -1;
}

void searchComp(COMPANIES companies,BUSINESS *business,COMMENTS comments) {
    int nif = getInt(NIF_MIN, NIF_MAX, NIF_MSG);
    int position = searchComps(companies,nif);

    if (position != -1) {
        printComp(companies.company[position],business,&comments);
    } else {
        puts(ERROR);
    }

}

void searchCompByName( COMPANIES *companies,BUSINESS *business) {

    char name[CHAR_MAX];

    printf("Insert company name: ");
    scanf("%s",name);

    for (int i = 0; i < companies->count; i++) {
        if (strstr(companies->company[i].name, name)) {

            printf("\nCompany found:\n");
            printf("NIF: %d\n",companies->company[i].nif);
            printf("Name: %s\n",companies->company[i].name);
            printf("Category: %s\n", showCatg(companies->company[i].category));
            printf("Business line: %s\n", showBLine(companies->company[i].business_line,&business));

        }
    }
}


void searchComByBl( COMPANIES *companies,BUSINESS *business) {

    char name[CHAR_MAX];

    printf("Insert Business line name: ");
    scanf("%s",name);

    for (int i = 0; i < companies->count; i++) {
        if (strstr(business->business[i].name, name) ) {

            printf("\nCompany found:\n");
            printf("NIF: %d\n",companies->company[i].nif);
            printf("Name: %s\n",companies->company[i].name);
            printf("Category: %s\n", showCatg(companies->company[i].category));
            printf("Business line: %s\n", showBLine(companies->company[i].business_line,&business));

        }
    }
}


void searchCompByCP( COMPANIES *companies,BUSINESS *business) {

    char name[CHAR_MAX];

    printf("Insert company postal code: ");
    scanf("%s",name);

    for (int i = 0; i < companies->count; i++) {
        if (strstr(companies->company[i].address.cp, name)) {

            printf("\nCompany found:\n");
            printf("NIF: %d\n",companies->company[i].nif);
            printf("Name: %s\n",companies->company[i].name);
            printf("Category: %s\n", showCatg(companies->company[i].category));
            printf("Business line: %s\n", showBLine(companies->company[i].business_line,&business));

        }
    }
}


//Reports

