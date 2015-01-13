//Zach Rump
//zrrm74
//Lab H
//HW3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

//prototypes
void display_menu(void);
int check_option(int);
int check_size(int);
void initialize_2Darray(int[][MAX], int);
void print_2Darray(int[][MAX], int);
void initialize_1Darray(int[], int);
void print_1Darray(int[], int);
int search_max(int[][MAX], int, int, int);
int count_diagonal(int[][MAX], int, int);
int closest_row(int[][MAX], int[], int);
void sort_1Darray(int[], int);
void sort_2Darray(int[][MAX], int);



int main(void)
{
	//local arrays
	int a1d[MAX] = { 0 };
	int a2d[MAX][MAX] = {{0}};
	int input_size=0;
	//ask for and check input size
	printf("Enter the size: ");
	do{
		scanf("%d", &input_size);
		if(!check_size(input_size))
		{
			printf("Invalid input enter the size of the array again: ");
		}
	}while(!check_size(input_size));
	int menu_option=0;
	do{     //menu loop
		//seed rng
		srand(time(NULL));
		//init arrays
		initialize_1Darray(a1d, input_size); //initialize 1d array
		initialize_2Darray(a2d, input_size); //initialize 2d array
		//display menu
		display_menu();
		//check menu selection
		do{
			scanf("%d", &menu_option);
			if(!check_option(menu_option))
			{
				printf("Invalid option enter the option again: ");
			}
		}while(!check_option(menu_option));
		switch(menu_option)
		{
			case 1: {	//search max
					printf("\n2D array\n");
					print_2Darray(a2d, input_size);
					int row=0;
					int col=0;
					printf("\nEnter the row: ");  
					do{	//bounds checking
						scanf("%d", &row);
						if(row<0||row>(input_size-1))
						{
							printf("Invalid row, enter a row between 0 and %d: ", (input_size-1));
						}
					}while(row<0||row>(input_size-1));
					printf("Enter the column: ");
					do{
						scanf("%d", &col);
						if(col<0||col>(input_size-1))
						{
							printf("Invalid column, enter a column between 0 and %d: ", (input_size-1));
						}
					}while(col<0||col>(input_size-1));
					printf("\nThe largest number present in the row %d and column %d is %d\n", row, col, search_max(a2d, row, col, input_size));
					break;
				}
			case 2: {	//Count Diagonal
					printf("\n2D arrays\n");
					print_2Darray(a2d, input_size);
					int i=0;
					for(i=0; i<input_size; i++)
					{
						printf("\nDiagonal element %d is present %d more times in the row %d and column %d", a2d[i][i], count_diagonal(a2d, i, input_size), i, i); 
					}
					printf("\n");
					break;
				}
			case 3: {	//Closest row 
					printf("\n2D arrays\n");	
					print_2Darray(a2d, input_size);
					printf("\n1D array\n");
					print_1Darray(a1d, input_size);
					printf("\nRow %d in the 2D array is closest to the 1D array\n", closest_row(a2d, a1d, input_size));
					break;
				}
			case 4: {	//1d sort
					printf("\n1D array before sorting\n");
					print_1Darray(a1d, input_size);
					sort_1Darray(a1d, input_size);
					printf("\n1D array after sorting\n");
					print_1Darray(a1d, input_size);
					break; 
				}
			case 5: {	//2d sort
					printf("\n2D array before sorting\n");
					print_2Darray(a2d, input_size);
					sort_2Darray(a2d, input_size);
					printf("\n2D array after sorting\n");
					print_2Darray(a2d, input_size);
					break;
				}
			case 6: {	//exit loop
					break;
				}
		
		}
	}while(menu_option != 6);
	return 0;
}

void display_menu(void)
{ //display menu options
	printf("\nArray operations, your operations are:\n\n1: Search Max\n2: Count Diagonal Number\n3: Closest Row\n4: Sort 1D Array\n5: Sort 2D Array\n6: Exit\n");
	printf("Enter the operation you would like to perform: ");
}

