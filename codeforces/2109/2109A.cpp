#include<iostream>
using namespace std;

int n, a[103];
bool has0, ans, is0;

void solve() {
	scanf("%d", &n);
	is0 = ans = has0 = false;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		if (a[i] == 0) {
			if (is0) {
				ans = true;
			}
			
			is0 = true;
			has0 = true;
		} else {
			is0 = false;
		}
	}
	
	if (!has0 || ans) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}