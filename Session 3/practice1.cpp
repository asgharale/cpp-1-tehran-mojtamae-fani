#include <iostream>

using namespace std;

int main()
{
    int sum = 0;

    int length;

    cout << "how many numbers you have? ";
    cin >> length;

    // int i = 1;

    // while (i <= 5)
    // {
    //     int temp = 0;
    //     cout << "enter the " << i << " number: ";
    //     cin >> temp;
    //     sum += temp; // sum = sum + temp
    //     i = i + 1; // i++;
    // }
    int temp = 0;

    for (int i = 0; i < length; i++)
    {
        cout << "enter the " << i << " number: ";
        cin >> temp;
        sum += temp; // sum = sum + temp
    }

    cout << sum / length;
}