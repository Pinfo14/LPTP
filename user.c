/**
* @file user.c
* @author Emanuel Pinto
* @date 11-01-2024
* @version 1
*
* @brief Implementation of user-related functions for comments and ratings.
*
* This file contains the implementation of functions related to user interactions,
* including the insertion of comments and ratings for companies.
*/

#include "user.h"
#include "general.h"

/**
 * @brief Inserts a comment for a specific company.
 *
 * @param comment A pointer to COMMENTS.
 * @param companies A COMPANIES .
 * @return 1 if the comment is successfully inserted, -1 if the company does not exist.
 */
int insertCom(COMMENTS *comment, COMPANIES companies) {
    int nif = getInt(NIF_MIN, NIF_MAX, NIF_MSG);
    int state = searchCompstate(companies, nif);

    if (state != 0) {
        comment->comment[comment->count].compNif = nif;
        getString(comment->comment[comment->count].userName, USER_NAME_MAX, NAME_MSG);
        getString(comment->comment[comment->count].userEmail, EMAIL_MAX, EMAIL_MSG);
        getString(comment->comment[comment->count].comment, COMMENT_MAX, COMMENT_MSG);
        comment->count++;
        return 1;
    }

    return -1;
}

/**
 * @brief Function to insert a comment and handle errors.
 *
 * @param comment A pointer to the COMMENTS .
 * @param companies A COMPANIES .
 */
void insertComm(COMMENTS *comment, COMPANIES companies) {
    if (insertCom(comment, companies) == -1) {
        puts(ERROR);
    }else{
        exportComments(*comment);
    }
}

/**
 * @brief Updates the average rating for a specific company.
 *
 * @param comNif The NIF  of the company.
 * @param ratings A pointer to the RATINGS .
 * @param companies A pointer to the COMPANIES .
 */
void updateMedRateForCompany(int comNif, RATINGS *ratings, COMPANIES *companies) {
    float totalRating = 0;
    int count = 0;

    for (int i = 0; i < ratings->count; ++i) {
        if (companies->company[i].rate != 0) {
            count = 1;
        }
        if (comNif == ratings->rating[i].comNif) {
            totalRating = companies->company[i].rate;
            totalRating += ratings->rating[i].rating;
            count++;
        }
    }

    int position = searchComps(*companies, comNif);
    if (position != -1 && count > 0) {
        float medRate = totalRating / count;

        if (medRate != companies->company[position].rate) {
            companies->company[position].rate = medRate;
        }
    }
}

/**
 * @brief Inserts a rating for a specific company.
 *
 * @param companies A COMPANIES structure.
 * @param ratings A pointer to the RATINGS .
 * @return 1 if the rating is successfully inserted, -1 if the company does not exist.
 */
int insertRatings(COMPANIES companies, RATINGS *ratings) {
    int nif = getInt(NIF_MIN, NIF_MAX, NIF_MSG);
    int position = searchComps(companies, nif);

    if (position != -1) {
        ratings->rating[ratings->count].comNif = nif;
        ratings->rating[ratings->count].rating = getInt(RATE_MIN, RATE_MAX, RATE_MSG);
        ratings->count++;

        updateMedRateForCompany(nif, ratings, &companies);

        return 1;
    }

    return -1;
}

/**
 * @brief Function to insert a rating and handle errors.
 *
 * @param companies A COMPANIES structure .
 * @param ratings A pointer to the RATINGS .
 */
void insertRating(COMPANIES companies, RATINGS *ratings) {
    if (insertRatings(companies, ratings) == -1) {
        printf(ERROR);
    }
}