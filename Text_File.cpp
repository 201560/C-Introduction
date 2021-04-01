#include <iostream>
#include <fstream>
using namespace std;
int main() {
	string input;
	cout << "What do you want to put in the text file?" << endl << "Type EXIT on a new line to close" << endl;
	ofstream file;
        file.open("Text.txt", ios_base :: app);
	while (input!="EXIT") {
		getline (cin, input);
		if (input != "EXIT") {
			file << input << " ";
		}
	}
	file.close();
}
