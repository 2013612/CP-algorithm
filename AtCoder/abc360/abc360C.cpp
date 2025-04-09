#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[100006], w[100006], ans;
vector<int> v[100006];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
		ans += w[i];
	}
	
	for (int i = 0; i < n; i++) {
		v[a[i]].push_back(w[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		if (v[i].size() > 0) {
			ans -= *max_element(v[i].begin(), v[i].end());
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}