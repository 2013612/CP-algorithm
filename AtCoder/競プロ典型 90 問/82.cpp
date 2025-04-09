#include <iostream>
using namespace std;

const int M = 1e9 + 7;

long long L, R;

long long p(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    if (b & 1) {
        return a * p(a, b - 1) % M;
    } else {
        long long temp = p(a, b / 2);
        return temp * temp % M;
    }
}

long long inv(long long a) {
    return p(a, M - 2);
}

long long cal(long long a) {
    long long digit = 1;
    long long ans = 0;
    long long a_mod = a % M;
    for (int i = 1; i <= 18; i++) {
        digit = digit * 10;
        long long digit_mod = (digit / 10) % M;
        long long last;
        if (a < digit) {
            last = a_mod;
        } else {
            last = (digit - 1) % M;
        }
        long long temp = last + digit_mod;
        temp = (temp * ((last - digit_mod + 1 + M) % M)) % M;
        temp = temp * inv(2) % M;
        temp = temp * i % M;
        ans = (ans + temp) % M;
        //cout << ans << endl;
        if (a < digit) {
            break;
        }
        if (i == 18) {
            ans = ans + (digit % M) * 19 % M;
        }
    }
    return ans % M;
}

int main()
{
    scanf("%lld %lld", &L, &R);
    printf("%lld\n", (cal(R) - cal(L - 1) + M) % M);
    return 0;
}

