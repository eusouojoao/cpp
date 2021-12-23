#include <iostream>
#include <iomanip> 
#include <cmath>

class Point {
    private:
        double x;
        double y;
    public:
        Point (void);
        Point (double x, double y);
        Point (const Point& other);
        virtual ~Point();
        virtual void Read (void);
        virtual void Translate (double dx, double dy);
        virtual void Scale (double fx, double fy);
        virtual void Rotate (double angle);
        virtual double DistanceTo (const Point& other) const;
        virtual void Write (void) const;
};

Point::Point():
    x(0), y(0)
{
    std::cout << "Default constructor: ";
    Write();
}

Point::Point(double x, double y):
    x(x), y(y)
{
    std::cout << "Elementary constructor: ";
    Write();
}

Point::Point(const Point& other):
    x(other.x), y(other.y)
{
    std::cout << "Copy constructor: ";
    Write();
}

Point::~Point()
{
    std::cout << "Destructor: ";
    Write();
}

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
    Point p;
    Point q(4, 6);
    q.Scale(2.5, 0.5);
    Point r(q);
    r.Translate(-1, -1);
    r.Write();

    return 0;
}
