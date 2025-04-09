#include<iostream>
using namespace std;

int main() {
	int n, t, a;
	scanf("%d %d %d", &n, &t, &a);
	
	if (t != a && n < 2 * max(t, a)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}