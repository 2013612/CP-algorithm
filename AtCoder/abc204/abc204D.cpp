#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int N, a[103], ans, presum[103];

void printDistSum(int arr[], int n)
{
    int sum = 0;
    for (int i=0; i<n; i++)
        sum += arr[i];
 
    // dp[i][j] would be true if arr[0..i-1] has
    // a subset with sum equal to j.
    bool dp[n+1][sum+1];
    memset(dp, 0, sizeof(dp));
 
    // There is always a subset with 0 sum
    for (int i=0; i<=n; i++)
        dp[i][0] = true;
 
    // Fill dp[][] in bottom up manner
    for (int i=1; i<=n; i++)
    {
        dp[i][arr[i-1]] = true;
        for (int j=1; j<=sum; j++)
        {
            // Sums that were achievable
            // without current array element
            if (dp[i-1][j] == true)
            {
                dp[i][j] = true;
                dp[i][j + arr[i-1]] = true;
            }
        }
    }
    //cout << sum << endl;
    // Print last row elements
    for (int j=0; j<=sum; j++)
        if (dp[n][j]==true)
            ans = min(ans, max(sum - j, j));
}

int main() {
	scanf("%d", &N);
	ans = 1e9;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		//presum[i] = presum[i - 1] + a[i];
	}
	printDistSum(a, N);
	printf("%d\n", ans);
	return 0;
}
