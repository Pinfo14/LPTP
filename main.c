#include <stdio.h>
#include "stdlib.h"
#include "company.h"
#include "menu.h"
#include "businessLines.h"

int main() {
    COMPANIES  *companies;
    companies=(COMPANIES*)malloc(sizeof(COMPANIES)*3 );
    companies->company =(COMPANY*)malloc(sizeof(COMPANY)*3 );
    companies->count=0;

    BUSINESS *business;
    business=(BUSINESS*) malloc(sizeof(BUSINESS)*3 );
    business->business=(BUS_LINE*) malloc(sizeof(BUS_LINE)*3 );
    business->count=0;


    COMMENTS *comments;
    comments =(COMMENTS*) malloc(sizeof(COMMENTS)*3 );
    comments->comment=(COMMENT *) malloc(sizeof(COMMENT)*3 );
    comments->count=0;



    RATINGS *ratings;
    ratings =(RATINGS *) malloc(sizeof(RATINGS)*3 );
    ratings->rating=(RATING *) malloc(sizeof(RATING )*3 );
    ratings->count=0;

    mainMenu(companies,business,comments,ratings);


    free(companies);
    free(companies->company);
    free(business);
    free(business->business);
    free(ratings);
    free(ratings->rating);
    return 0;
}
