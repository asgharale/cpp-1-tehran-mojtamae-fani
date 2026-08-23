#include <iostream>
#include "calculator.cpp"

using namespace std;

int main()
{
    unsigned double a;
    unsigned double b;

    double res;

    char opertionType;

    cout << "enter numbers" << endl << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    cout << "operation? (+ * / -) enter n for canceling the operation: ";
    cin >> opertionType;

    if (opertionType == '+')
    {
        res = SUM_OF_NUMBERS(a, b);
    }
    else if (opertionType == '*')
    {
        res = MULTIPLIE_OF_NUMS(a, b);
    }
    else if (opertionType == '/')
    {
        res = SUBTRACTION_OF_NUMS(a, b);
    }
    else if (opertionType == '-')
    {
        res = TAGHSIM_OF_NUMS(a, b);
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
    return 0;
}