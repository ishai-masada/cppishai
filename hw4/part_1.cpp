/*Ishai Masada
 * Print out the numbers from 19 to 65 except for 46 */

#include <iostream>

using namespace std;

int main()
{
    // Counts from 19 to 65. Excludes 46
    for (int i=19; i < 66; i++)
    {
        if (i == 46)
        {
            continue;
        }
        // Prints the number
        printf("%d\n", i);
    }
}
