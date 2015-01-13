#include <stdio.h>

int main(void) {
while(1) {
printf("\nFiling Status\n(1)Single\n(2)Married\n(3)Head of Household\n(0)Quit Program\nPlease make a selection: ");
static int fstatus;
scanf("%d", &fstatus);
while(fstatus<0 || fstatus>3) {
printf("Invalid choice, please make another selection: ");
scanf("%d", &fstatus); }
if(fstatus == 0) { printf("\nExiting the tax calculator\n\n"); break; }
else {
static int income;
printf("\nEnter the annual income: ");
scanf("%d", &income);
double taxrate;
switch(fstatus) {
	//case 0: { return 0; }
	case 1: { //single 
		  if(income>=0 && income<20000) { taxrate = 0.1; }
		  else if(income>=20000 && income<50000) { taxrate = 0.2; }
		  else if(income>=50000 && income<100000) { taxrate = 0.3; }
		  else if(income>=100000 && income<250000) { taxrate = 0.35; }
		  else if(income>=250000) { taxrate = 0.4; } 
		  break;	
		}
	case 2: { //Married
		  if(income>=0 && income<30000) { taxrate = 0.1; }
		  else if(income>=30000 && income<60000) { taxrate = 0.2; }
		  else if(income>=60000 && income<125000) { taxrate = 0.3; }
		  else if(income>=125000 && income<300000) { taxrate = 0.35; }
		  else if(income>=300000) { taxrate = 0.4; }
		  break;
		}
	case 3: { //Head of Household
		  if(income>=0 && income<50000) { taxrate = 0.1; }
		  else if(income>=50000 && income<100000) { taxrate = 0.2; }
		  else if(income>=100000 && income<250000) { taxrate = 0.3; }
		  else if(income>=250000 && income<500000) { taxrate = 0.35; }
		  else if(income>=500000) { taxrate = 0.4; }
		  break;
		}
	default: { break; } }
int tr = (int)(taxrate*100);
printf("Your tax rate is: %d%%", tr);
double taxes_paid = (income * taxrate);
double net_income = (income - taxes_paid);
printf("\nYou pay $%0.2lf in taxes", taxes_paid);
printf("\nAfter taxes your net income is: $%0.2lf\n", net_income); 

 } } return 0; } 
