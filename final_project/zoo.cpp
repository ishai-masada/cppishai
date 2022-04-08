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
        cout << "budget: " << budget << endl;
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
                                  map<string, int> owned_animals,
                                  string& animal_name, int& animal_cost,
                                  int& budget)
{
    while (true)
    {
        cout << endl << "Type in the name of the animal you want to buy or nothing to end the program: ";
        getline(cin, animal_name);

        // Check if the user hit enter
        if (animal_name.length() == 0)
        {
            return owned_animals;
        }

        else
        {
            // Check if the user entered a number
            if (is_number(animal_name))
            {
                cout << endl << "You can only enter letters" << endl;
                continue;
            }
        }

        // Check if the user can afford the animal they want to purchase
        if (make_purchase(animal_name, animal_cost, budget))
        {
            // Store the animal into the user's owned animals
            auto iterator = animals.find(animal_name);
            owned_animals.insert({iterator->first, iterator->second});
        }
    }

    return owned_animals;
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
            cout << iterator->first << " - $" << iterator->second << endl;
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
    map<string, int> owned_animals;

    int budget = 4000;
    string animal_name;
    int animal_cost = 0;

    cout << "Your budget: " << budget << endl;

    cout << "These are the animals you can buy: " << endl;
    display_animals(animals);

    cout << endl << "Your animals: " << endl;
    display_animals(owned_animals);

    animals = purchase_animals(animals, owned_animals, animal_name, animal_cost, budget);

    return 0;
}
