#include<iostream>
#include<set>
using namespace std;
typedef pair<int, int> pii;

int n, m, l[2000007], r[2000007], half, ans, a[2000007];
set<pii> edges;

void findInvalid(int pos, int* arr) {
	if (arr[pos] == -1) {
		return;
	}
	arr[pos] = -1;
	for (int i = 0; i < half; i++) {
		if (!(pos & (1 << i))) {
			findInvalid(pos + (1 << i), arr);
		}
	}
}



int main() {
	scanf("%d %d", &n, &m);
	half = (n + 1) / 2;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edges.insert({a - 1, b - 1});
	}
	for (int i = 0; i < (1 << half); i++) {
		for (int j = 0; j < half; j++) {
			if (i & (1 << j)) {
				l[i]++;
				r[i]++;
			}
		}
	}
	for (auto x : edges) {
		if (x.second < half) {
			findInvalid((1 << x.first) + (1 << x.second), l);
		} else if (x.first >= half) {
			findInvalid((1 << (x.first - half)) + (1 << (x.second - half)), r);
		}
	}
	
	for (int i = 0; i < (1 << half); i++) {
		if (r[i] < 0) {
			int maxi = -1;
			for (int j = 0; j < half; j++) {
				if (i & (1 << j)) {
					maxi = max(maxi, r[i - (1 << j)]);
				}
			}
			r[i] = maxi;
		}
	}
	
	for (int i = 0; i < half; i++) {
		for (int j = half; j < n; j++) {
			if (!edges.count({i, j})) {
				a[1 << i] += (1 << (j - half));
			}
		}
	}
	
	a[0] = (1 << (n - half)) - 1;
	for (int i = 1; i < (1 << half); i++) {
		a[i] = a[(i & (-i))] & a[i - (i & (-i))];
		if (l[i] > 0) {
			ans = max(ans, l[i] + r[a[i]]);
		}
	}
	
	printf("%d\n", ans);
	return 0;
}
