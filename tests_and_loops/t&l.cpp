#include <iostream>
using namespace std;

bool accept ( void )
{
    cout << "Do you want to proceed (y or n)?\n";
    
    char answear = 0;
    cin >> answear;

    if (answear == 'y') return true;
    return false;

}

bool accept2 ( void )
{
    cout << "Do you want to proceed (y or n?\n";

    char answear = 0;
    cin >> answear;

    switch (answear) {
    case 'y':
        return true;
    case 'n':
        return false;
    default:
        cout << "I'll take that for a no.\n";
        return false;
    }
}

bool accept3 ( void )
{
    int tries = 1;
    while ( tries < 4 )
    {
        cout << "Do you want to proceed (y or n)?\n";

        char answear = 0;
        cin >> answear;

        switch (answear) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                cout << "Sorry, I don't understand that.\n";
                ++tries;
        }
    }
    cout << "I'll take that for a no.\n";
    return false;
}

int main ( void )
{
    cout << "Accept #1\n\n";
    accept();
    cout << "Accept #2\n\n";
    accept2();
    cout << "Accept #3\n\n";
    accept3();

    return 0;
}
