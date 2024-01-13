/**
 *
 * @file general.c
 * @author Emanuel Pinto
 * @date 11-01-2024
 * @version 1
 *
 * Source file containing general functions.
 */

#include "general.h"


/**
 * Converts the numeric state (0 or 1) to INACTIVE or ACTIVE.
 *
 * @param state The numeric state(0 or 1).
 * @return state.
 */

char *showState(int state){
    char*stateChar=(char*) malloc(sizeof(char)*10 );
    switch (state) {
        case INACTIVE:
            strcpy(stateChar,"INACTIVE");
            break;
        case ACTIVE:
            strcpy(stateChar,"ACTIVE");
            break;
        default:
            printf("EROOR");
    }
    return stateChar;
}

/**
 * Converts the numeric category (1, 2, or 3) to (1 for MICRO, 2 for PME, 3 for BIG) .
 *
 * @param catg The numeric category (1, 2, or 3) .
 * @return category name.
 */
char *showCatg(int catg){
    char *catgName=(char*) malloc(sizeof(char)*10 );
    switch (catg) {
        case MICRO:
            strcpy(catgName,"Micro");
            break;
        case PME:
            strcpy(catgName,"PME");
            break;
        case BIG:
            strcpy(catgName,"Big");
            break;
        default:
            printf("EROOR");
    }
    return catgName;
}


/**
 * Retrieves the name of a business line based on its ID.
 *
 * This function searches for a business line with a specific ID in the BUSINESS
 * structure and returns its name.
 *
 * @param bl The ID of the business line.
 * @param business Pointer to the BUSINESS structure containing business line information.
 * @return business line name.
 */
char *showBLine(int bl,BUSINESS **business){

    char *name=(char*)malloc(sizeof(char)*10);
    for (int i = 0;(*business)->count > i; ++i) {
        if(bl ==(*business)->business[i].id){
            strcpy(name, (*business)->business[i].name);
        }
    }
    return name;
}

/**
 * @brief Exports business lines to a file.
 *
 * @param business  BUSINESS structure .
 */

void exportBline(BUSINESS business) {
    FILE *fp;
    int i;

    fp = fopen(BUSINESS_FILENAME, "w");
    if (fp == NULL) {
        printf("File not found.");
    }


    fprintf(fp,"%d\n", business.count);
    for (i = 0; i < business.count; i++) {

        fprintf(fp, "%d,%s,%d\n",
                business.business[i].id,
                business.business[i].name,
                business.business[i].state);
    }

    fclose(fp);
    printf("Bl exported");

}


/**
 * @brief Imports companies from a file.
 *
 * @param comments Pointer to the COMMENTS structure.
 */
void importBl(BUSINESS *business) {
    FILE *fp;

    fp = fopen(BUSINESS_FILENAME, "r");
    if (fp == NULL) {
        fp = fopen(BUSINESS_FILENAME, "w");
        printf(ERROR);
    } else {
        fscanf(fp, "%d", &business->count);



        business->business = (BUS_LINE *)realloc(business->business, sizeof(BUS_LINE) * (business->count+2));

        for (int i = 0; i < business->count; ++i) {
            fscanf(fp,"%d,%[^,],%d\n",
                   &business->business[i].id,
                   business->business[i].name,
                  & business->business[i].state);

        }
        fclose(fp);
        printf("Comments imported .\n");
    }
}


/**
 * @brief Exports companies to a file.
 *
 * @param comments COMMENTS structure.
 */

void exportComments(COMMENTS comments) {
    FILE *fp;
    int i;

    fp = fopen(COMMENTS_FILENAME, "w");
    if (fp == NULL) {
        printf("File not found.");
    }


    fprintf(fp,"%d\n", comments.count);
    for (i = 0; i < comments.count; i++) {

        fprintf(fp, "%d,%s,%s,%s\n",
                comments.comment[i].compNif,
                comments.comment[i].userName,
                comments.comment[i].userEmail,
                comments.comment[i].comment);
    }

    fclose(fp);
    printf("COmments exported");

}


/**
 * @brief Imports companies from a file.
 *
 * @param comments Pointer to the COMMENTS structure.
 */
void importComments(COMMENTS *comments) {
    FILE *fp;

    fp = fopen(COMMENTS_FILENAME, "r");
    if (fp == NULL) {
        fp = fopen(COMMENTS_FILENAME, "w");
        printf(ERROR);
    } else {
        fscanf(fp, "%d", &comments->count);



        comments->comment = (COMMENT *)realloc(comments->comment, sizeof(COMMENT) * (comments->count+2));

        for (int i = 0; i < comments->count; ++i) {
            fscanf(fp,"%d,%[^,],%[^,],%[^,]\n",
                   &comments->comment[i].compNif,
                   comments->comment[i].userName,
                   comments->comment[i].userEmail,
                   comments->comment[i].comment);

        }
        fclose(fp);
        printf("Comments imported .\n");
    }
}


/**
 * @brief Exports companies to a file.
 *
 * @param companies  COMPANIES struct.
 */

void exportCompanies(COMPANIES companies) {
    FILE *fp;
    int i;

    fp = fopen(FILENAME_COMP, "w");
    if (fp == NULL) {
        printf("File not found.");
    }


        fprintf(fp,"%d\n", companies.count);
        for (i = 0; i < companies.count; i++) {

            fprintf(fp, "%d,%s,%d,%d,%s,%s,%s,%d,%.2f\n",
                    companies.company[i].nif,
                    companies.company[i].name,
                    companies.company[i].category,
                    companies.company[i].business_line,
                    companies.company[i].address.city,
                    companies.company[i].address.street,
                    companies.company[i].address.cp,
                    companies.company[i].state,
                    companies.company[i].rate);

        }

        fclose(fp);
        printf("Files exported");

    }


/**
 * @brief Imports companies from a file.
 *
 * @param companies Pointer to the COMPANIES structure where company information will be stored.
 */
void importCompanies(COMPANIES *companies) {
    FILE *fp;

    fp = fopen(FILENAME_COMP, "r");
    if (fp == NULL) {
        fp = fopen(FILENAME_COMP, "w");
        printf(ERROR);
    } else {
      fscanf(fp, "%d", &companies->count);

        companies->company = (COMPANY *)realloc(companies->company, sizeof(COMPANY) * (companies->count+2));

        for (int i = 0; i < companies->count; ++i) {
         fscanf(fp, "%d,%[^,],%d,%d,%[^,],%[^,],%[^,],%d,%f\n",
                   &companies->company[i].nif,
                   companies->company[i].name,
                   &companies->company[i].category,
                   &companies->company[i].business_line,
                   companies->company[i].address.city,
                   companies->company[i].address.street,
                   companies->company[i].address.cp,
                   &companies->company[i].state,
                   &companies->company[i].rate);

        }
        fclose(fp);
        printf("Companies imported .\n");
    }
}
