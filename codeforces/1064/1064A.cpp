#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int a[3], ans;
int main(){
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	sort(a, a + 3);
	ans = a[2] - a[1] - a[0] + 1;
	ans = max(ans, 0);
	printf("%d\n", ans);
	return 0;
}
