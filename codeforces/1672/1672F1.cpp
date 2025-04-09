#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

int n, a[200006], b[200006], ans[200006];
void solve() {
	scanf("%d", &n);
	priority_queue<pii> pq;
	vector<int> v[n + 10];
	vector<pii> temp;
	for (int i = 1; i <= n; i++) {
		b[i] = 0;
		ans[i - 1] = 0;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		v[a[i]].push_back(i);
		b[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] > 0) {
			temp.push_back({b[i], i});
		}
	}
	sort(temp.begin(), temp.end(), greater<pii>());
	int f = 0, s = 0;
	for (int i = 1; i < temp.size(); i++) {
		for (int j = 0; j < temp[i].first; j++) {
			ans[v[temp[f].second][s]] = temp[i].second;
			s++;
			if (s == temp[f].first) {
				f++;
				s = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] == 0) {
			ans[i] = temp[0].second;
		}
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
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
