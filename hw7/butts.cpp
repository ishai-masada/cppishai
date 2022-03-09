#include <iostream>

using namespace std;

int add_one(int num_1, int num_2)
{
    num_1 += 1;
    num_2 += 1;

    return num_1, num_2;
}

int main()
{
    int num_one = 0;
    int num_two = 0;
    cout << "Type enter: ";
    cin >> num_one;
    cout << num_one << endl;

    return 0;
}
