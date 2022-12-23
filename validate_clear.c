#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "validate_clear.h"

/*
==================================================================
FILE			: validate_clear.c
AUTHOR			: Christian James C. Bayadog
DESCRIPTION		: This program validates user input and clear output screen
COPYRIGHT		: 12/9/2022
REVISION HISTORY
Date: 12/9/2022     By: Christian James C. Bayadog   Decsription: additional comments for better program readability
==================================================================
*/

/*
==================================================================
FUNCTION	: int validate_int_input(char string[], int a, int b)
DESCRIPTION	: print string and validate integer input
ARGUMENTS	: agrument string holds the string inputted by the user, argument a holds the minimum value allows, argument b holds the maximum value allowed
RETURNS		: retruns the converted string to int
==================================================================
*/

int validate_int_input(char string[], int a, int b){
	//declare variables
	int end = 0;
	char num[50];
	
	while (end != 1){//iterates until the input by the user is valid
		printf("%s",string); //print string set by the user
		fflush(stdin); //clear stream input
		gets(num); //get string and store in the num character array 
		
		if(check_input(num) == 1){ //check if inputted string is a number, otherwise it is invalid and continue to prompt user for input
			if(atoi(num) >= a && atoi(num) <= b){ //check if number is within the range desired by the user
				end = 1; 
			}
			else {
				printf("\n\tOnly input the valid choices\n");
				end = 0;	
			}
		}
		else{
			printf("\n\tOnly input the valid choices\n");
			end = 0;
		}
	}
	return atoi(num); //return converted string to num
}
/*
==================================================================
FUNCTION	: int check_input(char num[])
DESCRIPTION	: checks if string is a number
ARGUMENTS	: argument num holds the string inputted by the user
RETURNS		: returns 1 (if string is a number) and returns 0 (if string is not a number)
==================================================================
*/
int check_input(char num[]){
	int i = 0; // declare variable
	while(num[i] != '\0'){ //iterate to each of the character in the array until it reaches null
		if (isdigit(num[i]) == 0){//check if current character is a digit
			return 0;
		}
		i++; //increment
	}
	return 1;
}

float validate_parameters(char string[]){
	//declare vraiables//
	float end = 0;
	float num;
	//loops to ask for user's choice and checks if it's  valid//
	while(end != 1){
		//prompts input for user and store it in variable//
		printf("%s",string);
    	scanf("%f",&num);
		if (num > 0){//if  choice is within the valid range and then end loop, otherwise choice is invalid and loop through again to ask for valid input
			end = 1;	
		}
		else {
			printf("Only input positive values.\n");
			end = 0;
		}
	}
	return num; //returns user's choice
}

/*
==================================================================
FUNCTION	: void clear_calculator(void)
DESCRIPTION	: clears the outputscreen
ARGUMENTS	: none
RETURNS		: none
==================================================================
*/
void clear(void){
	system("cls");//clear output screen
	fflush(stdin); //clear the output buffer of the stream
}
