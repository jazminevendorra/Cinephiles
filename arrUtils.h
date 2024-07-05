/*
	
	arrUtils.h

	Specification file for the following array functions:
		- loadArray()
		- displayArray()
		- selectionSort()
		- bubbleSort()
*/

#pragma once		// Include this file only once

// Header Files
#include <string>
using namespace std;

// Function Prototypes
void loadArray(int*, string, int&, string&, string&);
void displayArray(int*, int);
int selectionSort(int[], int);
int bubbleSort(int[], int);

