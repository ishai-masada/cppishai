/* Ishai Masada
 * General Purpose Calculator */

#include <iostream>

using namespace std;

int highest_num()
{
    // First number
    int first_num = 0;

    // Second number
    int second_num = 0;

    // Third number
    int third_num = 0;

    cout << "Type in the first number: ";
    cin >> first_num;
    cout << "Type in the second number: ";
    cin >> second_num;
    cout << "Type in the third number: ";
    cin >> third_num;

    // Return the largest of the three numbers
    return max(max(first_num, second_num), third_num);
}

string reverse_num()
{
    string given_num;
    cout << "Type in a number to be reversed: ";
    cin >> given_num;

    // Number of digits in the number
    int given_num_size = given_num.length();

    // Iterate half the number of digits as the number
    for (int i = 0; i < (given_num_size / 2); i++)
    {
        // Switch the digits that are equidistant from the ends of the number
        swap(given_num[i], given_num[given_num_size - i - 1]);
    }

    return given_num;
}

float garage_charges(int hours)
{
    float start_rate = 3.75; // Dollars per hour
    int threshold = 12; // hours
    float new_rate = 5.00; // Dollars per hour

    // The total amount of charges owed by the user
    float charges = 0.00;

    // The amount of charges that the user owes after the first 12 hours
    float remaining_charges = 0.00;

    // Check if the user has stayed for more than 12 hours
    if (hours - threshold > 0)
    {
        hours -= threshold;

        // Calculate the number of hours owed by the user for the first 12 hours
        charges += start_rate * threshold;
        cout << "Charges for the first 12 hours: $" << charges << endl;
    }

    // Calculate the number of hours owed by the user after the first 12 hours
    remaining_charges = new_rate * hours;
    charges += remaining_charges;
    cout << "Charges for the remaining " << hours << " hours: $" << remaining_charges
         << endl;

    return charges;
}

int main()
{
    // The user's choice on the menu
    string choice;

    while (true)
    {
        // Print out the options to the user
        cout << "These are your options: " << endl;
        cout << "A) Highest of three numbers" << endl;
        cout << "S) Reverse a number" << endl;
        cout << "D) Calculate Parking Garage Charges" << endl;
        cout << "F) Exit" << endl;
        cout << "Type in the associated letter of your choice (case sensitive): ";
        cin >> choice;

        // String of the choices in the menu
        string answer_string = "ASDF";

        // Check if the user's answer is one of the options on the menu
        if (answer_string.find(choice) != string::npos)
        {
            break;
        }

        else
        {
            cout << endl << "You did not enter a valid input" << endl << endl;
        }
    }

    // Check if the user chose Highest of Three Numbers
    if (choice == "A")
    {
        int largest_num = highest_num();
        cout << "Highest of the three numbers: " << largest_num << endl;
    }

    // Check if the user chose Reverse a Number
    if (choice == "S")
    {
        string reversed_num = reverse_num();
        cout << "Reversed number: " << reversed_num << endl;
    }

    // Check if the user chose Parking Garage Charges
    if (choice == "D")
    {
        // The amount of hours that the user stayed at the parking garage
        int hours = 0;

        while (true)
        {
            cout << "Type in the number of hours you stayed at the parking garage. It has a maximum of 24 hours: ";
            cin >> hours;

            // Check if the user stayed for more than 24 hours
            if (hours > 24)
            {
                cout << "The number of hours cannot exceed 24" << endl;
            }

            break;
        }

        // Calculate the amount of charges owed by the user
        garage_charges(hours);
    }

    // Check if the user chose to exit the program
    if (choice == "F")
    {
        cout << "You exited the program" << endl;
        return 0;
    }

    return 0;
}
