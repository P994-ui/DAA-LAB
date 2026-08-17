#include <stdio.h>
#include <time.h>

int main()
{
    int a[100], n, i;
    int low = 0, mid = 0, high;
    int temp;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (0, 1 and 2): ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();

    high = n - 1;

    while(mid <= high)
    {
        if(a[mid] == 0)
        {
            temp = a[low];
            a[low] = a[mid];
            a[mid] = temp;

            low++;
            mid++;
        }
        else if(a[mid] == 1)
        {
            mid++;
        }
        else
        {
            temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;

            high--;
        }
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nExecution Time: %.10f seconds", time_taken);

    return 0;
}