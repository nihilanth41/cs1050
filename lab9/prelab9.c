#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//prototypes
void initialize_array(int *, int);
void print_array(int *, int);
int check_size(int);
int count_even(int *, int);

#define MAX 100 
int main(void)
{	int a[MAX] = { 0 };
	int *ptr=0; //integer pointer
	ptr=a; //point p at a
	//ask user for array size
	int input_size=0;
	printf("Enter the size of the input: ");
	do{
		scanf("%d", &input_size);
		if(!check_size(input_size))
		{
			printf("Invalid input enter the size of the array again: ");
		}
	}while(!check_size(input_size)); //error check using check_size()
	//initialize array with given size
	initialize_array(ptr, input_size);
	//print array
	printf("\nInput Array\n");
	print_array(ptr, input_size);
	//print even numbers
	int even_numbers = count_even(ptr, input_size);
	if(even_numbers==0)
	{
		printf("There are no even numbers present in the array");
	}
	else
	{
		printf("\nThere are %d even numbers present in the array\n", count_even(ptr, input_size));
	}
	return 0;
}

void initialize_array(int *p, int size)
{ //takes int pointer and int size and stores random numbers using the pointer. 
	srand(time(NULL)); //seed rng
	int i=0;
	for(i=0; i<size; i++)
	{
		*(p+i)=rand()%10; //store random number at location pointed to by *p
	}
	//other option *p = rand()%10; p++;
}

void print_array(int *p, int size)
{ //takes int pointer and input size and prints out random numbers using the pointer
	int i=0;
  	for(i=0; i<size; i++)
	{
		printf("%d ", *(p+i)); //print each element in array using ptr notation
	}
	printf("\n");
}

int check_size(int size)
{ //takes int number and checks if the number is between 0-100
	if(size>0&&size<=100)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int count_even(int *p, int size)
{ //takes int pionter and size and counts the number of even numbers present using the pointer
	int even_count=0;
	int i=0;
	for(i=0; i<size; i++)
	{
		if((*(p+i)%2)==0) //if the remainder of division by 2 is 0 then the number is even
		{
			even_count++;
		}
	}
	return even_count;
}






