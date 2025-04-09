#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, ans;
long long x, k, h[200006];
vector<long long> uni;
set<long long> s;

void solve() {
	scanf("%d %lld %lld", &n, &x, &k);
	s.clear();
	uni.clear();
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &h[i]);
		uni.push_back(h[i]);
	}
	sort(h, h + n, greater<long long>());
	sort(uni.begin(), uni.end());
	uni.erase(unique(uni.begin(), uni.end()), uni.end());
	
	int cur = 0;
	for (int i = 0; i < n; i++) {
		while (!s.empty()) {
//			printf("! %d %d\n", i, *s.rbegin());
			if (x * k <= *s.rbegin()) {
				s.erase(*s.rbegin());
				continue;
			}
			
			int pos = lower_bound(uni.begin(), uni.end(), h[i]) - uni.begin();
			if (uni[pos] == *s.begin()) {
				pos--;
			}
			
			ans = max<int>(ans, cur + s.size() + pos + 1);
			break;
		}
		
		if (x > h[i]) {
			x = h[i];
			cur++;
		} else {
			s.insert(h[i]);
		}
	}
	
//	printf("# %d %d\n", cur, s.size());
	ans = max(ans, cur);
	while (!s.empty()) {
//		printf("! %d\n", *s.rbegin());
		if (x * k <= *s.rbegin()) {
			s.erase(*s.rbegin());
			continue;
		}
		
		ans = max<int>(ans, cur + s.size());
		break;
	}
	
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}