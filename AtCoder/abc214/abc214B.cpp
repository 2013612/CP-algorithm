#include<iostream>
using namespace std;

int S, T, ans;
int main() {
	cin >> S >> T;
	for (int i = 0; i <= S; i++) {
		for (int j = 0; i + j <= S; j++) {
			for (int k = 0; i + j + k <= S; k++) {
				if (i * j * k <= T) {
					ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
