/*
Jazmin Even Dorra

cinephiles.cpp

This program will ask user for file containing the amount of movies seen by students in different faculties,
display the number of movies seen by number of students, and display the average movies seen.


*/


// Header Files
#include <iostream>
#include <string>
#include <fstream>
#include "arrUtils.h"
using namespace std;


int main()
{
	// Variables
	string filename;
	int* movies;					// Array

	char tryAgain = 'y';			// Loop controller

	string college,					// Name of college variable from file
		pathway;					// Pathway from file
	int size;						// Size (n) varible from file

	// Intro
	cout << "College Cinephiles Pathway Stats ...\n\n";

	while (tolower(tryAgain) == 'y')
	{
		// Prompt user for name of file 
		cout << "Please Enter Pathway File Name: ";
		cin >> filename;

		int* movies = nullptr;

		loadArray(movies, filename, size, college, pathway);	// Load array

		// Deallocate the array of integers
		delete[] movies;
		movies = nullptr;
		
		// Check for another file
		cout << "\nDo you have another file? (y/n) ";
		cin >> tryAgain;
	}
	
	return 0;
}


/*
	void loadArray(int* intPtr, string filename, int& size)

	Loads contents of the file filename into the array pointed to by intPtr.
	Loads file contents into pointer array
	Display contents of array
	Display average

	Return Value: None
*/
void loadArray(int* intPtr, string filename, int& size, string& college, string& pathway)
{

	int total = 0,				// Accumulator
		average;				// To hold the average movies seen
	
	ifstream inFile;

	// Open file
	inFile.open(filename);

	// Read the college
	getline(inFile, college);

	// Read the pathway
	getline(inFile, pathway);

	//read the number of students (n)
	inFile >> size;

	// Dynamically Allocate array 
	intPtr = new int[size];


	if (!inFile)
	{
		cout << "Error ... Could not open " << filename << endl;
		size = 0;
		return;
	}
	
	// Load file contents into array
	for (int i = 0; i < size; i++)
	{
		inFile >> *(intPtr + i);	
		
	}

	//Display array
	cout << "College: " << college << endl;
	cout << "Pathway: " << pathway << endl;
	cout << "------------------------------\n\n";
	cout << "Number of movies seen by " << size << " students\n\n";

	// Display array content
	// Ten items per line
	for (int i = 0; i < size; i++)
	{
		cout << "\t" << *(intPtr + i);

		if ((i + 1) % 10 == 0)
			cout << endl;
	}

	cout << endl;

	//calculate and display the average numb of movies seen during a month by the pathway students
	for (int i = 0; i < size; i++)
	{
		total += *(intPtr + i);

	}
	average = total / size;

	// Display average
	cout << "\nAverage number of movies seen per month " << average << endl;


	// Close file
	inFile.close();

	return;
}
