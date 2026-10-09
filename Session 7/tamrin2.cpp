#include <iostream>

using namespace std;

class User
{
    protected:
        string name;
}

class Student : protected User
{
    private:
        float grade;

    public:
        void PrintData()
        {
            cout << "user's name is " << name << "\t" << endl
                 << "grade: " << grade << endl;
        }
}

int main()
{

}