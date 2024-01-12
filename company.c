
//
// Created by Emanuel Pinto on 16/12/2023.
//
#include <stdio.h>
#include <float.h>
#include "stdlib.h"
#include "string.h"
#include "company.h"
#include "input.h"
#include "businessLines.h"
#include "search.h"


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
    int file=isFileEmpty(FILENAME_COMP);
    if (companies.count > 0 || file!=-1) {
        int i;
        for (i = 0; i < companies.count; i++) {
            printComp(companies.company[i],&business,&comments);
        }
    } else {
        puts("NO companies");
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

void deleteComp(COMPANIES *companies, COMMENTS *comments) {
    int index = -1;
    int nif = getInt(NIF_MIN,NIF_MAX,NIF_MSG);
    for (int i = 0; i < companies->count; i++) {
        if (companies->company[i].nif == nif) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Company not found.\n");
        return;
    }

    for (int i = 0; i < comments->count; i++) {
        if (comments->comment[i].compNif == nif) {
            companies->company[index].state = INACTIVE;
            printf("Company with NIF %d have comments. The company state changed to INACTIVE.\n", nif);
            return;
        }
    }
    companies->company[index] = companies->company[companies->count - 1];
    companies->count--;

    printf("Company with NIF %d was deleted.\n", nif);
}
void updateBLComp(COMPANY *company,BUSINESS *business){
    int bus_line;
    int found=0;
    do {
        listBusLine(business);
        bus_line = getInt(ID_MIN, ID_MAX, BUSINESS_LINE);

        for (int i = 0; i < business->count; ++i) {
            if (bus_line == business->business[i].id) {
             company->business_line = bus_line;
                found = 1;

                break;
            }
        }
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


void printComm(COMMENTS *comment,COMPANIES *company){
    int nif=comment->comment->compNif;
    char *compName = showCompName(nif,&company);
    printf("%s  %s  %s  %s", compName,comment->comment->userName,comment->comment->userEmail,comment->comment->comment);
    free(compName);
}

void comp_rate(COMPANIES *companies) {
    for (int i = 0; i < companies->count - 1; i++) {
        for (int j = 0; j < companies->count - i - 1; j++) {
            if (companies->company[j].rate < companies->company[j + 1].rate) {
                // Troca os elementos se estiverem fora de ordem
                COMPANY temp = companies->company[j];
                companies->company[j] = companies->company[j + 1];
                companies->company[j + 1] = temp;
            }
        }
    }
}
void print_best_comp(COMPANIES *companies){

    printf("\nTop3 Best Companies:\n");
    for (int i = 0; i <3; i++) {
        printf("company %d: %s - Rate: %.2f\n", i + 1, companies->company[i].name, companies->company[i].rate);
    }
}void lastComments(COMPANIES company, COMMENTS comments, int numComments) {
    printf("Last %d Comments :\n", numComments);

    int begin = comments.count - numComments;
    begin = (begin < 0) ? 0 : begin;

    for (int i = begin; i < comments.count; i++) {
        if (comments.comment[i].compNif == company.company[i].nif) {
            printf("User: %s\n", comments.comment[i].userName);
            printf("Email: %s\n", comments.comment[i].userEmail);
            printf("Comment: %s\n", comments.comment[i].comment);
            printf("----------------------\n");
        }
    }
}
void lastComment(COMPANIES companies,COMMENTS comments){

    int num=0;
    printf("Insert the number os comments: ");
    scanf("%d",&num);

    lastComments(companies,comments,num);
}
