#include<iostream>
using namespace std;

int n, a[103], ans;
bool b[103];
int main() {
	ans = 1e9;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		string s;
		cin >> s;
		b[i] = s == "L";
	}
	
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			int cnt = 0;
			int l = i;
			int r = j;
			for (int k = 0; k < n; k++) {
				if (b[k]) {
					cnt += abs(l - a[k]);
					l = a[k];
				} else {
					cnt += abs(r - a[k]);
					r = a[k];
				}
			}
			ans = min(ans, cnt);
		}
	}
	
	printf("%d\n", ans);
	return 0;
}