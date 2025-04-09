#include<iostream>
using namespace std;

int main() {
	int n, a;
	scanf("%d %d", &n, &a);
	int cur = 0;
	
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		
		cur = max(cur, t) + a;
		printf("%d\n", cur);
	}
	
	return 0;
}