#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, q, ans;
bool t[1003];

int main() {
	scanf("%d %d", &n, &q);
	
	for (int i = 1; i <= n; i++) {
		t[i] = true;
	}
	
	for (int i = 0; i < q; i++) {
		int temp;
		scanf("%d", &temp);
		t[temp] = !t[temp];
	}
	
	for (int i = 1; i <= n; i++) {
		ans += t[i];
	}
	
	printf("%d\n", ans);
	
	return 0;
}