#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, q, a[200005], ans[200005];
pair<pair<int, int>, int> req[200005];
vector<int> v;

int main() {
	scanf("%d %d", &n, &q);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < q; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		req[i] = {{u - 1, v}, i};
	}
	
	sort(req, req + q);
	
	int t = 0;
	
	for (int i = 0; i < n; i++) {
		int ind = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		if (ind >= v.size()) {
			v.push_back(a[i]);
		} else {
			v[ind] = a[i];
		}
		
		while (t < q && req[t].first.first == i) {
			int ind = upper_bound(v.begin(), v.end(), req[t].first.second) - v.begin();
			ans[req[t].second] = ind;
			t++;
		}
	}
	
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}