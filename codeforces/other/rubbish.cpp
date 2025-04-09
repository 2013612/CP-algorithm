#include<iostream>
#include<algorithm>
using namespace std;

int n,a[100006];
bool b[100006][100006];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int num = 0;
	for (int i = 0; i < n-1 ; i++) {
		for (int j = 1; j < n; j++) {
			if (!b[a[i]][a[j]]) {
				num++;
				b[a[i]][a[j]] = true;
			}
		}
	}
	printf("%d\n", num);
	return 0;
} 
