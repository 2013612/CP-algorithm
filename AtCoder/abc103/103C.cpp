#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n, a[10005];

/*int f(int m) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += m % a[i];
	}
	return ans;
} */
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		max += a[i]-1;
	}
	printf("%d\n", max);
	return 0;
}
