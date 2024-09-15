//chart.cpp
//Shah, Tirth
//tshah

#include <iostream>

using namespace std;

//this method is responsible for printing the pattern in desired pattern
//input: it takes size of the array, largest element of the array and the array that we have created in the main function from the user input
//output: the return type for this function is void so it does not return anything
void print_histogram(int size, int largest_element, int arr[]) {
    for (int row = largest_element-1; row >= 0; row--) {
        for (int col = 0; col < size-1; col++) {
            if (arr[col] < largest_element && arr[col] <= row) {
            cout << " ";
            }
            else {
            cout << "*";
            }
        }
        cout << endl;
    }
}

//this function is responsible for finding out the largest element present in the array
//input: this function expects the array and size of type integer as its input to give the necessary output.
//output: largest integer present in the given array
//return value is integer
int find_largest(int arr[], int size) {
    int current_largest = arr[0];
    //traverses the array and compares it with current max and sets new value if current max is less
    for (int index = 0; index < size; index++) {
        if (current_largest < arr[index]) {
            current_largest = arr[index];
        }
    }
    return current_largest;
}

//this is the main function and is the driving the whole program. It is calling other methods present in this file.
//does not have or require any parameters
//just returning 0
//integer
int main() {
    const int maxValue = 100;
    int array[maxValue];
    int total_size = 0;
    for (int size = 0; size<maxValue; size++) {
        cin >> array[size];
        total_size += 1;
        if (array[size] == 0) {
            break;
        }
    }

    int largest = find_largest(array, total_size);
    print_histogram(total_size, largest, array);
    return 0;
}