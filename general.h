//
// Created by emanuel on 11-01-2024.
//

#ifndef LPTP_GENERAL_H
#define LPTP_GENERAL_H
#include "input.h"
#include "stdio.h"
#include "stdlib.h"
#include "company.h"
#include "businessLines.h"
#include "search.h"
#include "string.h"
#define FILENAME_COMP "/home/emanuel/Desktop/1ºSemestre/LPTP/data/dataComp.txt"
#define BUSINESS_FILENAME "/home/emanuel/Desktop/1ºSemestre/LPTP/data/dataBL.txt"
#define COMMENTS_FILENAME "/home/emanuel/Desktop/1ºSemestre/LPTP/data/dataComm.txt"

char *showCompName(int nif,COMPANIES **company);
char *showState(int state);
char *showCatg(int catg);
char *showBLine(int bl,BUSINESS **business);
int isFileEmpty(const char *filename);
void initializeProgram(COMPANIES *companies, BUSINESS *business, COMMENTS *comments);
void exportData(COMPANIES *companies, BUSINESS *business, COMMENTS *comments);

#endif //LPTP_GENERAL_H
