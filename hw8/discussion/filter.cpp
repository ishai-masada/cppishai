/* Ishai Masada
 * Call-by-Reference Function */

#include <iostream>
#include <vector>

using namespace std;

// Displays the vector
void display_vect(vector<int> nums)
{
    // Iterate through each element in the vector
    for (auto i = nums.begin(); i < nums.end(); i++)
    {
        cout << *i << endl;
    }

    return;
}

// Filters out all of the numbers that are greater than 5
void filter(vector<int>& nums)
{
    // Applies condition to each element in the vector
    for (auto i = nums.begin(); i < nums.end(); i++)
    {
        if (nums[*i] > 5)
        {
            nums.erase(i);
            i--;
        }
    }

    return;
}

int main()
{
    // Vector to be changed
    vector<int> nums;

    // Initiating the value of the vector (1 through 9)
    for (int i=0; i < 10; i++)
    {
        nums.push_back(i);
    }

    filter(nums);
    display_vect(nums);

    return 0;
}
