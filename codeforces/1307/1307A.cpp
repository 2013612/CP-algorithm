#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int T, N, D, a[1004], ans;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &D);
		ans = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
			//cout << "@" << <<a[i] << endl;
		}
		//cout << "!" << a[0] << endl;
		for (int j = 1; j < N; j++) {
			for (int k = 0; k < a[j]; k++) {
				if (D < j) {
					break;
				}
				D -= j;
				ans++;
			}
		}
		//cout << "!" << a[0] << endl;
		printf("%d\n", ans + a[0]);
	}
	return 0;
}
