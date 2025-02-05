#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the first element is the smallest
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) { // Find the smallest element
                minIndex = j;
            }
        }
        // Swap only once per iteration
        swap(arr[i], arr[minIndex]);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {4, 3, 0, 1, 2};
    printArray(arr, 5);

    SelectionSort(arr, 5);

    printArray(arr, 5);
    return 0;
}
