#include<iostream>
using namespace std;

double SUM_OF_NUMBERS(double a, double b)
{
    return a + b;
}

double MULTIPLIE_OF_NUMS(double a, double b)
{
    return a * b;
}

double SUBTRACTION_OF_NUMS(double a, double b)
{
    return a - b;
}

double TAGHSIM_OF_NUMS(double a, double b)
{
    return a / b;
}

double OPERATION_FACTORY(double a, double b, char operation)
{
    double res;

    if (operation == '+')
    {
        res = SUM_OF_NUMBERS(a, b);
    }
    else if (operation == '*')
    {
        res = MULTIPLIE_OF_NUMS(a, b);
    }
    else if (operation == '/')
    {
        res = SUBTRACTION_OF_NUMS(a, b);
    }
    else if (operation == '-')
    {
        res = TAGHSIM_OF_NUMS(a, b);
    }

    return res;
}

int main ()
{
    double number1;
    double number2;
    double res;

    char opertionType;
    bool user_wanna_continue = false;
    char user_input;
    do
    {
        cout<<"dadash number1: ";
        cin>>number1;
        cout<<"dadash number2:";
        cin>>number2;

        cout << "chi mikhay? (+ * / -) enter n for canceling the operation: ";
        cin >> opertionType;
        if (opertionType == '+' || opertionType == '-' || opertionType == '/' || opertionType == '*')
        {
            res = OPERATION_FACTORY(number1, number2, opertionType);
        }
        else
        {
            cout << "chi mikhay (+ * / -).";
            return 0;
        }

        cout << "the result: " << res;

        cout << endl << "edame? (y/n): ";
        cin >> user_input;
        if (user_input=='y' || user_input=='Y')
            user_wanna_continue = true;
        else
        {
            cout << "afarin!";
            user_wanna_continue = false;
        }
    }
    while (user_wanna_continue);


    return 0; 
}