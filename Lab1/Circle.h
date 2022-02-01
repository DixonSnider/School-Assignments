
class Circle{

private: 

   int xcoord;
   int ycoord;
   double radius;

public: 

   // Everything that follows is public and can be "seen" and directly accessed 
   // from outside the class (from client code).
   
   // Default constructor
   // Note that the default constructor has no parameters.
   Circle(); 
   
   // Parameterized constructor
   Circle(int x, int y, double r);
      
   // Getters return information about the Circle. 
   int getX() const;
   int getY() const;
   double getRadius() const;

   // Setters change the values of the class' data members.
   void move(int horiz, int vert);
   void setRadius(double r);
   double computeArea() const;   
   void displayCircle() const;
   bool intersect(Circle C);

}; 

