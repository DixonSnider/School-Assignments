
#include <iostream>	// As we need to print data
#include "Circle.h"	// The header file for the class - we need this!

using namespace std;	// What does the namespace std contains?
const double PI  =3.141592653589793238463;

// Now, read each of the method implementations. 
// The Rectangle:: preceding each method indicates that the method belongs to the Rectangle class. 
// If it is omitted, the compiler will attempt to create a separate function 
// (not belonging to the class). This is not what we want.

// Default constructor
// Note: This part of the constructor's header " : width(1), height(1)"
// is called the "initialiation list". 
// Check what our textbooks and online resources have to say about it!
Circle::Circle() : xcoord(0), ycoord(0), radius(10) {

}//Circle())

// Parameterized constructor
Circle::Circle(int x, int y, double r)
{

   if (radius > 0)
   	  radius = r;
   else
   	  radius = 10;
   
   
}//circle(int,int,double)

// Getters return information about the Circle. 
int Circle::getX() const
{
   return xcoord;
   
}

int Circle::getY() const
{
   return ycoord;
   
}

double Circle::getRadius() const
{
	return radius;
}

// Setters change the values of the class' data members.
void Circle::move(int horiz, int vert)
{
	xcoord = horiz;
	ycoord = vert;
	  
}

void Circle::setRadius(double r)
{
   if (r > 0)
      radius = r;
   else
      radius = 10;
	  
}
   
double Circle::computeArea() const   
{
   return  PI * radius * radius;
   
}

void Circle::displayCircle() const
{
   cout << endl << "radius " << getRadius() << " at point x = " 
   << getX() << ", y = " << getY() <<endl;
   
}//Circle

bool intersect(Circle C) 
{
	int distSq = (0 - C.getX()) * (0 - C.getX()) +
                 (0 - C.getY()) * (0 - C.getY());
    double radSumSq = (10 + C.getRadius()) * (10+ C.getRadius());

	if (distSq < radSumSq)
        return true;
    return 0;
}

// End of the implementation file