#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, a[100006];

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		bool odd = false;
		bool even = false;
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
			if (a[j] % 2 != 0) {
				odd = true;
			} else {
				even = true;
			}
		}
		if (!odd || ((N % 2 == 0) && !even)) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
	return 0;
}
