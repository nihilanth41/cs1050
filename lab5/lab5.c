//zrrm74
//3/5/14
//Lab section H
#include <stdio.h>
#include <stdlib.h> //for abs()
#include <math.h>

/* prototypes */
int check_number(float);
int check_exponent(int);
float compute_power(float x, int n);
int GCD(int, int);

int main(void) 
{
float f; 
int n;

printf("Enter a float: ");
scanf("%f", &f);
// Read a float from the user, evaluate validity using check_number() 
if(!check_number(f)) 
{
	do {
	    printf("Enter a float between 0 and 100: ");
	    scanf("%f", &f);
	   }while(!check_number(f));
}
printf("Enter the exponent: ");
scanf("%d", &n);
// Check validity of exponent 
if(!check_exponent(n)) 
{ 
do 
	{
	printf("Enter an exponent between -5 and 5: ");
	scanf("%d", &n);
        }
while(!check_exponent(n));
}
// Compute the value using user-defined power function 
float result1 = compute_power(f, n);
float result2 = pow(f, n);
printf("pow(%0.3f,%d)= %0.6f using compute_power function\n", f, n, result1); 
printf("pow(%0.3f,%d)= %0.6f using builtin pow function\n", f, n, result2);
//printf("Bonus Part\n");
//variables to hold GCD numbers
//int n1,n2,gcd;
//printf("Enter the first number: ");
//scanf("%d", &n1);
//printf("Enter the second number: ");
//scanf("%d", n2);
//gcd = GCD(n1, n2);
//printf("GCD of %d and %d is: %d", n1, n2, gcd);
return 0; 
}

// User-defined pow() function 
float compute_power(float x, int n) 
{
float ret = x;
//if exponent is 0 return 1
if(n==0) { ret = 1; }
else 
{
float exp = abs(n); //take absolute value of exponent
ret = x;
int y;
for(y=1; y<exp; y++) { ret *= x; }
if(n<0) { ret = (1/ret); } //check for negative exponent
} 
return ret;
} 

//***NOT WORKING
int GCD(int m, int n) {
//make sure m is larger than n, otherwise swap their positions
int gcd, num, den, rem;
if(m>n) { num = m; den = n; }
else if(m<n) { num = n; den = m; }
while(1){
rem = (num % den);
if(rem != 0) { num = den; den = rem; }
else if(rem == 0) { gcd = num; break; } }
return gcd;
}

// Check to make sure base is between 0 and 100 
//returns 1 if true 0 if false
int check_number(float x) 
{
 if(x>=0&&x<=100) { return 1; }
 else { return 0; }
}

// Check to make sure exponent is between -5 and 5 */
//returns 1 if true 0 if false 
int check_exponent(int n) 
{ 
 if(n>=(-5)&&n<=5) { return 1; }
 else { return 0; }
} 
