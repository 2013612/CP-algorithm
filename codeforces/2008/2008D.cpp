#include<iostream>
using namespace std;

int a[200006], b[200006];

void solve() {
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = -1;
	}
	
	string s;
	cin >> s;

	for (int i = 1; i <= n; i++) {
		if (b[i] < 0) {
			int k = i;
			int cnt = 0;
			do {
				cnt += s[k - 1] == '0';
				k = a[k];
			} while (k != i);

			k = i;
			
			do {
				b[k] = cnt;
				k = a[k];
			} while (k != i);
		}
		
		printf("%d ", b[i]);
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