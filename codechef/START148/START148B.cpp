#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int n, k, a[200006], b[200006], ans;

class Compare {
public:
    bool operator()(int u, int v)
    {
        return b[u] + log2(a[u]) > b[v] + log2(a[v]);
    }
};

priority_queue<int, vector<int>, Compare> pq;

int pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    
    if (b & 1) {
        return (1ll * a * pow(a, b - 1)) % M;
    } else {
        int half = pow(a, b / 2);
        return (1ll * half * half) % M;
    }
}

void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = 0;
    }
    ans = 0;
    
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        pq.push(i);
    }
    
    while (k > 0 && pq.top() != n - 1) {
        int x = pq.top();
        pq.pop();
        b[x]++;
        pq.push(x);
        k--;
    }
    
    for (int i = 0; i < n; i++) {
        int x = pq.top();
        pq.pop();
//        printf("%d %d %d\n", a[x], b[x], b[x] + (k / n) + (i < k % n));
        ans = (1ll * ans + 1ll * a[x] * pow(2, b[x] + (k / n) + (i < k % n))) % M;
    }
    printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
	    solve();
	}
	return 0;
}
