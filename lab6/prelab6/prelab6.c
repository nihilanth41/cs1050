//Zach Rump
//Prelab 6
//CS1050 Spring 14
//Lab section H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//**************
//CHECK DIVISION FUNCTION

//prototypes
int generateNumber(void);
int cube(int);
float division(int, int);

int main(void)
{
	//provide seed for rng
	srand(time(NULL));
	int x = generateNumber();
	int y = generateNumber();
	printf("The first random number is: %d\n", x);
	printf("The second random number is: %d\n", y);
	printf("The cube of %d is %d\n", x, cube(x));
	printf("The cube of %d is %d\n", y, cube(y));
	float f = division(x,y);
	printf("Division(%d,%d)= %f\n", x, y, f);
	return 0; 
}


//generates a number between 0-9 and returns it
int generateNumber(void) 
{

	return (rand()%10);
}

//takes an int argument and returns the int^3
int cube(int i) 
{
	return (i*i*i);
}

//divide the larger of the two over the smaller of the two and return the result
float division(int x, int y)
{
	//if one of the numbers is 0 return 0
	if(x==0||y==0)
	{
		return 0;
	}
	else if(x==y)
	{
		return 1;
	}
	else if(x>y)
	{
		float f = (x/y);
		return f;
	}
	else //x<y
	{
		float f = (y/x);
		return f;
	}	
}

