#include<iostream>
#include<vector>
#include<list>
using namespace std;

long long n, l, r;
int ind = 1;
vector<int> ans, a, b;
int main() {
	scanf("%lld %lld %lld", &n, &l, &r);
	
	for (int i = 0; i <= n; i++) {
		b.push_back(i);
	}
	
	long long sum = 0;
	while (sum + n - ind < l && ind <= n) {
		sum += n - ind;
		ans.push_back(b[ind]);
		ind++;
	}
	
	for (int i = l - sum + ind; i <= n && l <= r; i++) {
		swap(b[ind], b[i]);
		l++;
	}
	ans.push_back(b[ind]);

	ind++;
	int cur = ind;
	
	while (l + n - ind <= r && ind < n) {
		ans.push_back(b.back());
		b.pop_back();
		l += n - ind;
		ind++;
	}
	
	for (int i = 1; l <= r; i++) {
		swap(b[cur], b[cur + i]);
		l++;
	}
	for (int i = cur; i < b.size(); i++) {
		ans.push_back(b[i]);
	}
	for (auto x: ans) {
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}