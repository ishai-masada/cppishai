#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

// Calculates the average of a sequence of values
float avg(vector<int> scores)
{
    float sum = 0;

    // Iterate over the vector of scores
    for (int i = 0; i < scores.size(); i++)
    {
        // Add up the scores
        sum += scores[i];
    }

    // Return the sum of the scores divided by the number of scores there are
    return sum / scores.size();
}
set
// Calculates the variance of a sequence of values
float var(vector<int> scores)
{
    // Get the average of the scores
    float average = avg(scores);

    float sum = 0;

    // Iterate over the vector of scores
    for (int i = 0; i < scores.size(); i++)
    {
        // Square the difference of each score and the average score
        sum += pow(scores[i] - average, 2);
    }

    // Return the sum divided by the number of scores there are
    return sum / scores.size();
}

vector<int> input_numbers(vector<int> scores, ifstream& istream)
{
    int num_1, num_2, num_3, num_4;

    // Input values from the input stream
    istream >> num_1 >> num_2 >> num_3 >> num_4;

    // Close the file
    istream.close();

    // Put all of the data from the file into the vector of scores
    scores.push_back(num_1);
    scores.push_back(num_2);
    scores.push_back(num_3);
    scores.push_back(num_4);

    return scores;
}

float std_dev(vector<int>& scores, ifstream& istream )
{
    // Store the scores into a vector
    scores = input_numbers(scores, istream);

    // Calculate the variance of the scores
    float variance = var(scores);

    // Return the square root of the variance of the scores
    return sqrt(variance);
}

int main()
{
    // Input and Output streams
    ifstream istream;
    ofstream ostream;

    vector<int> scores;

    // Initialize the Output stream with the data text file
    ostream.open("data.txt");

    // Check if the file fails to open
    if (ostream.fail())
    {
        cout << "File openning failed\n";
        exit(1);
    }

    // Put four random numbers into the data text file
    ostream << 1 + (rand() % 100) << '\n' << 1 + (rand() % 100) << '\n'
            << 1 + (rand() % 100) << '\n' << 1 + (rand() % 100);

    // Close the file
    ostream.close();

    // Initialize the Input stream with the data text file
    istream.open("data.txt");

    // Check if the file fails to open
    if (istream.fail())
    {
        cout << "File openning failed\n";
        exit(1);
    }

    // Get the standard deviation
    float std_deviation = std_dev(scores, istream);

    cout << "Standard Deviation: " << std_deviation << endl;

    return 0;
}
