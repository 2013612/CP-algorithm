#include<iostream>
#include<vector>
using namespace std;

void solve() {
	int ans = 0;
	vector<int> a(1, 0);
	printf("0\n");
	fflush(stdout);
	int k;
	scanf("%d", &k);

	int p = k;
	while (p > 0) {
		if (p & 1) {
			a.push_back(0);
		} else {
			a.push_back(1);
		}
		
		p /= 2;
	}
	
	int temp = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i]) {
			temp += (1 << i);
		}
	}
	
	printf("%d\n", temp);
	fflush(stdout);
	
	int k2;
	scanf("%d", &k2);
	
	printf("!\n");
	fflush(stdout);
	
	int m;
	scanf("%d", &m);
	
	for (int i = 0; i < 30; i++) {
		if (m & (1 << i)) {
			ans += (1 << (i + 1));
		} else {
			if (k & (1 << i)) {
				ans += (1 << i);
			} else {
				if (k2 & (1 << (i + 1))) {
					ans += (1 << (i + 1));
				}
			}
		}
	}
	
	printf("%d\n", ans);
	fflush(stdout);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
}