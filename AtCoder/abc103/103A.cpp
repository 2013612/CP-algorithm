#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n[3];
int main(){
	scanf("%d %d %d", &n[0], &n[1], &n[2]);
	sort(n, n + 3);
	int ans = 0;
	ans += n[2] - n[1];
	ans += n[1] - n[0];
	printf("%d\n", ans);
	return 0;
}
