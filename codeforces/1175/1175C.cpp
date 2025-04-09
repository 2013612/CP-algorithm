#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, K, ans, a[300006];

int abs(int x) {
	return x < 0? -x: x;
}

int f(int x, int k) {
	vector<int> temp;
	for (int i = 0; i < N; i++) {
		temp.push_back(abs(a[i] - x));
	}
	sort(temp.begin(), temp.end());
	return temp[k];
}

int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &K);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		int l = 0;
		int r = N - 1;
		int div = a[N - 1] - a[0];
		for (int j = 0; j < N - K; j++) {
			if (a[j + K] - a[j] < div) {
				div = a[j + K] - a[j];
				l = j;
				r = j + K;
			}
		}
		int temp, temp2, temp3;
		long long sum = 0;
		for (int j = l; j <= r; j++) {
			sum += a[j];
		}
		temp = sum/(K + 1);
		temp2 = temp - 1;
		temp3 = temp + 1;
		int dif = 0;
		int dif2 = 0;
		for (int j = l; j <= r; j++) {
			dif = max(dif, abs(temp - a[j]));
			dif2 = max(dif2, abs(temp2 - a[j]));
		}
		if (dif2 < dif) {
			temp = temp2;
		}
		dif = 0;
		dif2 = 0;
		for (int j = l; j <= r; j++) {
			dif = max(dif, abs(temp - a[j]));
			dif2 = max(dif2, abs(temp3 - a[j]));
		}
		if (dif2 < dif) {
			temp = temp3;
		}
		printf("%d\n", temp);
	}
	return 0;
} 
