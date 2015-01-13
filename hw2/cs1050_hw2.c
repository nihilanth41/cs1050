//Zachary Rump
//zrrm74
//Lab section H 
//HW-2
//USE -std=c99 when compiling
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//prototypes
int check_input(int);
void initialize_array(int[], int);
void print_array(int[], int);
void display_menu(void);
int check_option(int);
int common_numbers(int[], int[], int);
int count_numbers(int[], int, int);
int mode(int [], int);
void print_histogram(int[], int[], int);

int main(void) 
{
	int array1[100] = { 0 }, array2[100] = { 0 }; //local arrays
	int array_size=0;
	printf("Enter the size of the input: ");
	do
	{
		scanf("%d", &array_size);
		if(!check_input(array_size)) //check if size is between 0 & 100
		{
			printf("Invalid size enter the size of the input again: ");
		}
	}while(!check_input(array_size));
	int sel=0; //selection variable
	while(1) //main loop 
	{
		srand(time(NULL)); //seed rng
		//fill array1 and array2 with random numbers from index 0 to array_size
		initialize_array(array1, array_size);
		initialize_array(array2, array_size);
		display_menu(); //display options menu
		do
		{
			scanf("%d", &sel);
			if(!check_option(sel))
			{
				printf("Invalid option enter the option again: ");
			}	
		}while(!check_option(sel));
		if(sel == 4) //if selection was 4 then break out of the while loop and exit
		{
			break;
		}
		else if(sel>=1&&sel<=3) //if selection was 1-3 then print the arrays and do a switch/case
		{
			printf("\nInput arrays\n");
			print_array(array1, array_size);
			print_array(array2, array_size);
			switch(sel)
			{
				case 1: 
					{ //Common numbers
						printf("\nThere are %d common numbers between the two arrays\n", common_numbers(array1, array2, array_size)); 
						break;
					}
				case 2: 
					{ //Mode
						printf("\nThe mode for the first array is number %d\n", mode(array1, array_size));
					  	printf("\nThe mode for the second array is number %d\n", mode(array2, array_size));
						break;
					}
				case 3: 
					{ //Histogram
						printf("\nPrinting Histogram\n\n");
						print_histogram(array1, array2, array_size);
						break;
					}

			}			

		}	
	}
	return 0;
}

//check to see if number is between 0 and 100
//return 1 if true, 0 if false
int check_input(int x) 
{
	if(x>=0||x<=100)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void initialize_array(int a[], int size)
{
	for(int i=0; i<size; i++) 
	{
	//assign a random number between 0-9 to each element in the array
		a[i]=(rand()%10);
	}
}

void print_array(int a[], int size)
{
	for(int i=0; i<size; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");
}

void display_menu(void)
{
	printf("\nArray operations\nYour options are:\n\n(1) Common Numbers\n(2) Mode\n(3) Histogram\n(4) Exit\n\nEnter the operation you want to perform: ");
}

int check_option(int opt)
{
	//check if number is between 1-4 return 1 if true 0 if false
	if(opt>=1&&opt<=4)
	{
		return 1; 
	}
	else
	{
		return 0;
	}
}

int common_numbers(int a[], int b[], int size)
{
	int common_num=0;
	//count how many common numbers there are in the two arrays
	for(int i=0; i<size; i++)
	{
		common_num += count_numbers(b, size, a[i]);
	}
	return common_num;
}

int count_numbers(int a[], int size, int x)
{
	//take an integer array, it's size, and an int x and find out how many times x is present in the array
	int count=0;
	for(int i=0; i<size; i++)
	{
		if(a[i] == x)
		{
			count++;
		}
	}
	return count;
}


int mode(int a[], int size) 
{	int mode=0, freq_mode=0;
	int freq[10] = { 0 }; //array to store count of each number 0-9
	for(int i=0; i<10; i++) //iterate 0 through 9
	{
		freq[i] = count_numbers(a, size, i); //assign the count of each number i to freq[i]
		//printf("Freq[%d] = %d\n", i, freq[i]); //debug output
		if(freq[i] > freq_mode)
		{
			freq_mode = freq[i]; //store the the number of times the mode appears in freq_mode and use that to find new mode
			mode = i;
		}
	}
	return mode; //if there are multiple modes return the smallest number
}

void print_histogram(int a[], int b[], int size)
{	//get count of all the numbers stored in the two arrays
	int count[11] = { 0 }; //array to store count
	for(int i=0; i<10; i++) //for each possible number
	{ //count the number of times that number appears in a[] and b[] and increment count[i] that many times
		count[i] = (count_numbers(a, size, i) + count_numbers(b, size, i)); 
		printf("%d:",i); //print the number
		for(int j=0; j<count[i]; j++)
		{
			printf("%c",'*'); //print an asterisk for the number of times that number was counted in the two arrays
		}
		printf("\n");
	}
}
