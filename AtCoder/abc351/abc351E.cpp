#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> x[2], y[2];
long long ans;

void cal(vector<int> &v) {
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		ans += 1ll * v[i] * (2 * i - v.size() + 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		x[(a + b) % 2].push_back(a + b);
		y[(a + b) % 2].push_back(a - b);
	}
	
	cal(x[0]);
	cal(x[1]);
	cal(y[0]);
	cal(y[1]);
	
	printf("%lld\n", ans / 2);
	
	return 0;
}