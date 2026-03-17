#include<iostream>
using namespace std;

const int M = 10007;

int k, m, mod;
long long r;

int pow(long long a, int x) {
    if (x == 0) {
        return 1;
    }

    if (x & 1) {
        return a * pow(a, x - 1) % mod;
    } else {
        long long t = pow(a, x / 2);
        return t * t % mod;
    }
}

int ones(long long a, int x) {
    if (x == 0) {
        return 0;
    }

    if (x & 1) {
        return (1 + a * ones(a, x - 1)) % mod;
    } else {
        return (1 + a) * ones(1ll * a * a % mod, x / 2) % mod;
    }
}

int main() {
    scanf("%d %d", &k, &m);

    mod = m * M;

    for (int i = 0; i < k; i++) {
        int c, l;
        scanf("%d %d", &c, &l);

        long long x = pow(10, l);
        r = r * x % mod;
        long long y = ones(10, l);
        y = y * c % mod;
        r = (r + y) % mod;
    }

    printf("%lld\n", r / m % M);

    return 0;
}