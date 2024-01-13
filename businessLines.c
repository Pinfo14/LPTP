
/**
* @file businessLines.c
* @author Emanuel Pinto
* @date 20-12-2023
* @version 1
*
* @brief Implementation of functions for managing business lines.
*
* This file contains the implementation of functions for managing business lines,
* including printing, listing, searching, inserting, and updating business lines.
*/

#include "businessLines.h"
#include "stdio.h"
#include "input.h"
#include "company.h"
/**
 * @brief Prints the details of a business line.
 *
 * @param busLine The BUSINESS LINE structure representing a business line.
 */
void printBusLine(BUS_LINE busLine) {
    printf("\n%d   %s\n   ",busLine.id,busLine.name);
}

/**
 * @brief Lists all the available business lines.
 *
 * @param business A pointer to the BUSINESS structure representing the list of business lines.
 */
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

/**
 * @brief Searches for a business line by its ID.
 *
 * @param business A BUSINESS structure .
 * @param id The ID of the business line to search for.
 * @return The position of the business line in the array (-1 if not found).
 */
int searchBus(BUSINESS business, int id) {
    int i;
    for (i = 0; i < business.count; i++) {
        if (business.business[i].id == id) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Inserts a new business line into the list of business lines.
 *
 * @param business A pointer to the BUSINESS .
 * @return The position of the inserted business line in the array (-1 if insertion failed).
 */
int insertBusLines(BUSINESS *business) {
    int id;
    id= getInt(NIF_MIN,NIF_MAX,ID_MSG);

    if (searchBus(*business, id) == -1) {

        business->business[business->count].id = id;
        getString(business->business[business->count].name,CHAR_MAX,BUS_NAME);
        business->business[business->count].state= getInt(0,1,BUS_STATE);
        return business->count++;
    }

    return -1;

}

/**
 * @brief Inserts a new business line into the list of business lines, checking for capacity.
 *
 * @param business A pointer to the BUSINESS .
 */
void insertBusLine(BUSINESS *business) {
    if (business->count < 5) {
        if (insertBusLines(business) == -1) {
            puts(ERROR);
        }
    } else {
        puts(ERROR);
    }
}
/**
 * @brief Updates the details of a business line.
 *
 * @param business A pointer to the BUSINESS LINE .
 */
void updateBusLines(BUS_LINE *business){
    getString(business->name,CHAR_MAX,BUS_NAME);
    business->state= getInt(0,1,BUS_STATE);
}

/**
 * @brief Updates the details of an existing business line.
 *
 * @param business A pointer to the BUSINESS .
 */
void updateBusLine(BUSINESS *business){

    int position =searchBus( *business,getInt(ID_MIN,ID_MAX,ID_MSG));
    if(position !=-1) {
        updateBusLines(&business->business[position]);
    } else{
        printf("ERROO NOT FOUND !!!");
    }

}


void deleteBusLine(BUSINESS *business, COMPANIES *companies ) {
    int connectedCompanies = 0;
    int businessLineId = getInt(ID_MIN,ID_MAX,ID_MSG);

    for (int i = 0; i < companies->count; i++) {
        if (companies->company[i].business_line == businessLineId) {
            connectedCompanies++;
            companies->company[i].state = INACTIVE;
        }
    }

    if (connectedCompanies == 0) {
        for (int i = 0; i < business->count; i++) {
            if (business->business[i].id == businessLineId) {
                business->business[i] = business->business[business->count - 1];
                business->count--;
                printf("Business line deleted.\n");
                return;
            }
        }
    } else {

        for (int i = 0; i < business->count; i++) {
            if (business->business[i].id == businessLineId) {
                business->business[i].state = INACTIVE;

                printf("Business line connected companies set to inactive.\n");
                return;
            }
        }
    }

    printf("Business line  not found.\n");
}

