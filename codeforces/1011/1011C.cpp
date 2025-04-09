#include<iostream>
using namespace std;

int n, m, a[1004], b[1004];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	b[n] = b[0];
	double l = 0;
	double r = 1e9 + 1;
	while (r-l > 1e-6) {
		bool success = true;
		double mid = (l + r)/2;
		double weight = m + mid;
		for (int i = 0; i < n; i++){
			weight -= weight/a[i];
			weight -= weight/b[i+1];
			if (weight < m) {
				success = false;
				break;
			}
		}
		if (success) {
			r = mid;
		} else {
			l = mid - 1e-9;
		}
	}
	if (r > 1e9 + 0.5) {
		printf("-1\n");
	} else {
		printf("%f\n", l);
	}
	return 0;
}
