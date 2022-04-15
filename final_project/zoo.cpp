#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

const int TICKET_COST = 50;

class Animal
{
public:
    string name;

    int cost = 0;

    // Number of this animal
    int count = 0;

    // Constuctor for the Animal class
    Animal(string name, int cost)
    {
        this->name = name;
        this->cost = cost;
    }

    float get_earning_rate()
    {
        // Number of customers per day
        float earning_rate = cost / TICKET_COST;

        return earning_rate;
    }
};

// Checks if a string is a number
bool is_number(string num)
{
    // Iterates over the string
    for (int i; i < num.size(); i++)
    {
        // Checks if the character is a number
        if (isdigit(num[i]) == false)
        {
            return false;
        }
    }

    return true;
}

// Checks if the user can afford to purchase the desired animal
bool make_purchase(Animal desired_animal, int budget)
{
    cout << endl << "animal cost: " << desired_animal.cost << endl;

    // Checks if the user has enough funds to purchase the desired animal
    if (budget - desired_animal.cost >= 0)
    {
        budget -= desired_animal.cost;
        cout << "budget: " << budget << endl;
        cout << "You purchased a " << desired_animal.name << "!" << endl;

        return true;
    }

    else
    {
        cout << "You cannot afford that animal" << endl;

        return false;
    }
}

// Displays all animals of class Animal inside of a vector
void display_animals(vector<Animal> animals)
{
    // Checks if the vector is empty
    if (animals.size() == 0)
    {
        cout << "(None)" << endl;
    }

    else
    {
        // Iterates over each animal
        for (int i = 0; i < animals.size(); i++)
        {
            // Displays the name and cost of each animal
            cout << animals[i].name << " - $" << animals[i].cost << endl;
        }
    }
}

class Zoo
{
public:
    string name;

    // Vector to store all of the animals that the user owns
    vector<Animal> owned_animals;

    // Available animals to purchase
    vector<Animal> available_animals = {
        Animal("Tiger", 7500),
        Animal("Lion", 15000),
        Animal("Bear", 15000),
        Animal("Monkey", 3500),
        Animal("Giraffe", 60000),
        Animal("Zebra", 4000),
        Animal("Rhino", 27000),
        Animal("Crocodile", 1100)
    };

    // Constructor for the Zoo class
    Zoo(string name, vector<Animal> owned_animals)
    {
        this->name = name;
        this->owned_animals = owned_animals;
    }

    // Allows the user to purchase animals for their zoo
    void purchase_animals(int budget)
    {
        string animal_name;

        // Template variable of Animal class type
        Animal desired_animal("Name", 0);

        while (true)
        {
            cout << endl << "Type in the name of the animal you want to buy or nothing to end the program: ";

            // Stores the input from the user inside of the animal_name variable
            getline(cin, animal_name);

            // Check if the user hit enter
            if (animal_name.length() == 0)
            {
                return;
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

            // Checks if the user entered an available animal
            for (int i = 0; i < available_animals.size(); i++)
            {
                if (animal_name == available_animals[i].name)
                {
                    /* Sets the name and cost of the template variable to the
                     * name and cost of the available animal that matches the
                     * desired animal's name*/
                    desired_animal.name = available_animals[i].name;
                    desired_animal.cost = available_animals[i].cost;
                }
            }

            // Checks if the user can afford the animal they want to purchase
            if (make_purchase(desired_animal, budget))
            {
                // Stores the animal into the user's owned animals
                owned_animals.insert(owned_animals.end(), desired_animal);
            }
        }

        return;
    }
};

int main()
{
    // User's animals
    vector<Animal> owned_animals;

    // User's zoo
    Zoo zoo("Vermont Zoo", owned_animals);

    int budget = 4000000;

    for (int i = 0; i < 7; i++)
    {
        cout << endl << "Day " << i + 1 << endl;
        cout << endl << "Your budget: " << budget << endl;

        cout << "These are the animals you can buy: " << endl;

        // Displays the available animals and the user's animals
        display_animals(zoo.available_animals);

        cout << endl << "Your animals: " << endl;

        // Displays the available animals and the user's animals
        display_animals(zoo.owned_animals);

        // Allows the user to purchase animals
        zoo.purchase_animals(budget);
    }

    return 0;
}
