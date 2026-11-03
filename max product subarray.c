#include <stdio.h>
#include <time.h>

int maxProduct(int arr[], int n) {
    int maxProd = arr[0];
    int minProd = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            int temp = maxProd;
            maxProd = minProd;
            minProd = temp;
        }

        if (arr[i] > maxProd * arr[i])
            maxProd = arr[i];
        else
            maxProd = maxProd * arr[i];

        if (arr[i] < minProd * arr[i])
            minProd = arr[i];
        else
            minProd = minProd * arr[i];

        if (maxProd > result)
            result = maxProd;
    }

    return result;
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
    int result = maxProduct(arr, n);
    clock_t end = clock();

    printf("Maximum product subarray: %d\n", result);
    printf("Execution time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
