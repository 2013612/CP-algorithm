#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, a[1004][2];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j][0]);
		}
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j][1]);
		}
		int k = a[0][1];
		bool wtf = true;
		for (int j = 0; j < N; j++) {
			if (k != a[j][1]) {
				wtf = false;
			}
		}
		if (!wtf) {
			cout << "Yes" << endl;
		} else {
			bool suc = true;
			for (int j = 0; j < N - 1; j++) {
				if (a[j][0] > a[j + 1][0]) {
					suc = false;
					break;
				}
			}
			if (suc) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}
