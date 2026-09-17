#include <iostream>
#include <string>

using namespace std;

enum AnimalLivingType
{
    Unknown = 0,
    Khoshki = 1,
    Farya = 2,
    Hava = 3
};
enum Gender
{
    Unknown = 0,
    Male = 1,
    Female = 2
};

class Animal
{
    private:
        int age;
        string name = "";

        Gender Gender = Gender::Unknown;
        AnimalLivingType type = AnimalLivingType::Unknown;

    public:
        virtual void MakeSound()
        {
        }
        void EatFood()
        {
            cout << "omm im eating some food..."<< endl;
        }
};
class Dog : public Animal
{
    public:
        virtual void MakeSound()
        {
            cout << "bark bark..." << endl;
        }
};
class Cat : public Animal
{
    public:
        virtual void MakeSound()
        {
            cout << "meow meow..." << endl;
        }
                void EatFood()
        {
            cout << "omm im eating Lazania..."<< endl;
        }
};

int main()
{

    Cat garfild;

    string query = "select * from Animal where Type=3";

    var result = dbset.Exceute(query);

    dbset.Animal.Add(garfild);

    garfild.MakeSound();
    garfild.EatFood();

    

    return 0;
}