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

char *showCompName(int nif,COMPANIES **company);
char *showState(int state);
char *showCatg(int catg);
char *showBLine(int bl,BUSINESS **business);
#endif //LPTP_GENERAL_H
