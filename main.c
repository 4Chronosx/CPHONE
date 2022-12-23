#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include "lock_screen.h"
#include "app_menu.h"
#include "app_calculator.h"
#include "app_calendar.h"
#include "app_calculator.h"
#include "app_scrabble.h"
#include "app_utilities.h"
#include "validate_clear.h"

/*
==================================================================
FUNCTION	: int main(void)
DESCRIPTION	: execute CPHONE program
ARGUMENTS	: none
RETURNS		: return 0 (if program works fine)
==================================================================
*/
int main(void){
	lock(); //execute lockscreen of the program

	int n, end = 1;
	
	while(end != 0){
		clear(); //clear output screen
		n = menu(); //display menu and get user selection which will be stored in the variable
		switch(n){
			case 1: { //check if user chose 1 (use phonebook)
				clear(); //clear output screen
				end = phonebook(); //execute phonebook and returns 1(user wants to go to the menu again) or 0(user wants to exit program) 
				break;
			}
			case 2: {//check if user chose 2 (use phonebook)
				clear();//clear output screen
				end = calendar();//execute calendar and returns 1(user wants to go to the menu again) or 0(user wants to exit program) 	
				break;
			}
			case 3: {//check if user chose 3 (use phonebook)
				clear();//clear output screen
				end = calculator();//execute calculator and returns 1(user wants to go to the menu again) or 0(user wants to exit program) 
				break;
			}
			case 4: {//check if user chose 4 (use phonebook)
				clear();//clear output screen
				end = scrabble();//execute scrabble and returns 1(user wants to go to the menu again) or 0(user wants to exit program) 
				break;
			}
			case 5: {//check if user chose 5 (use phonebook)
				clear();//clear output screen
		    	end = utility();//execute utility and returns 1(user wants to go to the menu again) or 0(user wants to exit program) 
				break;
			}
			default: {//check if user chose 0 (use phonebook)
				clear();//clear output screen
				lock();//execute phonebook and returns 1(user wants to go to the menu again) or 0(user wants to exit program) 
				break;
			}
		}
	}
	return 0;
}





