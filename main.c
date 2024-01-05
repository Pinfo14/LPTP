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
    mainMenu(companies,*companies,business);

    free(companies);
    free(companies->company);
    free(business);
    free(business->business);
    return 0;
}
