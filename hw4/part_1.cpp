#include <iostream>

using namespace std;

int main()
{
    for (int i=19; i < 66; i++)
    {
        if (i == 46)
        {
            continue;
        }
        printf("%d\n", i);
    }
}
