#include <iostream>
#include <string>

using namespace std;

int main()
{
    double num1;
    double num2;
    double res;
    char opt;

    cout << "enter num1 pls:  ";
    cin >> num1;
    cout << "enter num 2 pls:  ";
    cin >> num2;
    cout << "enter one of them (+ - * / ): ";
    cin >> opt;

    if (opt=='+')
    {
        res=num1+num2;
    }
    else if (opt=='-')
    {
        res=num1-num2;
    }
    else if (opt=='*')
    {
        res=num1*num2;
    }
    else if (opt=='/')
    {
        res=num1/num2;
    }
    else 
    {
        return 1;
    }
    cout << res << endl;

    cout <<" thanks!:) "<< endl;
}
