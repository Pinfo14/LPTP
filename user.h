//
// Created by emanuel on 11-01-2024.
//

#ifndef LPTP_USER_H
#define LPTP_USER_H
#include "company.h"
#include "input.h"
#include "stdio.h"
#include "stdlib.h"
#include "search.h"
#include "businessLines.h"


void insertComm(COMMENTS *comment,COMPANIES companies);
void printComm(COMMENTS *comment,COMPANIES *company);

//RATING
void insertRating(COMPANIES companies,RATINGS *ratings);

#endif //LPTP_USER_H
