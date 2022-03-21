#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

float avg(vector<int> scores)
{
    float sum = 0;
    for (int i = 0; i < scores.size(); i++)
    {
        sum += scores[i];
    }

    return sum / scores.size();
}

float var(vector<int> scores)
{
    float average = avg(scores);

    float sum = 0;

    for (int i = 0; i < scores.size(); i++)
    {
        sum += pow(scores[i] - average, 2);
    }

    return sum / scores.size();
}

vector<int> input_numbers(vector<int> scores, ifstream& istream)
{
    int num_1, num_2, num_3, num_4;

    istream >> num_1 >> num_2 >> num_3 >> num_4;
    istream.close();

    scores.push_back(num_1);
    scores.push_back(num_2);
    scores.push_back(num_3);
    scores.push_back(num_4);

    return scores;
}

int main()
{
    ifstream istream;
    ofstream ostream;

    vector<int> scores;

    ostream.open("data.txt");
    if (ostream.fail())
    {
        cout << "File openning failed\n";
        exit(1);
    }
    ostream << 1 + (rand() % 100) << '\n' << 1 + (rand() % 100) << '\n'
            << 1 + (rand() % 100) << '\n' << 1 + (rand() % 100);
    ostream.close();

    istream.open("data.txt");
    if (istream.fail())
    {
        cout << "File openning failed\n";
        exit(1);
    }

    scores = input_numbers(scores, istream);

    float variance = var(scores);

    cout << "Standard Deviation: " << sqrt(variance)<< endl;

    return 0;
}
