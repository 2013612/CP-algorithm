#include<iostream>
using namespace std;

int n, a[200], b[200], q;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++) {
		int t, d;
		scanf("%d %d", &t, &d);
		t--;
		
		int new_d = d + (b[t] - d % a[t] + a[t]) % a[t];
		printf("%d\n", new_d);
	}
	
	return 0;
}