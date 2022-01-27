/* Ishai Masada
 * Fahrenheit and Celsius Conversions */

#include <iostream>
using namespace std;

// Converts temperature from Celsius to Fahrenheit
int f2c(int temp)
{
    return (temp - 32) * (5.0/9.0);
}

// Converts temperature from Fahrenheit to Celsius
int c2f(int temp)
{
    return (temp * 1.8) + 32;
}

int main()
{
    // Initial Temperature
    int temperature = 55;
    std::cout << "Temperature in Celsius: ";
    std::cout << temperature << endl;

    // Celsius to Fahrenheit
    std::cout << "Celsius to Fahrenheit: ";
    // The new temperature after it's been converted to Faherenheit
    int f_temp = c2f(temperature);
    std::cout << f_temp << endl;

    // Fahrenheit to Celsius
    std::cout << "Fahrenheit to Celsius: ";
    // The new temperature after it's been converted to Celsius
    int c_temp = f2c(f_temp);
    std::cout << c_temp << endl;
}
