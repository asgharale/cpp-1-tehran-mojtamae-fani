#include <iostream>
#include <string>

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
    User user0;
    cout << "Enter national Id of user: ";
    cin >> user0.NationalId;

    cout << "Enter The Name user: ";
    cin >> user0.FirstName;
    user0.LastName = "goodarzi";
    user0.Gender = 1;
    cout << user0.GetTitle() << "   " << user0.GetId() << "   " << user0.GetFullNameWithTitle() << endl;

    Student my_student;
    my_student.NationalId = "09873210";
    my_student.FirstName = "hosein";
    my_student.LastName = "shahani";
    my_student.Gender = 1;
    cout << my_student.GetTitle() << "   " << my_student.GetId() << "   " << my_student.GetFullNameWithTitle() << endl;

    Professor math_professor;
    math_professor.FirstName = "ali asghar";
    math_professor.LastName = "jafari";
    math_professor.Gender = 1;
    cout << math_professor.GetTitle() << "   " << math_professor.GetId() << "   " << math_professor.GetFullNameWithTitle() << endl;
}
