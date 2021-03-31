#include <iostream>
using namespace std;
int main() {
        int number;
        int guess;
        int play;
        int new_game;
        new_game = 1;
        while (new_game == 1) {
                srand(time(0));
                number = rand() % 10 + 1;
                play = 1;
                while (play == 1) {
                        cout << "Guess my favorite number.  Hint: it is from 1-10." << endl;
                        cin >> guess;
                        if (number == guess) {
                                cout << "Correct!" << endl;
                                play = 0;
                        }
                        if (number >  guess) {
                                cout << "Incorrect.  The number is greater than your guess." << endl << "Do you want to guess again? (Enter $
                                cin >> play;
                        }
                        if (number < guess) {
                                cout << "Incorrect.  The number is less than your guess." << endl << "Do you want to guess again? (Enter 1 f$
                                cin >> play;
                        }
                }
                cout << "My favorite number is " << number << " and you guessed " << guess << "." << endl << "Do you want to play again with$
                cin >> new_game;
        }
        return 0;
