#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include "app_scrabble.h"
#include "validate_clear.h"


/*
==================================================================
FILE			: app_scrabble.c
AUTHOR			: Christian Bayadog
DESCRIPTION		: This program executes the scrabble game
COPYRIGHT		: 11/27/2022
REVISION HISTORY
Date: 11/27/2022     By: Christian Bayadog   Decsription: additional comments for better program readability
==================================================================
*/


/*
==================================================================
FUNCTION	: void scrabble_instructions(int n)
DESCRIPTION	: print program instructions
ARGUMENTS	:argument n holds the number value that signifies which specific instruction to print
RETURNS		: none
==================================================================
*/
void scrabble_instructions(int n){
	//displays the instructions
	if (n == 1){ //checks if input is 1 then print main instructions for scrabble, otherwise proceed to next condition 
		printf("SCRABBLE GAME - C EDITION\n"); 
		printf("Instructions: Each player will input a word and whoever gets the word with most points accumulated wins!\n");
		printf("     Scoring: Each letter in the alphabet corresponds to a specific point. And also take note that the\n");  
		printf("	      more a letter is seldomly seen in english words, its equivalent point is much higher than\n"); 
		printf("	      those letters that are commonly used in english words. Best of luck players!\n");
		printf("\n\n(1) Continue\n(2) Go back to home");
		}
	else if (n == 2){//checks if input is 3 then print "after application use" instructions, otherwise do nothing
		printf("\n\nEnter '2' to play again");
		printf("\nEnter '1' to go back to menu");
		printf("\nEnter '0' to exit program\n\n");
	}
}

/*
==================================================================
FUNCTION	: validate_word(char* word, int x)
DESCRIPTION	: validates the word by basing it from the returned value from check_word function, 1 meaning word is valid, and 2 meaning word is invalid
ARGUMENTS	: argument word holds the pointer pf charracter array or word inputted by the user, argument x holds the player number
RETURNS		: none
==================================================================
*/
void validate_word(char* word, int x){
	//declare variables
	int end = 0;
	char word1[100];
	//get input from user and iterate again and again until user gives correct input
	while (end != 1){
		 //prompt user for input and store it in the variable
		printf("Player %d [word]: ",x);
		fflush(stdin);
 	   	gets(word1);
 	   	
 	   	if (check_word(word1)==1){ //checks if word is existent in the database, otherwise word is inexistent and then prompt user again for input
 	   		strcpy(word, word1); //copies the word inputted by the user and store it in another variable
 	   		printf("\n");
			end = 1; //end loop	
		}
		else {
			printf("Word not found in the database. Please choose another one:)\n");
			end = 0; //continue loop
		}
	}
}

/*
==================================================================
FUNCTION	: int scrabble(void)
DESCRIPTION	: executes the scrabble game and prints the winner
ARGUMENTS	: none
RETURNS		: returns 2 (play again), returns 1 (go back to home) or returns 0(end program)
==================================================================
*/
int scrabble(void){
	scrabble_instructions(1);
	//asks user to either continue with the program or go back to home
	int x = validate_int_input("\nEnter selection: ",1,2); //validate user input and store it in variable
	if(x == 2){ //checks if user wants to back to home
		return 1; //not proceed to program and go back home
	}
	printf("\n############################################ SCRABBLE GAME ##############################################\n"); 
	// Points assigned to each letter of the alphabet
	int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    // Get validated input words from both players
    char word1[100], word2[100];
    
	validate_word(word1, 1); //validated input from player 1
	validate_word(word2, 2); //validated input from player 2

    // Score both words
    int score1 = compute_score(word1,POINTS);
    int score2 = compute_score(word2,POINTS);

    //Print the winner
    if (score1 > score2)
    {
        printf("\nPlayer 1 wins!\n");
        printf("(^v^)(^v^)(^v^)(^v^)");
    }
    else if (score2 > score1)
    {
        printf("\nPlayer 2 wins!\n");
        printf("(^v^)(^v^)(^v^)(^v^)");
    }
    else
    {
        printf("\nTie!\n");
        printf("(•.•)(•.•)(•.•)(•.•)");
    }
    //prints the total accumulated points by the players
    printf("\n\n--------------------------------\nPoints accumulated by players:\n");
    printf("\nPlayer 1 = %d points\nPlayer 2 = %d points\n",score1,score2);
    //asks user for input in order for the program to execute one of the presented course of actions
    scrabble_instructions(2);
    int n = validate_int_input("\nEnter selection: ",0,2); //validates input from user
    if(n==2){ //checks if user wants to play scrabble again
    	clear(); //clear output screen
    	scrabble(); //execute scrabble
    	return 1; 
	}
	else if(n==1){ //checks if user wants to go back home
    	return 1; //redirected to home
	}
	else{
		return 0; //end program
	}
}

/*
==================================================================
FUNCTION	: int compute_score(char word[], int POINTS[])
DESCRIPTION	: computes the score by adding all the points each word gained
ARGUMENTS	: argument word holds the value of charracter array or word inputted by the user while argument POINTS holds an array of points specific to each letter of the alphabet
RETURNS		: returns score
==================================================================
*/
int compute_score(char word[], int POINTS[])
{
  	//declare variables 
    int sum = 0, sum1 = 0, sum2 = 0, point1 = 0, point2 = 0;

    //Iterate nth-times based in the length of the string
    int i, n;
    for (i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i])) // Uppercase Letters
        {
            // variable x holds the difference of the current letter's ASCII decimal number and 'A' (Which is equivalent to 65)
            int x = word[i] - 'A'; 
            point1 = POINTS[0 + x]; // the value of [x + 0] corresponds the point of the letter in the POINTS[] array
            sum1 = sum1 + point1; // Adds the points after each iteration
        }
        else if (islower(word[i])) // Lowercase letters
        {
            // variable y holds the difference of the current letter's ASCII decimal number and 'a' (Which is equivalent to 97)
            int y = word[i] - 'a';
            point2 = POINTS[0 + y]; // the value of [y + 0] corresponds the point of the letter in the POINTS[] array
            sum2 = sum2 + point2; // Adds the points after each iteration
        }
        sum = sum1 + sum2; // Sums up the points of sum1 and sum2 after each iteration
    }
    return sum; //returns the score 
}

/*
==================================================================
FUNCTION	: check_word(char word[])
DESCRIPTION	: checks if word is found in the database
ARGUMENTS	: argument word holds the charracter array value or word inputted by the user
RETURNS		: returns 1 (word is found) or returns 2(word is not found)
==================================================================
*/
int check_word(char word[]){
	//declare variables
	int res;
	char word1[100];
	//checks line by line inside the "listOfWords.txt" file if the word inputter by the user corresponds to one of the words in the file
	FILE *fptr=fopen("listOfWords.txt","r");//open file and read it
	while(fscanf(fptr,"%s\n",word1)!=EOF){
		res=strcmpi(word,word1); //checks if current word in the line inside the file is the same with the user's input
		if(res==0){
			return 1; //word is found
		}
	}
	fclose(fptr); //close file
	return 0; //word not found
}





