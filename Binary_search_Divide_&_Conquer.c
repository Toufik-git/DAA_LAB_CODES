#include <stdio.h>
#include <time.h>

// Binary Search function (Divide and Conquer)
int binarySearch(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if key is present at mid
        if (arr[mid] == key)
            return mid;

        // If key is smaller, search left half
        if (arr[mid] > key)
            return binarySearch(arr, left, mid - 1, key);

        // Else search right half
        return binarySearch(arr, mid + 1, right, key);
    }

    return -1; // Element not found
}

int main() {
    int n, key, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Start time
    clock_t start = clock();

    int result = binarySearch(arr, 0, n - 1, key);

    // End time
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
