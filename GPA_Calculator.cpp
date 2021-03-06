#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
int main () {
	int type = 2;
	while (type != 0 and type!= 1)  {
		cout << "Do you want to manually enter the grades or use a text file?  Type 0 for manually and 1 for text file." << endl;
		cin >> type;
		if (type != 0 and type!= 1) {
			cout << "Invalid number, try again." << endl;
		}
	}
	if (type == 0) {
		cout << "For each class, please input the level and letter grade recieved." << endl << "Enter AP+ for advanced placement plus classes, AP for advanced placement classes, H for honors classes, CP for college prep and career prep classes." << endl;
		cout << "How many classes do you want to enter?" << endl;
		int classes = 0;
		cin >> classes;
		string levels[classes];
		string grades[classes];
		for (int i=0; i < classes; i++) {
			while (levels[i] != "AP+" and levels[i] != "AP" and levels[i] != "H" and levels[i] != "CP" or grades[i] != "A" and grades[i] != "B" and grades[i] != "C" and grades[i] != "D" and grades[i] != "F") { 
				cout << "Enter the class level. (Class number " << i+1 << ") (AP+ = advanced placement, AP = advanced placement, H = honors, CP = college prep/career prep)" << endl;
				cin >> levels[i];
				cout << "Enter the letter grade recieved in that class level (use capital letters)."  << endl;
				cin >> grades[i];
				if (levels[i] != "AP+" and levels[i] != "AP" and levels[i] != "H" and levels[i] != "CP" or grades[i] != "A" and grades[i] != "B" and grades[i] != "C" and grades[i] != "D" and grades[i] != "F") {
					cout << "Invalid input.  Try again." << endl;
				}
			}
		}
		float total = 0;
		float possible = 0;
		for (int i=0; i < classes; i++) {
			if (levels[i] == "AP+") {
				possible = 5.5;
			}
			if (levels[i] == "AP") {
				possible = 5;
			}
		 	if (levels[i] == "H") {
                        	possible = 4.5;
                	}
                	if (levels[i] == "CP") {
                        	possible = 4;
                	}
			if (grades[i] == "A") {
				total += possible;
			}
			if (grades[i] == "B") {
                        	total += possible - 1;
			}
			if (grades[i] == "C") {
                        	total += possible - 2;
 			}
			if (grades[i] == "D") {
                        	total += possible - 3;
			}
			if (grades[i] == "F") {
                        	total += 0;
			}
		}
		float gpa = total/classes;
		cout << "Your gpa is " << gpa << "." << endl;
	}
	if (type == 1) {
		ifstream file("gpa.txt");
		stringstream buffer;
		buffer << file.rdbuf();
		string file_text = buffer.str();
		file.close();
		size_t position1 = 0;
		size_t position2;


		int number_of_spaces = 0;
		for (int i = 0; i < file_text.length(); i++) {
			if (file_text[i] == ' ') {
			number_of_spaces++;
			}
		}
		string levels[number_of_spaces];
		string grades[number_of_spaces];
		for (int i = 0; i < number_of_spaces; i++) {
			position2 = file_text.find(" ", position1);
			levels[i] = file_text.substr(position1, (position2 -position1));
			position1 = position2 + 1;
			position2 = file_text.find("\n", position1);
                        grades[i] = file_text.substr(position1, (position2 -position1));
                        position1 = position2 + 1;
		}

		float total = 0;
		float possible = 0;
		for (int i=0; i < number_of_spaces; i++) {
			if (levels[i] == "AP+") {
				possible = 5.5;
			}
			if (levels[i] == "AP") {
				possible = 5;
			}
			if (levels[i] == "H") {
                        	possible = 4.5;
                	}
                	if (levels[i] == "CP") {
                        	possible = 4;
                	}
			if (grades[i] == "A") {
				total += possible;
			}
			if (grades[i] == "B") {
                        	total += possible - 1;
			}
			if (grades[i] == "C") {
                        	total += possible - 2;
 			}
			if (grades[i] == "D") {
                        	total += possible - 3;
			}
			if (grades[i] == "F") {
                        	total += 0;
			}
		}
		float gpa = total/number_of_spaces;
		cout << "The program will only work if the file is named gpa.txt.  If it is not, please change it now and run the program again." << endl;
		cout << "Your gpa is " << gpa << "." << endl;
	}
	return 0;
}
