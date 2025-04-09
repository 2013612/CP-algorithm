#include<iostream>
#include<string>
using namespace std;

int T, N;
string L, ans;
int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> L;
		int turn = 0;
		for (int j = 0; j < 2 * N - 2; j++) {
			if (L[j] == 'E') {
				ans += 'S';
			} else {
				ans += 'E';
			}
		}
		cout << "Case #" << i << ": " << ans << endl;
		ans.clear();
	}
	return 0;
}
