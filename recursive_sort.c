#include <stdio.h>
#include <time.h>

void insertionSort(int a[], int n)
{
    int key, j;

    if(n <= 1)
        return;

    insertionSort(a, n - 1);

    key = a[n - 1];
    j = n - 2;

    while(j >= 0 && a[j] > key)
    {
        a[j + 1] = a[j];
        j--;
    }

    a[j + 1] = key;
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

    insertionSort(a, n);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nExecution Time: %.10f seconds", time_taken);
    
    return 0;
}