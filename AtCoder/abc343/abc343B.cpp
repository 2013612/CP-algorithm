#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[100006];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			int t;
			scanf("%d", &t);
			if (t) {
				printf("%d ", j);
			}
		}
		
		printf("\n");
	}
	
	return 0;
}