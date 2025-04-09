#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, M, ans, a[400006];

int summ(int N, int K) {
	if (K == 1) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += a[i];
		}
		return sum;
	}
	int len = N - K + 1;
	int temp = a[N - 1];
	int temp2 = N - 1;
	int sum = 0;
	for (int i = N - 1; i > N - len; i--) {
		sum += a[i];
		if (sum > temp) {
			temp = sum;
			temp2 = i;
		}
	}
	return K*temp + summ(temp2 + 1, K - 1);
}

int mini(int N, int K) {
	if (K == M) {
		int sum = 0;
		for (int i = N; i < M; i++) {
			sum += a[i];
		}
		return sum*K;
	}
	int len = (T - N) - (M - K) + 1;
	int temp = a[N];
	int temp2 = N;
	int sum = 0;
	for (int i = N; i < N + len; i++) {
		sum += a[i];
		if (sum < temp) {
			temp = sum;
			temp2 = i;
		}
	}
	return K*temp + mini(temp2, K + 1);
}

int main(){
	scanf("%d %d", &T, &M);
	for (int i = 0; i < T; i++) {
		scanf("%d", &a[i]);
	}
	int temp = summ(T, M);
	int temp2 = mini(0, 1);
	printf("%d\n", max(temp, temp2));
	return 0;
} 
