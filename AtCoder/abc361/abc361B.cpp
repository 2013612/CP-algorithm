#include<iostream>
using namespace std;

int a[3], b[3], c[3], d[3];
int main() {
	scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
	scanf("%d %d %d %d %d %d", &c[0], &c[1], &c[2], &d[0], &d[1], &d[2]);
	
	int x = max(min(b[0], d[0]) - max(a[0], c[0]), 0);
	int y = max(min(b[1], d[1]) - max(a[1], c[1]), 0);
	int z = max(min(b[2], d[2]) - max(a[2], c[2]), 0);
	
	if (1ll * x * y * z > 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}