//
// Created by emanuel on 21-12-2023.
//
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "input.h"

void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int getInt(int minVal,int maxVal,char*msg){

    int value;
    printf(msg);
    while (scanf("%d",&value)!=-1 && value<minVal||value>maxVal ){

        puts(ERROR);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return value;

}



void getString(char *string, unsigned int size, char *msg) {
    printf(msg);
    if (fgets(string, size, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}