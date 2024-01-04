
//
// Created by Emanuel Pinto on 16/12/2023.
//
#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "company.h"
#include "input.h"

 char *showBLine(int bl){
     BUSINESS **business ;
    char *name;
    for (int i = 0; i < (*business)->count; ++i) {
        if(bl ==(*business)->business[i].id){
            strcpy(name, (*business)->business[i].name);

        }
    }
     return name;
}
void printComp(COMPANY company) {
    printf("%d   %s   %d   %d   %s %s %s   %d",company.nif,company.name,company.category, showBLine(company.business_line),company.address.street,company.address.CP,company.address.city,company.state);
}


void listComp(COMPANIES companies) {
    if (companies.count > 0) {
        int i;
        for (i = 0; i < companies.count; i++) {
            printComp(companies.company[i]);
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

void searchComp(COMPANIES companies) {


}
void insertCompBus(COMPANIES *companies, BUSINESS **busLine){
    int bus_line;
    do {
        listBusLine(*busLine);
        bus_line=getInt(1,800,BUSINESS_LINE);
        for (int i = 0; i < (*busLine)->count; ++i) {
            if(bus_line == (*busLine)->business->id){
                companies->company[companies->count].business_line = bus_line;
            }
        }
    } while (bus_line!=(*busLine)->business->id);
}
//INSERT COMP
int insertComps(COMPANIES *companies,BUSINESS *business) {
    int nif;

    nif= getInt(NIF_MIN,NIF_MAX,"Insert the company NIF: ");

    if (searchComps(*companies, nif) == -1) {

        companies->company[companies->count].nif = nif;
        getString(companies->company[companies->count].name,CHAR_MAX,COMP_NAME);
        companies->company[companies->count].category=getInt(CATG_MIN,CATG_MAX,COMP_CATG);
        insertCompBus(companies,business);
        getString(companies->company[companies->count].address.street,CHAR_MAX,COMP_STREET);
        getString(companies->company[companies->count].address.city,CHAR_MAX,COMP_CITY);
        getString(companies->company[companies->count].address.CP,8,COMP_CP);
        companies->company[companies->count].state= getInt(0,1,COMP_STATE);
        return companies->count++;
    }
    return -1;
}


void insertComp(COMPANIES *companies,BUSINESS *business) {
    if (companies->count < 2) {
        if (insertComps(companies,business) == -1) {
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
    strcpy(company->address.CP,"");
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