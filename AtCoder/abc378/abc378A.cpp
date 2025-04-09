#include<iostream>
#include<algorithm>
using namespace std;

int a[10], ans;

int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + 4);
	
	if (a[0] == a[1] && a[2] == a[3]) {
		ans = 2;
	} else if (a[0] == a[1] || a[1] == a[2] || a[2] == a[3]) {
		ans = 1;
	}
	
	printf("%d\n", ans);
	
	return 0;
}