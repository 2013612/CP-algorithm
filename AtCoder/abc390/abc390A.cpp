#include<iostream>
#include<algorithm>
using namespace std;

int n, a[10], b[10];
bool can;

int main() {
	n = 5;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + n);
	
	for (int i = 0; i < n - 1; i++) {
		swap(a[i], a[i + 1]);
		for (int j = 0; j < n; j++) {
			if (a[j] != b[j]) {
				break;
			}
			
			if (j == n - 1) {
				can = true;
			}
		}
		swap(a[i], a[i + 1]);
	}
	
	if (can) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}