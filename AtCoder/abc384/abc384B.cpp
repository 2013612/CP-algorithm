#include<iostream>
using namespace std;

int n, r;

int main() {
	int n;
	
	scanf("%d %d", &n, &r);
	for (int i = 0; i < n; i++) {
		int d, a;
		scanf("%d %d", &d, &a);
		int l = d == 1 ? 1600 : 1200;
		int h = d == 1 ? 2799 : 2399;
		
		if (r >= l && r <= h) {
			r += a;
		}
	}
	
	printf("%d\n", r);
	
	return 0;
}