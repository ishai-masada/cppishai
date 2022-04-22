#include <iostream>
#include <vector>

using namespace std;

const int TICKET_COST = 50;
const int INITIAL_BUDGET = 10000;

// Animal Class
class Animal
{
public:
    // Animal name
    string name;

    // Animal cost
    int cost = 0;

    // Number of this animal
    int count = 0;

    // Animal Class Constructor
    Animal(string name, int cost, int count)
    {
        this->name = name;
        this->cost = cost;
        this->count = count;
    }

    // Calculates the earning rate
    float get_earnings()
    {
        // Number of customers per day
        float earnings = (cost / 100) * count * TICKET_COST;

        return earnings;
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
bool make_purchase(Animal desired_animal, int& budget)
{
    // Checks if the user has enough funds to purchase the desired animal
    if (budget - desired_animal.cost >= 0)
    {
        // Decrements the budget by the cost of the animal
        budget -= desired_animal.cost;

        cout << "Your budget: " << budget << endl;
        cout << "You purchased a " << desired_animal.name << "!" << endl;

        return true;
    }

    else
    {
        cout << "You cannot afford that animal" << endl;

        return false;
    }
}

// Zoo Class
class Zoo
{
public:
    // Zoo name
    string name;

    // Vector to store all of the animals that the user owns
    vector<Animal> owned_animals;

    // Available animals to purchase
    vector<Animal> available_animals = {
        Animal("Tiger", 7500, 0),
        Animal("Lion", 15000, 0),
        Animal("Bear", 15000, 0),
        Animal("Monkey", 3500, 0),
        Animal("Giraffe", 60000, 0),
        Animal("Zebra", 4000, 0),
        Animal("Rhino", 27000, 0),
        Animal("Crocodile", 1100, 0),
        Animal("Rhino", 27000, 0),
        Animal("Crocodile", 1100, 0),
        Animal("Whale Shark", 500000, 0),
        Animal("Turtle", 1000, 0),
        Animal("Eel", 500, 0),
        Animal("Reef Shark", 6000, 0),
        Animal("Starfish", 100, 0),
        Animal("Manta Ray", 500, 0)
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
        Animal desired_animal("Name", 0, 0);

        while (true)
        {
            cout << endl << "Type in the name of the animal you want to buy or nothing to end: ";

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

            // Variable to check if the user entered a valid name
            bool is_valid = false;

            // Iterate over the available animals
            for (int i = 0; i < available_animals.size(); i++)
            {
                // Checks if the user entered an available animal
                if (animal_name == available_animals[i].name)
                {
                    /* Sets the name and cost of the template variable to the
                     * name and cost of the available animal that matches the
                     * desired animal's name*/
                    desired_animal.name = available_animals[i].name;
                    desired_animal.cost = available_animals[i].cost;
                    is_valid = true;
                }
            }

            // Checks if the user entered an available animal
            if (is_valid == false)
            {
                cout << "Your input was invalid" << endl;
                continue;
            }

            // Checks if the user can afford the animal they want to purchase
            if (make_purchase(desired_animal, budget))
            {
                // Variable to check if the user already owns the desired animal
                bool is_owned = false;

                // Iterate over the user's animals
                for (int i = 0; i < owned_animals.size(); i++)
                {
                    // Checks if the user already owns one of the desired animal
                    if (desired_animal.name == owned_animals[i].name)
                    {
                        // Increments the count of the desired animal
                        owned_animals[i].count += 1;
                        is_owned = true;
                    }
                }

                /*Checks if the user doesn't already own one of the desired
                 * animal*/
                if (is_owned == false)
                {
                    // Increments the count of the desired animal by 1
                    desired_animal.count += 1;

                    // Stores the animal into the user's owned animals
                    owned_animals.insert(owned_animals.end(), desired_animal);
                }
            }
        }

        return;
    }

    // Calculates the total earnings for the day
    void calculate_earnings(int& budget, float& daily_earnings,
                            float& number_of_customers)
    {
        daily_earnings = 0;
        number_of_customers = 0;

        // Iterates over the user's animals
        for (int i = 0; i < owned_animals.size(); i++)
        {
            // Increments the earnings by the amount the animal earned
            daily_earnings += owned_animals[i].get_earnings();
        }

        number_of_customers = daily_earnings / TICKET_COST;

        // Increments the budget by the amount the Zoo earned
        budget += daily_earnings;

        return;
    }

    // Displays all animals of class Animal inside of a vector
    void display_animals(int budget)
    {
        cout << "\"" << name << "\"" << endl;
        cout << endl << "Your budget: " << budget << endl << endl;

        cout << "These are the animals you can buy: " << endl;

        // Iterates over the available animals
        for (int i = 0; i < available_animals.size(); i++)
        {
            cout << available_animals[i].name << " - $" << available_animals[i].cost << endl;
        }

        cout << endl << "Your animals: " << endl;

        // Checks if the vector is empty
        if (owned_animals.size() == 0)
        {
            cout << "(None)" << endl;
        }

        else
        {
            // Iterates over each animal
            for (int i = 0; i < owned_animals.size(); i++)
            {
                // Displays the name and cost of each animal
                cout << owned_animals[i].name << "(x" << owned_animals[i].count << ")" << " - $" << owned_animals[i].cost << endl;
            }
        }
    }
};

// Displays how much the user earned in profit
void display_profits(int budget)
{
    int profit = budget - INITIAL_BUDGET;

    // Checks if user made a profit
    if (profit > 0)
    {
        cout << "You earned $" << profit << " in profits!" << endl;
    }

    // Checks if the user lost money
    else if (profit < 0)
    {
        cout << "You lost $" << profit * -1 << "!" << endl;
    }

    // Checks if the user is at the same place they started
    else if (profit = 0)
    {
        cout << "You earned zero profit!" << endl;
    }
}

int main()
{
    // User's animals
    vector<Animal> owned_animals;

    // User's zoo
    Zoo zoo("Vermont Zoo", owned_animals);

    int budget = INITIAL_BUDGET;

    // How much the user earns a day
    float daily_earnings = 0;
    float number_of_customers = 0;

    // Iterates 7 times
    for (int i = 0; i < 7; i++)
    {
        cout << endl << "Day " << i + 1 << endl;

        // Displays the available animals and the user's animals
        zoo.display_animals(budget);

        // Allows the user to purchase animals
        zoo.purchase_animals(budget);

        // Calculates how much the user has earned that day
        zoo.calculate_earnings(budget, daily_earnings, number_of_customers);

        cout << "Your earnings of the day: " << daily_earnings << endl;
        cout << "Number of customers: " << number_of_customers << endl;
        cout << "Total budget: " << budget << endl;
    }

    // Display the user's profits
    display_profits(budget);

    return 0;
}
