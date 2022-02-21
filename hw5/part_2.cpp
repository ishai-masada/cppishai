/* Ishai Masada
 * Exponentiation of two numbers */

#include <iostream>

using namespace std;

float num_1 = 0, num_2 = 0;
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
    int i = 0;
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
    get_numbers();
    calculate_power(num_1, num_2);
    print_result(power);
}
