#include <iostream>
#include <ostream>
using namespace std;

enum class Color {red, green, blue};
enum class Traffic_light {green, yellow, red};
enum Color_int {red, green, blue};

Traffic_light& operator++(Traffic_light& t)
// Prefix increment: ++
{
    switch (t) {
        case Traffic_light::green:
            return t = Traffic_light::yellow;
        case Traffic_light::yellow:
            return t = Traffic_light::red;
        case Traffic_light::red:
            return t = Traffic_light::green;
    }
}

int main ( void )
{
    Color col = Color::red;
    Traffic_light light = Traffic_light::red;

/*
    Color x = red;                  // error: which red?
    Color y = Traffic_light::red;   // error: that red is not a Color
    Color z = Color::red;           // OK

    int i = Color::red;             // error: Color::red is not an int
    Color c = 2;                    // error: 2 is not a Color

    int j = Color_int::red;         // OK, Color_int is NOT a enum class (it's a "plain enum")
*/
    cout << "Traffic light: \n";
    for (int i = 0; i < 3; ++i) 
    {
        cout << (int) ++light << " ";
    }
    cout << endl;

    return 0;
}
