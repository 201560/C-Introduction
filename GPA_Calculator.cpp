#include <iostream>
using namespace std;
int main () {
	int classes = 0;
	cout << "For each class, please input the level and letter grade recieved." << endl << "Enter AP+ for advanced placement plus classes, AP for advanced placement classes, H for honors classes, CP for college prep and career prep classes." << endl;
	cout << "How many classes do you want to enter?" << endl;
	cin >> classes;
	string levels[classes];
	string grades[classes];
	for (int i=0; i < classes; i++) {
		cout << "Enter the class level. (Class number " << i+1 << ") (AP+ = advanced placement, AP = advanced placement, H = honors, CP = college prep/career prep)" << endl;
		cin >> levels[i];
		cout << "Enter the letter grade recieved in that class level (use capital letters)."  << endl;
		cin >> grades[i];
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
	return 0;
}
