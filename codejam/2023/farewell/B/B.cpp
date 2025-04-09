#include<iostream>
using namespace std;

// long long gcd(long long a, long long b) {
//     return b == 0 ? a : gcd (b, a % b);
// }

pair<long long, pair<long long, long long> > extendedEuclid(long long a, long long b) 
{
    long long x = 1, y = 0;
    long long xLast = 0, yLast = 1;
    long long q, r, m, n;
    while (a != 0) 
    {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x; 
        yLast = y;
        x = m; 
        y = n;
        b = a; 
        a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}

void solve() {
    long long w, n, d;
    long long a[1003];
    scanf("%lld %lld %lld", &w, &n, &d);
    for (int i = 0; i < w; i++) {
        scanf("%lld", &a[i]);
        a[i]--;
    }
    long long ans = 0;
    pair<long long, pair<long long, long long> > k = extendedEuclid(n, d);
    long long gcd = k.first;
    long long y = (k.second.second + n) % n;
    for (int i = 0; i < w / 2; i++) {
        if (a[i] > a[w - i - 1]) {
            swap(a[i], a[w - i - 1]);
        }
        
        if ((a[w - i - 1] - a[i]) % gcd) {
            printf("IMPOSSIBLE\n");
            return;
        }
        
        long long diff1 = a[w - i - 1] - a[i];
        long long loop1 = (diff1 % d) / gcd;
        long long temp1 = (loop1 * y % n) + diff1 / d;

        ans += min(temp1, n / gcd - temp1);
    }
    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}