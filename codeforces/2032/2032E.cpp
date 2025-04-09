#include<iostream>
#include<algorithm>
#include<atcoder/convolution>
using namespace std;
using namespace atcoder;

int n, a[200006], maxi;
vector<long long> c, d, ans;

void solve() {
	scanf("%d", &n);
	
	maxi = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		maxi = max(maxi, a[i]);
	}
	
	if (n == 1) {
		printf("0\n");
		return;
	}
	
	c.clear();
	d.clear();
	
	d.resize(n);
	
	for (int i = 0; i < n; i++) {
		c.push_back(maxi - a[i]);
	}
	
	int mid = n / 2;
	
	d[mid] = n / 2;
	d[mid - 1] = d[mid + 1] = 0;
	
	for (int i = mid - 2; i >= 0; i -= 2) {
		d[i] = d[i + 2] - 1;
	}
	
	for (int i = mid + 2; i < n; i += 2) {
		d[i] = d[i - 2] - 1;
	}
	
	for (int i = mid - 3; i >= 0; i -= 2) {
		d[i] = d[i + 2] + 1;
	}
	
	for (int i = mid + 3; i < n; i += 2) {
		d[i] = d[i - 2] + 1;
	}
	
	rotate(d.begin(), d.begin() + n / 2, d.end());
	
	vector<long long> k = convolution_ll(c, d);
	
	ans.clear();
	ans.resize(n);
	
	for (int i = 0; i < n; i++) {
		ans[i] = k[i];
	}
	
	for (int i = n; i < k.size(); i++) {
		ans[i - n] += k[i];
	}
	
	for (int i = 0; i < n; i++) {
		printf("%lld ", ans[i]);
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