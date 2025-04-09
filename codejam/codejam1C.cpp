#include<iostream>
#include<string>
using namespace std;

int T, A, max_leng;
string C[300], ans;
bool sur[300], can;
int main(){
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> A;
		for (int j = 0; j < A; j++) {
			cin >> C[j];
			sur[j] = true;
		}
		int survive = A;
		ans.clear();
		can = true;
		for (int j = 0; survive > 0 ; j++) {
			bool exist[] = {false, false, false};
			for (int k = 0; k < A; k++) {
				if (!sur[k]) {
					continue;
				}
				int p = j % C[k].length();
				if (C[k][p] == 'P') {
					exist[0] = true;
				} else if (C[k][p] == 'S') {
					exist[1] = true;
				} else {
					exist[2] = true;
				}
			}
			if (exist[0] && exist[1] && exist[2]) {
				can = false;
				break;
			} else if (exist[0] && exist[1]) {
				ans.push_back('S');
			} else if (exist[0] && exist[2]) {
				ans.push_back('P');
			} else if (exist[1] && exist[2]) {
				ans.push_back('R');
			} else if (exist[0]) {
				ans.push_back('S');
			} else if (exist[1]) {
				ans.push_back('R');
			} else {
				ans.push_back('P');
			}
			for (int k = 0; k < A; k++) {
				if (!sur[k]) {
					continue;
				}
				int p = j % C[k].length();
				if (ans[j] == 'P' && C[k][p] == 'R') {
					sur[k] = false;
					survive--;
				}
				if (ans[j] == 'S' && C[k][p] == 'P') {
					sur[k] = false;
					survive--;
				}
				if (ans[j] == 'R' && C[k][p] == 'S') {
					sur[k] = false;
					survive--;
				}
			}
		}
		if (!can) {
			printf("Case #%d: IMPOSSIBLE\n", i);
		} else {
			printf("Case #%d: ", i);
			cout << ans << endl;
		}
	}
	return 0;
}
