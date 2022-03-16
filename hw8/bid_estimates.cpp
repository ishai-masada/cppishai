#include <iostream>

using namespace std;

void get_sqr_ft(int& wall_sqr_ft, int& ceiling_sqr_ft)
{
    // Get the square feet for the walls
    cout << "Type in the number of square feet for the walls: ";
    cin >> wall_sqr_ft;

    // Get the square feet for the ceiling
    cout << "Type in the number of square feet for the ceilings: ";
    cin >> ceiling_sqr_ft;

    return;
}

double calculate_painting_labor(int& wall_sqr_ft, int& ceiling_sqr_ft, double& total_labor)
{
    // Dollars per hour for walls and ceilings
    int dol_per_hr = 40;

    // Hours per 200 Square Feet
    const float ceiling_hr_per_sqft = 3.2;

    // Hours per 200 Square Feet
    const float wall_hr_per_sqft = 2.5;

    // Number of hours to paint the walls
    double wall_hours = 0;

    // Amount of dollars to paint the walls
    double wall_labor = 0;

    // Calculate the labor expenses to paint to walls
    double ceiling_labor = ((ceiling_sqr_ft / 200) * ceiling_hr_per_sqft) * dol_per_hr;

    // Check if the square footage is greater than 1400 square feet
    if (wall_sqr_ft > 1400)
    {
        // Calculate the labor expenses to paint to walls
        wall_sqr_ft -= 1400;
        wall_hours += (wall_sqr_ft / 200) * wall_hr_per_sqft;
        wall_labor = (dol_per_hr * 17.5) + (34 * wall_hours);
    }

    else
    {
        // Calculate the labor expenses to paint to walls
        wall_hours += (wall_sqr_ft / 200) * wall_hr_per_sqft;
        wall_labor = dol_per_hr * wall_hours;
    }

    cout << "Ceiling Labor: " << ceiling_labor << endl << "Wall Labor: "
         << wall_labor << endl;

    // Calculate the total expenses
    total_labor += ceiling_labor + wall_labor;

    return total_labor;
}

void painting_cost()
{

    // Total expenses for painting
    double total_labor = 0;

    // Number of square feet
    int wall_sqr_ft = 0;
    int ceiling_sqr_ft = 0;

    // Get the number of square feet to paint
    get_sqr_ft(wall_sqr_ft, ceiling_sqr_ft);

    // Get the total expenses for painting the walls and the ceiling
    total_labor = calculate_painting_labor(wall_sqr_ft, ceiling_sqr_ft, total_labor);

    cout << "Total expenses for the walls and ceilings: " << total_labor
         << endl;

    return;
}

string get_fm()
{
    // Floor material
    string floor_material;

    // Get the floor material
    cout << "Type in your floor\'s material (Wood, Tile, Other): ";
    cin >> floor_material;

    return floor_material;
}

void get_sqft(int& sqft)
{
    // Get the number of square feet to replace
    cout << "Type in the number of square foot to replace: ";
    cin >> sqft;

    return;
}

double calculate_flooring_labor(double dol_per_hr, double hr_per_sqft, int sq_ft)
{
    // Return the cost of replacing the flooring
    return (((sq_ft / 100) * hr_per_sqft) * dol_per_hr);
}

void flooring_cost()
{
    // Total expenses for replacing the flooring
    double total_labor = 0;

    // Dollars per hour
    double dol_per_hr = 0;

    // Number of square feet
    int sq_ft = 0;

    // Floor material
    string floor_material = get_fm();

    // Hours per 100 Square Feet
    double hr_per_sqft = 0;

    while (true)
    {
        // Check if the floor material is wood
        if (floor_material == "Wood")
        {
            dol_per_hr = 48;
            hr_per_sqft = 2;
            break;
        }

        // Check if the floor material is tile
        if (floor_material == "Tile")
        {
            dol_per_hr = 52;
            hr_per_sqft = 2.8;
            break;
        }

        // Check if the floor material is something else
        if (floor_material == "Other")
        {
            dol_per_hr = 30;
            hr_per_sqft = 1.7;
            break;
        }

        /* Prompt the user to type in their floor material if their input was */
        /* invalid */
        cout << "Your input did not match \"Wood\", \"Tile\", or \"Other\"."
             << endl;
        floor_material = get_fm();
    }

    // Get the square footage of the floors
    get_sqft(sq_ft);

    // Calculate the total expenses for the floors
    total_labor = calculate_flooring_labor(dol_per_hr, hr_per_sqft, sq_ft);

    cout << "Total expenses for replacing the flooring: " << total_labor
         << endl;
}

int main()
{
    painting_cost();
    flooring_cost();

    return 0;
}
