#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int swaps = 0;
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swaps++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
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

    bubbleSort(arr, n);

    printf("Sorted array:    ");
    printArray(arr, n);

    return 0;
}