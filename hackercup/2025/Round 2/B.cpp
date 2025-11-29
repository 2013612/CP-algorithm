#include<bits/stdc++.h>
using namespace std;

int n, m, a[1000006], b[1000006];
vector<int> v;

bool f(int p) {
	if (v.size() > p + m) {
		return true;
	}

	long long need_prize_sum = 0;
	long long prize_sum = 0;
	int com_sum = 0;
	for (int i = p; i < v.size(); i++) {
		com_sum += v[i];
		need_prize_sum += 1ll * v[i] * (i - p + 1);
	}

	for (int i = 0; i < m; i++) {
		prize_sum += min(com_sum, b[i]);
	}

	return need_prize_sum > prize_sum;
}

void solve() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	
    sort(a, a + n);
	sort(b, b + m, greater<int>());
	v = vector<int>(1, 1);
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			v.push_back(0);
		}

		v.back()++;
	}

	int l = -1, r = v.size();

	while (l + 1 < r) {
		int mid = (l + r) / 2;

		// printf("%d %d\n", mid, f(mid));
		if (f(mid)) {			
			l = mid;
		} else {
			r = mid;
		}
	}

	int ans = 0;
	for (int i = r; i < v.size(); i++) {
		ans += v[i];
	}

	printf("%d\n", ans);
}

int main() {
	freopen("defining_prizes_input.txt", "r", stdin);
	freopen("defining_prizes_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}