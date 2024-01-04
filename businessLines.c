

//
// Created by emanuel on 03-01-2024.
//
#include "businessLines.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "input.h"
#include "company.h"

void printBusLine(BUS_LINE busLine) {
    printf("\n%d   %s\n   ",busLine.id,busLine.name);
}
void listBusLine(BUSINESS *business){
    if (business->count > 0) {
        int i;
        for (i = 0; i <business->count; i++) {
            printBusLine(business->business[i]);
        }
    } else {
        puts("ja foste");
    }
}
int searchBus(BUSINESS business, int id) {
    int i;
    for (i = 0; i < business.count; i++) {
        if (business.business[i].id == id) {
            return i;
        }
    }
    return -1;
}

//INSERT COMP
int insertBusLines(BUSINESS *business) {
    int id;
    id= getInt(NIF_MIN,NIF_MAX,"Insert the id: ");

    if (searchBus(*business, id) == -1) {

        business->business[business->count].id = id;
        getString(business->business[business->count].name,CHAR_MAX,BUS_NAME);

        return business->count++;
    }

    return -1;

}


void insertBusLine(BUSINESS *business) {
    if (business->count < 2) {
        if (insertBusLines(business) == -1) {
            puts(ERROR);
        }
    } else {
        puts(ERROR);
    }
}