/* Ishai Masada
 * Mathematical Operations */

#include <iostream>

using namespace std;

int main()
{
    // Get the first number from the user
    int first_num;
    cout << "Type in the first number: ";
    cin >> first_num;

    // Get the second number from the user
    int second_num;
    cout << "Type in the second number: ";
    cin >> second_num;

    // Let's the user know how the numbers are used
    cout << endl << "Each operation is always done using the first number before the second"
         << endl;

    // Checks if the division operation is divding by zero
    if (second_num != 0)
    {
        // Displays the quotient of the two numbers
        int quotient = first_num / second_num;
        cout << endl << "Quotient of the two numbers: " << quotient << endl;
    }
    else
    {
        // Error code for dividing by zero
        cout << endl << "You cannot divide any number by 0" << endl;
    }

    // Displays the difference of the two numbers
    int difference = first_num - second_num;
    cout << endl << "Difference of the two numbers: " << difference << endl;

    // Displays the sum of the two numbers
    int sum = first_num + second_num;
    cout << endl << "Sum of the two numbers: " << sum << endl;

    // Displays the product of the two numbers
    int product = first_num * second_num;
    cout  << endl << "Product of the two numbers: " << product << endl;

    return 0;
}
