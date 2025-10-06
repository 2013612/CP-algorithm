#include<bits/stdc++.h>
using namespace std;

const int M = 550;

int n, q;
long long a[300005];

struct Bucket {
    int cnt = 0;
    long long mini = 1e16;
    long long minus = 0;
} b[M + 10];

long long update(int l, int r, long long k, int buc) {
    int cnt = 0;
    long long mini = 1e16;
    long long sum = 0;
    for (int j = buc * M; j < (buc + 1) * M; j++) {
        if (a[j] == 0) {
            continue;
        }
        a[j] -= b[buc].minus;
        if (j >= l && j <= r) {
            long long x = min(a[j], 1ll * k);
            sum += x;
            a[j] -= x;
        }

        if (a[j] > 0) {
            cnt++;
            mini = min(mini, a[j]);
        }
    }

    b[buc] = {cnt, mini, 0};

    return sum;
}

long long find(int l, int r, long long k) {
    int start = l / M;
    int end = r / M;

    long long sum = 0;
    for (int i = start; i <= end; i++) {
        if (i == start || i == end) {
            sum += update(l, r, k, i);
        } else {
            if (b[i].mini - b[i].minus > k) {
                sum += 1ll * b[i].cnt * k;
                b[i].minus += k;
            } else {
                sum += update(l, r, k, i);
            }
        }
    }

    return sum;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);

        b[i / M].cnt++;
        b[i / M].mini = min(b[i / M].mini, a[i]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);

        printf("%lld\n", find(l - 1, r - 1, 1ll * k));
    }

    return 0;
}