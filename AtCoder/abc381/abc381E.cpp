#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, q;
vector<int> slash, one, two;

int main() {
	scanf("%d %d", &n, &q);
	string s;
	cin >> s;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			one.push_back(i);
		} else if (s[i] == '2') {
			two.push_back(i);
		} else {
			slash.push_back(i);
		}
	}
	
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		r--;
		
		int u = 0;
		int v = r - l;
		
		int st = lower_bound(one.begin(), one.end(), l) - one.begin();
		
		while (u + 1 < v) {
			int mid = (u + v) / 2;
			
			int ed = st + mid - 1;
			
			if (ed >= one.size()) {
				v = mid;
				continue;
			}
			
			int sl = lower_bound(slash.begin(), slash.end(), one[ed]) - slash.begin();
			
			if (sl >= slash.size()) {
				v = mid;
				continue;
			}
			
			int st2 = lower_bound(two.begin(), two.end(), slash[sl]) - two.begin();
			int ed2 = st2 + mid - 1;
			
			if (ed2 >= two.size() || two[ed2] > r) {
				v = mid;
				continue;
			}
			
			u = mid;
		}
		
		int ans = 2 * u + 1;
		
		if (u == 0) {
			int sl = lower_bound(slash.begin(), slash.end(), l) - slash.begin();
			if (sl >= slash.size() || slash[sl] > r) {
				ans = 0;
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}