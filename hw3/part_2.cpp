#include <iostream>

using namespace std;

int main()
{
    char super_premium[50] = "\"Super Premium\"";
    char premium[50] = "\"Premium\"";
    char normal[50] = "\"Normal Quality\"";
    char low_quality[50] = "\"Not so great\"";

    // Get the percent of fat in the user's dog food
    int percent_fat;
    cout << "Type in the percent of fat in your dog food: ";
    cin >> percent_fat;

    // Get the percent of protein in the user's dog food
    int percent_protein;
    cout << "Type in the percent of protein in your dog food: ";
    cin >> percent_protein;

    /* Check if the fat percentage is less than 18 and the protein percentage
     * is greater than 23*/
    if (percent_fat < 18 and percent_protein > 23)
    {
        printf("Your dog food is a %s quality dog food", super_premium);
        cout << endl;
        return 0;
    }

    /* Check if the fat percentage is less than 20 and the protein percentage
     * is greater than 20*/
    if (percent_fat < 20 and percent_protein > 20)
    {
        printf("Your dog food is a %s quality dog food", premium);
        cout << endl;
        return 0;
    }

    /* Check if the fat percentage is less than 25 and the protein percentage
     * is greater than 16*/
    if (percent_fat < 25 and percent_protein > 16)
    {
        printf("Your dog food is a %s quality dog food", normal);
        cout << endl;
        return 0;
    }

    /* Check if the fat percentage is less than 40 and the protein percentage
     * is greater than 8*/
    if (percent_fat < 40 and percent_protein > 8)
    {
        printf("Your dog food is a %s quality dog food", low_quality);
        cout << endl;
        return 0;
    }

    else
    {
        cout << "Your dog food is unclassified" << endl;
    }

    return 0;
}
