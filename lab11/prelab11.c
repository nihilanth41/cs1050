#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

//prototypes
int load_data(char *filename);
void print_data(int size);

typedef struct
{
	int id;
	int grade;
} data;

data students[MAX];

int main(int argc, char **argv)
{
	if(argc<2)
	{
		printf("Insufficient arguments\n");
		return -1; 
	}
	int size = load_data(argv[1]);
	//check whether or not load_data was able to open the file
	if(size == 0)
	{
		printf("Unable to open input file\n");
		return -1; 
	}
	//call print_data to display data
	print_data(size);

	return 0;
}

int load_data(char *filename)
{
	FILE *file = fopen(filename, "r");
	if(file==NULL)
	{
		return 0;
	}
	int size=0;
	fscanf(file, "%d", &size); //first line of text file is size of input
	int i=0;
	for(i=0; i<size; i++)
	{
		//first thing on each line is student id #
		fscanf(file, "%d", &students[i].id);
		//second thing is the associated grade 
		fscanf(file, "%d", &students[i].grade);

	}
	fclose(file);
	return size; 
}

void print_data(int size)
{
	printf("\nStudent Record\n");
	printf("ID\tGrade\n");
	int i=0;
	for(i=0; i<size; i++)
	{
		printf("%d\t%d\n", students[i].id, students[i].grade);
	}
}



