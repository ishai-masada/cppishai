#include <iostream>

using namespace std;

int main()
{
    // First score
    float first_score;

    // Second score
    float second_score;

    // Third score
    float third_score;

    // Fourth score
    float fourth_score;

    // For loop over the range of 0 to 2
    for (int i = 0; i < 2; i++)
    {
        cout << "Type in the first score: ";
        cin >> first_score;

        cout << "Type in the second score: ";
        cin >> second_score;

        cout << "Type in the third score: ";
        cin >> third_score;

        cout << "Type in the fourth score: ";
        cin >> fourth_score;

        // Adds up all of the scores
        int sum = first_score + second_score + third_score + fourth_score;
        cout << "Sum: " << sum << endl;

        // Takes the average of the scores
        int average = sum / 4.0;
        cout << "Average: " << average << endl;
    }

    return 0;
}
