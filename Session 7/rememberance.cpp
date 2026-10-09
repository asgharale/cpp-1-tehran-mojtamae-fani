#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> names_vec;
    vector<int> ages_vec;

    char input='0';

    while(true)
    {
        string name;
        int age;

        cout << "enter your age pls: ";
        cin >> age;

        cout << "enter your name pls: ";
        cin.ignore();
        getline(cin, name);

        names_vec.push_back(name);
        ages_vec.push_back(age);

        cout << "do you wanna continue? (n for No): ";
        cin >> input;
        if (input == 'n' || input == 'N')
            break;
    }


    for (int i=0; i < names_vec.size(); i++)
    {
        cout << "user" << i << " name: " << names_vec[i] << "   age: " << ages_vec[i] << endl;
    }





    int count;
    cout << "how many users you wanna enter: ";
    cin >> count;

    int ages[count];
    string names[count];

    for (int i=0; i < count; i++)
    {
        int age;
        cout << "enter your age pls: ";
        cin >> age;

        cout << "enter your name pls: ";
        string name;
        cin.ignore();
        getline(cin, name);

        ages[i] = age;
        names[i] = name;
    }

    cout << endl << endl;

    for (int i=0; i<count; i++)
    {
        cout << "user" << i << " name: " << names[i] << "   age: " << ages[i] << endl;
    }
}