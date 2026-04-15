#include <stdio.h>
void insertionSort(int arr[], int n) {
    int swaps = 0;
    int comparisons = 0;

    for (int i = 1; i < n; i++) {
        int value = arr[i];
        int j;

        for (j = i - 1; j >= 0 ; j--) {
            comparisons++;
            if(arr[j]>value){
                swaps++;
                arr[j + 1] = arr[j];
            }
            else{
                break;
            }
        }

        arr[j + 1] = value;
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

    insertionSort(arr, n);

    printf("Sorted array:    ");
    printArray(arr, n);

    return 0;
}