// COMP218
// Danil Ulmashev
//
// A C++ program that reads the characters from the file and sorts them out by the amount of 
// the digits, upper case letters, lower case lettes, blanc spaces and all other remaining 
// characters. The program outputs three diffrent messages accoridng to the file status - 
// if file does not exist, if file is empty and if file exists and contains characters.
// The amount of characters in file is expressed in numerical values and their corresponding 
// percentages.



// Adding libraries
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// declaring functions
void printHeader();
void readFromFile();
double percentage(int a, int b);
void messageThankYou() ;
void printStats();
void resetStats();

// Declaring the couters.
int total = 0, upperCase = 0, lowerCase = 0, digits = 0, whiteSpace = 0, otherCharacters = 0;

// Main function
int main() {
	printHeader();
	readFromFile();
	return 0;
}

// Printing the header
void printHeader() {
    string a = "¦";
    cout << "-a-b-c-d-e-f-g-1-2-3-2-1-G-F-E-D-C-B-A-" << endl;
    cout << a << "                                     " << a << endl;
    cout << a << "       Nancy's Character Counter     " << a << endl;
    cout << a << "                                     " << a << endl;
    cout << "--*-&-^-%-$-#-@-!-?-/->-<-=-[-]-{-}-'--" << endl << endl;
}


// Reading from file and counting characters.
void readFromFile() {
	// Opening the file
	ifstream fin;
	fin.open("A3Q1.dat");

	// Checking if file exists
	if (!fin) {
		cout << "Sorry, Could not open file. Program ending ... \n" << endl;
		exit(1); // terminate with error
	}
	else {
		cout << "Characters from file are: " << endl;
		resetStats();

		// Reading the characters
		while (!fin.eof()) {
			char ch;
			fin.get(ch);
			
			// Counting the characters
			if (ch != 0) {
				total++;
			}
			if (ch >= 'A' && ch <= 'Z') {
				upperCase++;
			}
			else if (ch >= 'a' && ch <= 'z') {
				lowerCase++;
			}
			else if (ch >= '0' && ch <= '9') {
				digits++;
			}
			else if (ch == ' ' || ch == '\t') {
				whiteSpace++;
			}
			else {
				otherCharacters++;
			}

			// Printing characters on the screen
			cout << "  " << ch;
			if (total % 10 == 0) {
				cout << endl;
			}
		}

		// Closing the file
		
        
        

		// Checking if the file was empty
		if (total == 0) {
			cout << "The file existed but was empty. Strange ... \n" << endl;
			messageThankYou();
			exit(1); // terminate with error
		}

		// Printing the statis
		printStats();
		// Print message Thank you 
		messageThankYou();
    }
}

// Calculating the percentage
double percentage(int a, int b) {
	return ((double)a / (double)b) * 100.00; 
}

// Declaring the printStats function
void printStats() {
	cout << endl << "There is a total of " << total << " characters in the data file" << endl;
	cout << "Here is the breakdown: \n";
	cout << "          The number of digits characters is " << digits << " <" << setprecision(4) << percentage(digits, total) << " of total characters>" << endl;
	cout << "          The number of uppercase characters is " << upperCase << " <" << setprecision(4) << percentage(upperCase, total) << " of total characters>" << endl;
	cout << "          The number of lowercase characters is " << lowerCase << " <" << setprecision(4) << percentage(lowerCase, total) << " of total characters>" << endl;
	cout << "          The number of white space characters is " << whiteSpace << " <" << setprecision(4) << percentage(whiteSpace, total) << " of total characters>" << endl;
	cout << "          The number of othe characters is " << otherCharacters << " <" << setprecision(4) << percentage(otherCharacters, total) << " of total characters>" << endl;
	cout << endl;
}

// Declaring the messageThankYou function
void messageThankYou() {
	cout << "Thank you for using the Character Manipulator ... " << endl;
}

// Declaring function resteStats.
void resetStats() {
	total = 0;
	upperCase = 0;
	lowerCase = 0;
	digits = 0;
	whiteSpace = 0;
	otherCharacters = 0;
}
