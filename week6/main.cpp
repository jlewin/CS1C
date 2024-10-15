#include <iostream>
#include <cmath>

using namespace std;

class RegularPolygon {
private:
    int n; //  defines the number of sides in the polygon.
    double side; // that stores the length of the side.
    double x; // that defines the x-coordinate of the center of the polygon.
    double y; // that defines the y-coordinate of the center of the polygon.
public:
    // -arg constructor that creates a regular polygon with n 3, side 1, x 0, and y 0.
    RegularPolygon();

    // A constructor that creates a regular polygon with the specified number of sides and length of side, and centered at (0, 0).
    RegularPolygon(double n, double side);

    // A constructor that creates a regular polygon with the specified number of sides, length of side, and x- and y-coordinates.
    RegularPolygon(double n, double side, double x, double y);

    // The constant accessor functions and mutator functions for all data fields.
    int getN();
    double getSide() const;
    double getX() const;
    double getY() const;

    void setN(int);
    void setSide(double);
    void setX(double);
    void setY(double );

    double getPerimeter() const;
    double getArea() const;
};

// -arg constructor that creates a regular polygon with n 3, side 1, x 0, and y 0.
RegularPolygon::RegularPolygon() { 
    n = 3;
    side = 1;
    x = 0;
    y = 0;
}

// A constructor that creates a regular polygon with the specified number of sides and length of side, and centered at (0, 0).
RegularPolygon::RegularPolygon(double n, double side) { 
    this->n = n;
    this->side = side;
    this->x = 0;
    this->y = 0;
}

// A constructor that creates a regular polygon with the specified number of sides, length of side, and x- and y-coordinates.
RegularPolygon::RegularPolygon(double n, double side, double x, double y) { 
    this->n = n;
    this->side = side;
    this->x = x;
    this->y = y;
}

// The constant accessor functions and mutator functions for all data fields.
int RegularPolygon::getN() { 
    return n;
}

double RegularPolygon::getSide() const { 
    return side;
}

double RegularPolygon::getX() const { 
    return x;
}

double RegularPolygon::getY() const { 
    return y;
}

// The mutator functions for all data fields.
void RegularPolygon::setN(int n) { 
    this->n = n;
}

void RegularPolygon::setSide(double side) { 
    this->side = side;
}

void RegularPolygon::setX(double x) { 
    this->x = x;
}

void RegularPolygon::setY(double y) { 
    this->y = y;
}

double RegularPolygon::getPerimeter() const { 
    return n * side;
}

double RegularPolygon::getArea() const {
    double pi = 3.14159; 
    return (n * side * side) / (4 * tan(pi/n));
}


void printRect(RegularPolygon& rpolygon) {
    cout << rpolygon.getPerimeter() << " " << rpolygon.getArea() << endl;
}

int main() {
    for (RegularPolygon pg : { RegularPolygon(), RegularPolygon(6, 4), RegularPolygon(10, 4, 5.6, 7.8) })
        printRect(pg);

    return 0;
}