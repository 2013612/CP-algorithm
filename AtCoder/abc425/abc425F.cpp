#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;

typedef modint998244353 mint;

int n;
string t;
mint dp[5000006];

int main() {
    scanf("%d", &n);
    cin >> t;

    dp[(1 << n) - 1] = 1;

    for (int i = (1 << n) - 1; i > 0; i--) {
        char last = '!';
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                continue;
            }

            if (j > 0 && t[j] == last) {
                continue;
            }

            last = t[j];
            dp[i - (1 << j)] += dp[i];
        }
    }

    printf("%d\n",dp[0]);

    return 0;
}