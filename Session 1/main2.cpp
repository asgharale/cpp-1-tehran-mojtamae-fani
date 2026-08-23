#include <iostream>

using namespace std;

int main()
{
    int num_1 = 1;

    cout << num_1 << endl;

    num_1 = num_1 + 5;

    num_1 = num_1 + 1;
    num_1++;
    // 8
    cout << num_1 << endl;
    cout << ++num_1 << endl; // 9

    // for loop
    for (int i=0; i < 8; i++)
    {
        cout << i;
    }

    // while loop
    int computer_num = 6;
    int user_num;
    int default_score = 10;
    cout << "\nenter your number (0-10): ";
    cin >> user_num;

    while (user_num > 10 || user_num < 0)
    {
        cout << "you've not entered a valid value!!!\nenter again: ";
        cin >> user_num;
    }

    while (computer_num != user_num) 
    {
        cout << "=== not correct! ===\n";
        default_score--;
        cout << "\nyou've lost 1 point, you've got: " << default_score << " more" << "\ntry again: ";
        cin >> user_num;
    }
    cout << "\nnice very good, your score is " << default_score;

    // do while loop
    char first_character = 'a';
    char user_first_character = 'a';
    do
    {
        cout << "\nenter a character pls: ";
        cin >> user_first_character;
        cout << "first_charachter: " << first_character << "\nuser_first_charachter:" << user_first_character;
    }
    while (first_character != user_first_character);

    return 0;
}