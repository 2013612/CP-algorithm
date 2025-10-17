#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int t, n, m, c[5004], a[5004];
unordered_map<int, int> p_rev;
vector<int> p;
vector<vector<int>> fac;

void f(int maxi) {
    for (int i = 1; i <= maxi; i++) {
        a[i] = i;
    }

    for (int i = 2; i <= maxi; i++) {
        if (a[i] == i) {
            p_rev[i] = p.size();
            p.push_back(i);
        }

        for (auto x: p) {
            if (x > a[i] || x * i > maxi) {
                break;
            }

            a[x * i] = x;
        }
    }
}

long long pow(long long a, long long x) {
    if (x == 0) {
        return 1;
    }

    if (x & 1) {
        return a * pow(a, x - 1) % m;
    } else {
        long long p = pow(a, x / 2);
        return p * p % m;
    }
}

void solve() {
    scanf("%d", &n);

    int sum = 0;
    long long ans = 1;
    vector<int> g(p.size(), 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        
        for (int j = 0; j < fac[c[i]].size(); j++) {
            g[j] -= fac[c[i]][j];
        }

        sum += c[i];
    }

    for (int j = 0; j < fac[sum].size(); j++) {
        g[j] += fac[sum][j];

        ans *= pow(p[j], g[j]);
        ans %= m;
    }

    printf("%lld\n", ans);
}

void init() {
    f(5000);

    for (int i = 0; i <= 5000; i++) {
        if (i < 2) {
            fac.push_back(vector<int>(p.size(), 0));
        } else {
            fac.push_back(fac.back());
            int x = i;
            while (x > 1) {
                fac.back()[p_rev[a[x]]]++;
                x /= a[x];
            }
        }
    }
}

int main() {
    scanf("%d %d", &t, &m);
    init();
    while (t-- > 0) {
        solve();
    }

    return 0;
}