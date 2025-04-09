#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N, M, ans;
int main(){
	scanf("%d %d", &N, &M);
	int temp = M/N;
	int stop;
	for (int i = 1; ; i++) {
		if (i*i > M) {
			stop = i - 1;
			break;
		}
	}
	for (int i = 1; i <= min(stop, temp); i++) {
		if (M % i == 0) {
			if (M / i <= temp) {
				ans = max(ans, M/i);
			}
			ans = max(ans, i);
		}
	}
	printf("%d\n", ans);
	return 0;
}
