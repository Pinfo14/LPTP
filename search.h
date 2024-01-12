/**
* @file search.h
* @author Emanuel Pinto
* @date 11-01-2024
* @version 1
*
* @brief Header file providing functions for searching and retrieving company information.
*
* This file contains a collection of functions designed to search and retrieve information
* about companies based on different criteria such as name, business line, and postal code.
*/
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
void  searchCompByName( COMPANIES *companies, BUSINESS *business);
void searchComByBl( COMPANIES *companies,BUSINESS *business);
void searchCompByCP( COMPANIES *companies,BUSINESS *business);
#endif //LPTP_SEARCH_H
