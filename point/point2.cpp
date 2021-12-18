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
    int n;
    Point p;
    std::cout << "Enter the number of vertices: \n";
    std::cin >> n;
    std::cout << "Starting point coordinates (x,y): \n";
    p.Read();

    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < n; i++)
    {
        p.Write();
        p.Rotate(2 * 3.1415926535 / n);
    }

    return 0;
}
