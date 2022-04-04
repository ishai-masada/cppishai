#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

// Checks if string is a number
bool is_number(string word)
{
    // Loop over word
    for (int i = 0; i < word.size(); i++)
    {
        // Checks if each character is a number
        if (isdigit(word[i]) == false)
        {
            return false;
        }
    }

    return true;
}

// Returns the average given the sum and the numebr of values
double avg(int sum, int num_of_values)
{
    return sum / num_of_values;
}

// Calculates the average scores of each student
vector<int> get_averages(vector<int> averages, vector<string> sentences)
{
    int NUM_OF_SCORES = 10;

    // Template word
    string word;

    int sum = 0;
    int counter = 0;

    // Iterates over each sentence in the input data vector
    for (int i = 0; i < sentences.size(); i++)
    {
        // Creates a string stream object out of each sentence
        istringstream string_obj(sentences[i]);

        // Keeps going until there aren't any words left
        while (string_obj >> word)
        {
            // Checks if the word is a number
            if (is_number(word))
            {
                counter += 1;
                sum += stoi(word);

                // Checks if this is the last score for the student
                if (counter >= NUM_OF_SCORES)
                {
                    averages.push_back(avg(sum, NUM_OF_SCORES));
                    sum = 0;
                    counter = 0;
                }
            }
        }
    }

    return averages;
}

// Displays the average scores for each student
void display(vector<int> averages)
{
    // Loops over the averages vector
    for (int i = 0; i < averages.size(); i++)
    {
        cout << "Average: " << averages[i] << endl;
    }
}

// Handles file streams and displays the average scores
void calculate_avg_scores(vector<int> averages)
{
    ifstream istream;
    ofstream ostream;
    vector<string> input_data;

    // Initialize the Input stream with the data text file
    istream.open("StudentScores.txt");

    // Check if the file fails to open
    if (istream.fail())
    {
        cout << "File openning failed\n";
        exit(1);
    }

    while (istream)
    {
        string line;
        getline(istream, line);
        input_data.push_back(line);
        if (istream.eof())
        {
            istream.close();
            break;
        }
    }

    // Initialize the Input stream with the data text file
    ostream.open("StudentScores.txt");

    // Check if the file fails to open
    if (ostream.fail())
    {
        cout << "File openning failed\n";
        exit(1);
    }

    averages = get_averages(averages, input_data);
    display(averages);

    for (int i = 0; i < averages.size(); i++)
    {
        ostream << input_data[i]<< " " << averages[i] << endl;
    }

    ostream.close();
}

int main()
{
    vector<string> scores;
    vector<string> words;
    vector<int> averages;
    string choice;


    // Prompt the user for their choice
    cout << "Would you like to calculate the averages of the students' scores?"
         << "(\"Yes\" or \"No\"): "<< endl;
    cin >> choice;

    while (true)
    {
        // Checks if the user wants to end the program
        if (choice == "No")
        {
            cout << "Ending program." << endl;
            return 0;
        }

        // Checks if the user wants to continue
        else if (choice == "Yes")
        {
            break;
        }

        else
        {
            cout << "You did not enter a valid response." << endl;
        }

        // Prompt the user
        cout << "Would you like to calculate the averages of the students' scores?"
             << "(\"Yes\" or \"No\"): "<< endl;
        cin >> choice;
    }

    calculate_avg_scores(averages);

   return 0;
}
