#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, P, T;
int main(){
	scanf("%d %d %d", &N, &P, &T);
	int ans = P;
	ans -= T/9*3;
	T = T % 9;
	if (T == 5 || T == 7) {
		ans -= 1;
	} else if (T == 8) {
		ans -= 2;
	}
	if (ans <= 0 || ans > N) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}
