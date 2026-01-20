#include<iostream>
#include<algorithm>
using namespace std;

int n;
pair<int, int> r[300005];
long long w_sum, p_sum;

bool f(pair<int, int> a, pair<int, int> b) {
    return a.first + a.second < b.first + b.second;
}

void solve() {
    scanf("%d", &n);

    p_sum = w_sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &r[i].first, &r[i].second);
        p_sum += r[i].second;
    }

    sort(r, r + n, f);

    for (int i = 0; i < n; i++) {
        p_sum -= r[i].second;
        w_sum += r[i].first;

        if (w_sum > p_sum) {
            printf("%d\n", i);
            return;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        solve();
    }

    return 0;
}