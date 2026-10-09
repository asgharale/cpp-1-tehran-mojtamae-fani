#include <iostream>


using namespace std;

double factorial(double n)
{
    if (n <= 1)
        return 1;
    return (n * factorial(n - 1));
}


int main()
{
    double input = 0;

    cout << "enter the number: ";
    cin >> input;

    cout << "res: ";
    double result = factorial(input);

    cout << result;
}
