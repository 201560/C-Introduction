#include <iostream>
using namespace std;
int main () {
        float fahrenheit;
        float celsius;
        fahrenheit = 0;
        celsius = 0;
        cout << "Enter the temperature in fahrenheit." << endl;
        cin >> fahrenheit;
        celsius = (fahrenheit - 32)*5/9;
        cout << "The temperature is " << celsius << " degrees celsius." << endl;
        return 0;
}
