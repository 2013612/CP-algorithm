#include<iostream>
using namespace std;

int N, L, A, t[100006], l[100006], ans;
int main(){
	scanf("%d %d %d", &N, &L, &A);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &t[i], &l[i]);
	}
	if (N == 0) {
		printf("%d\n", L/A);
		return 0;
	}
	int time = 0;
	for (int i = 0; i < N; i++) {
		ans += (t[i] - time) / A;
		time = t[i] + l[i];
	}
	ans += (L - time) / A;
	printf("%d\n", ans);
	return 0;
}