int check_option(int opt)
{ //check if opt is between 1-6 returns 1 if true 0 if false
	if(opt>=1&&opt<=6)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int check_size(int size)
{ //check if size is between 0 and 100, return 1 if true 0 if false
	if(size>0&&size<=100)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void initialize_2Darray(int a[][MAX], int size)
{ //takes 2D int array and input size. Initialize square array w/ random numbers 0-9
	//seed rng
	//srand(time(NULL));
	int i=0;
	for(i=0; i<size; i++)
	{
		int j=0;
		for(j=0; j<size; j++)
		{
			a[i][j] = rand()%10; //assign random numbers 0-9
		}
	}
}

void print_2Darray(int a[][MAX], int size)
{	//printf("2D Array\n");
	int i=0;
	for(i=0; i<size; i++) //increment rows
	{
		int j=0;
		for(j=0; j<size; j++) //increment columns
		{
			printf("%d ", a[i][j]);
		}
		printf("\n"); //newline after each row
	}
}

void initialize_1Darray(int a[], int size)
{ //takes int array and initializes w/ random numbers 0-9
	//seed rng
	//srand(time(NULL));
	int i=0;
	for(i=0; i<size; i++)
	{
		a[i] = rand()%10;
	}
}

void print_1Darray(int a[], int size)
{ //takes int array and size and prints out array content
	//printf("1D Array\n");
	int i=0;
	for(i=0; i<size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int search_max(int a[][MAX], int r, int c, int size)
{ //takes 2d int array, row, column, and size and returns largest number
  //present in both the row r and col c
	int max=0; 
  	int i=0;
  	//check row first
  	for(i=0; i<size; i++)
	{
		int j=0;
		for(j=0; j<size; j++)
		{
			if(a[r][i] == a[j][c]); //if the value in the row is equal to the value in the column
			{
				if(a[r][i] > max)
				{
					max = a[r][i];
				}
			}
		}
	}
	return max;
}

int count_diagonal(int a[][MAX], int i, int size)
{ //takes 2d int array, the index, and the size
  //returns the count of the element in the i'th row and i'th column
	int diagonal_num = a[i][i];
	int diagonal_count = 0;
  	int j=0;
  	for(j=0; j<size; j++)
  	{
		//check row first
		if(a[i][j] == diagonal_num)
		{	
			if(!(i==j)) //exclude diagonal
			{
				diagonal_count++;
			}
		}
		//check column
		if(a[j][i] == diagonal_num)
		{
			if(!(i==j)) //exclude the diagonal
			{
				diagonal_count++;
			}
		}
	}
	return (diagonal_count); //subtract 1 so it does not include the original element in the count
}

int closest_row(int a[][MAX], int b[], int size)
{ //takes 2d array, 1d, and the size of the arrays
  //finds a row in the 2d array which is closest to the 1d array
  //returns index of closest row
  //hint use abs() to compute the absolute difference between each
	int closest_val = 100; //initialize to high value
	int closest_row = 0;
	int i=0;
	for(i=0; i<size; i++) //traverse rows
	{
		int t=0; //temp var to hold abs values
		int j=0;
		for(j=0; j<size; j++) //traverse columns
		{
			t += abs(a[i][j]-b[j]); //abs value of the difference between each column
		}
		if(t<closest_val)
		{
			closest_val = t; //record the abs value of the difference of rows
			closest_row = i; //record the row index
		}
	}
	return closest_row;
}

void sort_1Darray(int a[], int size)
{ //this function sorts the 1D integer array in the increasing order
	int hold=0;
  	int pass=0;
  	for(pass=1; pass<size; pass++)
  	{
		  int i=0;
	  	for(i=0; i<(size-1); i++)
	  	{
		 	 if(a[i]>a[i+1]) //larger value apppears first
		  	{
			  hold = a[i]; //hold larger value
			  a[i] = a[i+1]; //move smaller value forward
			  a[i+1] = hold; //swap larger value in it's place
		  	}
	  	}
  	}
}

void sort_2Darray(int a[][MAX], int size)
{ //sort each row of the 2d integer array in increasing order
	int i=0;
	for(i=0; i<size; i++) //increment rows
	{
		sort_1Darray(a[i], size); //pass the 1d array at a[i] 
	}
	//each row is sorted in ascending order
}


  
