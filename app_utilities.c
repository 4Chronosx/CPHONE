#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "app_utilities.h"
#include "validate_clear.h"
/*
==================================================================
FUNCTION	: void calcu_instructions(int n)
DESCRIPTION	: print program instructions
ARGUMENTS	:argument n holds the number value that signifies which specific instruction to print
RETURNS		: none
==================================================================
*/
void program_instructions(int n){ 
	//displays the isntructions for the program
	if(n == 1){//checks if input is 1 then print main instructions for calculator, otherwise proceed to next condition 
		printf("Choose a utility:\n");
		printf("\t(1) Electricity\n");
		printf("\t(2) Water\n");
		printf("\t(3) Cancel\n\n");
	} 
	else if(n == 2){//checks if input is 2 then print 2nd instructions for calculator, otherwise proceed to next condition 
		printf("Electricity bill calculator [Device Consumption]\n\n");
		printf("Instruction:    Get your device's wattage. Find this information at the bottom or back of the device, \n\t\tor in the owner's manual.\n"); 
		printf("                You may also try searching the device's technical specs online.\n\n");
		printf("This calculator will do the following: \n");
		printf("	1. Compute the watts the device consumes daily. Multiply the wattage by the average number of hours the device\n\t   is used per day.\n"); 
		printf("	2. Convert watt-hours to kilowatts. Divide the device's watt-hours by 1,000 to convert it to kilowatts, which \n\t   is the unit of measurement used in a Meralco bill.\n"); 
		printf("	3. Compute the device's monthly power consumption. Multiply your device's daily kWh by 30 days to determine\n\t   how much it consumes per month.\n"); 
		printf("	4. Add total estimated bill for all the devices inputted.\n\n");
		printf("Note: P9.70 is the current average rate per kwh in the Philippines hence such rate will be used in this program.\n");
		printf("-----------------------------------------------------------------------------------------------------------------------");
		printf("\n############################################ ELECTRICITY BILL CALCULATOR ##############################################"); 
	}
	else if (n == 3){//checks if input is 3 then 3rd instructions for calculator, otherwise proceed to next condition 
		clear();
		printf("WATER BILL CALCULATOR\n");
		printf("Instructions: This program will calculate the estimated water bill based on the current amount of units consumed by the\n\t\tuser.\n");
		printf("This calculator will do the following:\n");
		printf("\t1. Obtain usage charge by multiplying the units and the rate per unit.\n");
		printf("\t2. The water bill will be calculated by adding the service charge and the usage charge\n\n");
		printf("-----------------------------------------------------------------------------------------------------------------------");
		printf("\n############################################ WATER BILL CALCULATOR ##############################################\n\n"); 
	}
	else if(n == 4){//checks if input is 4 then print "after application use" instructions, otherwise do nothing
		printf("\n\nEnter '2' to use utilities again\n");
		printf("Enter '1' to go back to Home\n");
		printf("Enter '0' to exit program\n\n");
	}	
}

