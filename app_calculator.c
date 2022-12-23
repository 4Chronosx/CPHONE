#include <stdio.h> 
#include <math.h> 
#include "app_calculator.h"
#include "validate_clear.h"

/*
==================================================================
FILE			: app_calculator.c
AUTHOR			: Dominic Paolo S. Son
DESCRIPTION		: This program will be performing the 4 basic mathematical calculations inputted by the user
COPYRIGHT		: 10/26/2022
REVISION HISTORY
Date: 10/26/2022     By: Dominic Paolo S. Son    Decsription: additional comments for better program readability
==================================================================

==================================================================
FUNCTION	: void calcu_instructions(int n)
DESCRIPTION	: print program instructions
ARGUMENTS	:argument n holds the number value that signifies which specific instruction to print
RETURNS		: none
==================================================================
*/

void calcu_instructions(int n){
	//displays the instructions
	if (n == 1){//checks if input is 1 then print main instructions for calculator, otherwise proceed to next condition 
		printf("CALCULATOR\nInstruction: This program will be performing the 4 basic mathematical calculations\n");
		printf("########################################### CALCULATOR ####################################################\n");
		printf("\nPlease enter the operation you wish to perform ");
		printf("\n\n(1) Addition \n(2) Subtraction\n(3) Multiplication\n(4) Division\n\n(5) Cancel");
	}
	else if (n == 2){//checks if input is 3 then print "after application use" instructions, otherwise do nothing
		printf("\n\nEnter '2' to use calculator again");
		printf("\nEnter '1' to go back to menu");
		printf("\nEnter '0' to exit program\n\n");
	}
}

/*
==================================================================
FUNCTION	: int calculator(void)
DESCRIPTION	: calculates multiple operations and prints their results
ARGUMENTS	: the argument a holds the value of the first number and the argument b holds the value of the 2nd number
RETURNS		: return 2 (use calculator again) or return 1 (go back to home) or return 0 (exit program)
==================================================================
*/

int calculator(void){
	//declare variables
	float result,a,b;
	int op;
	calcu_instructions(1); //print 1st program instructions
	op=validate_int_input("\n\nChosen operation: ",1,5);//checks if choice inputted is valid and store it in a variable//
	if (op == 5){ //checks if the user wants to cancel the use of calculator
		return 1; // go back to home
	}
	printf("\n\n=================================================\n");
	//ask user for inputs and store it in the variables//
	printf("\nEnter the first number: ");
	scanf("%f", &a);
	printf("\nEnter the second number: ");
	scanf("%f", &b);
	printf("\n\n=================================================\n");
	if(op == 1){//if user chooses addition proceed, otherwise go to the next
		result = add(a, b);// adds the the two numbers and store in the variable
		printf("\nThe sum of %.2f and %.2f is %.2f", a, b, result);//print result
	} 
	else if(op == 2){
		result = subtract(a, b);// subtracts the the two numbers and store in the variable
		printf("\nThe difference of %.2f and %.2f is %.2f", a, b, result);//print result
	} 
	else if(op == 3){
		result = multiply(a, b);// multiplies the the two numbers and store in the variable
		printf("\nThe product of %.2f and %.2f is %.2f", a, b, result);//print result
	} 
	else if (op == 4){
		result = divide(a, b);// divides the the two numbers and store in the variable
		printf("\nThe quotient of %.2f and %.2f is %.2f", a, b, result);//print result
	} 
	calcu_instructions(2); //print 2nd program instructions
	int n = validate_int_input("\nEnter selection: ",0,2); //validate input and store it in the variable
    if(n==2){ // if n == 2, use calculator again, otherwise proceed to the next condition
    	clear(); //clear output screen
    	calculator(); //display calculator
    	return 1; 
	}
	else if(n==1){ // if n == 1, return to home, otherwise exit the program
    	return 1;
	}
	else {
		return 0; 
	}
}



/*
==================================================================
FUNCTION	: float add(float a, float b) 
DESCRIPTION	: adds two numbers
ARGUMENTS	: the argument a holds the value of the first number and the argument b holds the value of the 2nd number
RETURNS		: return a+b
==================================================================
*/
float add(float a, float b) 
{
	return a + b; //add a and b
}
/*
==================================================================
FUNCTION	: float subtract(float a, float b) 
DESCRIPTION	: subtracts two numbers
ARGUMENTS	: the argument a holds the value of the first number and the argument b holds the value of the 2nd number
RETURNS		: return a-b
==================================================================
*/
float subtract(float a, float b) 
{
	return a - b; //subtract a and b
}
/*
==================================================================
FUNCTION	: float multiply(float a, float b)
DESCRIPTION	: multiplies two numbers 
ARGUMENTS	: the argument a holds the value of the first number and the argument b holds the value of the 2nd number
RETURNS		: return a*b
==================================================================
*/
float multiply(float a, float b) 
{
	return a * b; //multiply and b 
}
/*
==================================================================
FUNCTION	: float divide(float a, float b) 
DESCRIPTION	: divides two numbers 
ARGUMENTS	: the argument a holds the value of the first number and the argument b holds the value of the 2nd number
RETURNS		: return a/b
==================================================================
*/
float divide(float a, float b) 
{
	return a / b; // devide a and b
}





