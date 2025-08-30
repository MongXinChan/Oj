#include <iostream>
#include <vector>
#include <algorithm>

// Function to partition the array around a pivot
// It returns the index of the pivot after partitioning
int partition(std::vector<int>& arr, int low, int high) {
    // Choose the rightmost element as the pivot
    int pivot = arr[high];
    
    // Index of the smaller element
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            std::swap(arr[i], arr[j]);
        }
    }
    // Swap the pivot element with the element at position (i + 1)
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot's final index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before the pivot
        quickSort(arr, low, pi - 1);

        // Recursively sort the elements after the pivot
        quickSort(arr, pi + 1, high);
    }
}