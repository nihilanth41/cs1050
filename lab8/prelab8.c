//zrrm74
//prelab8
//section H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 //preprocessor declaration for array size

//prototypes
int check_size(int);
void initialize_2Darray(int[][MAX], int);
void print_2Darray(int [][MAX], int);
int smallest_number(int [][MAX], int);

int main(void)  
{	//main array
	int array[MAX][MAX] = { 0 };
	int array_size=0; //var for array size
	do{	//check array size in a loop
		printf("Enter the size of the array: ");
		scanf("%d", &array_size);
		if(!check_size(array_size))
		{
			printf("Invalid array size\n");
		}
	   }while(!check_size(array_size));
	//initialize square array of given size
	initialize_2Darray(array, array_size);
	//print out array
	printf("\nInput array\n");
	print_2Darray(array, array_size);
	//print smallest number
	printf("\nSmallest number in the array is %d\n", smallest_number(array, array_size));
	return 0;
}

int check_size(int n)
{ //takes int argument, returns 1 if number is between 0-100, 0 if not
	if(n>100||n<0)
	{
		return 0;
	}
	else
	{
		return 1; 
	}
}

void initialize_2Darray(int a[][MAX], int size)
{ //initialize array w/ random numbers 0-9 
  srand(time(NULL)); //seed rng
  for(int i=0; i<size; i++) //iterate rows
  {
	  for(int j=0; j<size; j++) //iterate columns
	  {
		  a[i][j]=(rand()%10); //assign random number 0-9
	  }
  }

}

void print_2Darray(int a[][MAX], int size)
{ //prints content of 2d array
	for(int i=0; i<size; i++) //iterate rows
  	{
		for(int j=0; j<size; j++) //iterate columns
	  	{
			printf("%d ", a[i][j]); //print array element at row i column j
	  	}
	  printf("\n"); //print newline after every row
  	}
}

int smallest_number(int a[][MAX], int size)
{ //find smallest number in the array
	int min=10; //assign min to high value 
	for(int i=0; i<size; i++) //iterate rows
	{
		for(int j=0; j<size; j++) //iterate columns
		{
			if(a[i][j]<min) //if element is less than min
			{ 
				min=a[i][j]; //assign new min
			}
		}
	}
	return min;
}
