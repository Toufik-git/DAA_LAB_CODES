#include <stdio.h>
#include <time.h>

// Structure to store min and max
struct Pair {
    int min;
    int max;
};

// Function using Divide and Conquer
struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair result, left, right;

    // Base case: Only one element
    if (low == high) { 
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // Base case: Two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // Divide
    int mid = (low + high) / 2;

    // Conquer
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Combine
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Start time
    clock_t start = clock();

    struct Pair result = findMinMax(arr, 0, n - 1);

    // End time
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);

    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
