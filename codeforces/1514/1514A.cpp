#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		bool can = false;
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			for (int k = 1; k <= 100; k++) {
				if (k * k == temp) {
					break;
				}
				if (k == 100) {
					can = true;
				}
			}
		}
		if (can) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
