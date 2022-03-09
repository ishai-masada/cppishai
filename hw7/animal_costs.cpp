#include <iostream>
#include <iterator>
#include <map>

using namespace std;

auto get_animal_info(map<string, int> animals, string animal_name,
                     int animal_cost)
{
    while (true)
    {
        cout << "Type in the name of the animal or 0 to end the program: ";
        cin >> animal_name;
        if (animal_name == "0")
        {
            return animals;
        }
        cout << "Type in the integer cost of the animal or 0 to end the program: ";
        cin >> animal_cost;
        if (animal_cost == 0)
        {
            return animals;
        }
        animals.insert({animal_name, animal_cost});
    }

    for (auto iterator = animals.begin(); iterator != animals.end(); iterator++)
    {
        cout << iterator->first;
        cout << iterator->second;
    }

    return animals;
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
    animals = get_animal_info(animals, animal_name, animal_cost);
    expenses = calculate_cost(animals);
    cout << "Final expenses of all of the animals: " << expenses << endl;

    return 0;
}
