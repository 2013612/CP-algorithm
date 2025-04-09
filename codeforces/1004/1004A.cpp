#include<iostream>
using namespace std;

int n, d, a[102];
int main(){
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int ans = 2;
	for (int i = 0; i < n; i++) {
		if (a[i+1] - a[i] == 2*d && i != n-1) {
			ans++;
		} else if (a[i+1] - a[i] > 2*d && i != n-1) {
			ans+=2;
		}
	}
	printf("%d\n", ans);
	return 0;
}
