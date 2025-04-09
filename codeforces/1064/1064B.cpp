#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, a, ans, b[50];
int main(){
	scanf("%d", &N);
	b[0] = 1;
	for (int i = 1; i < 32; i++) {
		b[i] = 2 * b[i - 1];
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		ans = 0;
		while (a > 0) {
			if (a % 2 == 1) {
				ans++;
			}
			a /= 2;
		}
		printf("%d\n", b[ans]);
	}
	return 0;
}
