#include <stdio.h>


int main(void) {
static int x,y,z;
/* Read three numbers, as integers, using scanf() */
printf("\n Enter the first integer: ");
/*  If the number entered is less than or equal to zero (<=0) then display the error message and ask the user to enter the number again. */
scanf("%d", &x); 
if(x<=0) { 
printf("Invalid number, please enter an integer greater than 0: "); 
/* Assume input is valid the second time */
scanf("%d", &x); }

/* Ask for second number */
printf("Enter the second integer: ");
scanf("%d", &y); 
if(y<=0) { 
printf("Invalid number, please enter an integer greater than 0: "); 
scanf("%d", &y); }

/* Ask for third number */
printf("Enter the third integer: ");
scanf("%d", &z);
if(z<=0) { 
printf("Invalid number, please enter an integer greater than 0: "); 
scanf("%d", &z); }

static int sum, product; 
/* Calculate sum */
sum = (x+y+z);
/* Calculate product */
product = (x*y*z); 
/* Print sum and product to stdout */
printf("Sum of %d, %d, and %d is: %d\nProduct of %d, %d, and %d is: %d\n", x, y, z, sum, x, y, z, product);

/* Do same process as above but with floats instead */
static double a,b,c;
printf("\nEnter the first floating point number: ");
scanf("%lf", &a); 
if(a<=0.0) {
printf("Invalid number, please enter a floating point number greater than 0: "); 
scanf("%lf", &a); }

printf("\nEnter the second floating point number: ");
scanf("%lf", &b); 
if(b<=0.0) {
printf("Invalid number, please enter a floating point number greater than 0: "); 
scanf("%lf", &b); }

printf("\nEnter the third floating point number: ");
scanf("%lf", &c);
if(c<=0.0) {
printf("Invalid number, please enter a floating point number greater than 0: "); 
scanf("%lf", &c); }

static double fsum, fproduct;
fsum = (a+b+c);
fproduct = (a*b*c);
printf("Sum of %lf, %lf, and %lf is: %lf \nProduct of %lf, %lf, and %lf is: %lf\n", a, b, c, fsum, a, b, c, fproduct);

/* Return error status and exit */ 
return 0; }


