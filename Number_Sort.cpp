#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
int main() {
	ifstream file("list10k.txt"); //sets a string (file_text) to the text from the file.
	stringstream buffer;
	buffer << file.rdbuf();
	string file_text = buffer.str();
	file.close();

	int number_of_spaces = 0; //counts the amount of spaces in the file.

	for (int i = 0; i < file_text.length(); i++) {
		if (file_text[i] == ' ') {
			number_of_spaces++;
		}
	}

	string string_array[number_of_spaces - 1]; //string array with length based on number_of_spaces.
	size_t position1 = 0;
	size_t position2;

	for (int i = 0; i <= number_of_spaces - 2; i++) { //divides the file text into each number and sets each term in string_array to a number.
		position2 = file_text.find(" ", position1);
		string_array[i] = file_text.substr(position1, (position2 -position1));
		position1 = position2 + 1;
	}

	int integer_array[number_of_spaces - 1]; //integer array with length based on number_of_spaces.

	for (int i = 0; i <= number_of_spaces - 2; i++) { //converts string from string_array to integers in integer_array.
		integer_array[i] = stoi(string_array[i]);
	}


	int index_of_swap_possible_number = 0; //defining variables in preperation of the sorting algorithm.
	int maximum_of_values_after_index_value = 0;
	int current_maximum = 0;
	int secondary_index = 0;
	int index_of_largest_value_after_intial_index = 0;

	for (int index_of_swap_possible_number = 0; index_of_swap_possible_number <= number_of_spaces - 3; index_of_swap_possible_number++) { //algorithm to sort the integer_array.
		secondary_index = index_of_swap_possible_number + 2;
		maximum_of_values_after_index_value = integer_array[index_of_swap_possible_number + 1];
		index_of_largest_value_after_intial_index = index_of_swap_possible_number + 1;

		while (secondary_index <= number_of_spaces - 2) {
			current_maximum = integer_array[secondary_index];

			if (current_maximum > maximum_of_values_after_index_value) {
				maximum_of_values_after_index_value = current_maximum;
				index_of_largest_value_after_intial_index = secondary_index;
			}
			secondary_index++;
		}

		if (integer_array[index_of_swap_possible_number] < integer_array[index_of_largest_value_after_intial_index]) {
			swap(integer_array[index_of_swap_possible_number], integer_array[index_of_largest_value_after_intial_index]);
		}
	}

	for (int i = 0; i <= number_of_spaces - 2; i++) { //prints the sorted integer_array.
		cout << integer_array[i] << " ";
	}
	cout << endl;
	return 0;
}
