#include <iostream>
#include <string>

using namespace std;

int main()
{
    double num1;
    double num2;
    // char operator;
    string operatorString;

    double res;

    cout << "enter num 1 pls: ";
    cin >> num1;

    cout << "enter num 2 pls: ";
    cin >> num2;

    cout << "enter the operator (jame-zarb-menha-taghsim): ";
    cin >> operatorString;

    if (operatorString == "jame")
    {
        res = num1 + num2;
    }
    else if (operatorString == "menha")
    {
        res = num1 - num2;
    }
    else if (operatorString == "zarb")
    {
        res = num1 * num2;
    }
    else if (operatorString == "taghsim")
    {
        res = num1 / num2;
    }
    else
    {
        cout << "you've entered an unvalid value.";
        return 1;
    }

    cout << res;

    return 0;
}