#include <iostream>

using namespace std;

int get_liters(int liters)
{
    cout << "Type in the number of liters you want to boil: " << endl;
    cin >> liters;
    return liters;
}

string get_setting(string setting)
{
    cout << "Type in the setting you want to boil the water at (Low or High): "
         << endl;
    cin >> setting;
    return setting;
}

int calculate_time(int liters, string setting)
{
    int time = 0;
    if (setting == "High" or setting == "high")
    {
        time = 20 * liters;
    }

    if (setting == "Low" or setting == "low")
    {
        time = 60 * liters;
    }

    return time;
}

int main()
{
    string setting;
    int liters = 0;
    liters = get_liters(liters);
    setting = get_setting(setting);
    cout << "Amount of time it will take to boil the water: "
         << calculate_time(liters, setting) << endl;
}
