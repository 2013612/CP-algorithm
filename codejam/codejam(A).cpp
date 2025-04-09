#include<iostream>
#include<string>
using namespace std;

int T;
string N, ans[2];
int main(){
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		for (int j = 0; j < N.length(); j++) {
			int temp = N[j] - '0';
			if (temp == 4) {
				ans[0].push_back('3');
				ans[1].push_back('1');
			} else {
				ans[0].push_back(N[j]);
				ans[1].push_back('0');
			}
		}
		int digit = 0;
		for (int j = 0; j < ans[1].length(); j++) {
			if (ans[1][j] != '0') {
				digit = j;
				break;
			}
		}
		cout << "Case #" << i << ": " << ans[0] << " " << ans[1].substr(digit) << endl;
		ans[0].clear();
		ans[1].clear();
	}
	return 0;
}
