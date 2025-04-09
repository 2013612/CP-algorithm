#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N, k1, k2, w, b;
		scanf("%d %d %d", &N, &k1, &k2);
		scanf("%d %d", &w, &b);
		w -= k1 / 2  + k2 /2;
		if (k1 % 2 == 1 && k2 % 2 == 1) {
			w -= 1;
		}
		b -= (N - k1) / 2 + (N - k2) / 2;
		if ((N - k1) % 2 == 1 && (N - k2) % 2 == 1) {
			b -= 1;
		}
		//cout << w << " " << b << endl;
		if (w <= 0 && b <= 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
