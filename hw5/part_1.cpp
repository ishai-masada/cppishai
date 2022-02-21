/* Ishai Masada
 * Average of five numbers */

#include <iostream>

using namespace std;

float num_1 = 0, num_2 = 0, num_3 = 0, num_4 = 0, num_5 = 0;
float average = 0;

void get_numbers()
{
    cout << "Type in the first number: " << endl;
    cin >> num_1;
    cout << "Type in the second number: " << endl;
    cin >> num_2;
    cout << "Type in the third number: " << endl;
    cin >> num_3;
    cout << "Type in the fourth number: " << endl;
    cin >> num_4;
    cout << "Type in the fifth number: " << endl;
    cin >> num_5;
}

void calculate_average(float num_1, float num_2, float num_3, float num_4,
                        float num_5)
{
    average = (num_1 + num_2 + num_3 + num_4 + num_5) / 5;
}

void print_result(float average)
{
    cout << endl << "Average of the five numbers: " << average << endl;
}

int main()
{
    get_numbers();
    calculate_average(num_1, num_2, num_3, num_4, num_5);
    print_result(average);

    return 0;
}
