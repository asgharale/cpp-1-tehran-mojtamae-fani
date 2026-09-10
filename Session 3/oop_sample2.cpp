#include <iostream>

using namespace std;

class User
{
    public:
        // inhertence
        // polymorphism
        // encapsolation
        // abtraction

        int age;
        string FirstName;
        string LastName;
        int height;
        float weight;
        string NationalId;
        int Gender;

        // Constructor (سازنده)
        User()
        {
            cout << endl << "an instance just got created" << endl;

            cout << "pls enter first name of the user: ";
            cin >> FirstName;

            cout << "pls enter last name of the user: ";
            cin >> LastName;

            cout << "pls enter gender of user (1=male - 2=female): ";
            cin >> Gender;

            cout << "pls enter national_id of the user: ";
            cin >> NationalId;
        };

        // Distructor (مخرب)
        ~User()
        {
            cout << endl << "Disrtuctor Got Called." << endl;
        }

        string GetFirstName()
        {
            return FirstName;
        }

        virtual string GetTitle()
        {
            return "dear user";
        }
        virtual string GetId()
        {
            return NationalId;
        }
        virtual string GetFullNameWithTitle()
        {
            string res = "";

            if (Gender == 1)
            {
                res = "mr";
            }
            else if (Gender == 2)
            {
                res = "mis/mrs";
            }
            res += " " + FirstName + " " + LastName;
            return res;
        }
};

class Student : public User
{
    public:
        string GetTitle()
        {
            return "Dear Student";
        }
};

class Professor : public User
{
    public:
        string PersonalCode = "123";

                
        // Constructor (سازنده)
        Professor()
        {

        };

        // Distructor (مخرب)
        ~Professor()
        {

        }

        string GetTitle()
        {
            return "Dear Professor";
        }
        string GetId()
        {
            return PersonalCode;
        }
        string GetFullNameWithTitle()
        {
            string res = "";
            res = "Dr, " + FirstName + " " + LastName;
            return res;
        }
};


int main()
{
    char type;
    string title = "";

    cout << "Choose The Type (u=normal_user - s=student - p=professor): ";
    cin >> type;

    if (type == 'u')
    {
        User user0;
        title = "user";
    }
    else if (type == 's')
    {
        Student student0;
        title = "student";
    }
    else if (type == 'p')
    {
        Professor professor0;
        title = "professor";
    }
    else
    {
        cout << "Unvalid Input!";
        return 1;
    }

    cout << endl << "==========" << title << " Successfully Created." << "==========";
}