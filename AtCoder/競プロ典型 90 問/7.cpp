#include <iostream>
#include <algorithm>

using namespace std;

int N, Q, a[300006];
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + N);
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int temp;
        scanf("%d", &temp);
        int pos = lower_bound(a, a + N, temp) - a;
        int ans = 2e9;
        if (pos == 0) {
            ans = abs(a[0] - temp);
        } else if (pos == N) {
            ans = abs(a[N - 1] - temp); 
        } else {
            ans = min(abs(a[pos] - temp), abs(a[pos - 1] - temp));
        }
        printf("%d\n", ans);
    }
    return 0;
}

