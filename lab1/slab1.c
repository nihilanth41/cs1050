#include <stdio.h>

int main(void) {
int x, y, z;

/*scanf takes type specifier and address-of (&) as argument(s) */
printf("\n Enter the first number: ");
scanf("%d", &x);

printf("\n Enter the second number: ");
scanf("%d", &y);

printf("\n Enter the third number: ");
scanf("%d", &z);

if(x>y) {
	if(x>z) {printf("\n %d is the largest number", x); } 
	}
else { 
	if(y>z) { printf("\n %d is the largest number", y); }
else { printf("\n  %d is the largest number", z); } }
printf("\n");
return 0; }
