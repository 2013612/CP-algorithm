#include<iostream>
#include<vector>
using namespace std;

int n;
int a[1000006];

bool f(int x) {
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++) {
		if (a[i] <= x || (i > 0 && visited[i - 1] && (abs(a[i] - a[i - 1]) <= x))) {
			visited[i] = true;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] <= x || (i < n - 1 && visited[i + 1] && (abs(a[i] - a[i + 1]) <= x))) {
			visited[i] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			return false;
		}
	}

	return true;
}

void solve() {
	scanf("%d", &n);
	int ans = 2e9;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

		ans = min(ans, a[i]);
	}

	int l = 0;
	int r = 1e9 + 1;

	while (l + 1 < r) {
		int mid = (l + r) / 2;

		if (f(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}

	printf("%d\n", max(ans, r));
}

int main() {
	freopen("snake_scales_chapter_2_input.txt", "r", stdin);
	freopen("snake_scales_chapter_2_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}