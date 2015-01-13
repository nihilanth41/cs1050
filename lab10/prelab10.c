#include <stdio.h>

//prototypes
int string_length(char *); //returns length of passed str
void copy_string(char *, char *); //takes addr of input string and an empty char array

int main(int argc, char **argv)
{
	char chararray[100];
	if(argc<2)
	{
		printf("Not enough parameters\n");
		return 0;
	}
	char *str1 = *(argv+1);
	char *str2 = *(argv+2);
	printf("\nInput String is ");
	int i=0

	
	return 0;
}

int string_length(char *str)
{	
	int i=0, count=0;
	char c = *str;
	while(c != '\0')
	{	
		count++;
		c = *(str+i); //c gets a char out of the str
		i++; //increment string pos 
	}
	return count; 
}

/*
void copy_string(char *p, *newstr)
{
	int strsize = string_length(straddr);
	int i=0;
	for(i=0; i<strsize+1; i++)
	{
		//copy string into new string
		*(newstr+i)=*(straddr+i);
	}
}
*/

		




		
	
