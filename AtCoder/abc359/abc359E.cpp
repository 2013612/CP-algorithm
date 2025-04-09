#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int n, a[200006];
vector<long long> ans;
stack<int> s;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		while (!s.empty() && a[s.top()] < a[i]) {
			s.pop();
		}
		long long temp = 1;
		long long t = -1;
		if (!s.empty()) {
			t = s.top();
		}
		if (!ans.empty() && t >= 0) {
			temp = ans[t];
		}
//		printf("%d %d %d\n", i, temp, t);
		temp += a[i] * (i - t);
		ans.push_back(temp);
		s.push(i);
	}
	
	for (int i = 0; i < n; i++) {
		printf("%lld ", ans[i]);
	}
	printf("\n");
	
	return 0;
}