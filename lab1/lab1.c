/* Zach Rump
 * Lab 1 Assignment
 * CS1050 Spring 2014 
 * LAB CODE: aurist 
*/
#include <stdio.h> 

//prototypes
double bonus_question(int u, int a, int t);

int main(void) { 

//variables to hold input
static int x,y,z;

//printf("\n Enter the first number: ");
printf("\n Enter the initial velocity: ");
scanf("%d", &x); 

//printf(" Enter the second number: ");
printf(" Enter the acceleration: ");
scanf("%d", &y);

//printf(" Enter the third number: ");
printf(" Enter the time: ");
scanf("%d", &z);

//int sum = (x+y+z); 
double dist_mi = bonus_question(x, y, z);
//convert to meters:
double dist_meters = (dist_mi*1600); 
printf("\n Total distance travelled by the vehicle in %d seconds is %0.3f miles or %0.3f meters \n", z, dist_mi, dist_meters);
//printf("\n Sum of the three numbers is %d \n", sum);
return 0; }

//Usage: bonus_question(initial velocity(mi/h), acceleration(miles/hr^2), time(seconds))
double bonus_question(int u, int a, int t) {
static double s;
//convert time in seconds to time in hours:
double time_hours = ((((double)t)/60)/60);
s = (((double)u)*(time_hours))+((((double)a)*(time_hours*time_hours))/2);
return s; }


