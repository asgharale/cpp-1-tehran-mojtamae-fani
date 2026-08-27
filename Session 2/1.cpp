#include <iostream>
#include <string>

using namespace std;

int make_multiplie_2(int num)
{
    return num * 2;
}

int main()
{
    long age;
    char firstLetter = 'A';
    string FirstName = "user first name";
    string lastName = "user last name";

    // چاب در خروجی
    cout << FirstName << endl; // endl => new line

    cout << "enter your age pls: ";
    cin >> age;

    if (FirstName == "asghar")
    {
        cout << "hello, admin";
    }

    if (age <= 18)
    {
        cout << "teenager";
    }
    else if (age > 18 && age <=30)
    {
        cout << "young";
    }
    else
    {
        cout << "old";
    }

    //حلقه  while
    while (age <= 18)
    {
        cout << FirstName << endl;
        age++;
    }

    // for حلقه
    for (int g=0; g <= age; g++)
    {
        cout << g << " is smaller than " << age << endl;
    }

    int num;
    cout << "enter a number to get double it! " << endl << "num: ";
    cin >> num;
    cout << "the double of " << num << " is: " << make_multiplie_2(num);

    return 0;
}