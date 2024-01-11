//
// Created by emanuel on 11-01-2024.
//

#ifndef LPTP_SEARCH_H
#define LPTP_SEARCH_H
#include "company.h"
#include "input.h"
#include "stdio.h"
#include "stdlib.h"
#include "search.h"
#include "businessLines.h"
#include "string.h"
#include "general.h"


int searchCompstate(COMPANIES companies, int nif);
int searchComps(COMPANIES companies, int nif);
void searchCompByName( COMPANIES *companies, BUSINESS *business);
void searchComByBl( COMPANIES *companies,BUSINESS *business);
void searchCompByCP( COMPANIES *companies,BUSINESS *business);
#endif //LPTP_SEARCH_H
