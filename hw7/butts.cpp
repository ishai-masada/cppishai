#include <iostream>

using namespace std;

/* int add_one(int num_1, int num_2) */
/* { */
/*     num_1 += 1; */
/*     num_2 += 1; */

/*     return num_1, num_2; */
/* } */

int main()
{
    int num_one = 0;
    int num_two = 0;
    cout << "Type in a number: ";
    cin >> num_one;
    cout << num_one << endl;
    if (isdigit((char) num_one))
    {
        cout << "Num one is 0" << endl;
    }
    cout << "Type in a number: ";
    cin >> num_one;
    cout << num_one << endl;
    cout << "Type in a number: ";
    cin >> num_one;
    cout << num_one << endl;

    return 0;
}
