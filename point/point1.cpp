#include <iostream>
#include <cmath>

class Point {
    private:
        double x;
        double y;
    public:
        Point (void);
        Point (double x, double y);
        Point (const Point& other);
        virtual void Read (void);
        virtual void Translate (double dx, double dy);
        virtual void Scale (double fx, double fy);
        virtual void Rotate (double angle);
        virtual double DistanceTo (const Point& other) const;
        virtual void Write (void) const;
};

Point::Point():
    x(0), y(0)
{}

Point::Point(double x, double y):
    x(x), y(y)
{}

Point::Point(const Point& other):
    x(other.x), y(other.y)
{}

void Point::Read(void)
{
    std::cin >> x >> y;
}

double Point::DistanceTo(const Point& other) const
{
    return ( ::sqrt( ::pow(x - other.x, 2) + ::pow(y - other.y, 2)) );
}

void Point::Translate(double dx, double dy)
{
    x += dx;
    y += dy;
}

void Point::Scale(double fx, double fy)
{
    x *= fx;
    y *= fy;
}

void Point::Rotate(double angle)
{
    double x0 = x;
    double y0 = y;
    x = x0 * ::cos(angle) - y0 * ::sin(angle);
    y = x0 * ::sin(angle) + y0 * ::cos(angle);
}

void Point::Write(void) const
{
    std::cout << x << " " << y << "\n";
}

int main ( void )
{
    Point p1;
    Point p2(1.0, 1.0);
    Point p3(p2);
    
    p3.Rotate(1.5707963268);
    p1.Write();
    p2.Write();
    p3.Write();

    double side1 = p1.DistanceTo(p2);
    double side2 = p2.DistanceTo(p3);
    double side3 = p3.DistanceTo(p1);

    double perimeter = side1 + side2 + side3;
    std::cout << perimeter << std::endl;

    Point p4;
    p4.Write();
    p4.Read();
    p4.Write();

    return 0;
}
