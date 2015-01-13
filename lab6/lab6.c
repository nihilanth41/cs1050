//zrrm74
//lab6
//lab code: if i don't submit to section H i will recieve - 5 points
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for srand

//prototypes
int generateNumber(void);
void displayMenu(void);
int errorCheck(int);
int checkGuess(int, int);
void printResult(int, int);



int main(void) 
{
int playAgain = 1; //variable to control outer loop
int tries=0, wins=0; //keep track of number of wins and attempts
do
{
	tries++; //increment variable for number of attempts
	srand(time(NULL)); //seed for rng
	displayMenu(); //display input options
	int answer = 0, result = 0, guess = 0;
	do
	{
		scanf("%d", &guess);
		if(!errorCheck(guess)) //keep asking for a guess if user doesn't enter 0 or 1
		{ 
			printf("Invalid guess please enter 0 or 1: ");
		}
	}while(!errorCheck(guess));
	answer = generateNumber(); //flip a coin
	result = checkGuess(guess, answer); //check guess against answer (returns 1 if true 0 if false
	if(result == 1) 
	{
		wins++; //increment win counter if result is 1 
	}
	printResult(result, answer);
	printf("Do you want to play again? (1 yes, 0 no): ");
	do
	{
		scanf("%d", &playAgain);
		if(!errorCheck(playAgain))
		{
			printf("Invalid input. Enter 1 to play again, 0 to quit: ");
		}
	}while(!errorCheck(playAgain)); //make sure playAgain is 0 or 1, otherwise prompt the user until they enter 0 or 1
}while(playAgain == 1);
float winp = 100*((float)wins)/((float)(tries));
printf("\nYou made %d correct guesses in %d tries\n", wins, tries);
printf("Your win percentage is: %0.2f%%\n\n", winp);
return 0; 
}

int generateNumber(void) 
{
	return (rand()%2); //0 or 1 (heads/tails)
}

void displayMenu(void)
{
	printf("\nTake a guess:\n 0: Heads\n 1: Tails\nEnter your guess: ");
}

int errorCheck(int guess) 
{
	if(guess == 0 || guess == 1) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int checkGuess(int guess, int answer)
{
	if(guess == answer)
	{ 
		return 1; 
	}
	else
	{
		return 0;
	}
}

void printResult(int result, int answer) 
{
	if(result == 1) //guess was correct 
	{
		if(answer == 0) 
		{
			printf("\nYour guess was heads and it was a correct guess\n");
		}
		else if(answer == 1)
		{
			printf("\nYour guess was tails and it was a correct guess\n");
		}
	}
	else if(result == 0) //incorrect guess
	{
		if(answer == 0) //answer is heads
		{
			printf("\nYour guess was tails and it was an incorrect guess\n");
		}
		else if(answer == 1) //answer is tails
		{
			printf("\nYour guess was heads and it was an incorrect guess\n");
		}
	}
}

