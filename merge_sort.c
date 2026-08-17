#include <stdio.h>
#include <time.h>

void merge(int a[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int a[100], n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();

    mergeSort(a, 0, n - 1);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted Array: ");

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nExecution Time: %f seconds", time_taken);

    return 0;
}