#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[200006];

void solve() {
	int n;
	scanf("%d", &n);
	printf("1");
	for (int i = n; i >= 2; i--) {
		printf(" %d", i);
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