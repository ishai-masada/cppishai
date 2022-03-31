#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream istream;

    // Initialize the Input stream with the data text file
    istream.open("input.txt");

    // Check if the file fails to open
    if (istream.fail())
    {
        cout << "File openning failed\n";
        exit(1);
    }

    string sentence;
    getline(istream, sentence);
    istream.close();

    cout << "Sentence: " << sentence << endl;

    int count = 0;

    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] == 'a')
        {
            count += 1;
        }
    }

    ofstream ostream;

    ostream.open("output.txt");

    // Check if the file fails to open
    if (ostream.fail())
    {
        cout << "File openning failed\n";
        exit(1);
    }
    ostream << "The letter \"A\" was used " << count << " time(s)" << endl;
    ostream.close();

    istream.open("output.txt");

    if (istream.fail())
    {
        cout << "File openning failed\n";
        exit(1);
    }

    string new_sentence;
    getline(istream, new_sentence);
    istream.close();

    cout << new_sentence << endl;
    return 0;
}
