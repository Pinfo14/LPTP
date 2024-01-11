//
// Created by emanuel on 11-01-2024.
//

#include "user.h"

int insertCom(COMMENTS *comment,COMPANIES companies){
    int nif = getInt(NIF_MIN,NIF_MAX,NIF_MSG);
    int state = searchCompstate(companies, nif);
    if(state!= 0 ){
        comment->comment[comment->count].compNif =nif;
        getString(comment->comment[comment->count].userName,USER_NAME_MAX,NAME_MSG);
        getString(comment->comment[comment->count].userEmail,EMAIL_MAX,EMAIL_MSG);
        getString(comment->comment[comment->count].comment,COMMENT_MAX,COMMENT_MSG);
        comment->count++;
        return 1;
    }
    return -1;
}

void insertComm(COMMENTS *comment,COMPANIES companies){
    if(insertCom(comment,companies) ==-1){
        puts(ERROR);
    }
}



void updateMedRateForCompany(int comNif, RATINGS *ratings, COMPANIES *companies) {
    float totalRating = 0;
    int count = 0;

    for (int i = 0; i < ratings->count; ++i) {
        if(companies->company[i].rate !=0){
            count =1;
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

int insertRatings(COMPANIES companies, RATINGS *ratings) {
    int nif = getInt(NIF_MIN, NIF_MAX, NIF_MSG);
    int position = searchComps(companies, nif);

    if (position != -1) {
        ratings->rating->comNif = nif;
        ratings->rating->rating = getInt(RATE_MIN, RATE_MAX, RATE_MSG);
        ratings->count++;

        updateMedRateForCompany(nif, ratings, &companies);

        return 1;
    }

    return -1;
}

void insertRating(COMPANIES companies,RATINGS *ratings){

    if(insertRatings(companies,ratings)==-1){
        printf(ERROR);
    }
}

