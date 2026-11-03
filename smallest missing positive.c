#include <stdio.h>
#include <time.h>

int firstMissingPositive(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 &&
               arr[i] <= n &&
               arr[arr[i] - 1] != arr[i]) {

            int temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }

    return n + 1;
}

int main() {
    int n, arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid input.\n");
        return 0;
    }

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start = clock();
    int result = firstMissingPositive(arr, n);
    clock_t end = clock();

    printf("Smallest missing positive integer: %d\n", result);
    printf("Execution time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
