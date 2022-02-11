#include <iostream>

using namespace std;

int main()
{
    float first_score;
    float second_score;
    float third_score;
    float fourth_score;

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

        float sum = first_score + second_score + third_score + fourth_score;
        cout << "Sum: " << sum << endl;

        float average = sum / 4.0;
        cout << "Average: " << average << endl;
    }

    return 0;
}
