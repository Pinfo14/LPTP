//
// Created by emanuel on 21-12-2023.
//
#include "stdio.h"
#include "stdlib.h"
#include "menu.h"

void mainMenu(COMPANIES *company,COMPANIES companies,BUSINESS *business){
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
                userMenu( company,companies,business);
                break;
            case 2:
                adminMenu( company,companies,business);
                break;
            default:

                printf("Invalid");

        }
    } while (op !=0);
    exit(1);
}
void adminMenu(COMPANIES *company,COMPANIES companies,BUSINESS *business){
    int op=0;

    do{
        printf("\nADMIN MENU\n");
        printf("1. Manage companies\n");
        printf("2. Manage business lines\n");
        printf("5. Go back\n");
        printf("0. EXIT\n  ");
        printf("CHOOSE OPTION: ");
        scanf("%d",&op);
        switch (op ) {
            case 1:
                manageComp(company,companies,business);
                break;
            case 2:
                manageBusLine(company,companies,business);
                break;
            case 5:
                mainMenu(company,companies,business);
                break;
            default:

        }
    } while (op !=0);
    exit(1);
}

void manageComp(COMPANIES *company,COMPANIES companies,BUSINESS *business){
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
                insertComp(&companies,business);
                manageComp(company,companies,business);
                break;
            case 2:
                updateComps(&companies,business);
                manageComp(company,companies,business);
                break;
            case 3:
                listComp(companies,*business);
                manageComp(company,companies,business);
                break;
            case 4:
                //deleteComp(&companies);
                manageComp(company,companies,business);
                break;
            case 5:
                adminMenu(company,companies,business);

                break;
            default:

        }
    } while (op !=0);
    exit(1);
}
void manageBusLine(COMPANIES *company,COMPANIES companies,BUSINESS *business){
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
                manageBusLine(company,companies,business);
                break;
            case 2:
                updateBusLine(business);
                manageBusLine(company,companies,business);
                break;
            case 3:
                listBusLine(business);
                manageBusLine(company,companies,business);
                break;
            case 4:
                // deleteComp(&companies);
                manageBusLine(company,companies,business);
                break;
            case 5:
                adminMenu(company,companies,business);

                break;
            default:

        }
    } while (op !=0);
    exit(1);

}
void userMenu(COMPANIES *company,COMPANIES companies,BUSINESS *business){
    int userOp;
    do {

        printf("\nUSER MENU\n");
        printf("1. Search company\n");
        printf("2. Rate company\n");
        printf("3. Comment company\n");
        printf("4. Go back\n");
        printf("0. EXIT\n");
        printf("CHOOSE OPTION: ");
        scanf("%d", &userOp);

        switch (userOp) {
            case 1:
                //pesquisarEmpresas(empresas, numEmpresas);
                break;
            case 2:
                //classificarEmpresa(empresas, numEmpresas);
                break;
            case 3:
                //comentarEmpresa(empresas, numEmpresas);
                break;
            case 4:
                mainMenu(company,companies,business);
                break;
            default:
                printf("ERROORR!!\n");
        }

    } while (userOp != 0);
    exit(1);
}