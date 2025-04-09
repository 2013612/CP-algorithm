#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, c, ans[200006], maxi;
vector<int> s[103], t[103];
int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		int p, q, r;
		scanf("%d %d %d", &p, &q, &r);
		s[r].push_back(p);
		t[r].push_back(q);
	}
	for (int i = 1; i <= c; i++) {
		int a[200006];
		for (int j = 0; j < 200006; j++) {
			a[j] = 0;
		}
		for (auto x:s[i]) {
			a[2 * x - 1]++;
		}
		for (auto x:t[i]) {
			a[2 * x]--;
		}
		for (int j = 1; j < 200006; j++) {
			a[j] += a[j - 1];
			ans[j] += a[j] > 0;
		}
	}
	for (int i = 1; i < 200006; i++) {
		maxi = max(maxi, ans[i]);
	}
	printf("%d\n", maxi);
	return 0;
}
