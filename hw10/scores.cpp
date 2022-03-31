#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>

using namespace std;

bool is_number(string value)
{
    for (int i = 0; i < value.length(); i++)
    {
        if (isdigit(value[i]) == false)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int ARRAY_SIZE = 12;
    string scores[ARRAY_SIZE];
    string input_data[ARRAY_SIZE];

    ifstream istream;
    ofstream ostream;

    // Initialize the Input stream with the data text file
    istream.open("StudentScores.txt");

    // Check if the file fails to open
    if (istream.fail())
    {
        cout << "File openning failed\n";
        exit(1);
    }

    int sum = 0;
    int count = 0;
    double average = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        getline(istream, input_data[i], ' ');
        if (istream.eof())
        {
            istream.close();
            break;
        }
    }

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << "Value: " << input_data[i] << endl << "Bool: "
             << is_number(input_data[i]) << endl;
    }

    /* sum += stoi(input_data[i]); */
    /* count += 1; */
    /* average = sum / count; */
    /* cout << "Average: " << average << endl; */

   return 0;
}
