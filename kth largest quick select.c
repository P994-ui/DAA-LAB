#include <stdio.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k - 1)
            return arr[pivotIndex];

        if (pivotIndex > k - 1)
            return quickSelect(arr, low, pivotIndex - 1, k);

        return quickSelect(arr, pivotIndex + 1, high, k);
    }

    return -1;
}

int main() {
    int n, k, arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid input.\n");
        return 0;
    }

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Invalid value of k.\n");
        return 0;
    }

    clock_t start = clock();
    int result = quickSelect(arr, 0, n - 1, k);
    clock_t end = clock();

    printf("Kth largest element: %d\n", result);
    printf("Execution time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
