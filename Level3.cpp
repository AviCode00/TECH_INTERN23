/*
Name       : Avijit Mondal
Department : Masters of Computer Applications(MCA)
College    : Dr. B. C. Engineering College , Durgapur
Level      : 3
Questionn  : Assume that you have an array of integers and you want to find the second-largest element in the array.
			 Write a C++ or C program to do this in a single pass without sorting the array.
*/


#include <iostream>
using namespace std;

// Function to find the index of the second-largest element in the array
int secondLargest(int arr[], int n) {
	// Initialize two variables to keep track of the indices of the largest and second-largest elements
	int first = 0, second = -1;

	// Loop through the array, updating the largest and second-largest indices as necessary
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[first]) {
			// If the current element is greater than the current largest element, update both largest and second-largest indices
			second = first;
			first = i;
		}
		else if (arr[i] < arr[first]) {
			// If the current element is smaller than the current largest element, but greater than the current second-largest element (if it exists), update the second-largest index
			if (second == -1 || arr[second] < arr[i])
				second = i;
		}
	}

	// Return the index of the second-largest element, or -1 if there is no second-largest element
	return second;
}

int main() {
	// Test the secondLargest function with a sample array
	int arr[] = { 10, 3, 1, 11, 4, 1 };
	int index = secondLargest(arr, sizeof(arr)/sizeof(arr[0]));

	// Print the second-largest element if it exists, or a message indicating that it doesn't exist otherwise
	if (index == -1)
		cout << "Second largest element does not exist";
	else
		cout << "Second largest element: " << arr[index];

	// Return 0 to indicate successful program execution
	return 0;
}

