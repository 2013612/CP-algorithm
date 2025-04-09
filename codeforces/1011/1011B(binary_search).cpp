#include<iostream>
using namespace std;

int n, m, a[102], b, part;

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b);
		a[b]++;
	}
	int l = 0;
	int r = m/n;
	while (l < r) {
		part = n;
		int mid = (l + r + 1)/2;
		bool success = false;
		for (int j = 1; j <= 100; j++) {
			part -= a[j]/mid;
			if (part <= 0){
				success = true;
				break;
			}
		}
		if (success) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	printf("%d\n", l);
	return 0;
}
