#include <iostream>
#include <random>

using namespace std;

int check_guess(string guess, string answer)
{
    if (guess == answer)
    {
        cout << "You guessed the correct answer!" << endl;
    }

    else
    {
        cout << "You guessed incorrectly. the correct answer was " << answer
             << endl;
    }

    return 0;
}

string get_answer(string cards[])
{
    random_device device;
    uniform_int_distribution<int> distribution(1, 52);
    string answer = cards[distribution(device)];

    return answer;
}

int main()
{
    vector<string> discard_pile;
    string guess;
    cout << "Guess a card. Example: \"5h\" would be five of hearts" << endl;
    cin >> guess;

    string cards[52] = {"5h", "3s", "As", "8c", "2d", "9d", "2c", "5d", "3h"};
    check_guess(guess, get_answer(cards));

    for (int i; i < 52; i++)
    {
        if (cards[i] == guess)
        {
            discard_pile.push_back(guess);
        }
    }

    return 0;
}
