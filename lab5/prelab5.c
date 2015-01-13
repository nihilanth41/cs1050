#include <stdio.h>

/* prototypes */
int check_number(float);
void display_menu(void);
float sum(float, float);
float square(float);
float cube(float);


int main(void) {
//read float from user, check for valid input:
float f1,f2;
do {
printf("Enter a float: "); 
if(!check_number(f1)) { printf("Enter a float between 0 and 100: "); }
scanf("%f", &f1); } while(!check_number(f1));
//read a second float
do {
printf("Enter a float: "); 
if(!check_number(f2)) { printf("Enter a float between 0 and 100: "); }
scanf("%f", &f2); } while(!check_number(f2));
display_menu();



return 0; }

int check_number(float f) {
	if(f>=0&&f<=100) { return 1; }
	else return 0; } 

void display_menu(void) { 
printf("Enter the arithmetic operation you wish to perform:
		(1) Square
		(2) Cube
		(3) Addition ");
int selection;
scanf("%d", &selection); 
switch(selection) {
	case 1: { }
	case 2: { }
	default: { break; }
}

float sum(float x, float y) { return (x+y); }
float square(float f) { return (f*f); }
float cube(float f) { return (f*f*f); }

