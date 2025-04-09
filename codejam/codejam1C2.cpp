#include<iostream>
#include<string>
#include<map>
using namespace std;

int T, F, fac[10];
char fig[600];
string ans;
bool checked[600];
map<char, int> mymap;
int main() {
	cin >> T >> F;
	fac[0] = 1;
	for (int i = 1; i < 10; i++) {
		fac[i] = fac[i - 1] * i;
	}
	for (int i = 1; i <= T; i++) {
		int count = 0;
		ans.clear();
		for (int j = 0; j < 600; j++) {
			checked[j] = false;
		}
		bool used[] = {false, false, false, false, false};
		for (int j = 1; j <= 4; j++) {
			mymap['A'] = 0;
			mymap['B'] = 0;
			mymap['C'] = 0;
			mymap['D'] = 0;
			mymap['E'] = 0;
			for (int k = j; k <= 595; k += 5) {
				if (checked[k]) {
					continue;
				}
				cout << k << endl;
				//cout << checked[k] << endl;
				cin >> fig[k];
				mymap[fig[k]]++;
				count++;
			}
			for (char c = 'A'; c <= 'E'; c++) {
				//cout << "@" << mymap[c] << " " << fac[5 - j] << endl;
				if (mymap[c] == fac[5 - j] - 1 && !used[c - 'A']) {
					ans.push_back(c);
					used[c - 'A'] = true;
				}
			}
			//cout << '!' << ans[j - 1] << endl;
			for (int k = j; k <= 595; k += 5) {
				//cout << fig[k] << endl;
				if (ans[j - 1] != fig[k]) {
					for (int l = k; ; l++) {
						if (l != k && l % 5 == 1) {
							break;
						}
						//cout << l << endl;
						checked[l] = true;
						//cout << checked[k] << endl;
					}
				}
			}
		}
		for (int j = 0; j < 5; j++) {
			if (!used[j]) {
				ans.push_back('A' + j);
				break;
			}
		}
		while (count < F) {
			cout << 1 << endl;
			cin >> fig[1];
			count++;
		}
		cout << ans << endl;
		char p;
		cin >> p;
		if (p == 'N') {
			break;
		}
	}
	return 0;
}
