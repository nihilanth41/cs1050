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

int guess = 0;

int main(void) 
{
	srand(time(NULL)); //seed for rng
	displayMenu(); 
	int answer = 0, result = 0; 
	do
	{
	scanf("%d", &guess);
	if(!errorCheck(guess)) //keep asking for a guess if user doesn't enter 0 or 1
		{ 
		printf("Invalid guess please enter 0 or 1: ");
		}
	}	
	while(!errorCheck(guess));
	answer = generateNumber(); //flip a coin
	result = checkGuess(guess, answer); //check guess against answer (returns 1 if true 0 if false)
	printResult(result, answer);

	return 0; 
}

int generateNumber(void) 
{
	return (rand()%2); //0 or 1 (heads/tails)
}

void displayMenu(void)
{
	printf("Take a guess:\n 0: Heads\n 1: Tails\nEnter your guess: ");
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
	if(result == 1) 
	{
		if(guess == 0) 
		{
			printf("Your guess was heads and it was a correct guess\n");
		}
		else if(guess == 1)
		{
			printf("Your guess was tails and it was a correct guess\n");
		}
	}
	else if(result == 0)
	{
		if(guess == 0)
		{
			printf("Your guess was heads and it was an incorrect guess\n");
		}
		else if(guess == 1)
		{
			printf("Your guess was tails and it was an incorrect guess\n");
		}
	}
}

