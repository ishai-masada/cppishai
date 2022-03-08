#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> hydra_heads;
    for (int i = 0; i < 10; i++)
    {
        hydra_heads.insert(hydra_heads.end(), 1);
        hydra_heads.insert(hydra_heads.end(), 1);
    }

    cout << hydra_heads.size() << endl;

    return 0;
}
