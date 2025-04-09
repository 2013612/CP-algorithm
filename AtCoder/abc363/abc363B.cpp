#include<iostream>
#include<algorithm>
using namespace std;

int n, t, p, l[103];

int main() {
	scanf("%d %d %d", &n, &t, &p);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &l[i]);
	}
	sort(l, l + n, greater<int>());
	
	printf("%d\n", max(t - l[p - 1], 0));
	
	return 0;
}