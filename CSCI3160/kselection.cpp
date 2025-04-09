#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

int N, pos, a[100006];

int ksel(int V[], int K, int length) {
	/*for (int i = 0; i < length; i++) {
		cout << V[i] << " ";
	}
	cout << endl;*/
	int temp3[length];
	int temp, temp2, l, r;
	while (true) {
		temp = rand() % length;
		temp2 = V[temp];
		l = 0;
		r = length - 1;
		for (int i = 0; i < length; i++) {
			if (i == temp) {
				continue;
			}
			if (V[i] < temp2) {
				temp3[l] = V[i];
				l++;
			} else {
				temp3[r] = V[i];
				r--;
			}
		}
		//cout << temp2 << endl;
		if (l + 1 == K) {
			return temp2;
		} else if (l >= N/3 && l <= 2 * N / 3) {
			break;
		}
	}
	if (l + 1 > K) {
		return ksel(temp3, K, l);
	} else {
		return ksel(temp3 + (l + 1), K - (l + 1), length - l);
	}
}

int main() {
	scanf("%d %d", &N, &pos);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int ans = ksel(a, pos, N);
	cout << ans << endl;
	sort(a, a + N);
	cout << a[pos - 1] << endl;
	return 0;
}
