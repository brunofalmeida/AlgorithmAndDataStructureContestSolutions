/* C++ - Common Problems */




#include <iostream>
using namespace std;

int main() {
	
	/* 1. File Submission */
	
	// When you submit your code, you must submit the main.cpp file only or copy/paste the main.cpp code,
	// NOT submit the project folder
	
	
	
	
	/* 2. Newline Characters */
	
	// Most problems will ask you to output values on separate lines,
	// so remember to use endl or \n to move the following output to the next line
	
	// Example: You need to output 1 and 2 on separate lines
	
	// bad (will output "12")
	cout << 1;
	cout << 2;
	
	// good (will output "1" and "2" on separate lines)
	cout << 1 << endl;
	cout << 2 << endl;
	
	
	
	
	/* 3. Outputting Spaces */
	
	// Some problems will ask you to output 2 numbers on the same line, separated by a space
	// You can use one cout statement, but remember to add a space string in between
	
	// Example: You need to output "1 2" (with a space between the numbers)
	
	// bad (will output "12")
	cout << 1 << 2 << endl;
	
	// good (will output "1 2")
	// (normally you would output variables instead of 1 and 2)
	cout << 1 << " " << 2 << endl;
	
	
	
	
	/* 4. Inputting Strings with Spaces */
	
	// Sometimes, you need to input an entire line (with spaces) as a single string
	
	// By default, cin only inputs data until it finds a space
	// Remember to use getline() to input a string with spaces!
	
	// 2 parameters to getline():
	// first  - the input stream (cin)
	// second - the variable to input data to
	
	// Example: The input is "Programming is cool!" - includes spaces!
	
	// Declare a string variable to hold the data
	string inputStr;
	
	// Input the whole line from cin into the string variable
	getline(cin, inputStr);
	
	


    return 0;
}