/*
==================================================================
FUNCTION	: int utility(void)
DESCRIPTION	: provides a menu for specific utility selection and redirect user upon his specified choice
ARGUMENTS	: none
RETURNS		: returns 1 (go back to home) , returns 0 (end program)
==================================================================
*/
int utility(void){
	//declare variables
	int selection,x;
	program_instructions(1);
	//prompt user for input and validates it, and then store it in a variable
	selection = validate_int_input("\nEnter selection: ",1,3);
	
	if(selection == 1){ //checks if the user chooses to use the electricity calculator, otherwise user chooses water bill calculator
		x = electricity_calculator(); //execute the electricity bill calculator and returns an int (signifying a user's direction (1) go back to home or (0) end program
	}
	else if(selection == 2){
		x = water_calculator(); //execute the water bill calculator
	}
	else {
		x = 1;
	}
	return x; //returns the int value returned to the calculator functions to the main function in CPHONE.c
}
/*
==================================================================
FILE			: electricity.c
AUTHOR			: Christian James Bayadpg
DESCRIPTION		: This program will be calculating the electricity bill
COPYRIGHT		: 11/27/2022
REVISION HISTORY
Date: 11/27/2022     By: Christian James Bayadog    Decsription: additional comments for better program readability
==================================================================
==================================================================
FUNCTION	: int electricity_calculator(void)
DESCRIPTION	: calculates and prints electricity bill
ARGUMENTS	: none
RETURNS		: returns 1 (go back to home) , returns 0 (end program)
==================================================================
*/
int electricity_calculator(void){
	//declare variables
	float watts[100], usage[100], device_consumption[100], total_bill;
	int choice;
	program_instructions(2); //print program instructions
	
	int end = 0, index = 0, x = 1; // declare variables
	while (end != 1){ //a loop that asks user for input repeatedly 
		//prompt user for input, validate it, and store it in their designated variable
		printf("\n\n[Device %d]\n",x);
		watts[index] = validate_parameters("\tWatts: "); //ask user for watts and validate it
		usage[index] = validate_parameters("\tAverage daily usage (hours): "); //ask user for daily usage and validate it
		device_consumption[index] = calculate_device_consumption(watts[index],usage[index]); //calculate device consumption in a month
		//prompt user to select which course of action to proceed with
		printf("\n\t(1) Add more\n\t(2) Check bill\n");
		choice = validate_int_input("\tEnter selection: ",1,2); //validate selection of the user if inputted value is within the range of choices, and then store it in the variable
		end = end_loop(choice); //returns 1 (to end the loop) or returns 0 (to continue with the loop)
		//increment
		index++;
		x++;
	}
	total_bill = calculate_total_bill(device_consumption, index); //calculate the total bill for all the devices of the user
	printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n");
	printf("Projected bill by the end of the month: P %.2f\n",total_bill); //print total bill
	printf("-----------------------------------------------------------------------------------------------------------------------");
	//prompt user to select which course of action to proceed with
	program_instructions(4);
	int n = validate_int_input("\nEnter selection: ",0,2); //validate selection of the user if inputted value is within the range of choices, and then store it in the variable
    if(n==2){ //checks if user chooses to use the utilities again, otherwise proceed to the next condition 
    	clear(); //clear output screen
    	utility(); //execute utility again
	}
	else if(n==1){ //checks if user chooses to go back to home
		clear();
    	return 1; //go back home
	}
	else if(n==0){
		return 0; //returns the 1 value (go back home) to the utility function
	} 
}
/*
==================================================================
FUNCTION	: float convert_to_kwh(float usage_per_day)
DESCRIPTION	: convert watts to kilowatss
ARGUMENTS	: argument usage_per_day holds the value of watts consumed by a device in a day
RETURNS		: returns converted watts (kilowatts)
==================================================================
*/
float convert_to_kwh(float usage_per_day){
	return usage_per_day/1000; //convert watts to kilowatts
}
/*
==================================================================
FUNCTION	: end_loop(int choice)
DESCRIPTION	: determines if a user wants to end the loop or not
ARGUMENTS	: argument choice holds the value of selection inputted by the user
RETURNS		: returns 1 (add another device) or returns 2 (check bill)
==================================================================
*/
int end_loop(int choice){
	if (choice == 1){ // if user wants to input another device's consumption, proceed, otherwise return 1 to stop loop
		return 0;
	}
	else if(choice == 2){
		return 1; 
	}
}
/*
==================================================================
FUNCTION	: float calculate_device_consumption(float watts, float usage)
DESCRIPTION	: calculate device consumption in a month
ARGUMENTS	: argument watts holds the watts value while argument usage holds the usage value 
RETURNS		: returns device's monthly consumption
==================================================================
*/
float calculate_device_consumption(float watts, float usage){
	float daily_usage = watts*usage; //calculate daily usage
	return 30 * convert_to_kwh(daily_usage); //calculate a device's monthly usage/consumption
}
/*
==================================================================
FUNCTION	: calculate_total_bill(float device_consumption[], int index)
DESCRIPTION	: calculates the total bill for all devices
ARGUMENTS	: argument device_consumption holds an array of consumption values from each of the devices while argument index holds the total number of devices
RETURNS		: returns total bill
==================================================================
*/
float calculate_total_bill(float device_consumption[], int index){
	int j;
	float total_bill;
	float rate_kwh = 9.70;
	for (j = 0; j < index; j++){
		total_bill = total_bill + (device_consumption[j] * rate_kwh); //multiplies each of the device's monthly consumption to the hourly rate, and then add the product repeatedly for all devices
	}
	return total_bill; //return sum of all the device's monthly bill
}
/*
==================================================================
FILE			: water_bill.c
AUTHOR			: Nathaniel Cornelio
DESCRIPTION		: This program will be calculating the water bill
COPYRIGHT		: 11/27/2022
REVISION HISTORY
Date: 11/27/2022     By: Nathaniel Cornelio    Decsription: additional comments for better program readability
==================================================================

==================================================================
FUNCTION	: int water_calculator(void)
DESCRIPTION	: calculate waterbill from inputted parameters from user
ARGUMENTS	: argument string holds the an array of characters inputted by the user
RETURNS		: returns 1 (use utility again) or returns 0 (go back to home)
==================================================================
*/
int water_calculator(void){
	//print instructions
	program_instructions(3);
	
	float service_charge, usage_charge, water_bill, rate_p_unit, units; 
	
	units = validate_parameters("Enter unit/s: "); //asks user for unit input and validate it
	rate_p_unit = validate_parameters("Enter rate per unit: "); //asks user for rate input and validate it
	service_charge = validate_parameters("Enter service charge: "); //asks user for service charge and validate it
	
	usage_charge = units * rate_p_unit; //calculate usage charge
	water_bill = service_charge + usage_charge; //calculate water bill
	printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n");
	printf("Estimated water bill: P %.2f", water_bill); //print water bill
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n\n");
	//prompt user to select which course of action to proceed with
	program_instructions(4);
	int n = validate_int_input("\nEnter selection: ",0,2);//validate selection of the user if inputted value is within the range of choices, and then store it in the variable
    if(n==2){//checks if user chooses to use the calculator again, otherwise proceed to the next condition 
    	clear(); //clear output screen
    	utility(); //use utlitilies again 
	}
	else if(n==1){ //checks if user chooses to go back to home, otherwise end program
		clear();
    	return 1; //return 1 to utility function to redirect back to home
	}
	else{
		return 0; 
	}
}





