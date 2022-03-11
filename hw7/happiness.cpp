#include <iostream>

using namespace std;

int get_input(int& sunshine_level)
{
    cout << "Type in the amount of sunshine (in kilolumens) you have (if the "
         << "amount of sunshine is less than 10, the program will end): ";
    cin >> sunshine_level;

    return 0;
}

int happiness(int sunshine_level, int& gaba_level)
{
    gaba_level = sunshine_level + 10;

    return 0;
}

int main()
{
    int sunshine_level = 0;
    int gaba_level = 0;
    while (true)
    {
        get_input(sunshine_level);
        happiness(sunshine_level, gaba_level);
        cout << "Happiness level: " << gaba_level << endl;

        if (gaba_level < 20)
        {
            cout << "Happiness level is below 20" << endl;
            break;
        }
    }

    return 0;
}
