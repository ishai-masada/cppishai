#include <iostream>
#include <sstream>

using namespace std;

void input_number(int& number)
{
    cout << "Type in a number: ";
    cin >> number;

    number -= 10;
}

bool is_number(string num)
{
    for (int i; i < num.size(); i++)
    {
        if (isdigit(num[i]) == false)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int dudu = 0;
    string butts;

    cout << "Press enter: " << endl;
    getline(cin, butts);
    cout << butts.length() << endl;


    return 0;
}
