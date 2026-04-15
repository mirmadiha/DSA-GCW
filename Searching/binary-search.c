#include <stdio.h>

int binarySearch(int arr[], int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return mid;      
        else if (arr[mid] < target)
            start = mid + 1;   
        else
            end = mid - 1;      
    }

    return -1;              
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in sorted order: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int start = 0;
    int end=n-1;

    int target;
    printf("Enter element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, start, end, target);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found\n", target);

    return 0;
}