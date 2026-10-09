#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class BaseClass
{
    protected:
        long Id;

    public:
        long GetId()
        {
            return this->Id;
        }
};

class Book : public BaseClass
{
    private:
        string name = "";
        string author = "";
        string location = "";
        long count = 0;

    public:
        // getter / setter
        string GetName()
        {
            return this->name;
        }
        string GetDetail()
        {
            return this->name + " - author: " + this->author;
        }
        string GetAuthor()
        {
            return this->author;
        }
        string GetLocation()
        {
            return this->location;
        }
        long GetCount()
        {
            return this->count;
        }
        void DecreaseByCount(long c)
        {
            this->count -= c;
        }

        Book(string name, string author, string location,
             long count, long lastId)
        {
            this->name = name;
            this->author = author;
            this->location = location;
            this->count = count;
            this->Id = ++lastId;
        }
};

enum ReserveStatus
{
    OPEN = 1,
    GIVEN = 2,
    PENDING = 3
};

class Reserve : public BaseClass
{
    private:
        long UserId = 0;
        long BookId = 0;
        ReserveStatus Status;
        long count = 0;
        long maxDays = 0;
    
    public:
        Reserve(long userId, long bookId, ReserveStatus status,
        long count, long maxDays, long lastId)
        {
            this->UserId = userId;
            this->BookId = bookId;
            this->Status = status;
            this->count = count;
            this->maxDays = maxDays;
            this->Id = ++lastId;
        }

        void SetStatus(ReserveStatus status)
        {
            this->Status = status;
        }

        string ReserveStatusTranslate(ReserveStatus status)
        {
            string res = "نامشخص";
            if (status == ReserveStatus::PENDING)
            {
                res = "در صف";
            }
            else if (status == ReserveStatus::OPEN)
            {
                res = "در دست عضو کتابخوانه";
            }
            else if (status == ReserveStatus::GIVEN)
            {
                res = "برگردانده شده";
            }
            return res;
        }

        long GetUserId()
        {
            return this->UserId;
        }
        long GetBookId()
        {
            return this->BookId;
        }
        long GetCount()
        {
            return this->count;
        }
        long GetMaxDays()
        {
            return this->maxDays;
        }
        ReserveStatus GetStatus()
        {
            return this->Status;
        }
};

class User: public BaseClass
{
    private:
        string firstname;
        string lastname;
        int age;
        string phonenumber;
    
    public:
        User(string firstname, string lastname, int age,
             string phonenumber, int lastId)
        {
            this->firstname = firstname;
            this->lastname = lastname;
            this->phonenumber = phonenumber;
            this->age = age;
            this->Id = ++lastId;
        }

        string GetFirstName()
        {
            return firstname;
        }
        string GetLastName()
        {
            return lastname;
        }
        string GetPhoneNumber()
        {
            return phonenumber;
        }
        int GetAge()
        {
            return age;
        }
};

void ShowMenu()
{
    cout << "1. Show Books In Library " << endl 
         << "2. Show Users" << endl
         << "3. Show Reservations" << endl
         << "4. Add Book" << endl
         << "5. Add User" << endl
         << "6. Add Reservation" << endl
         << "7. Return Reservation" << endl;
}

Book CreateBook(long lastId)
{
    string name;
    cout << "enter name: ";
    cin.ignore();
    getline(cin, name);

    string author;
    cout << "enter author: ";
    cin.ignore();
    getline(cin, author);

    string location;
    cout << "enter location: ";
    cin.ignore();
    getline(cin, location);

    long count;
    cout << "enter count: ";
    cin >> count;

    Book book(name, author, location, count, lastId);

    ofstream context("books.txt", ios::app);
    context << lastId+1 << "," << name << "," << author << ","
        << count << "," << location << "\n";

    return book;
}

User CreateUser(long lastId)
{
    string fname;
    cout << "enter first name: ";
    cin.ignore();
    getline(cin, fname);

    string lname;
    cout << "enter last name: ";
    cin.ignore();
    getline(cin, lname);

    string phoneNumber;
    cout << "enter phone number: ";
    cin.ignore();
    getline(cin, phoneNumber);
    
    int age;
    cout << "enter age pls: ";
    cin >> age;

    User user(fname, lname, age, phoneNumber, lastId);

    ofstream context("li_users.txt", ios::app);
    context << lastId+1 << "," << fname << "," << lname
        << "," << age << "," << phoneNumber << "\n";

    return user;
}

