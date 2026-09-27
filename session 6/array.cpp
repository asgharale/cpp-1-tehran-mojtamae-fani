#include <iostream>

using namespace std;

int main()
{
    int size = 0;

    cout << "enter the size of array: ";
    cin >> size;

    int numbers[size] = {0};

    for (int i=0; i<size; i++)
    {
        int num;
        cout << "enter item " << i << ": ";
        cin >> num;
        numbers[i] = num;
    }

    for (int i=0; i<size; i++)
    {
        cout << "item " << i << " is " << numbers[i] << endl;
    }
}