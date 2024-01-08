
//
// Created by Emanuel Pinto on 16/12/2023.
//
#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "company.h"
#include "input.h"

 char *showBLine(int bl,BUSINESS **business){

     char *name=(char*)malloc(sizeof(char)*10);
    for (int i = 0;(*business)->count > i; ++i) {
        if(bl ==(*business)->business[i].id){
            strcpy(name, (*business)->business[i].name);

        }
    }
     return name;
}
void printComp(COMPANY company,BUSINESS *business) {
    char *busLine=showBLine(company.business_line,&business);
    printf("%d   %s   %d   %s   %s %s %s   %d",company.nif,company.name,company.category,busLine ,company.address.street,company.address.cp,company.address.city,company.state);
   free(busLine);
}


void listComp(COMPANIES companies,BUSINESS business) {
    if (companies.count > 0) {
        int i;
        for (i = 0; i < companies.count; i++) {
            printComp(companies.company[i],&business);
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
        bus_line=getInt(ID_MIN,ID_MAX,BUSINESS_LINE);
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
        getString(companies->company[companies->count].address.cp,CP_MAX,COMP_CP);
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
void updateBLComp(COMPANY *company,BUSINESS **business){
    int bus_line;
    do {
        listBusLine(*business);
        bus_line=getInt(ID_MIN,ID_MAX,BUSINESS_LINE);
        for (int i = 0; i < (*business)->count; ++i) {
            if(bus_line == (*business)->business->id){
               company->business_line = bus_line;
            }
        }
    } while (bus_line!=(*business)->business->id);
}
void updateComp(COMPANY *company,BUSINESS *business) {
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