#include<stdio.h>
#include "app_calendar.h"
#include "validate_clear.h"

/*
==================================================================
FILE			: app_calendar.c
AUTHOR			: Luigi Adrian T. Hatamosa
DESCRIPTION		: The purpose of this program is to show and portray the dates of a selected month for the year 2022
COPYRIGHT		: 11/24/2022
REVISION HISTORY
Date: 11/9/2022     By: Luigi Adrian T. Hatamosa    Decsription: additional comments for better program readability
==================================================================

==================================================================
FUNCTION	: void calendar_instructions(int n)
DESCRIPTION	: print program instructions
ARGUMENTS	:argument n holds the number value that signifies which specific instruction to print
RETURNS		: none
==================================================================
*/

void calendar_instructions(int n){
	//displays the instructions for calendar application
	if (n == 1){ //checks if input is 1 then print main instructions for calendar, otherwise proceed to next condition 
		printf("CALENDAR\nInstructions: This program generates the calendar of the month (for the year 2022).\n"); 
	}
	else if (n == 2){//checks if input is 2 then print menu for calendar, otherwise proceed to next condition 
		printf("############################### CALENDAR ##################################\n");
		printf("***************************************************************************\n");
		printf("\n\t(1) January    (2) February   (3) March     (4) April");
		printf("\n\t(5) May        (6) June       (7) July      (8) August");
		printf("\n\t(9) September  (10) October   (11) November (12) December\n\n");
	}
	else if (n == 3){//checks if input is 3 then print "after application use" instructions, otherwise do nothing
		printf("\n\nEnter '2' to use calendar again");
		printf("\nEnter '1' to go back to menu");
		printf("\nEnter '0' to exit program\n\n");
	}
}

/*
==================================================================
FUNCTION	: int calendar(void)
DESCRIPTION	: generate monthly calendar
ARGUMENTS	: none
RETURNS		: returns 1(to go back home) or returns 0 (exit program)
==================================================================
*/
int calendar(void){
	calendar_instructions(1); //print program main instructions
	int x = validate_int_input("\n\t(1) Continue\n\t(2) Go back to home\n\n\tEnter selection: ",1,2); //validate user input and store it in variable
	if(x == 2){ //checks if user wants to back to home
		return 1; //not proceed to program and go back home
	}
	clear();//clear output screen
	calendar_instructions(2); //print 2nd program instructions
	int month = validate_int_input("\nEnter month (numerical): ",1,12);
	//declare variables//
	int month_count = month - 1; 
	int month_gap[] = {6,2,2,5,0,3,5,1,4,6,2,4}; //The number of gap days before a month begins in a calendar//
	int days[] = {31,28,31,30,31,30,31,31,30,31,30,31}; //The number of days per month//
	clear();
	print_month (month); //print the name of the month
	generate_month(month, month_count, month_gap, days); //generate the calendar
	calendar_instructions(3); //print "after application use" instructions
	int n = validate_int_input("\nEnter selection: ",0,2); //validate selection of the user if inputted value is within the range of choices, and then store it in the variable
    if(n==2){//checks if user chooses to use the calendar again, otherwise proceed to the next condition 
    	clear(); //clear output screen
    	calendar(); //execute calendar again
	}
	else if(n==1){ //checks if user wants to go back to home, otherwise end program
		clear(); // clear output screen
    	return 1; //go back to home
	}
	else {
		return 0; //end program
	}
}
/*
==================================================================
FUNCTION	: void print_month (int input)
DESCRIPTION	: prints the name of the month
ARGUMENTS	: argument input holds the value of user's month choice 
RETURNS		: none
==================================================================
*/
void print_month (int input){ 
	printf("############################### CALENDAR ##################################\n");
	printf("***************************************************************************\n");
	switch (input){
		case 1: {
			printf("\n               January\n\n"); //print month name of January
			break;
		}
		case 2: {
			printf("\n               February\n\n"); //print month name of February
			break;
		}
		case 3: {
			printf("\n               March\n\n"); //print month name of March
			break;
		}
		case 4: {
			printf("\n               April\n\n"); //print month name of April
			break;
		}
		case 5: {
			printf("\n               May\n\n"); //print month name of May
			break;
		}
		case 6: {
			printf("\n               June\n\n"); //print month nameof June
			break;
		}
		case 7: {
			printf("\n               July\n\n"); //print month name of July
			break;
		}
		case 8: {
			printf("\n               August\n\n"); //print month name of August
			break;
		}
		case 9: {
			printf("\n               September\n\n"); //print month name of September
			break;
		}
		case 10: {
			printf("\n               October\n\n"); //print month name of October
			break;
		}
		case 11: {
			printf("\n               November\n\n"); //print month name of November
			break;
		}
		default: {
			printf("\n               December\n\n"); //print month name of December
			break;
		}
	}
	
} 
/*
==================================================================
FUNCTION	: void generate_month(int month, int month_count, int month_gap[], int days[])
DESCRIPTION	: generate calendar of the month
ARGUMENTS	: argument month holds the value of the month of choice, argument month_count holds the indexed value of the month, argument month_gap holds the number of gap days/per month and argument days holds the value of the number of days in a month
RETURNS		: none
==================================================================
*/
void generate_month(int month, int month_count, int month_gap[], int days[]){
	printf("    S    M    T    W    T    F    S\n   _________________________________\n"); //This function shows the dates in a calendar form//
	int i, n=1;
	for (i = 0; i < 6; i++){ //weeks in a month
		int j;
		for (j = 0; j < 7; j++){ //days in a week
			if(i == 0 && j < month_gap[month_count]){ //checks if current day is a gap day
				printf("     "); //print 5 spaces if current day is a gap day
			}
			else{
				if (n <= days[month_count]){ //checks if the current day is not a gap day
						printf("%5d",n++); //print the day
				}
			}
		}
		printf("\n"); //new line for the following week
	}
}






