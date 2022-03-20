#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

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

int main()
{
    vector<int> scores;

    for (int i = 0; i < 4; i++)
    {
        scores.push_back(1 + (rand() % 100));
    }

    float variance = var(scores);

    cout << "Standard Deviation: " << sqrt(variance)<< endl;

    return 0;
}
