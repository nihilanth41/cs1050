//Zach Rump zrrm74
//04/9/14
//lab9 section H
//lab code: underbrace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//prototypes
void initialize_array(int *, int);
void print_array(int *, int);
int check_size(int);
int count_even(int *, int);
float median(int *, int);
int count_duplicate(int *, int);
void sort(int *, int);
float standard_deviation(int *, int); //bonus part

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
		printf("\nThere are no even numbers present in the array\n");
	}
	else
	{
		printf("\nThere are %d even numbers present in the array\n", even_numbers);
	}
	//print duplicate numbers
	int duplicate_numbers = count_duplicate(ptr, input_size);
	if(duplicate_numbers == 0)
	{
		printf("\nThere are no duplicate numbers present in the array\n");
	}
	else
	{
		printf("\nThere are %d duplicate numbers present in the array\n", duplicate_numbers);
	}
	//print median value
	float median_val = median(ptr, input_size);
	//print sorted array (to verify)
	//printf("\nSorted Array\n");
	//print_array(ptr, input_size);
	printf("\nMedian value is %0.2f\n", median_val);
	//bonus part
	printf("\nBonus Part\n");
	//print standard deviation
	float std_dev = standard_deviation(ptr, input_size);
	printf("\nStandard Deviation is %0.3f\n\n", std_dev);
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

float median(int *p, int size)
{ //compute median value for given set 
	float median_val = 0;
	//sort array
	sort(p, size);
	if(size%2==0) //if number of elements is even
	{
		//median is the average of the two middle most elements in the sorted array
		median_val += *(p+(size/2)); //add value of right middle element 
		median_val += *(p+((size/2)-1)); //add value of left middle element
		median_val /= 2; //take average of the two
	}
	else //num elements is odd
	{
		median_val = *(p+(size-1)/2); //assign median to the value of the middle index of the sorted array
	}
	return median_val;
}

int count_duplicate(int *p, int size)
{
	//count the number of duplicate numbers in the set
	int count[10] = { 0 }; //for each #0-9
	int *countptr = 0;
	countptr = count;
	int i = 0;
	for(i=0; i<size; i++) //for each element in the array
	{
		int j=0;
		for(j=0; j<10; j++) //for each number 0-9
		{
			if(j==*(p+i)) //if 0-9 equals the value at *p+i 
			{
				//increment count array
				*(countptr+j) = (*(countptr+j)+1);
			}
		}
	}
	int duplicate_count=0;
	for(i=0; i<10; i++) //for each element in the count array
	{
		if(*(countptr+i)%2==0) //if the number is even divide by 2 and add it to the dupe count
		{
			duplicate_count += (*(countptr+i)/2);
		}
		else //if the number is odd then subtract 1, divide by 2, and add it to the count
		{
			duplicate_count += ((*(countptr+i)-1)/2);
		}
	}
	return duplicate_count;
}

void sort(int *p, int size)
{ //merge sort 
	int hold = 0;
	int pass = 0;
	for(pass=1; pass<size; pass++)
	{
		int i=0;
		for(i=0; i<(size-1); i++)
		{
			if(*(p+i) > *(p+i+1)) //if larger value appears in smaller index then swap
			{
				hold = *(p+i); //hold larger value
				*(p+i) = *(p+i+1); //swap smaller value into smaller index
				*(p+i+1) = hold; //swap larger value with larger index		
			}
		}
	}

}


float standard_deviation(int *p, int size)
{
	//find the mean of the entire array
	float mean = 0;
	int i=0;
	for(i=0; i<size; i++)
	{
		mean += *(p+i); 
	}
	mean /= size; //mean is average
	float std_sum = 0; //numerator 
	for(i=0; i<size; i++) //for each element
	{
		float temp = (*(p+i) - mean); //temp variable to store the current element minus the mean
		std_sum += pow(temp, 2); //square the result and add it to the total
	}
	std_sum /= (size-1); //(n-1)
	float stdd = sqrt(std_sum); //sqrt total
	return stdd; 
}

		



