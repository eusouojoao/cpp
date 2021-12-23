#include "Vector.h"
#include <stdexcept>
using namespace std;

Vector::Vector( int s )
    :elem{new double[s]}, sz{s}
{
}

double& Vector::operator[]( int i )
{
    if (i < 0 || size() <= i) throw out_of_range {"Vector::operator[]"};
    return elem[i];
}

int Vector::size()
{
    return sz;
}

void f (Vector& v)
{
    // ...
    try 
    { // exceptions are handled by the handler defined bellow
        v[v.size()] = 7;
    }
    catch (out_of_range) 
    { // oops: out_of_range error
        // ... handle range error
    }
    // ...
}
