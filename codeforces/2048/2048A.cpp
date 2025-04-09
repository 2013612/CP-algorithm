#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int x, ans;

void solve() {
	scanf("%d", &x);
	
	if (x % 33) {
		printf("NO\n");
	} else {
		printf("YES\n");
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