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