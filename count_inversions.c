#include <stdio.h>
#include <time.h>

int merge(int a[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = 0;
    int count = 0;

    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];

            count = count + (mid - i + 1);
        }
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];

    return count;
}

int mergeSort(int a[], int low, int high)
{
    int mid;
    int count = 0;

    if(low < high)
    {
        mid = (low + high) / 2;

        count = count + mergeSort(a, low, mid);
        count = count + mergeSort(a, mid + 1, high);
        count = count + merge(a, low, mid, high);
    }

    return count;
}

int main()
{
    int a[100], n, i;
    int inversions;

    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();

    inversions = mergeSort(a, 0, n - 1);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nNumber of Inversions = %d", inversions);

    printf("\nExecution Time: %f seconds", time_taken);

    return 0;
}