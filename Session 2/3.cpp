#include <iostream>

using namespace std;

int main()
{

    // int // عدد
    // long // عدد با حافظه بیشتری

    // float // عدد اعشاری
    // double // عدد اعشاری با حافظه بیشتر

    // bool // ترو یا فابل (0 یا 1)

    // char letter = 'a';
    // string sentence = "hello world";

    // استراکچر یا ساختار
    struct UserStrcut
    {
        int age;
        string FirstName;
        string LastName;
        int height;
        float weight;
        string NationalId;
    }

    int mainNumber = 123;

    UserStrcut user0;

    user0.FirstName = "asghar";
    user0.age = 21;

    cout << user0.FirstName;

    return 0;
}