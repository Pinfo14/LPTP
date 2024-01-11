
//
// Created by Emanuel Pinto on 16/12/2023.
//
#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "company.h"
#include "input.h"
#include "businessLines.h"


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

void showCom(int nif,COMMENTS *comments){

    for (int i = 0;comments->count > i; ++i) {
        if(nif ==comments->comment[i].compNif){
         printf("%s / %s / %s\n",comments->comment[i].userName,comments->comment[i].userEmail,comments->comment[i].comment) ;
        }
    }
}




void printComp(COMPANY company,BUSINESS *business,COMMENTS *comments) {
    char *busLine=showBLine(company.business_line,&business);
    char *catgName=showCatg(company.category);
    char *state= showState(company.state);
    printf("%d   %s   %s   %s   %s %s %s   %s\n",company.nif,company.name, catgName,busLine ,company.address.street,company.address.cp,company.address.city,state);
    printf("RATE: %.2f \n",company.rate);
    puts(COMMENT_LINE);
    showCom(company.nif,comments);
    free(busLine);
    free(catgName);
    free(state);
}


void listComp(COMPANIES companies,BUSINESS business,COMMENTS comments) {
    if (companies.count > 0) {
        int i;
        for (i = 0; i < companies.count; i++) {
            printComp(companies.company[i],&business,&comments);
        }
    } else {
        puts("ja foste");
    }
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
void insertCompBus(COMPANIES *companies, BUSINESS *busLine) {
    int bus_line;
    int found = 0;
    if(busLine->count!=0) {
        do {
            listBusLine(busLine);
            bus_line = getInt(ID_MIN, ID_MAX, BUSINESS_LINE);
            for (int i = 0; i < busLine->count; ++i) {
                if (bus_line == busLine->business[i].id) {
                    companies->company[companies->count].business_line = bus_line;
                    found = 1;
                    break;
                }
            }
            if (!found) {

                printf("Invalid business line. Please try again.\n");
            }
        } while (found != 1);
    }else{
        insertBusLine(busLine);
        insertCompBus(companies,busLine);
    }
}

//INSERT COMP
int insertComps(COMPANIES *companies,BUSINESS *business,RATINGS *ratings) {
    int nif;
    nif= getInt(NIF_MIN,NIF_MAX,NIF_MSG);
    if (searchComps(*companies, nif) == -1) {
        companies->company[companies->count].nif = nif;
        companies->company[companies->count].rate=0;
        getString(companies->company[companies->count].name,CHAR_MAX,COMP_NAME);
        companies->company[companies->count].category=getInt(CATG_MIN,CATG_MAX,COMP_CATG);
        insertCompBus(companies, business);
        getString(companies->company[companies->count].address.street,CHAR_MAX,COMP_STREET);
        getString(companies->company[companies->count].address.city,CHAR_MAX,COMP_CITY);
        getString(companies->company[companies->count].address.cp,CP_MAX,COMP_CP);
        companies->company[companies->count].state= getInt(0,1,COMP_STATE);
        return companies->count++;
    }
    return -1;
}


void insertComp(COMPANIES *companies,BUSINESS *business,RATINGS *ratings) {
    if (companies->count < 10) {
        if (insertComps(companies,business,ratings) == -1) {
            puts(ERROR);
        }
    } else {
        puts(ERROR);
    }
}

void deleteCompData(COMPANY *company) {
    company->nif=0;
    strcpy(company->name,"");
    strcpy(company->address.city,"");
    strcpy(company->address.street,"");
    strcpy(company->address.cp,"");
    company->business_line=0;
    company->category=0;
    company->state=-1;
}

void deleteComp(COMPANIES *companies){

    int i;
    int nif = searchComps(*companies, getInt(NIF_MIN,NIF_MAX,NIF_MSG));
    if(nif != -1){
        for (i=nif ; i <companies->count-1 ; i++) {
            companies->company[i]=companies->company[i+1];
        }
        deleteCompData(&companies->company[i]);
        companies->count--;
    }else{
        printf("COMPANY DON'T EXIST");
    }
}
void updateBLComp(COMPANY *company,BUSINESS *business){
    int bus_line;
    int found=0;
    do {
        listBusLine(business);
        bus_line = getInt(ID_MIN, ID_MAX, BUSINESS_LINE);

        // Assume bus_line is not found initially


        for (int i = 0; i < business->count; ++i) {
            if (bus_line == business->business[i].id) {
             company->business_line = bus_line;
                found = 1;
                // Exit the loop after finding a match
                break;
            }
        }

        // If bus_line is not found, you might want to handle that case
        if (!found) {

            printf("Invalid business line. Please try again.\n");
        }

    } while (found!=1);
}
void updateComp(COMPANY *company,BUSINESS *business) {
    float rating = company->rate;
    company->rate =rating;
    getString(company->name, CHAR_MAX, COMP_NAME);
    company->category=getInt(CATG_MIN,CATG_MAX,COMP_CATG);
    updateBLComp(company,business);
    getString(company->address.street,CHAR_MAX,COMP_STREET);
    getString(company->address.city,CHAR_MAX,COMP_CITY);
    getString(company->address.cp,CP_MAX,COMP_CP);
    company->state= getInt(0,1,COMP_STATE);
}

void updateComps(COMPANIES *companies,BUSINESS *business) {
    int position = searchComps(*companies, getInt(NIF_MIN ,NIF_MAX, NIF_MSG));

    if (position != -1) {
        updateComp(&companies->company[position], business);
    } else {
        puts("ERROR COMPANY NOT FOUND!!");
    }
}
//comments

char *showCompName(int nif,COMPANIES **company){

    char *name=(char*)malloc(sizeof(char)*10);
    for (int i = 0;(*company)->count > i; ++i) {
        if(nif ==(*company)->company[i].nif){
            strcpy(name, (*company)->company[i].name);

        }
    }
    return name;
}




int insertCom(COMMENTS *comment,COMPANIES companies){
    int nif = getInt(NIF_MIN,NIF_MAX,NIF_MSG);
    int state = searchCompstate(companies, nif);
    if(state!= 0 ){
        comment->comment[comment->count].compNif =nif;
        getString(comment->comment[comment->count].userName,USER_NAME_MAX,NAME_MSG);
        getString(comment->comment[comment->count].userEmail,EMAIL_MAX,EMAIL_MSG);
        getString(comment->comment[comment->count].comment,COMMENT_MAX,COMMENT_MSG);
        comment->count++;
        return 1;
    }
    return -1;
}

void insertComm(COMMENTS *comment,COMPANIES companies){
    if(insertCom(comment,companies) ==-1){
        puts(ERROR);
    }
}

void printComm(COMMENTS *comment,COMPANIES *company){
    int nif=comment->comment->compNif;
    char *compName = showCompName(nif,&company);
    printf("%s  %s  %s  %s", compName,comment->comment->userName,comment->comment->userEmail,comment->comment->comment);
    free(compName);
}

void updateMedRateForCompany(int comNif, RATINGS *ratings, COMPANIES *companies) {
    float totalRating = 0;
    int count = 0;


    // Itera sobre todas as classificações para encontrar as classificações para a empresa específica
    for (int i = 0; i < ratings->count; ++i) {
        if(companies->company[i].rate !=0){
            count =1;
        }
        if (comNif == ratings->rating[i].comNif) {
            totalRating = companies->company[i].rate;
            totalRating += ratings->rating[i].rating;
            count++;
        }
    }

    // Atualiza o campo rate da empresa se houver classificações e a média mudou
    int position = searchComps(*companies, comNif);
    if (position != -1 && count > 0) {
        // Calcula a média das classificações
        float medRate = totalRating / count;

        // Atualiza o campo rate apenas se a média mudou
        if (medRate != companies->company[position].rate) {
            companies->company[position].rate = medRate;
        }
    }
}

int insertRatings(COMPANIES companies, RATINGS *ratings) {
    int nif = getInt(NIF_MIN, NIF_MAX, NIF_MSG);
    int position = searchComps(companies, nif);

    if (position != -1) {
        ratings->rating->comNif = nif;
        ratings->rating->rating = getInt(RATE_MIN, RATE_MAX, RATE_MSG);
        ratings->count++;

        // Atualiza a média das classificações para a empresa específica
        updateMedRateForCompany(nif, ratings, &companies);

        return 1;
    }

    return -1;
}

void insertRating(COMPANIES companies,RATINGS *ratings){

    if(insertRatings(companies,ratings)==-1){
        printf(ERROR);
    }
}