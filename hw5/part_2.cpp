/* Ishai Masada
 * Exponentiation of two numbers */

#include <iostream>

using namespace std;

// The numbers that will be used in the exponentiation
float num_1 = 0, num_2 = 0;

// Result of the exponentiation
float power = 1;

void get_numbers()
{
    cout << "Type in the first number: " << endl;
    cin >> num_1;
    cout << "Type in the second number: " << endl;
    cin >> num_2;
}

void calculate_power(float num_1, float num_2)
{
    // Counter variable for while loop
    int i = 0;

    // Multiply the power varible by num_1, "num_2" amount of times
    while (i < num_2)
    {
        power *= num_1;
        i++;
    }
}

void print_result(float power)
{
    cout << "The first number raised to the power of the second number: "
         << power << endl;
}

int main()
{
    // Get the numbers for the calculations
    get_numbers();

    // Calculate the result of the exponentiation
    calculate_power(num_1, num_2);

    // Print out the results of the calculations
    print_result(power);
}
