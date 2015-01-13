//Zachary Rump 
//ZRRM74
//LAB H
//CS1050 HW4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//prototypes
int load_data(char *filename);
void print_data(int size);
int update_data(char *filename, int n);
int highest_grade(int size);
int lowest_grade(int size);
float average_grade(int size);
int write_content(char *fname, int size, int low, int high, float avg);

#define MAX 50
typedef struct
{
	int id;
	int grade;
} data;
data students[MAX];

int main(int argc, char **argv)
{
	if(argc<4) //4 arguments including the program's own call
	{
		printf("\nInsufficient arguments\n");
		return -1; 
	}
	//load student data into global struct array
	int size = load_data(argv[1]); //argv[1] is input txt file
	//check whether or not load_data was able to open the file
	if(size == 0)
	{
		printf("\nUnable to open input file\n");
		return -1; 
	}
	//call print_data to display data on stdout
	printf("\nStudent Record\n");
	print_data(size);
	//record highest, lowest, and average grade;
	int high_grade = highest_grade(size);
	int low_grade = lowest_grade(size);
	float avg_grade = average_grade(size);
	//print highest grade
	printf("The student with the highest grade has the id %d and the grade %d\n", students[high_grade].id, students[high_grade].grade);
	//print lowest grade
	printf("The students with the lowest grade has the id %d and the grade %d\n", students[low_grade].id, students[low_grade].grade);
	//print average grade
	printf("The average grade for the class is %.2f\n", avg_grade);
	//call update_data w/ update.txt
	size = update_data(argv[2], size); //second argument is update.txt file
	if(size == 0) //unable to open update file
	{
		printf("Unable to open update file\n");
		return -1;
	}
	//print updated student record
	printf("\nUpdated Student Record\n");
	print_data(size);
	//record new high, low, and avg grades
	high_grade = highest_grade(size);
	low_grade = lowest_grade(size);
	avg_grade = average_grade(size);
	//print updated info
	printf("\nStudent Statistics after update operation:\n");
	//print highest grade
	printf("The student with the highest grade has the id %d and the grade %d\n", students[high_grade].id, students[high_grade].grade);
	//print lowest grade
	printf("The students with the lowest grade has the id %d and the grade %d\n", students[low_grade].id, students[low_grade].grade);
	//print average grade
	printf("The average grade for the class is %.2f\n", avg_grade);
	//write data to output file
	int ret = write_content(argv[3], size, low_grade, high_grade, avg_grade);
	if(ret == 0)
	{
		printf("Unable to write output file");
		return -1;
	}
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
	printf("ID\tGrade\n");
	int i=0;
	for(i=0; i<size; i++)
	{
		printf("%d\t%d\n", students[i].id, students[i].grade);
	}
}

int update_data(char *filename, int n)
{
	//takes update filename and the number of students 
	//whose information is already stored in the struct array
	//
	FILE *file = fopen(filename, "r"); //open file readonly
	if(file == NULL)
	{
		return 0; //unable to open file
	}
	int size=0;
	fscanf(file, "%d", &size);
	int i=0; 
	//add new student information to existing student information
	for(i=n; i<(n+size); i++)
	{
		//first number is student id
		fscanf(file, "%d", &students[i].id);
		//second number is associated grade
		fscanf(file, "%d", &students[i].grade);
	}
	fclose(file);
	return (n+size); //return new size as the sum of the existing size and the size of the update
}

int highest_grade(int size)
{
	//size is the num of students in the global struct array
	int i=0, high_grade=-1, student_index=-1; //initialize high grade to lower than possible
	for(i=0; i<size; i++)
	{
		if(students[i].grade>high_grade) //if student grade is higher than high_grade
		{
			student_index = i; //record the index of the student/grade
			high_grade = students[i].grade; //record the grade of the student
		}
	}
	return student_index; //returns index in struct array of student w/ highest grade
}

int lowest_grade(int size)
{
	//size is number of students in the struct array
	int i=0, low_grade=101, student_index=-1; //initialize low grade to higher than possible
	for(i=0; i<size; i++)
	{
		if(students[i].grade<low_grade) //if student grade is less than the lowest grade
		{
			student_index = i;
			low_grade = students[i].grade;
		}
	}
	return student_index; //returns index in struct array of student w/ lowest grade
}

float average_grade(int size)
{
	//size is the number of students w/ data entered into the global struct array
	//compute average grade among all students
	int i=0;
	float avg=0;
	for(i=0; i<size; i++) //for each student
	{
		avg += students[i].grade;
	}
	avg /= size; //take average 
	return avg;
}

int write_content(char *fname, int size, int low, int high, float avg)
{
	FILE *file = fopen(fname, "w"); //open an output stream associated with file fname
	if(file==NULL)
	{
		return 0; //failed to open file
	}
	//start writing to file
	//each students id, grade, and a newline
	int i=0;
	for(i=0; i<size; i++)
	{
		fprintf(file, "%d\t%d\n", students[i].id, students[i].grade);
	}
	//write highest grade
	fprintf(file, "\nThe student with the highest grade has the id %d and the grade %d\n", students[high].id, students[high].grade);
	//write lowest grade
	fprintf(file, "The students with the lowest grade has the id %d and the grade %d\n", students[low].id, students[low].grade);
	//write average grade
	fprintf(file, "The average grade for the class is %.2f\n", avg);
	//close file
	fclose(file);
	//return 1 if file was able to open
	return 1;
}



