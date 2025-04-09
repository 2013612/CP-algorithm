#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, a, b;
int main(){
	scanf("%d", &N);
	int ans = 0;
	int rep = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &b);
		if (i != 0) {
			if (b <= 2*a) {
				rep++;
			} else {
				ans = max(ans, rep);
				rep = 1;
			}
		}
		a = b;
	}
	ans = max(ans, rep);
	printf("%d\n", ans);
	return 0;
}
