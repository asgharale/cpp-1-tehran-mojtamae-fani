#include <iostream>
#include "calculator.cpp"

using namespace std;

int main()
{
    double a;
    double b;
    double res;

    char opertionType;
    bool user_wanna_continue = false;
    char user_input;
    do
    {
        cout << "enter numbers" << endl << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;

        cout << "operation? (+ * / -) enter n for canceling the operation: ";
        cin >> opertionType;

        if (opertionType == '+' || opertionType == '-' || opertionType == '/' || opertionType == '*')
        {
            res = OPERATION_FACTORY(a, b, opertionType);
        }
        else if (opertionType == 'n' || opertionType == 'N')
        {
            cout << "Thanks for your time.";
        }
        else
        {
            cout << "please enter valid value! only (+ * / -).";
            return 0;
        }

        cout << "the result: " << res;

        cout << "\nwanna continue? (y/n): ";
        cin >> user_input;
        if (user_input=='y' || user_input=='Y')
            user_wanna_continue = true;
        else
            user_wanna_continue = false;
    }
    while (user_wanna_continue);


    return 0;
}