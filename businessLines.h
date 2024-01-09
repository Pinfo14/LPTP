/**
* @file businessLines.h
* @author Emanuel Pinto
* @date 20-12-2023
* @version 1
*
* @copyright Copyright (C) Emanuel 2023. All Rights MIT Licensed.
*
* @brief A header file providing utility functions for business line management.
*
* This  file contains a collection of functions designed to manage the business lines
* in a C or C++ program. It includes functions for create, delete,update and read  lines of business
*/

#ifndef TP_LP_BUSINESSLINES_H
#define TP_LP_BUSINESSLINES_H
#define  ID_MSG "Insert the  business line id: "
#define BUS_NAME "Insert  business line name: "
#define CHAR_MAX 100
#define ID_MIN 1
#define ID_MAX 9999
typedef struct {
    int id;
    char name[CHAR_MAX];
}BUS_LINE;

typedef struct {
    int count;
    BUS_LINE *business;
}BUSINESS;

//BUSINESS LINES
void insertBusLine(BUSINESS *business);
void updateBusLine(BUSINESS *business);
void listBusLine(BUSINESS *business);

#endif //TP_LP_BUSINESSLINES_H