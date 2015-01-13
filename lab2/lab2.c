/* Zach Rump
 * Lab 2 Assignment
 * 2/6/14
 * Section: H
 * CODE: Snow Day? */
#include <stdio.h>
#include <math.h>

double get_distance(int x1, int y1, int x2, int y2);

int main(void) {

//variables to hold coordinates
static int x1,x2,x3,y1,y2,y3;

/* Ask for first x coordinate */
printf("\nEnter the x coordinate of the first point: "); 
scanf("%d", &x1);
if(x1<0) {
printf("Invalid coordinate, please enter the coordinate again: ");
scanf("%d", &x1); }
/* Ask for first y coordinate */
printf("\nEnter the y coordinate of the first point: ");
scanf("%d", &y1); 
if(y1<0) {
printf("Invalid coordinate, please enter the coordinate again: ");
scanf("%d", &y1); }

/* Ask for second x coordinate */
printf("\nEnter the x coordinate of the second point: ");
scanf("%d", &x2);
if(x2<0) {
printf("Invalid coordinate, please enter the coordinate again: ");
scanf("%d", &x2); }
/* Ask for second y coordinate */
printf("\nEnter the y coordinate of the second point: ");
scanf("%d", &y2);
if(y2<0) {
printf("Invalid coordinate, please enter the coordinate again: ");
scanf("%d", &y2); }

/* Ask for third x coordinate */
printf("\nEnter the x coordinate of the third point: ");
scanf("%d", &x3);
if(x3<0) {
printf("Invalid coordinate, please enter the coordinate again: ");
scanf("%d", &x3); }
/* Ask for third y coordinate */
printf("\nEnter the y coordinate of the third point: ");
scanf("%d", &y3); 
if(y3<0) {
printf("Invalid coordinate, please enter the coordinate again: ");
scanf("%d", &y3); }

double d12, d13, d23, dmax, dmin, dsum;
d12 = get_distance(x1, y1, x2, y2);
d13 = get_distance(x1, y1, x3, y3);
d23 = get_distance(x2, y2, x3, y3);
dsum = (d12+d13+d23);
/* Find max & min */
dmax = d12;
dmin = d12;
if(d13 > dmax) { dmax = d13; } 
else if(d23 > dmax) { dmax = d23; }
if(d13 < dmin) { dmin = d13; }
else if(d23 < dmin) { dmin = d23; } 
printf("Distance between points 1 and 2 is: %lf \n", d12);
printf("Distance between points 1 and 3 is: %lf \n", d13);
printf("Distance between points 2 and 3 is: %lf \n", d23);
printf("Sum of the distances is: %lf \n", dsum);
printf("\nBonus Part \n");
printf("\nLongest distance is: %lf\n", dmax);
printf("Shortest distance is: %lf\n\n", dmin);
return 0; }


double get_distance(int x1, int y1, int x2, int y2) {
int dx, dy;
dx = (x1-x2);
dy = (y1-y2);
dx *= dx;
dy *= dy;
double distance = sqrt((dx+dy));
return distance; }


