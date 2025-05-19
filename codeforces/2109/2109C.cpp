#include<iostream>
using namespace std;

void solve() {
	int n, a;
	scanf("%d", &n);
	
	printf("mul 999999999\n");
	fflush(stdout);
	scanf("%d", &a);
	
	printf("digit\n");
	fflush(stdout);
	scanf("%d", &a);
	
	if (n != 81) {
		printf("add %d\n", n - 81);
		fflush(stdout);
		scanf("%d", &a);
	}
	
	printf("!\n");
	fflush(stdout);
	scanf("%d", &a);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}