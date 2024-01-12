//
// Created by emanuel on 11-01-2024.
//

#include "general.h"



char *showCompName(int nif,COMPANIES **company){

    char *name=(char*)malloc(sizeof(char)*10);
    for (int i = 0;(*company)->count > i; ++i) {
        if(nif ==(*company)->company[i].nif){
            strcpy(name, (*company)->company[i].name);

        }
    }
    return name;
}

// used to show de state INACTIVE or ACTIVE instead of 0 or 1
char *showState(int state){
    char*stateChar=(char*) malloc(sizeof(char)*10 );
    switch (state) {
        case 0:
            strcpy(stateChar,"INACTIVE");
            break;
        case 1:
            strcpy(stateChar,"ACTIVE");
            break;
        default:
            printf("EROOR");
    }
    return stateChar;
}

// used to show de category name instead of the representative number
char *showCatg(int catg){
    char *catgName=(char*) malloc(sizeof(char)*10 );
    switch (catg) {
        case 1:
            strcpy(catgName,"Micro");
            break;
        case 2:
            strcpy(catgName,"PME");
            break;
        case 3:
            strcpy(catgName,"Big");
            break;
        default:
            printf("EROOR");
    }
    return catgName;
}
// used to show the category instead of the id
char *showBLine(int bl,BUSINESS **business){

    char *name=(char*)malloc(sizeof(char)*10);
    for (int i = 0;(*business)->count > i; ++i) {
        if(bl ==(*business)->business[i].id){
            strcpy(name, (*business)->business[i].name);
        }
    }
    return name;
}
int isFileEmpty(const char *filename) {
    FILE *file = fopen(filename, "r");  // Open the file in read mode

    if (file == NULL) {
        perror("Error opening file");
        return -1;  // Error opening the file
    }

    fseek(file, 0, SEEK_END);  // Move the file pointer to the end of the file
    long size = ftell(file);   // Get the current position, which is the file size

    fclose(file);  // Close the file

    if (size == 0) {
        return -1;  // File is empty
    } else {
        return 1;  // File is not empty
    }
}

void exportBusinessLines(BUSINESS *business) {
    FILE *fp;
    int i;

    fp = fopen(BUSINESS_FILENAME, "w");
    if (fp == NULL) {
        printf(ERROR);

    } else {
        fprintf(fp, "%d\n", business->count);
        for (i = 0; i < business->count; i++) {
            fprintf(fp, "%d,%s\n", business->business[i].id, business->business[i].name);
        }

        fclose(fp);
        printf("Business lines exported successfully.\n");
    }
}

void importBusinessLines(BUSINESS *business) {
    FILE *fp;

    fp = fopen(BUSINESS_FILENAME, "r");
    if (fp == NULL) {
        printf(ERROR);
    } else {
        fscanf(fp, "%d", &business->count);

        // Allocate memory for the business array
        business->business = (BUS_LINE *)realloc(business->business, sizeof(BUS_LINE) * (business->count + 1));

        for (int i = 0; i < business->count; ++i) {
            fscanf(fp, "%d,%s\n", &business->business[i].id, business->business[i].name);
        }
        fclose(fp);
        printf("Business lines imported successfully.\n");
    }
}

void exportComments(COMMENTS *comments) {
    FILE *fp;
    int i;

    fp = fopen(COMMENTS_FILENAME, "w");
    if (fp == NULL) {
        printf(ERROR);

    } else {
        fprintf(fp, "%d\n", comments->count);
        for (i = 0; i < comments->count; i++) {
            fprintf(fp, "%s,%s,%s,%d\n", comments->comment[i].userName, comments->comment[i].userEmail, comments->comment[i].comment, comments->comment[i].compNif);
        }

        fclose(fp);
        printf("Comments exported successfully.\n");
    }
}

void importComments(COMMENTS *comments) {
    FILE *fp;

    fp = fopen(COMMENTS_FILENAME, "r");
    if (fp == NULL) {
        printf(ERROR);
    } else {
        fscanf(fp, "%d", &comments->count);

        // Allocate memory for the comment array
        comments->comment = (COMMENT *)realloc(comments->comment, sizeof(COMMENT) * (comments->count + 1));

        for (int i = 0; i < comments->count; ++i) {
            fscanf(fp, "%[^,],%[^,],%[^,],%d\n", comments->comment[i].userName, comments->comment[i].userEmail, comments->comment[i].comment, &comments->comment[i].compNif);
        }
        fclose(fp);
        printf("Comments imported successfully.\n");
    }
}

void exportCompanies(COMPANIES *companies) {
    FILE *fp;
    int i;

    fp = fopen(FILENAME_COMP, "w");
    if (fp == NULL) {
        printf(ERROR);

    } else {
        fprintf(fp, "%d\n", companies->count);
        for (i = 0; i < companies->count; i++) {

            fprintf(fp, "%d,%s,%d,%d,%s,%s,%s,%d,%f\n",
                    companies->company[i].nif,
                    companies->company[i].name,
                    companies->company[i].category,
                    companies->company[i].business_line,
                    companies->company[i].address.city,
                    companies->company[i].address.street,
                    companies->company[i].address.cp,
                    companies->company[i].state,
                    companies->company[i].rate);
        }

        fclose(fp);
        printf("NIIICE");

    }
}

void importCompanies(COMPANIES *companies) {
    FILE *fp;

    fp = fopen(FILENAME_COMP, "r");
    if (fp == NULL) {
        printf(ERROR);
    } else {
        fscanf(fp, "%d", &companies->count);

        // Allocate memory for the company array
        companies->company = (COMPANY *)realloc(companies->company, sizeof(COMPANY) * (companies->count+1));

        for (int i = 0; i < companies->count; ++i) {
            fscanf(fp, "%d,%s,%d,%d,%s,%s,%s,%d,%f\n",
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
        printf("Companies imported successfully.\n");
    }
}
void initializeProgram(COMPANIES *companies, BUSINESS *business, COMMENTS *comments) {
    importBusinessLines(business);
    importCompanies(companies);
    importComments(comments);
}

void exportData(COMPANIES *companies, BUSINESS *business, COMMENTS *comments) {
    exportCompanies(companies);
    exportBusinessLines(business);
    exportComments(comments);
}