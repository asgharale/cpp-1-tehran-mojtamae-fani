#include <iostream>

using namespace std;

int main()
{
    double a;
    double b;

    cout << "enter a & b: ";

    cin >> a;
    cin >> b;

    double _t1 = a * b;
    double _t2 = a * a;

    // boolean (true/false)
    bool if1 = (_t1 == _t2);


    if (if1)
    {
        cout << "is moraba" << endl;
    }
    else
    {
        cout << "not maraba" << endl;
    }

    cout << "end";
}

