#include<stdio.h>
#include<string.h>
#include "app_phonebook.h"
#include "validate_clear.h"

/*
==================================================================
FILE			: app_phonebook.c
AUTHOR			: Nathaniel Cornelio
DESCRIPTION		: This program holds contact details of T1 students that has search functions and list functions
COPYRIGHT		: 11/24/2022
REVISION HISTORY
Date: 12/9/2022     By: Nathaniel Cornelio    Decsription: additional comments for better program readability
==================================================================
*/

/*
==================================================================
FUNCTION	: int phonebook(void)
DESCRIPTION	: execute phonebook program
ARGUMENTS	: none
RETURNS		: return 1(redirect to home) or return 0 (end program)
==================================================================
*/
int phonebook(void){
	//declare variables and store data in array
	char people[38][50];
	
	strcpy(people[0],"Don King Ababa");
	strcpy(people[1],"Miguel Andrei Abella");
	strcpy(people[2],"Janno Arradaza");
	strcpy(people[3],"John Barrot");
	strcpy(people[4],"Miguel Bautista");
	strcpy(people[5],"Christian James Bayadog");
	strcpy(people[6],"Peterbrille Camba");
	strcpy(people[7],"Isabella Campos");
	strcpy(people[8],"Jac Gary Cañete");
	strcpy(people[9],"Lance Cerenio");
	strcpy(people[10],"Remy Cordero");
	strcpy(people[11],"Nathaniel Cornelio");
	strcpy(people[12],"Rainier Darle");
	strcpy(people[13],"Clive Delima");
	strcpy(people[14],"Maurice Fontanosa");
	strcpy(people[15],"Matt Fulache");
	strcpy(people[16],"Luigi Hatamosa");
	strcpy(people[17],"Kyle Jalang");
	strcpy(people[18],"Franchesca Kho");
	strcpy(people[19],"Max Limpag");
	strcpy(people[20],"Kimberly Luistro");
	strcpy(people[21],"Dean Mata");
	strcpy(people[22],"Kim Mauring");
	strcpy(people[23],"Karl Medina");
	strcpy(people[24],"Ghemarson Nacua");
	strcpy(people[25],"Angelo Nullar");
	strcpy(people[26],"Belle Ocampo");
	strcpy(people[27],"Belha Puso");
	strcpy(people[28],"Vince Reales");
	strcpy(people[29],"Zechariah Refugio");
	strcpy(people[30],"John Carlo Sandro");
	strcpy(people[31],"Christian Supremo");
	strcpy(people[32],"Dominic Son");
	strcpy(people[33],"Daphne Surigao");
	strcpy(people[34],"Jaden Tejano");
	strcpy(people[35],"Conrad Urgel");
	strcpy(people[36],"Vincent Villariza");
	strcpy(people[37],"John Andre Yap");
	
	double number[38];
	number[0] = 9923529466;
	number[1] = 9278527381;
	number[2] = 9695628580;
	number[3] = 9202061075;
	number[4] = 9391474844;
	number[5] = 9611855867;
	number[6] = 9761973945;
	number[7] = 9391866286;
	number[8] = 9164840820;
	number[9] = 9159031303;
	number[10] = 9171556002;
	number[11] = 9084103715;
	number[12] = 9209738903;
	number[13] = 9924669985;
	number[14] = 9157255069;
	number[15] = 9062629221;
	number[16] = 9560499050;
	number[17] = 9954119220;
	number[18] = 9162347261;
	number[19] = 9198491531;
	number[20] = 9293438367;
	number[21] = 9565011604;
	number[22] = 9473671505;
	number[23] = 9999603389;
	number[24] = 9154534812;
	number[25] = 9390037670;
	number[26] = 9669103846;
	number[27] = 9566480547;
	number[28] = 9206323039;
	number[29] = 9663929594;
	number[30] = 9102142656;
	number[31] = 9777741247;
	number[32] = 9560374845;
	number[33] = 9562656800;
	number[34] = 9272921612;
	number[35] = 9273498577;
	number[36] = 9138238730;
	number[37] = 9150443019;
	//display instructions
	printf("PHONEBOOK\nInstructions: This phonebook contains the contact numbers of all the T1 Students\n\n");
	printf("\t(1) Search\n\t(2) List\n\t(3) Cancel\n");
	int n = validate_int_input("\n\tEnter selection: ",1,3); //validate selection of the user if inputted value is within the range of choices, and then store it in the variable
	int x; 
	switch(n){
		case 1: {
			clear(); //clear output screen
			x = search(people,number); //use search function and return 0 (user wants to end program) or return 1 (user wants to go back to home)
			break;
		}
		case 2: {
			clear();//clear output screen
			x = list(people, number); //use list function and return 0 (user wants to end program) or return 1 (user wants to go back to home)
			break;
		}
		default: {
			return 1; // return to home
			break;
		}
	}
	return x; // return the value of user's choice of action
	
}
/*
==================================================================
FUNCTION	: int search(char people[38][50], double number[])
DESCRIPTION	: search for contact details 
ARGUMENTS	: argumment people holds an array of contact names, argument number holds the contact numbers 
RETURNS		: return 1(redirect to home) or return 0 (end program)
==================================================================
*/
int search(char people[38][50], double number[]){
	//declare variables
	char search[100];
	printf("############################################ SEARCH ############################################\n");
	printf("************************************************************************************************\n");
	printf("Enter name of contact: "); //prompt user for input and store it in a variable
	gets(search);
	
	//declare variables
	int i, check = 0;
	
	for (i = 0; i < 38; i++){ //iterates and views each of the elements in the people array
		if(strcmpi(search,people[i]) == 0){ //checks if the searched name of the user corresponds to the same name in the data base / array
			printf("Person found!\n----------------\n");
			printf("Name: %s\nContact number: %011.0lf\n\n\n",people[i],number[i]); //print contact name and number
			check = 1; //signify that contact is found
			break; 
		}
	}
	if (check == 0){ //checks if contact is not found
		printf("Person not found!");
	}
	//prompt user to select which course of action to proceed with
	printf("\n\nEnter '2' to use phonebook again\n");
	printf("Enter '1' to go back to Home\n");
	printf("Enter '0' to exit program\n\n");
	int n = validate_int_input("\nEnter selection: ",0,2);//validate selection of the user if inputted value is within the range of choices, and then store it in the variable
    if(n==2){//checks if user chooses to use the calculator again, otherwise proceed to the next condition 
    	clear(); //clear output screen
    	phonebook();

	}
	else if(n==1){ //checks if user chooses to go back to home, otherwise end program
		clear();
    	return 1; //return 1 to utility function to redirect back to home
	}
	else{
		return 0; //end program
	}
}
/*
==================================================================
FUNCTION	: int list(char people[38][50], double number[])
DESCRIPTION	: display list of contacts 
ARGUMENTS	: argumment people holds an array of contact names, argument number holds the contact numbers 
RETURNS		: return 1(redirect to home) or return 0 (end program)
==================================================================
*/
int list(char people[38][50], double number[]){
	printf("############################################ LIST ############################################\n");
	printf("************************************************************************************************\n");
	int i;
	for (i = 0; i < 38; i++){ //iterates through all of the elements in the people and number array
		printf("Name: %s\nContact number: %011.0lf\n\n",people[i],number[i]); //print each element one by one
		printf("\n");
	}
	//prompt user to select which course of action to proceed with	
	printf("\n\nEnter '2' to use phonebook again\n");
	printf("Enter '1' to go back to Home\n");
	printf("Enter '0' to exit program\n\n");
	int n = validate_int_input("\nEnter selection: ",0,2);//validate selection of the user if inputted value is within the range of choices, and then store it in the variable
    if(n==2){//checks if user chooses to use the calculator again, otherwise proceed to the next condition 
    	clear(); //clear output screen
    	phonebook();

	}
	else if(n==1){ //checks if user chooses to go back to home, otherwise end program
		clear();
    	return 1; //return 1 to utility function to redirect back to home
	}
	else{
		return 0; //end program
	}
}






