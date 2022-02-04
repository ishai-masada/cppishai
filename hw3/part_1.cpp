#include <iostream>

using namespace std;

int main()
{
    int first_num = cin >> "Type in the first number: " >> endl;
    int second_num = cin >> "Type in the second number: " >> endl;

    if (second_num != 0)
    {
        int sum = first_num + second_num;
        cout << "Sum of the two numbers: " << sum << endl;
    }
    else
    {
        cout << "You cannot divide any number by 0." << endl;
    }

    int difference = first_num - second_num;
    cout << "Difference of the two numbers: " << difference << endl;

    int quotient = first_num / second_num;
    cout << "Quotient of the two numbers: " << quotient << endl;

    int product = first_num * second_nim;
    cout << "Product of the two numbers: " << product << endl;

    return 0;
}
