#include <stdio.h>
#include <stdlib.h> // For malloc and free

void countingSort(int arr[], int n) {
    if (n == 0) {
        return; // Handle empty array case
    }

    // Find the maximum value in the array to determine the range for the count array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create count array and initialize it to zero
    // The size of count array will be max + 1 to accommodate values from 0 to max
    int* count = (int*)calloc(max + 1, sizeof(int));
    if (count == NULL) {
        printf("Memory allocation failed for count array.\n");
        return;
    }

    // Store the frequency of each element in the count array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify the count array to store the cumulative sum
    // This indicates the position of each element in the sorted output array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create an output array to store the sorted elements
    int* output = (int*)malloc(n * sizeof(int));
    if (output == NULL) {
        printf("Memory allocation failed for output array.\n");
        free(count); // Free previously allocated memory
        return;
    }

    // Build the sorted output array
    // Iterate from the end of the original array to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--; // Decrement the count for the current element
    }

    // Copy the sorted elements from the output array back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free the dynamically allocated memory
    free(count);
    free(output);
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1, 0, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
