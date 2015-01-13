//Zachary Rump
//zrrm74
//lab 7 section H
//lab code: springbreak
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//global array
#define SIZE_MAX 100
int array[SIZE_MAX] = { 0 }; //initialize to 0

//prototypes
int check_input(int);
void initialize_array(int);
int max(int);
int min(int);
float average(int);
void compute_stats(int);
int search(int, int);
void print_array(int);
int count_numbers(int, int);
void sort(int);

int main(void)
{	
	int input_size = 0;
	//read size of array from user
	printf("Enter the size of the input: ");
	do{
		scanf("%d", &input_size);
		if(!check_input(input_size))
		{
			printf("Invalid input enter the size of the input again: ");
		}
	}while(!check_input(input_size)); //keep asking for valid input until it's received
	//initialize array with random numbers
	initialize_array(input_size); 
	//print array and statistics about array
	printf("\nInput array\n");
	print_array(input_size);
	compute_stats(input_size);
	//ask user for a number to search for
	int search_num = 0;
	printf("\nEnter the number you want to search: ");
	scanf("%d", &search_num);
 	int search_index = 0; //variable to hold the result of search()
	search_index = search(input_size, search_num);
	if(search_index < 0)
	{
		printf("\nThe number %d is not present in the array\n", search_num);
	}
	else 
	{
		
		printf("\nThe number %d is present at index %d\n", search_num, search_index);
	}
	//count_numbers
	int num_count = 0; //variable to hold the result of count_numbers()
	num_count = count_numbers(input_size, search_num);
	if(num_count < 0)
	{
		//number is not present
		printf("The number %d is not present in the array\n", search_num);
	}
	else
	{
		printf("The number %d is present %d times in the array\n", search_num, num_count);
	}
	//bonus part
	printf("\nBonus Part\n");
	//print array before sorting
	printf("Array before sorting\n");
	print_array(input_size);
	//sort array
	sort(input_size);
	//print sorted array
	printf("Array after sorting\n");
	print_array(input_size);
	printf("\n");
	return 0;
}

int check_input(int input)
{
	if(input<=0||input>SIZE_MAX)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void initialize_array(int size)
{
	
	srand(time(NULL)); //seed rng
	for(int i=0; i<size; i++)
	{
		array[i] = (rand()%10); //fill array w/ random numbers from 0-9 
	}
}

int max(int size)
{
	int max=0;
	for(int i=0; i<size; i++)
	{
		if(array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

int min(int size)
{
	int min=100; //initialize to large value;
	for(int i=0; i<size; i++)
	{
		if(array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

float average(int size)
{
	float avg = 0;
	for(int i=0; i<size; i++)
	{
		avg += array[i]; //add all the values of each element
	}
	avg /= size; //average the whole array
	return avg;
}

void compute_stats(int size)
{
	printf("\nLargest number is %d\n", max(size));
	printf("Smallest number is %d\n", min(size));
	printf("Average of numbers is %.3f\n", average(size));
}

int search(int size, int num)
{
	//if num is present in array return the index
	for(int i=0; i<size; i++)
	{
		if(array[i] == num)
		{
			return i;
		}
	}
	//only gets here if number is not present 
	return -1;
	
}

void print_array(int size)
{
	for(int i=0; i<size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int count_numbers(int size, int num)
{
	int count = 0;
	//return number of times num is present in the array
	for(int i=0; i<size; i++)
	{
		if(array[i] == num)
		{
			count++;
		}
	}
	if(count == 0)
	{//if num is not present return -1
		return -1;
	}
	else 
	{
		return count;
	}
}

void sort(int size)
{	
	int hold = 0; //variable to hold values temporarily while sorting
	for(int pass=1; pass<size; pass++)
	{
		for(int i=0; i<(size-1); i++)
		{
			if(array[i] > array[i+1])
			{
				hold = array[i]; //hold the larger value
				array[i] = array[i+1]; //swap smaller value with smaller index
				array[i+1] = hold; //swap larger value with larger index
			}
		}
	}
}



		
