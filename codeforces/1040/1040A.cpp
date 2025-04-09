#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, ans, A, B, c1[1004], c2[1004];
int main(){
	scanf("%d %d %d", &N, &A, &B);
	for (int i = 0; i < N; i++) {
		scanf("%d", &c1[i]);
		c2[N - i - 1] = c1[i]; 
	}
	if (N % 2 == 1 && c1[N/2] == 2) {
		ans += min(A, B);
	}
	for (int i = 0; i < N/2; i++) {
		if (c1[i] == 0) {
			if (c2[i] == 1) {
				ans = -1;
				break;
			} else if (c2[i] == 2){
				ans += A;
			}
		} else if (c1[i] == 1) {
			if (c2[i] == 0) {
				ans = -1;
				break;
			} else if (c2[i] == 2) {
				ans += B;
			}
		} else {
			if (c2[i] == 0) {
				ans += A;
			} else if (c2[i] == 1) {
				ans += B;
			} else {
				ans += 2 * min(A, B);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
