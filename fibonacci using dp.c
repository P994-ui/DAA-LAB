#include <stdio.h>
#include <time.h>

long long fibonacci(int n) {
    if (n <= 1)
        return n;

    long long dp[100];

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 0 || n >= 100) {
        printf("Enter n between 0 and 99.\n");
        return 0;
    }

    clock_t start = clock();
    long long result = fibonacci(n);
    clock_t end = clock();

    printf("Nth Fibonacci number: %lld\n", result);
    printf("Execution time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
