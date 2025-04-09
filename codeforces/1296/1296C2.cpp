#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int T, N;
vector<pair<int, int>> ans;
pair<int, int> a[300006];
pair<int, int> Z = make_pair(0, 0);

bool bin(int mid) {
	mid *= 2;
	//cout << "%" << mid << endl;
	pair<int, int> temp = Z;
	bool done = false;
	//cout << l << " " << r << endl;
	for (int j = 0; j < mid; j++) {
		temp = make_pair(temp.first + a[j].first, temp.second + a[j].second);
	}
	//cout << l << " " << r << endl;
	if (temp == Z) {
		done = true;
		ans.push_back(make_pair(1, mid));
		//cout << "#" << 1 << " " << mid << endl;
	} else {
		for (int j = mid; j < N - (mid - 1); j++) {
			temp = make_pair(temp.first + a[j].first - a[j - mid].first, temp.second + a[j].second - a[j - mid].second);
			if (temp == Z) {
				done = true;
				ans.push_back(make_pair(j - mid + 2, j + 1));
				//cout << "@" << j - mid + 2 << " " << j + 1 << endl;
				break;
			}
		}
	}
	return done;
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		string s;
		cin >> s;
		ans.clear();
		for (int j = 0; j < N; j++) {
			if (s[j] == 'L') {
				a[j] = make_pair(-1, 0);
			} else if (s[j] == 'R') {
				a[j] = make_pair(1, 0);
			} else if (s[j] == 'U') {
				a[j] = make_pair(0, 1);
			} else {
				a[j] = make_pair(0, -1);
			}
		}
		int l = 1;
		int r = N / 2;
		while (l < r) {
			//cout << l << " " << r << endl;
			int mid = (l + r) /2;
			if (!bin(mid)) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		bin(l);
		bin(r);
		if (ans.empty()) {
			cout << -1 << endl;
		} else {
			pair<int, int> temp = ans[0];
			for (auto x:ans) {
				//cout << "!" << x.first << " " << x.second << endl;
				if (temp.second - temp.first > x.second - x.first) {
					temp = x;
				}
			}
			cout << temp.first << " " << temp.second << endl;
		}
	}
	return 0;
}
