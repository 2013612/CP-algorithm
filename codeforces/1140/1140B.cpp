#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, ans;
char c[1004];
int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		scanf("%s", c);
		int left, right;
		for (int j = 0; j < N; j++) {
			if (c[j] == '>') {
				left = j;
				break;
			}
		}
		for (int j = N - 1; j >= 0; j--) {
			if (c[j] == '<') {
				right = N - j - 1;
				break;
			}
		}
		printf("%d\n", min(left, right));
	}
	return 0;
}
