#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[300005];
string ans[103];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ans[i] = string(n, ' ');
	}
	
	for (int i = 1; i <= n; i++) {
		int j = n + 1 - i;
		if (i > j) {
			continue;
		}
		for (int u = i; u <= j; u++) {
			for (int v = i; v <= j; v++) {
				if (i & 1) {
					ans[u - 1][v - 1] = '#'; 
				} else {
					ans[u - 1][v - 1] = '.'; 
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}