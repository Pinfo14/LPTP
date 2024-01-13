/**
 *
 * @file company.c
 * @author Emanuel Pinto
 * @date 16-12-2023
 * @version 1
 *
 * Source file containing all the functions about companies.
 */
#include <stdio.h>
#include "stdlib.h"
#include "company.h"
#include "input.h"

#include "search.h"

/**
 * Displays comments related to a specific company based on its NIF.
 *
 * This function prints the user name, email, and comment for each comment associated
 * with the specific company NIF.
 *
 * @param nif The NIF of the company.
 * @param comments Pointer to the COMMENTS structure .
 */
void showCom(int nif,COMMENTS *comments){

    for (int i = 0;comments->count > i; ++i) {
        if(nif ==comments->comment[i].compNif){
         printf("%s / %s / %s\n",comments->comment[i].userName,comments->comment[i].userEmail,comments->comment[i].comment) ;
        }
    }
}
/**
 * Prints information about a company, including its business line, category,
 * address, state, and average rate.
 *
 * This function retrieves and displays information about a company, including business
 * line and category names instead of IDs. It also prints comments related to the
 * company.
 *
 * @param company The COMPANY structure representing the company.
 * @param business Pointer to the BUSINESS structure .
 * @param comments Pointer to the COMMENTS structure .
 */
void printComp(COMPANY company,BUSINESS *business,COMMENTS *comments) {
    char *busLine=showBLine(company.business_line,&business);
    char *catgName=showCatg(company.category);
    char *state= showState(company.state);
    printf("%d   %s   %s   %s   %s %s %s   %s\n",company.nif,company.name, catgName,busLine ,company.address.street,company.address.cp,company.address.city,state);
    printf("RATE: %.2f \n",company.rate);
    puts(COMMENT_LINE);
    showCom(company.nif,comments);
    free(busLine);
    free(catgName);
    free(state);
}
/**
 * Lists all companies along with detailed information and associated comments.
 *
 * This function lists all companies, including detailed information and comments.
 *
 * @param companies The COMPANIES structure .
 * @param business Pointer to the BUSINESS structure.
 * @param comments Pointer to the COMMENTS structure.
 */

void listComp(COMPANIES companies,BUSINESS business,COMMENTS comments) {
    int file=isFileEmpty(FILENAME_COMP);
    if (companies.count > 0 || file!=-1) {
        int i;
        for (i = 0; i < companies.count; i++) {
            printComp(companies.company[i],&business,&comments);
        }
    } else {
        puts("NO companies");
    }
}

/**
 * Inserts a business line ID into a company's business_line field .
 *
 * This function prompts the user to select a business line ID and inserts it into the
 * specified company's business_line.
 *
 * @param companies Pointer to the COMPANIES structure.
 * @param busLine Pointer to the BUSINESS structure .
 */


void insertCompBus(COMPANIES *companies, BUSINESS *busLine) {
    int bus_line;
    int found = 0;
    if(busLine->count!=0) {
        do {
            listBusLine(busLine);
            bus_line = getInt(ID_MIN, ID_MAX, BUSINESS_LINE);
            for (int i = 0; i < busLine->count; ++i) {
                if (bus_line == busLine->business[i].id) {
                    companies->company[companies->count].business_line = bus_line;
                    found = 1;
                    break;
                }
            }
            if (!found) {

                printf("Invalid business line. Please try again.\n");
            }
        } while (found != 1);
    }else{
        insertBusLine(busLine);
        insertCompBus(companies,busLine);
    }
}
/**
 * Inserts a new company into the COMPANIES structure after verifying the NIF.
 *
 * This function ask the user for company information and inserts a new company into
 * the COMPANIES structure after verifying the NIF.
 *
 * @param companies Pointer to the COMPANIES structure.
 * @param business Pointer to the BUSINESS structure.
 * @param ratings Pointer to the RATINGS structure.
 * @return The index where the new company is inserted, or -1 if insertion fails.
 */
int insertComps(COMPANIES *companies,BUSINESS *business,RATINGS *ratings) {
    int nif;
    nif= getInt(NIF_MIN,NIF_MAX,NIF_MSG);
    if (searchComps(*companies, nif) == -1) {
        companies->company[companies->count].nif = nif;
        companies->company[companies->count].rate=0;
        getString(companies->company[companies->count].name,CHAR_MAX,COMP_NAME);
        companies->company[companies->count].category=getInt(CATG_MIN,CATG_MAX,COMP_CATG);
        insertCompBus(companies, business);
        getString(companies->company[companies->count].address.street,CHAR_MAX,COMP_STREET);
        getString(companies->company[companies->count].address.city,CHAR_MAX,COMP_CITY);
        getString(companies->company[companies->count].address.cp,CP_MAX,COMP_CP);
        companies->company[companies->count].state= getInt(0,1,COMP_STATE);
        return companies->count++;
    }
    return -1;
}

/**
 * Initiates the insertion of a new company.
 *
 * This function initiates the process of inserting a new company by verifying the count
 * and calling the insertComps function.
 *
 * @param companies Pointer to the COMPANIES structure.
 * @param business Pointer to the BUSINESS structure.
 * @param ratings Pointer to the RATINGS structure.
 */
