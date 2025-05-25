#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int linearSearch(int arr[], int size, int x);
int binarySearch(int arr[], int left, int right, int x);
int fibonacciSearch(int arr[], int size, int x);

int min(int x, int y) { return (x <= y) ? x : y; }

int main() {
    int arr[] = {2, 3, 4, 10, 40, 45, 55, 65, 77, 89, 99};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x, choice, result;

    printf("Enter the element to search: ");
    scanf("%d", &x);

    printf("Choose search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Fibonacci Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = linearSearch(arr, size, x);
            break;
        case 2:
            result = binarySearch(arr, 0, size - 1, x);
            break;
        case 3:
            result = fibonacciSearch(arr, size, x);
            break;
        default:
            printf("Invalid choice\n");
            return -1;
    }

    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index: %d\n", result);

    return 0;
}

// Linear Search
int linearSearch(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // Check if x is at mid
        if (arr[mid] == x)
            return mid;

        // If x is smaller, it can only be in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);

        // Else it can only be in right subarray
        return binarySearch(arr, mid + 1, right, x);
    }

    // Element is not present in array
    return -1;
}

// Fibonacci Search
int fibonacciSearch(int arr[], int size, int x) {
    int fibMMm2 = 0;   // (m-2)'th Fibonacci number
    int fibMMm1 = 1;   // (m-1)'th Fibonacci number
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci

    while (fibM < size) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM  = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, size - 1);

        if (arr[i] < x) {
            fibM  = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (arr[i] > x) {
            fibM  = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }

    if(fibMMm1 && arr[offset + 1] == x) {
        return offset + 1;
    }

    return -1;
}
