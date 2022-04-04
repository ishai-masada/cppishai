#include <iostream>
#include <iterator>
#include <map>

using namespace std;

bool is_number(string num)
{
    for (int i; i < num.size(); i++)
    {
        if (isdigit(num[i]))
        {
            return true;
        }
    }

    return false;
}

int get_animal_info(map<string, int>& animals, string& animal_name,
                     int& animal_cost)
{
    while (true)
    {
        cout << "Type in the name of the animal or 0 to end the program: ";
        cin >> animal_name;
        cout << animal_name << endl;
        if (is_number(animal_name))
        {
            break;
        }
        cout << "Type in the integer cost of the animal or 0 to end the program: ";
        cin >> animal_cost;
        cout << animal_cost << endl;
        if (animal_cost == 0)
        {
            break;
        }
        animals.insert({animal_name, animal_cost});
    }

    /* for (auto iterator = animals.begin(); iterator != animals.end(); iterator++) */
    /* { */
    /*     cout << iterator->first; */
    /*     cout << iterator->second; */
    /* } */

    return 0;
}

int calculate_cost(map<string, int> animals)
{
    int expenses = 0;
    map<string, int>::iterator iterator = animals.begin();
    while (iterator != animals.end())
    {
        int cost = iterator->second;
        expenses += cost;
    }
    return expenses;
}

int main()
{
    map<string, int> animals;
    int expenses = 0;
    string animal_name;
    int animal_cost;
    get_animal_info(animals, animal_name, animal_cost);

    int age = 0;

    expenses = calculate_cost(animals);
    cout << "Final expenses of all of the animals: " << expenses << endl;

    return 0;
}