void insertComp(COMPANIES *companies,BUSINESS *business,RATINGS *ratings) {
    if (companies->count < 10) {
        if (insertComps(companies,business,ratings) == -1) {
            puts(ERROR);
        }
    } else {
        puts(ERROR);
    }
}
/**
 * Deletes a company from the COMPANIES structure based on its NIF.
 *
 * This function ask the user for a company NIF, searches for the company, and
 * deletes it. If the company has  comments, its state is changed to INACTIVE.
 *
 * @param companies Pointer to the COMPANIES structure.
 * @param comments Pointer to the COMMENTS structure.
 */
void deleteComp(COMPANIES *companies, COMMENTS *comments) {
    int index = -1;
    int nif = getInt(NIF_MIN,NIF_MAX,NIF_MSG);
    for (int i = 0; i < companies->count; i++) {
        if (companies->company[i].nif == nif) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Company not found.\n");
        return;
    }

    for (int i = 0; i < comments->count; i++) {
        if (comments->comment[i].compNif == nif) {
            companies->company[index].state = INACTIVE;
            printf("Company with NIF %d have comments. The company state changed to INACTIVE.\n", nif);
            return;
        }
    }
    companies->company[index] = companies->company[companies->count - 1];
    companies->count--;

    printf("Company with NIF %d was deleted.\n", nif);
}
/**
 * Updates a company's business line based on user input.
 *
 * This function updates a company's business line by asking the user for a new
 * business line ID.
 *
 * @param company Pointer to the COMPANY .
 * @param business Pointer to the BUSINESS.
 */
void updateBLComp(COMPANY *company,BUSINESS *business){
    int bus_line;
    int found=0;
    do {
        listBusLine(business);
        bus_line = getInt(ID_MIN, ID_MAX, BUSINESS_LINE);

        for (int i = 0; i < business->count; ++i) {
            if (bus_line == business->business[i].id) {
             company->business_line = bus_line;
                found = 1;

                break;
            }
        }
        if (!found) {

            printf("Invalid business line. Please try again.\n");
        }

    } while (found!=1);
}
/**
 * Updates a company's information based on user input.
 *
 * This function updates a company's information, including name, category, business
 * line, address, and state, based on user input.
 *
 * @param company Pointer to the COMPANY .
 * @param business Pointer to the BUSINESS.
 */
void updateComp(COMPANY *company,BUSINESS *business) {
    float rating = company->rate;
    company->rate =rating;
    getString(company->name, CHAR_MAX, COMP_NAME);
    company->category=getInt(CATG_MIN,CATG_MAX,COMP_CATG);
    updateBLComp(company,business);
    getString(company->address.street,CHAR_MAX,COMP_STREET);
    getString(company->address.city,CHAR_MAX,COMP_CITY);
    getString(company->address.cp,CP_MAX,COMP_CP);
    company->state= getInt(0,1,COMP_STATE);
}
/**
 * Initiates the update of a company's information.
 *
 * This function initiates the process of updating a company's information by searching
 * for the company based on its NIF and calling the updateComp function.
 *
 * @param companies Pointer to the COMPANIES.
 * @param business Pointer to the BUSINESS.
 */
void updateComps(COMPANIES *companies,BUSINESS *business) {
    int position = searchComps(*companies, getInt(NIF_MIN ,NIF_MAX, NIF_MSG));

    if (position != -1) {
        updateComp(&companies->company[position], business);
    } else {
        puts("ERROR COMPANY NOT FOUND!!");
    }
}

void comp_rate(COMPANIES *companies) {
    for (int i = 0; i < companies->count - 1; i++) {
        for (int j = 0; j < companies->count - i - 1; j++) {
            if (companies->company[j].rate < companies->company[j + 1].rate) {
                COMPANY temp = companies->company[j];
                companies->company[j] = companies->company[j + 1];
                companies->company[j + 1] = temp;
            }
        }
    }
}

/**
 * Prints the top three best-rated companies.
 *
 * This function prints the names and rates of the top three best-rated companies.
 *
 * @param companies Pointer to the COMPANIES.
 */
void print_best_comp(COMPANIES *companies){

    printf("\nTop3 Best Companies:\n");
    for (int i = 0; i <3; i++) {
        printf("company %d: %s - Rate: %.2f\n", i + 1, companies->company[i].name, companies->company[i].rate);
    }
}
/**
 * Displays the last N comments.
 *
 * This function displays the last N comments related to a specific company.
 *
 * @param companies Pointer to the COMPANIES.
 * @param comments Pointer to the COMMENTS.
 * @param numComments The number of comments to display.
 */
void lastComments(COMPANIES company, COMMENTS comments, int numComments) {
    printf("Last %d Comments :\n", numComments);

    int begin = comments.count - numComments;
    begin = (begin < 0) ? 0 : begin;

    for (int i = begin; i < comments.count; i++) {
        if (comments.comment[i].compNif == company.company[i].nif) {
            printf("User: %s\n", comments.comment[i].userName);
            printf("Email: %s\n", comments.comment[i].userEmail);
            printf("Comment: %s\n", comments.comment[i].comment);
            printf("----------------------\n");
        }
    }
}
/**
 * Initiates the display of the last N comments .
 *
 * This function initiates the process of displaying the last N comments by asking
 * the user for the number of comments and calling the
 * lastComments function.
 *
 * @param companies Pointer to the COMPANIES .
 * @param comments Pointer to the COMMENTS.
 */
void lastComment(COMPANIES companies,COMMENTS comments){

    int num=0;
    printf("Insert the number os comments: ");
    scanf("%d",&num);

    lastComments(companies,comments,num);
}
