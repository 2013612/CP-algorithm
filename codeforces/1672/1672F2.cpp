#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef pair<int, int> pii;

int n, a[200006], b[200006], ans[200006], c[200006];
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
	}
	int cnt1 = 0;
	map<pii, int> m1, m2;
	for (int i = 0; i < n; i++) {
		pii cur = {ans[i], a[i]};
		if (m1.count(cur)) {
			m1[cur]--;
			cnt1++;
			if (m1[cur] == 0) {
				m1.erase(cur);
			}
		} else {
			m1[{a[i], ans[i]}]++;
		}
	}
	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		pii cur = {c[i], a[i]};
		if (m2.count(cur)) {
			m2[cur]--;
			cnt2++;
			if (m2[cur] == 0) {
				m2.erase(cur);
			}
		} else {
			m2[{a[i], c[i]}]++;
		}
	}
	if (cnt1 == cnt2) {
		printf("AC\n");
	} else {
		printf("WA\n");
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
