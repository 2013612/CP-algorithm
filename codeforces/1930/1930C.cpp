#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n, a[300006], ans;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] = -(a[i] + i + 1);
	}
	
	sort(a, a + n);
	
	int last = 2e9;
	
	for (int i = 0; i < n; i++) {
		int temp = -a[i];
		if (temp >= last) {
			temp = last - 1;
		}
		last = temp;
		printf("%d ", temp);
	}
	
	printf("\n");
}
int main() {
	scanf("%d", &t);
	
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}