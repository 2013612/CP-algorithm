#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int T, ans;
vector<int> a[30];
string s, t;
int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		cin >> s >> t;
		for (int j = 0; j < s.length(); j++) {
			a[s[j] - 'a'].push_back(j);
		}
		for (int j = 0; j < t.length(); j++) {
			if (a[t[j] - 'a'].empty()) {
				ans = -1;
				break;
			}
		}
		if (ans != -1) {
			ans = 1;
			int temp = 0;
			for (int j = 0; j < t.length(); ) {
				int num = t[j] - 'a';
				int pos = lower_bound(a[num].begin(), a[num].end(), temp) - a[num].begin();
				//cout << t[j] << ' ' << pos << ' ' << temp << endl;
				if (pos != a[num].size()) {
					//cout << "!" << j << endl;
					temp = a[num][pos] + 1;
					j++;
				} else {
					//cout << "@" << j << endl;
					temp = 0;
					ans++;
				}
			}
		}
		printf("%d\n", ans);
		for (int j = 0; j < 30; j++) {
			a[j].clear();
		}
		ans = 0;
	}
	return 0;
}
