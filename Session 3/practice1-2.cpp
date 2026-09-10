#include <iostream>

using namespace std;

int main()
{
    int len
    int numbers[5] = {0}; // {0,0,0,0,0}
    int sum = 0;
    int length = sizeof(numbers) / sizeof(numbers[0]);



    cout << length << endl;

    for (int i=0; i < 5; i++)
    {
        cout << "enter the " << i << "number: ";
        cin >> numbers[i];
        sum += numbers[i];
    }

    cout << sum / 5;

    return 0;
}