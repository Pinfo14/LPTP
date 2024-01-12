/**
* @file user.h
* @author Emanuel Pinto
* @date 11-01-2024
* @version 1
*
* @brief A header file providing functions for user interactions and feedback.
*
* This file contains a collection of functions related to user interactions, comments, and ratings.
*/
#ifndef LPTP_USER_H
#define LPTP_USER_H
#include "company.h"
#include "input.h"
#include "stdio.h"
#include "stdlib.h"
#include "search.h"
#include "businessLines.h"


void insertComm(COMMENTS *comment,COMPANIES companies);
//RATING
void insertRating(COMPANIES companies,RATINGS *ratings);

#endif //LPTP_USER_H
