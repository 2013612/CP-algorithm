#include<iostream>
#include<vector>
using namespace std;

int n, a[200006], cnt[200006];
bool visit[200006];
vector<int> v;

void dfs(int node) {
	if (cnt[node] > 0) {
		return;
	}
	
	if (node == a[node]) {
		cnt[node] = 1;
		return;
	}
	
	if (visit[a[node]]) {
		if (cnt[a[node]] > 0) {
			cnt[node] = cnt[a[node]] + 1;
		} else {
			int k;
			for (int i = 0; i < v.size(); i++) {
				if (v[i] == a[node]) {
					k = v.size() - i + 1;
					break;
				}
			}
			int t = node;
			while (cnt[t] == 0) {
				cnt[t] = k;
				t = a[t];
			}
		}
		
		return;
	}
	visit[node] = true;
	v.push_back(node);
	dfs(a[node]);
	v.pop_back();
	if (cnt[node] == 0) {
		cnt[node] = cnt[a[node]] + 1;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		dfs(i);
		ans += cnt[i];
	}
	
	printf("%lld\n", ans);
	
	return 0;
}