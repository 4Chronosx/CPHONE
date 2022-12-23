#include<stdio.h>
#include "app_menu.h"
#include "validate_clear.h"
/*
==================================================================
FILE			: app_menu.c
AUTHOR			: Luigi Hatamosa
DESCRIPTION		: This program display the menu for the cphone
COPYRIGHT		: 11/27/2022
REVISION HISTORY
Date: 11/27/2022     By: Luigi Hatamosa  Decsription: additional comments for better program readability
==================================================================

==================================================================
FUNCTION	: int menu(void)
DESCRIPTION	: display menu and ask user for choice
ARGUMENTS	: none
RETURNS		: return choice
==================================================================
*/
int menu(void){
	//display menu
	printf("-------------------------- APPLICATIONS ---------------------\n\n");    
    printf("\t               ____           ____\n");
    printf("\t              |----|         |30  |\n");
    printf("\t              |    |         |....|\n");
    printf("\t              |    |         |....|\n");
    printf("\t              |____|         |____|\n\n");
    printf("\t         (1) PHONEBOOK  (2) CALENDAR\n\n");
    printf("\t               ____           ____\n");
    printf("\t              |0000|         |SCRA|\n");    
    printf("\t              |....|         |BBLE|\n");
    printf("\t              |+-*/|         |101 |\n");
    printf("\t              |____|         |____|\n\n");  
    printf("\t         (3) CALCULATOR (4) SCRABBLE\n\n");
    printf("\t                ____\n");
    printf("\t               |ELEC|\n");
    printf("\t               | &  |\n");
    printf("\t               |H2O |\n");
    printf("\t               |____|\n\n");
    printf("\t         (5) UTILITIES  (0) lock phone\n\n");

	int choice = validate_int_input("\nChosen application: ",0,5); //ask user for application choice and validate it 
	
	return choice; //return choice to the main function in CPHONE.c
}


