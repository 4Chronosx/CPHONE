#include <stdio.h>
#include <dos.h>
#include "lock_screen.h"
#include "validate_clear.h"
/*
==================================================================
FILE			: Lock.c
AUTHOR			: Dominic Paolo S. Son
DESCRIPTION		: This program logins the user into the c-phone program 
COPYRIGHT		: 10/26/2022
REVISION HISTORY
Date: 10/26/2022     By: Dominic Paolo S. Son    Decsription: additional comments for better program readability
==================================================================


==================================================================
FUNCTION	: void lock(void)
DESCRIPTION	: prints login screen and asks user for password to log in to the cphone program
ARGUMENTS	: takes no argument
RETURNS		: none
==================================================================
*/
void lock(void) {
	printf("----------------------C - PHONE----------------------\n");
	printf("*****************************************************\n");
	printf("\n\n");
	printf("           ############################\n");
	printf("           ############################\n");
	printf("           ############################\n");
	printf("           ############################\n");
	printf("           ############################\n");
	printf("           ##############\n");
	printf("           ##############\n");
	printf("           ##############\n");
	printf("           ##############\n");
	printf("           ##############\n");
	printf("           ##############\n");
	printf("           ##############\n");
	printf("           ############################\n");
	printf("           ############################\n");
	printf("           ############################\n");
	printf("           ############################\n");
	printf("           ############################\n\n");
	printf("\t   Welcome to the CPHONE device!\n\n");// displays the instructions//
	//declare varaibles//
	char pass[100], x=1;	
	int check_pass; 
	//a loop that will ask the user's input and checks if it is correct
	while (x!=0){
	//prompt user for input and stores it in a variable
		printf("\n\t   Enter password: ");
		gets(pass);
		check_pass=check_password(pass);//checks if password is correct and stores returned value from the function to the variable
	
		if (check_pass==1){//checks if password is correct, otherwise print password is wrong and iterate loop again to ask user password input
			x=0; //password is correct
		}
		else{
			printf("\t   Wrong Password, try again..."); //password is wrong
			sleep(1);
		}
		printf("\n");
	}
		
}
/*
==================================================================
FUNCTION	: int check_password(char pass[])
DESCRIPTION	: checks if the password is correct
ARGUMENTS	: argument pass holds the a character array inputed by the user
RETURNS		: return 1 (password is correct) and return 0 (password is incorrect)
==================================================================
*/
int check_password(char pass[]){
	if (strcmp(pass,"ilovecfp") == 0){//checks password inputted is equivalent to the system's passowrd, otherwise password is incorrect 
		return 1;//returns 1 if password is correct//
	}
	else 
		return 0;//returns 0 if password is incorrect//								
}
