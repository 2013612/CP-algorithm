#include<iostream>
using namespace std;

int N, pt[1004][2], ans;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &pt[i][0], &pt[i][1]);
	}
	
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (abs(pt[i][1] - pt[j][1]) <= abs(pt[i][0] - pt[j][0])) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
