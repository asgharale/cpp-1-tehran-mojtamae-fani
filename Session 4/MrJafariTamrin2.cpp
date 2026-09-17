#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int number = rand() % 100 + 1;
    int guess;
    int score = 7;

    
    while (score > 0) {
        cout << "remain score: " << score << endl;
        
        cout << "guess a number between 1 and 100: ";
        cin >> guess;

        if (guess > 100 || guess <= 0)
        {
            cout << "Invalid Value.";
            return 0;
        }

        if (guess > number) {
            cout << "your number is larger than computer number" << endl;
        }
        else if (guess < number) {
            cout << "your number is smaller than computer number" << endl;
        }
        else {
            break;
        }
        score--;
    }

    if (score > 0)
    {
        cout << "well done, you've won!! " << "Final Score Is: " << score << endl;
    }
    else
    {
        cout << "Game Over!";
    }

    return 0;
}