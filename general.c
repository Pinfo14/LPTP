//
// Created by emanuel on 11-01-2024.
//

#include "general.h"



char *showCompName(int nif,COMPANIES **company){

    char *name=(char*)malloc(sizeof(char)*10);
    for (int i = 0;(*company)->count > i; ++i) {
        if(nif ==(*company)->company[i].nif){
            strcpy(name, (*company)->company[i].name);

        }
    }
    return name;
}

// used to show de state INACTIVE or ACTIVE instead of 0 or 1
char *showState(int state){
    char*stateChar=(char*) malloc(sizeof(char)*10 );
    switch (state) {
        case 0:
            strcpy(stateChar,"INACTIVE");
            break;
        case 1:
            strcpy(stateChar,"ACTIVE");
            break;
        default:
            printf("EROOR");
    }
    return stateChar;
}

// used to show de category name instead of the representative number
char *showCatg(int catg){
    char *catgName=(char*) malloc(sizeof(char)*10 );
    switch (catg) {
        case 1:
            strcpy(catgName,"Micro");
            break;
        case 2:
            strcpy(catgName,"PME");
            break;
        case 3:
            strcpy(catgName,"Big");
            break;
        default:
            printf("EROOR");
    }
    return catgName;
}
// used to show the category instead of the id
char *showBLine(int bl,BUSINESS **business){

    char *name=(char*)malloc(sizeof(char)*10);
    for (int i = 0;(*business)->count > i; ++i) {
        if(bl ==(*business)->business[i].id){
            strcpy(name, (*business)->business[i].name);
        }
    }
    return name;
}

