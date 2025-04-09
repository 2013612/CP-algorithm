#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, ans, a[200006], N;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		ans = 1;
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		sort(a, a + N);
		for (int j = N - 1; j >= 0; j--) {
			if (a[j] > N) {
				//cout << "!" << a[j] - N << endl;
				N--;
			} else {
				ans = j + 2;
				break;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
