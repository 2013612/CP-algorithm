#include <iostream>
#include <algorithm>

using namespace std;

int N, a[100006], b[100006];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &b[i]);
    }
    sort(a, a + N);
    sort(b, b + N);
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(a[i] - b[i]);
    }
    printf("%lld\n", ans);
    return 0;
}

