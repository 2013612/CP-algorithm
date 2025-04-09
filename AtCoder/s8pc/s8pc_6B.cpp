#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int N;
long long a[103], b[103], ans, c[206];

int main()
{
    scanf("%d", &N);
    ans = 2e18;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a[i], &b[i]);
        c[i] = a[i];
        c[N + i] = b[i];
    }
    sort(c, c + 2 * N);
    for (int i = 0; i < 2 * N; i++) {
        for (int j = i; j < 2 * N; j++) {
            long long sum = 0;
            for (int k = 0; k < N; k++) {
                if (c[i] <= a[k] && c[j] <= b[k]) {
                    sum += 2 * b[k] - c[i] - c[j];
                } else if (c[i] <= a[k] && c[j] >= b[k]) {
                    sum += c[j] - c[i];
                } else if (a[k] <= c[i] && c[j] <= b[k]) {
                    sum += 2 * (b[k] - a[k]) - (c[j] - c[i]);
                } else {
                    sum += c[i] + c[j] - 2 * a[k];
                }
            }
            ans = min(ans, sum);
        }
    }
    printf("%lld\n", ans);
    return 0;
}

