#include<iostream>
using namespace std;

int n, m, ans;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int h;
		scanf("%d", &h);
		
		if (m >= h) {
			ans++;
		}
		m -= h;
	}
	
	printf("%d\n", ans);
	return 0;
}