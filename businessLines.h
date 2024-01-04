//
// Created by emanuel on 03-01-2024.
//

#ifndef TP_LP_BUSINESSLINES_H
#define TP_LP_BUSINESSLINES_H
//#include "company.h"

#define BUS_NAME "Insert businesess line name: "
#define CHAR_MAX 100
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