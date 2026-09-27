#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ages;

    char input = 'a';

    while (input != 'n')
    {
        int age;
        cout << "enter age of user: ";
        cin >> age;

        ages.push_back(age);

        cout << "wanna continue? (y/n): ";
        cin >> input;
    }

    cout << "size of ages is " << ages.size() << endl;

    for (int i=0; i < ages.size(); i++)
    {
        cout << ages[i] << endl;
    }
}