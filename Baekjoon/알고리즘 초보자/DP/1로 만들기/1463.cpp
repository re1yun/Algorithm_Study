#include<stdio.h>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))  

int main() {
	int n, i, dp[1000001]; scanf("%d", &n);
	dp[0] = dp[1] = 0;
	for (i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = MIN(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = MIN(dp[i], dp[i / 3] + 1);
    }
	printf("%d", dp[n]);
}