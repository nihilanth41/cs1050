//Zachary Rump
//ZRRM74
//4/23/14
//CS1050 LAB SECTION H
//LAB 10
//LAB CODE: Nepotal

#include <stdio.h>
#define MAX 100

//prototypes
int string_length(char *); //returns length of passed str
void copy_string(char *, char *); //takes addr of input string and an empty char array
void merge_string(char *, char *, char *);
int prefix(char *, char *);
int substring(char *, char *);

int main(int argc, char **argv)
{
	char strcopy[100] = { 0 };
	char strmerged[100] = { 0 };
	if(argc!=3) //assume exactly 2 input strings
	{
		printf("Not enough parameters\n");
		return 0;
	}
	char *str1 = *(argv+1);
	char *str2 = *(argv+2);
	//print string
	printf("\nInput String is %s %s\n", str1, str2);
	//print length of string
	printf("Length of the first string is: %d\n", string_length(str1));
	printf("Length of the second string is: %d\n", string_length(str2));
	//copy string and print copied string
	copy_string(str1, strcopy);
	printf("Copied string is %s\n", strcopy);
	merge_string(str1, str2, strmerged);
	printf("Merged string is %s\n", strmerged);
	int isPrefix=0;
	isPrefix=prefix(str1, str2);
	if(isPrefix)
	{
		printf("%s is a prefix of the string %s\n", str2, str1);
	}
	else
	{
		printf("%s is not a prefix of the string %s\n", str2, str1);
	}
	//Bonus Part
	printf("\nBonus Part\n");
	int isSubstring=0;
	isSubstring = substring(str1, str2);
	if(isSubstring)
	{
		printf("%s is a substring of %s\n", str2, str1);
	}
	else
	{
		printf("%s is not a substring of %s\n", str2, str1);
	}
	return 0;
}


int string_length(char *str)
{	
	int i=0, count=0;
	char c = *str;
	while(1)
	{
		c = *(str+i); //c gets a char out of the str
		if(c != '\0') //check for null terminator
		{
			count++;
			i++; //increment string pos 
		}
		else
		{
			break; //don't include nul terminator in count
		}

	}
	return count; 
}


void copy_string(char *strptr, char *newstr)
{
	int strsize = string_length(strptr);
	int i=0;
	for(i=0; i<strsize; i++)
	{
		//copy string into new string
		*(newstr+i)=*(strptr+i);
	}
	//add null terminator
	*(newstr+(i+1))='\0';
}


void merge_string(char *str1, char *str2, char *newstr)
{
	int str1_length=0, str2_length=0, total_length=0;
	str1_length = string_length(str1);
	str2_length = string_length(str2);
	total_length = str1_length+str2_length;
	int i=0;
	for(i=0; i<total_length; i++)
	{
		if(i<str1_length)
		{
			//printf("copying char %c from str1 into newstring[%d]\n", *(str1+i), i);
			*(newstr+i) = *(str1+i);
		}
		else if(i>=str1_length)
		{
			//printf("copying char %c from str2 into newstring[%d]\n", *(str2+(i-str1_length)), i);
			*(newstr+i) = *(str2+(i-str1_length));
		}
	}
	//printf("adding null terminator at newstring[%d]\n", (i));
	*(newstr+(i)) = '\0'; //add null terminator

}


int prefix(char *str1, char *str2)
{
	//get length of prefix (str2)
	int prefix_length = string_length(str2);
	int i=0, isPrefix=1; //initialize to 1 because we are ANDing 
	for(i=0; i<prefix_length; i++) //for each element corresponding to the size of the prefix
	{
		isPrefix &= (*(str1+i)==*(str2+i)); //AND the value of the comparison w/ the value isPrefix - a single non-match will clear the variable
	}
	return isPrefix;
}

int substring(char *str1, char *str2)
{
	//get length of substring (str2) and main string
	int str2_length = string_length(str2); 
	int str1_length = string_length(str1);
	int isSubstring = 0; //initialize to 1 because we are ANDing 
	int i=0;
	for(i=0; i<=(str1_length-str2_length); i++) //for each element in the array
	{
		int j=0, isMatch=1;
		for(j=0; j<str2_length; j++) //for each element in the substring
		{
			if(*(str2+j) == *(str1+i)) //if the first element of the str and substring match
			{
				//check for a match for each successive element up to the size of the substring
				int z=0;
				for(z=1; z<str2_length; z++) //start at 1 because we already did first compare
				{
					isMatch &= (*(str2+j+z)==*(str1+i+z)); //AND comparison w/ isMatch
				}
				if(isMatch)
				{
					return 1; 
				}
			}
		}
	}
	return 0; //will only get here if isMatch never returns
}





			



		
		




		
	
