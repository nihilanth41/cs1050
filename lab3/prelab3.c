#include <stdio.h>


int main(void) {
static int x=0;
printf("\n Enter a number: ");
while(x<=0) {
scanf("%d", &x);
if(x<=0) { printf("Invalid number, enter a number greater than zero\n"); } }
printf("The number entered is: %d\n", x);
printf("Sentinel Loop: \n");
static int y=0;
while(y!=-1) {
printf("Enter a number: ");
scanf("%d", &y);
printf("Number entered is: %d", y); }

return 0; }

