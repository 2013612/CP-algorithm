#include<iostream>
#include<vector>
using namespace std;
int N, A[3], sum, ans;
int main() {
	cin >> N >> A[0] >> A[1] >> A[2];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			sum = N - i * A[0] - j * A[1];
			if (sum >= 0 && sum % A[2] == 0) {
				ans = max(ans, i + j + sum/A[2]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

