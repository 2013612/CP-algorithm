#include <iostream>
#include <vector>

using namespace std;

long long N, D, a[103], ans;

int main()
{
    scanf("%lld %lld", &N, &D);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    ans = (1ll << D);
    for (long long i = 1; i < (1ll << N); i++) {
        long long sign = 1;
        long long temp = 0;
        for (long long j = 0; j < N; j++) {
            if (i & (1ll << j)) {
                sign *= -1;
                temp = temp | a[j];
            }
        }
        long long cou = 0;
        for (long long j = 0; j < D; j++) {
            if (temp & (1ll << j)) {
                cou++;
            }
        }
        ans += sign * (1ll << (D - cou));
    }
    printf("%lld\n", ans);
    return 0;
}

