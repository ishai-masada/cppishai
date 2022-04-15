#include <iostream>
#include <map>

using namespace std;

void display_money(int numbers[], int ARRAY_SIZE, bool& success)
{
    // Iterate over the numbers array
    for (int i = 0; i < ARRAY_SIZE; i += 2)
    {
        // Check if "i" has incremented beyond the size of the array
        if (i > ARRAY_SIZE)
        {
            success = true;
            cout << "The program was successful!" << endl;
            return;
        }

        cout << "Amount: $" << numbers[i] << '.' << numbers[i + 1] << endl;

    }
}

int main()
{
    const int ARRAY_SIZE = 10;
    bool success = false;

    // Money values in dollar-cent pairs
    int numbers[ARRAY_SIZE] = {10, 30, 67, 82, 89, 10, 98, 40, 10000, 78};

    // Display the numbers in USD format
    display_money(numbers, ARRAY_SIZE, success);

    return 0;
}
