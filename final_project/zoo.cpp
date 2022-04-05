#include <iostream>
#include <iterator>
#include <map>

using namespace std;

bool is_number(string num)
{
    for (int i; i < num.size(); i++)
    {
        if (isdigit(num[i]) == false)
        {
            return false;
        }
    }

    return true;
}

bool make_purchase(string animal_name, int animal_cost, int& budget)
{
    if (budget - animal_cost > 0)
    {
        budget -= animal_cost;
        cout << "You purchased a " << animal_name << "!" << endl;
        cout << "Your budget now: " << budget << endl;

        return true;
    }

    else
    {
        cout << "You cannot afford that animal" << endl;

        return false;
    }
}

map<string, int> purchase_animals(map<string, int> animals,
                                  map<string, int> user_animals,
                                  string& animal_name, int& animal_cost,
                                  int& budget)
{
    while (true)
    {
        cout << "Type in the name of the animal you want to buy or 0 to end the program: ";
        cin >> animal_name;
        if (is_number(animal_name))
        {
            if (animal_name == to_string(0))
            {
                return user_animals;
            }

            cout << "You can only enter letters" << endl;
            continue;
        }

        if (make_purchase(animal_name, animal_cost, budget))
        {
            auto iterator = animals.find(animal_name);
            user_animals.insert({iterator->first, iterator->second});
        }
    }

    return user_animals;
}

void display_animals(map<string, int> animals)
{
    if (animals.size() == 0)
    {
        cout << "(None)" << endl;
    }

    else
    {
        for (auto iterator = animals.begin(); iterator != animals.end(); iterator++)
        {
            cout << "Name: " << iterator->first << " - " << "Cost: "
                 << iterator->second << endl;
        }
    }
}

int main()
{
    // Available animals to buy
    map<string, int> animals = {
        {"Tiger", 7500},
        {"Lion", 15000},
        {"Bear", 15000},
        {"Monkey", 3500},
        {"Giraffe", 60000},
        {"Zebra", 4000},
        {"Rhino", 27000},
        {"Crocodile", 1100}
    };

    // User's animals
    map<string, int> user_animals;

    int budget = 4000;
    string animal_name;
    int animal_cost = 0;

    cout << "Your budget: " << budget << endl;

    cout << "These are the animals you can buy: " << endl;
    display_animals(animals);

    cout << "Your animals: " << endl;
    display_animals(user_animals);

    animals = purchase_animals(animals, user_animals, animal_name, animal_cost, budget);

    return 0;
}
