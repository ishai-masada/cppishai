#include <iostream>

using namespace std;

int get_input(int& sunshine_level)
{
    cout << "Type in the amount of sunshine (in kilolumens) you have (if the "
         << "amount of sunshine is less than 10, the program will end): ";
    cin >> sunshine_level;

    return 0;
}

int happiness(int sunshine_level, int& serotonin_level)
{
    if (sunshine_level < 10)
    {
        cout << "Your serotonin levels are really Low!" << endl;
    }

    if (sunshine_level >= 10 && sunshine_level < 50)
    {
        cout << "Your serotonin levels are Low!" << endl;
    }

    if (sunshine_level >= 50 && sunshine_level < 100)
    {
        cout << "Your serotonin levels are less than Moderate!" << endl;
    }

    if (sunshine_level >= 100 && sunshine_level < 150)
    {
        cout << "Your serotonin levels are Moderate!" << endl;
    }

    if (sunshine_level >= 150)
    {
        cout << "Your serotonin levels are High!" << endl;
    }

    return 0;
}

int main()
{
    int sunshine_level = 0;
    int serotonin_level = 0;
    while (true)
    {
        get_input(sunshine_level);
        happiness(sunshine_level, serotonin_level);

        if (serotonin_level < 10)
        {
            break;
        }
    }

    return 0;
}
