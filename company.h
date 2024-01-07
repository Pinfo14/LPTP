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
* in a C or C++ program. It includes functions for create, delete,update and read companies and lines of business
*/

#ifndef TP_LP_COMPANY_H
#define TP_LP_COMPANY_H
#include "businessLines.h"
#define CHAR_MAX 100
#define NIF_MIN 1
#define NIF_MAX 999999
#define CATG_MIN 1
#define CATG_MAX 3
#define CP_MAX 8
#define NIF_MSG "Insert NIF: "
#define  COMP_NAME "Insert company name: "
#define COMP_CATG "Insert the company Category 1-->micro  2-->pme  3-->big: "
#define BUSINESS_LINE "Insert business line: "
#define COMP_STREET "Insert the street: "
#define  COMP_CITY "Insert the city: "
#define COMP_CP "Insert the CP: "
#define COMP_STATE "Company state: "

typedef enum{MICRO=1,PME,BIG}CATEGORY;
typedef enum{INACTIVE,ACTIVE}STATE;


typedef struct {
    char street[CHAR_MAX];
    char city[CHAR_MAX];
    char cp[CP_MAX];
}ADDRESS;

typedef struct {
    unsigned int nif;
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

//COMPANIES
void insertComp(COMPANIES *companies,BUSINESS *business);
void updateComps(COMPANIES *companies,BUSINESS *business);
void deleteComp(COMPANIES *companies);
void searchComp(COMPANIES companies);
void listComp(COMPANIES companies,BUSINESS business);



#endif //LPTP_COMPANY_H
