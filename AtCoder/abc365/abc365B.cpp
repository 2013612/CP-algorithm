#include<iostream>
using namespace std;

int n, a[103], maxi, maxi2 = 1;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		if (i > 1) {
			if (a[maxi] <= a[i]) {
				maxi2 = maxi;
				maxi = i;
			} else if (a[maxi2] <= a[i]) {
				maxi2 = i;
			}
		} else {
			if (a[0] < a[1]) {
				maxi = 1;
				maxi2 = 0;
			} else {
				maxi = 0;
				maxi2 = 1;
			}
		}
	}
	
	printf("%d\n", maxi2 + 1);
	
	return 0;
}