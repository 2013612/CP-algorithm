#include<iostream>
#include<algorithm>
using namespace std;

int n;
string a[300006];
long long ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n);
	
	for (int i = 0; i < n - 1; i++) {
		int r = n;
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i + 1].size() <= j || a[i + 1][j] != a[i][j]) {
				break;
			}			
			int l1 = i + 1;
			int r1 = r;
			while (l1 + 1 < r1) {
				int mid = (l1 + r1) / 2;
				if (a[mid].size() <= j || a[mid][j] <= a[i][j]) {
					l1 = mid;
				} else {
					r1 = mid;
				}
			}
			
			ans += r1 - (i + 1);
			r = r1;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}