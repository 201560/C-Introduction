#include <iostream>
using namespace std;
int main () {
	cout << "You have been given 100 units of knights." << endl << "There are 10 castles to fight for, player 1 and player 2 in a fight to the death." << endl << "Whichever player has more knights at a castle wins, and a tie nobody wins." << endl;
	int castle = 1;
	int player1[10];
	int player2[10];
	int number = 0;
	int total = 0;
	int old_total = 0;
	for (int i = 1; i <= 10; i++) {
		cout << "Player 1 enter your knights." << endl;
		castle = i;
		cout << "How many knights do you want to send to castle " << castle << "?" << endl;
		cin >> number;
		player1[i-1] = number;
		total = total + number;
		while (total > 100) {
			cout << "Invalid amount of knights.  Try again." << endl;
			cout << "How many knights do you want to send to castle " << castle << "?" << endl;
			cin >> number;
                	player1[i-1] = number;
                	total = old_total + number;
		}
		old_total = total;
		cout << "You have allocated " << total << " knights.  You have " << 100-total  << " left." << endl;
	}
	cout << "Player 2 enter your knights." << endl;
	total = 0;
	old_total = 0;
	for (int i = 1; i <= 10; i++) {
                castle = i;
		cout << "How many knights do you want to send to castle " << castle << "?" << endl;
                cin >> number;
                player2[i-1] = number;
                total = total + number;
                while (total > 100) {
                        cout << "Invalid amount of knights.  Try again." << endl;
                        cout << "How many knights do you want to send to castle " << castle << "?" << endl;
                        cin >> number;
                        player2[i-1] = number;
                        total = old_total + number;
                }
                old_total = total;
                cout << "You have allocated " << total << " knights.  You have " << 100-total  << " left." << endl;
        }


	int player1_score = 0;
	int player2_score = 0;
	for (int i; i<=9; i++) {
		if (player1[i]>player2[i]) {
			player1_score++;
		}
		if (player1[i]<player2[i]) {
			player2_score++;
		}
	}
	if (player1_score>player2_score) {
		cout << "Player 1 won!" << endl;
	}
	if (player1_score<player2_score) {
		cout << "Player 2 won!" << endl;
	}
	if (player1_score==player2_score) {
		cout << "Tie" << endl;
	}
	cout << "The score was:" << endl << "Player 1: " << player1_score << endl << "Player 2: " << player2_score << endl;
	cout << "The breakdown:" << endl;
	for (int i=0; i<=9; i++) {
		cout << "Castle " << i + 1 << ":" << "Player 1:" <<  player1[i] << " Player 2:" << player2[i] << endl;
	}
}
