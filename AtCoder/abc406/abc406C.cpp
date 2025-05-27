#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[300005];
vector<int> f, s;
long long ans;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 1; i < n - 1; i++) {
		if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
			f.push_back(i);
		}
		
		if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
			s.push_back(i);
		}
	}
	
	f.push_back(n - 1);
	s.push_back(n - 1);
	
	for (int i = 0; i < n - 3; i++) {
		if (a[i] < a[i + 1]) {
			int f_i = lower_bound(f.begin(), f.end(), i + 1) - f.begin();
			int s_i = lower_bound(s.begin(), s.end(), i + 1) - s.begin();
			
			if (f_i + 1 == f.size() || s_i + 1 == s.size()) {
				break;
			}
			
			int start = max(f[f_i], s[s_i]);
			int end = min(f[f_i + 1], s[s_i + 1]);
			
			ans += end - start;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}