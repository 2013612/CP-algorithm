#include<iostream>
#include<algorithm>
using namespace std;

int n, ans;
pair<int, int> a[200006];

bool f(pair<int, int> a, pair<int, int> b) {
	int min_a = min(a.first, a.second);
	int max_a = max(a.first, a.second);
	int min_b = min(b.first, b.second);
	int max_b = max(b.first, b.second);
	
	if (min_a == min_b) {
		return max_a < max_b;
	}
	
	return min_a < min_b;;
}

void solve() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[i] = {x, y};
	}
	
	sort(a, a + n, f);
	
	for (int i = 0; i < n; i++) {
		printf("%d %d ", a[i].first, a[i].second);
	}
	
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}