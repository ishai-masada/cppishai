#include <iostream>

using namespace std;

int main()
{
    int num_of_guests = 0;
    cout << "Type in the number of guests that will attend the wedding: "
         << endl;
    cin >> num_of_guests;

    if (num_of_guests <= 100)
    {
        cout << "You can fit the guests into the smaller dining room!" << endl;
    }

    if (num_of_guests > 100)
    {
        cout << "You will need to use the larger dining room!" << endl;
    }

    return 0;
}
