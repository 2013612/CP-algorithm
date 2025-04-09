#include<iostream>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        string s, t;
        cin >> s >> t;
        int dp[1004][1004];
        for (int i = 0; i < 1004; i++) {
            dp[0][i] = dp[i][0] = 0;
        }
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < t.length(); j++) {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                if (s[i] == t[j]) {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                }
            }
        }
        printf("%d\n", dp[s.length()][t.length()]);
    }
    return 0;
}
