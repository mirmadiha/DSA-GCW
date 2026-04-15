#include <stdio.h>

void selectionSort(int arr[], int n) {
    int swaps = 0;
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swaps++;
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
    printf("Comparisons: %d\n", comparisons); 
    printf("Swaps:       %d\n", swaps);         
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array:  ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array:    ");
    printArray(arr, n);

    return 0;
}