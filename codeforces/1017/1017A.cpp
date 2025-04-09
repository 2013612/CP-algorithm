#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, a[1004], b;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &b);
			a[i] += b;
		}
	} 
	b = a[0];
	sort(a, a+n);
	reverse(a, a+n);
	for (int i = 0; i < n; i++) {
		if (a[i] == b) {
			printf("%d", i + 1);
			return 0;
		}
	}
	return 0;
}
