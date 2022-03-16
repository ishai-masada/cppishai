#include <iostream>

using namespace std;

int get_input(int& sunshine_level)
{
    // Prompt the user for the amount of sunshine they are getting
    cout << "Type in the amount of sunshine (in kilolumens) you have (if the "
         << "amount of sunshine is less than 10, the program will end): ";
    cin >> sunshine_level;

    return 0;
}

int happiness(int sunshine_level, int& serotonin_level)
{
    // Check if the sunshine level is below 10
    if (sunshine_level < 10)
    {
        cout << "Your serotonin levels are really Low!" << endl;
    }

    // Check if the sunshine level is between 10 and 50
    if (sunshine_level >= 10 && sunshine_level < 50)
    {
        cout << "Your serotonin levels are Low!" << endl;
    }

    // Check if the sunshine level is between 50 and 100
    if (sunshine_level >= 50 && sunshine_level < 100)
    {
        cout << "Your serotonin levels are less than Moderate!" << endl;
    }

    // Check if the sunshine level is between 100 and 150
    if (sunshine_level >= 100 && sunshine_level < 150)
    {
        cout << "Your serotonin levels are Moderate!" << endl;
    }

    // Check if the sunshine level is greater than or equal to 150
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
        // Get the amount of sunshine from the user
        get_input(sunshine_level);

        // Calculate the amount of serotonin
        happiness(sunshine_level, serotonin_level);

        if (serotonin_level < 10)
        {
            break;
        }
    }

    return 0;
}
