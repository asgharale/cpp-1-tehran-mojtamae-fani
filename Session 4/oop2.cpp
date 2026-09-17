#include <iostream>

using namespace std;

class DbInstance
{
    private:
        string Name;
        string Password;
        string Address;
        string UserName;
    
    public:
        bool ConnectToDb(string Password, string UserName)
        {
            // connect to db with given data
            cout << "Cnonection was successful." << endl;
            return true;
        }
        string GetDatabaseInstanceName()
        {
            return this->Name;
        }
        string GetDatabaseInstanceAddress()
        {
            return this->Address;
        }



    DbInstance(string Address, string Name)
    {
        this->Address = Address;
        this->Name = Name;
        cout << "Basic Info Was Updated." << endl;
    }
    ~DbInstance()
    {
        // close the connection
        cout << "connection is down." << endl;
    }
};

int main()
{
    string Address, Name;

    cout << "Enter the Address Od Db: ";
    cin >> Address;

    cout << "Enter The Name Of Db: ";
    cin >> Name;

    DbInstance sqlserver1(Address, Name);

    cout << sqlserver1.GetDatabaseInstanceAddress() << endl;

    return 0;
}