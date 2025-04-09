#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int T, N, M, ans;
int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		if (N % M == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
