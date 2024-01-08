/**
* @file input.h
* @author Emanuel Pinto
* @date 19-12-2023
* @version 1
*
* @copyright Copyright (C) Emanuel 2023. All Rights MIT Licensed.
*
* @brief A header file providing utility functions for input control.
*
* This  file contains a collection of functions designed to help and control the user input
* in a C or C++ program. It includes functions for get an integer, a sting
*/

#ifndef TP_LP_INPUT_H
#define TP_LP_INPUT_H

#define ERROR "ERROOOOR"
int getInt(int minVal,int maxVal,char*msg);
void getString(char *string, unsigned int size, char *msg);





#endif //TP_LP_INPUT_H
