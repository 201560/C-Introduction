#include <iostream>
using namespace std;
int main() {
        string input;
        string output;
        cin >> input;
        output = input;
        for (int i = 0; i < input.length(); i++) {
                 output[i] = input[input.length() - 1 - i];
        }
        cout << output << endl;
}
