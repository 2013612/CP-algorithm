#include<iostream>
#include<algorithm>
using namespace std;

int n,a[100006],b[100006];
bool c[100006];
int main() {
	scanf("%d", &n);
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[a[i]]++; 
		maxi = max(maxi, a[i]);
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (!c[a[i]] && b[a[i]] > 0) {
			b[a[i]]--;
			for (int j = 1; j <= maxi; j++) {
				if (b[j] > 0) {
					num++;
				}
			}
			c[a[i]] = true;
		} else {
			b[a[i]]--;
		}
	}
	printf("%d\n", num);
	return 0;
} 
