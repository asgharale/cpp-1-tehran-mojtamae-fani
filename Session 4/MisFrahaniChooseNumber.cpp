#include <iostream>

using namespace std;

int main()
{
    int my_number = 12;
    int your_number;
    cout << " choose number between 1-100 " << endl;
    
    while(true)
    {
        cout << "your number : ";
        cin >> your_number;
        
        if ( your_number > my_number)
        {
            cout << "choose a lower number" << endl;
        }
        else if (your_number < my_number)
        {
            cout << " choose a higher number" << endl;
        }
        else
        {
            cout << " nice ! your number is correct ! " << endl;
            break;
        };
    };
    return 0;
}