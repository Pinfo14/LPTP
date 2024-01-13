/**
* @file general.h
* @author Emanuel Pinto
* @date 11-01-2024
* @version 1
*
* @brief A header file providing general utility functions for program management.
*
* This file contains a collection of general utility functions for managing the overall program.
* It includes functions for handling companies, business lines, search operations, and file I/O.
*/

#ifndef LPTP_GENERAL_H
#define LPTP_GENERAL_H
#include "input.h"
#include "stdio.h"
#include "stdlib.h"
#include "company.h"
#include "businessLines.h"
#include "search.h"
#include "user.h"
#include "string.h"
#define INITIAL_SIZE 10
#define FILENAME_COMP "/home/emanuel/Desktop/1ºSemestre/LPTP/data/dataComp.txt"
#define BUSINESS_FILENAME "/home/emanuel/Desktop/1ºSemestre/LPTP/data/dataBL.txt"
#define COMMENTS_FILENAME "/home/emanuel/Desktop/1ºSemestre/LPTP/data/dataComm.txt"
#define NOT_FOUND  "ERRO NOT FOUND"
#define EXIST "Already exist"

char *showState(int state);
char *showCatg(int catg);
char *showBLine(int bl,BUSINESS **business);

void  exportCompanies(COMPANIES companies);
void importCompanies(COMPANIES *companies);

void exportComments(COMMENTS comments);
void importComments(COMMENTS *comments);

void exportBline(BUSINESS business);
void importBl(BUSINESS *business);



#endif //LPTP_GENERAL_H
