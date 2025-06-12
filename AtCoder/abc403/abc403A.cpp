#include<iostream>
using namespace std;

int n, ans;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		
		if (i % 2 == 0) {
			ans += t;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}