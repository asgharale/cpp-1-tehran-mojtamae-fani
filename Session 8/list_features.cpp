#include <iostream>
#include <vector>

using namespace std;


void add_scores(float num, vector<float>& scores)
{
    if (num >= 0 && num <=20)
    {
        scores.push_back(num);
    }
}


int main()
{
    vector<float> scores = {12.0, 20.0, 10.5};

    char input = '1';

    while (input != 'n')
    {
        float score = 0.0;

        cout << "enter the new score: ";
        cin >> score;

        add_scores(score, scores);

        cout << "wanna continue (n = NO): ";
        cin >> input;
    }

    for (int i=0; i<scores.size(); i++)
    {
        cout << scores[i] << endl;
    }
}