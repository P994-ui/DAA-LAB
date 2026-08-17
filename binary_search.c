#include <stdio.h>
#include <time.h>

int main()
{
    int a[100], n, target;
    int low, high, mid;
    int index = -1;
    int i;

    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter rotated sorted array: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    start = clock();

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == target)
        {
            index = mid;
            break;
        }

        /* Left half is sorted */

        if(a[low] <= a[mid])
        {
            if(target >= a[low] && target < a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        /* Right half is sorted */

        else
        {
            if(target > a[mid] && target <= a[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if(index != -1)
        printf("\nElement found at index = %d", index);
    else
        printf("\nElement not found");

    printf("\nExecution Time: %f seconds", time_taken);

    return 0;
}