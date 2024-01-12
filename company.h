/**
* @file company.h
* @author Emanuel Pinto
* @date 16-12-2023
* @version 1
*
* @copyright Copyright (C) Emanuel 2023. All Rights MIT Licensed.
*
* @brief A header file providing utility functions for company management.
*
* This  file contains a collection of functions designed to manage the company
* It includes functions for create, delete,update and read companies
*/

#ifndef TP_LP_COMPANY_H
#define TP_LP_COMPANY_H
#include "businessLines.h"
#define INITIAL_SIZE 2
#define CHAR_MAX 100
#define NIF_MIN 1
#define NIF_MAX 999999
#define CATG_MIN 1
#define CATG_MAX 3
#define CP_MAX 8
#define RATE_MAX 5
#define RATE_MIN 1
#define USER_NAME_MAX  20
#define EMAIL_MAX  30
#define COMMENT_MAX  100
#define COMMENT_LINE "/------------COMMENTS------------/"
#define RATE_MSG "Rate 1 to 5: "
#define NIF_MSG "Insert NIF: "
#define  COMP_NAME "Insert company name: "
#define COMP_CATG "Insert the company Category 1-->micro  2-->pme  3-->big: "
#define BUSINESS_LINE "Insert business line: "
#define COMP_STREET "Insert the street: "
#define  COMP_CITY "Insert the city: "
#define COMP_CP "Insert the CP: "
#define COMP_STATE "Company state: "
#define NAME_MSG "Enter your name: "
#define EMAIL_MSG "Enter your email: "
#define COMMENT_MSG "Comment: "

typedef enum{MICRO=1,PME,BIG}CATEGORY;
typedef enum{INACTIVE,ACTIVE}STATE;


typedef struct {
    char street[CHAR_MAX];
    char city[CHAR_MAX];
    char cp[CP_MAX];
}ADDRESS;

typedef struct {
    int nif;
    float rate;
    char name[CHAR_MAX];
    CATEGORY category;
    int business_line;
    ADDRESS address;
    STATE state;
}COMPANY;

typedef struct {
    int count;
    COMPANY *company;
}COMPANIES;

typedef struct {
    char userName[USER_NAME_MAX];
    char userEmail[EMAIL_MAX];
    char comment[COMMENT_MAX];
    int compNif;
}COMMENT;

typedef struct {
    int count;
    COMMENT *comment;
}COMMENTS;


typedef struct{
    int rating;
    int comNif;
}RATING;

typedef struct {
    int count;
    RATING *rating;
}RATINGS;

//COMPANIES
void insertComp(COMPANIES *companies,BUSINESS *business,RATINGS *ratings);
void updateComps(COMPANIES *companies,BUSINESS *business);
void deleteComp(COMPANIES *companies, COMMENTS *comments);
void searchComp(COMPANIES companies,BUSINESS *business,COMMENTS comments);
void listComp(COMPANIES companies,BUSINESS business,COMMENTS comments);
void printComp(COMPANY company,BUSINESS *business,COMMENTS *comments);
void print_best_comp(COMPANIES *companies);
void lastComment(COMPANIES companies,COMMENTS comments);



#endif //LPTP_COMPANY_H
