#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ofstream out("users.txt", ios::app);

    char input = '0';

    while (true)
    {
        int id;
        int age;
        string name;
        string last_name;

        cout << "enter user id: ";
        cin >> id;

        cout << "enter ru age pls: ";
        cin >> age;

        cout << "enter your name: ";
        cin.ignore();
        getline(cin, name);

        cout << "enter ur last name: ";
        cin.ignore();
        getline(cin, last_name);

        out << id << "," << name << "," << last_name << "," << age << "\n";

        cout << "do you wanna continue? (n for No): ";
        cin >> input;
        if (input == 'n' || input == 'N')
            break;
    }

    ifstream mydata("users.txt");
    if (!mydata)
    {
        cout << "load wasnt successful";
        return 1;
    }


    string line;
    while(getline(mydata, line))
    {
        string id_string;
        string age_string;
        string name;
        string last_name;
        int age;
        int id;

        stringstream ss(line);

        getline(ss, id_string, ',');
        id = stoi(id_string);

        getline(ss, name, ',');

        getline(ss, last_name, ',');

        getline(ss, age_string, ',');
        age = stoi(age_string);

        cout << line << endl << endl;
        cout << "id: " << id << "\t"
        << "name: " << name << "\t"
        << "last name: " << last_name << "\t"
        << "age: " << age << endl;
    }
}
