#include <iostream>

using namespace std;

int get_damage()
{
    int damage = 0;
    cout << "Type in the amount of damage the player will take: ";
    cin >> damage;

    return damage;
}

int damage_player(int damage, int& player_health)
{
    player_health -= damage;

    return 0;
}

int main()
{
    int player_health = 100;
    cout << "Current player's health: " << player_health << endl;
    int damage = get_damage();
    damage_player(damage, player_health);

    cout << "Player's health after taking damage: " << player_health << endl;

    return 0;
}
