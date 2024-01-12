//
// Created by emanuel on 21-12-2023.
//
#include "stdio.h"
#include "stdlib.h"
#include "menu.h"

void mainMenu(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings){
    int op;

    do{
        printf("\nMAIN MENU\n");
        printf("1. USER\n");
        printf("2. ADMIN\n");
        printf("0. EXIT\n");
        printf("CHOOSE OPTION: ");
        scanf("%d",&op);
        switch (op) {
            case 1:
                userMenu( company,business,comments,ratings);
                break;
            case 2:
                adminMenu( company,business,comments,ratings);
                break;
            default:

                printf("Invalid");

        }
    } while (op !=0);
    exit(1);
}
void adminMenu(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings){
    int op=0;

    do{
        printf("\nADMIN MENU\n");
        printf("1. Manage companies\n");
        printf("2. Manage business lines\n");
        printf("3. Reports\n");
        printf("5. Go back\n");
        printf("0. EXIT\n  ");
        printf("CHOOSE OPTION: ");
        scanf("%d",&op);
        switch (op ) {
            case 1:
                manageComp(company,business,comments,ratings);
                break;
            case 2:
                manageBusLine(company,business,comments,ratings);
                break;
            case 3:
                reportMenu(company,business,comments,ratings);
                break;
            case 5:
                mainMenu(company,business,comments,ratings);
                break;
            default:

        }
    } while (op !=0);
    exit(1);
}

void reportMenu(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings) {
    int op = 0;

    do {
        printf("\nMANAGE COMPANY\n");
        printf("1. Last Comments\n");
        printf("2. Best companies\n");
        printf("3. Go back\n");
        printf("0. EXIT  ");
        printf("CHOOSE OPTION: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                lastComment( *company, *comments);
                reportMenu(company, business, comments, ratings);
                break;
            case 2:
                print_best_comp(company);
                reportMenu(company, business, comments, ratings);
                break;
            case 3:

               adminMenu(company, business, comments, ratings);
                break;

            default:

        }
    } while (op != 0);
    exit(1);
}

void manageComp(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings){
    int op=0;

    do{
        printf("\nMANAGE COMPANY\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. List\n");
        printf("4. Delete\n");
        printf("5. Go back\n");
        printf("0. EXIT  ");
        printf("CHOOSE OPTION: ");
        scanf("%d",&op);
        switch (op) {
            case 1:
                insertComp(company,business,ratings);
                manageComp(company,business,comments,ratings);
                break;
            case 2:
                updateComps(company,business);
                manageComp(company,business,comments,ratings);
                break;
            case 3:
                listComp(*company,*business,*comments);
                manageComp(company,business,comments,ratings);
                break;
            case 4:
                //deleteComp(&companies);
                manageComp(company,business,comments,ratings);
                break;
            case 5:
                adminMenu(company,business,comments,ratings);

                break;
            default:

        }
    } while (op !=0);
    exit(1);
}
void manageBusLine(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings){
    int op=0;

    do{
        printf("\nMANAGE BUSINESS LINES\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. List\n");
        printf("4. Delete\n");
        printf("5. Go back\n");
        printf("0. EXIT  ");
        printf("CHOOSE OPTION: ");
        scanf("%d",&op);
        switch (op) {
            case 1:
                insertBusLine(business);
                manageBusLine(company,business,comments,ratings);
                break;
            case 2:
                updateBusLine(business);
                manageBusLine(company,business,comments,ratings);
                break;
            case 3:
                listBusLine(business);
                manageBusLine(company,business,comments,ratings);
                break;
            case 4:
                // deleteComp(&companies);
                manageBusLine(company,business,comments,ratings);
                break;
            case 5:
                adminMenu(company,business,comments,ratings);

                break;
            default:

        }
    } while (op !=0);
    exit(1);

}

void userMenu(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings){
    int userOp;
    do {

        printf("\nUSER MENU\n");
        printf("1. Search company\n");
        printf("4. Go back\n");
        printf("0. EXIT\n");
        printf("CHOOSE OPTION: ");
        scanf("%d", &userOp);

        switch (userOp) {
            case 1:
                searchMenu(company,business,comments,ratings);
                break;

            case 4:
                mainMenu(company,business,comments,ratings);
                break;
            default:
                printf("ERROORR!!\n");
        }

    } while (userOp != 0);
    exit(1);
}

void rateComMenu(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings){
    int userOp;
    do {

        printf("\nSEARCH MENU\n");
        printf("1. Rate company\n");
        printf("2. Comment company\n");
        printf("3. Go back\n");
        printf("0. EXIT\n");
        printf("CHOOSE OPTION: ");
        scanf("%d", &userOp);
        switch (userOp) {
            case 1:
                insertRating(*company,ratings);
                rateComMenu(company,business,comments,ratings);
                break;
            case 2:
                insertComm(comments,*company);
                rateComMenu(company,business,comments,ratings);

                break;
            case 3:

                searchMenu(company,business,comments,ratings);
                break;
            default:
                printf("ERROORR!!\n");
        }
    } while (userOp != 0);
    exit(1);
}
void searchMenu(COMPANIES *company,BUSINESS *business,COMMENTS *comments,RATINGS *ratings){
    int userOp;
    do {

        printf("\nSEARCH MENU\n");
        printf("1. Name\n");
        printf("2. Business Line\n");
        printf("3. Postal Code\n");
        printf("4. Go Back\n");
        printf("0. Exit\n");
        printf("CHOOSE OPTION: ");
        scanf("%d", &userOp);
        switch (userOp) {
            case 1:
                searchCompByName(company,business);
                rateComMenu(company,business,comments,ratings);
                break;
            case 2:
                searchComByBl(company,business);
                rateComMenu(company,business,comments,ratings);

                break;
            case 3:
                searchCompByCP(company,business);
                rateComMenu(company,business,comments,ratings);
                break;
            case 4:
                userMenu(company,business,comments,ratings);
                break;
            default:
                printf("ERROORR!!\n");
        }
    } while (userOp != 0);
    exit(1);
}