int ConvertReserveStatusToInt(ReserveStatus status)
{
    if (status == ReserveStatus::OPEN)
        return 1;
    else if (status == ReserveStatus::GIVEN)
        return 2;
    else if (status == ReserveStatus::PENDING)
        return 3;
    else
        return 0;
};

ReserveStatus ConvertIntToStatus(int status)
{
    if (status == 1)
        return ReserveStatus::OPEN;
    else if (status == 2)
        return ReserveStatus::GIVEN;
    else if (status == 3)
        return ReserveStatus::PENDING;
    return ReserveStatus::OPEN;
};

Reserve CreateReservation(long lastId)
{
    long userId;
    cout << "user id: ";
    cin >> userId;

    long bookId;
    cout << "book id: ";
    cin >> bookId;

    long maxDays;
    cout << "max days: ";
    cin >> maxDays;

    ReserveStatus status = ReserveStatus::OPEN;

    long count;
    cout << "count: ";
    cin >> count;

    Reserve reservation(userId, bookId, status, count, maxDays, lastId);

    ofstream context("reservations.txt", ios::app);
    context << lastId+1 << "," << userId << "," << bookId << ","
        << ConvertReserveStatusToInt(status) << "," << count << "," << maxDays << "\n";

    return reservation;
}

int main()
{
    char input = 'a';

    vector<Book> books;
    vector<User> users;
    vector<Reserve> reserves;

    string line;
    string id_str;
    long lastBookId = 0;
    long lastUserId = 0;
    long lastReservationId = 0;
    long id;


    // load books
    ifstream booksContex("books.txt");

    string count_str;
    string book_name;
    string book_location;
    string author;
    long count;
    while(getline(booksContex, line))
    {
        stringstream ss(line);
        getline(ss, id_str, ',');
        id = stoi(id_str);
        getline(ss, book_name, ',');
        getline(ss, author, ',');
        getline(ss, count_str, ',');
        count = stol(count_str);
        getline(ss, book_location, ',');

        lastBookId++;
        id--;

        Book book(book_name, author, book_location, count, id--);
        books.push_back(book);
    }

    // load users
    ifstream usersContex("li_users.txt");

    line = "";
    id = 0;
    id_str= "";
    string fname;
    string lname;
    int age;
    string age_str;
    string phoneNumber;
    while(getline(usersContex, line))
    {
        stringstream ss(line);
        getline(ss, id_str, ',');
        id = stoi(id_str);
        getline(ss, fname, ',');
        getline(ss, lname, ',');
        getline(ss, age_str, ',');
        age = stoi(age_str);

        getline(ss, phoneNumber);

        lastUserId++;
        id--;

        User user(fname, lname, age, phoneNumber, id--);
        users.push_back(user);
    }

    line = "";
    id = 0;
    id_str= "";
    count_str = "";
    string userId_str;
    string bookId_str;
    string status_str;
    string maxDays_str;
    long status_int;
    long userId;
    long bookId;
    long reserve_count;
    long maxDays;
    ReserveStatus status;

    ifstream reservContext("reservations.txt");
    while(getline(reservContext, line))
    {
        stringstream ss(line);
        getline(ss, id_str, ',');
        id = stoi(id_str);
        getline(ss, userId_str, ',');
        userId = stoi(userId_str);
        getline(ss, bookId_str, ',');
        bookId = stoi(bookId_str);
        getline(ss, status_str, ',');
        status_int = stoi(status_str);
        status = ConvertIntToStatus(status_int);
        getline(ss, count_str, ',');
        reserve_count = stoi(count_str);
        getline(ss, maxDays_str, ',');
        maxDays = stoi(maxDays_str);

        lastReservationId++;
        id--;

        Reserve reserve(userId, bookId, status, reserve_count, maxDays, id);
        reserves.push_back(reserve);
    }

    do
    {
        ShowMenu();

        cout << "enter (n/N for quit): ";
        cin >> input;

        if (input == '1')
        {
            int innerInput = 0;
            for (int i=0; i<books.size(); i++)
            {
                cout << "--------" << endl <<
                    "|. Id: " << books[i].GetId() << endl <<
                    "|. name: " << books[i].GetName() << endl <<
                    "|. author: " << books[i].GetAuthor() << endl <<
                    "|. location: " << books[i].GetLocation() << endl <<
                    "|. count: " << books[i].GetCount() << endl <<
                    "--------" << endl;
            }
            cout << "=====" << endl << "choose an option: " << endl <<
                "1. add a book" << endl <<
                "2. back to menu" << endl << "enter: ";
            cin >> innerInput;

            if (innerInput ==1)
            {
                books.push_back(CreateBook(lastBookId));
                lastBookId++;
                cout << endl << "Book Added Was successful!" << endl;
            }
        }
        else if (input == '2')
        {
            int innerInput = 0;
            for (int i=0; i<users.size(); i++)
            {
                cout << "--------" << endl <<
                    "|. Id: " << users[i].GetId() << endl <<
                    "|. first name: " << users[i].GetFirstName() << endl <<
                    "|. last name: " << users[i].GetLastName() << endl <<
                    "|. phone number: " << users[i].GetPhoneNumber() << endl <<
                    "|. age: " << users[i].GetAge() << endl <<
                    "--------" << endl;
            }

            cout << "=====" << endl << "choose an option: " << endl <<
                "1. add a user" << endl <<
                "2. back to menu" << endl << "enter: ";

            cin >> innerInput;

            if (innerInput == 1)
            {
                users.push_back(CreateUser(lastUserId));
                cout << "User added successfully" << endl;
                lastUserId++;
            }
        }
        else if (input == '3')
        {
            string firstname;
            string lastname;
            string bookname;

            int innerInput = 0;
            for (int i=0; i<reserves.size(); i++)
            {
                for (int j=0; j<users.size(); j++)
                {
                    if (users[j].GetId() == reserves[i].GetUserId())
                    {
                        firstname = users[j].GetFirstName();
                        lastname = users[j].GetLastName();
                    }
                }

                for (int j=0; j<books.size(); j++)
                {
                    if (books[j].GetId() == reserves[i].GetBookId())
                    {
                        bookname = books[j].GetName();
                    }
                }

                cout << "--------" << endl <<
                    "|. Id: " << reserves[i].GetId() << endl <<
                    "|. user name: " << firstname + " " + lastname << endl <<
                    "|. book name: " << bookname << endl <<
                    "|. count: " << reserves[i].GetCount() << endl <<
                    "|. max days: " << reserves[i].GetMaxDays() << endl <<
                    "|. Status: " << reserves[i].ReserveStatusTranslate(reserves[i].GetStatus()) << endl <<
                    "--------" << endl;
            }

            cout << "=====" << endl << "choose an option: " << endl <<
                "1. add a reservation" << endl <<
                "2. back to menu" << endl << "enter: ";

            cin >> innerInput;

            if (innerInput == 1)
            {
                reserves.push_back(CreateReservation(lastReservationId));
                cout << "Reservation Added Successfully";
                lastReservationId++;
            }
        }
        else if (input == '4')
        {
            books.push_back(CreateBook(lastBookId));
            lastBookId++;
            cout << endl << "Book Added Was successful!" << endl;
        }
        else if (input == '5')
        {
            users.push_back(CreateUser(lastUserId));
            cout << "User added successfully" << endl;
            lastUserId++;
        }
        else if (input == '6')
        {
            reserves.push_back(CreateReservation(lastReservationId));
            cout << "Reservation Added Successfully";
            lastReservationId++;
        }
        else if (input == '7')
        {
            long reservationId = 0;
            cout << "enter the reservation Id: ";
            cin >> reservationId;

            for (int i=0; i<reserves.size(); i++)
            {
                if (reserves[i].GetId() == reservationId)
                    reserves[i].SetStatus(ReserveStatus::GIVEN);
            }
        }
    }
    while(input != 'n');
}