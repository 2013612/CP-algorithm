#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int N, a[5004], ans, pos[5004];
vector<int> u;
set<int> v;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		pos[i] = i;
		scanf("%d", &a[i]);
		if (a[i] == 1) {
			u.push_back(i);
		} else {
			v.insert(i);
		}
	}
	for (int i = 0; i < u.size(); i++) {
		set<int>::iterator temp = v.upper_bound(u[i]);
		int right, left;
		if (temp == v.end()) {
			right = 1e9;
		} else {
			right = *temp;
		}
		if (temp == v.begin()) {
			left = 1e9;
		} else {
			temp--;
			left = *temp;
		}
		//cout << left << " " << right << endl;
		if (abs(u[i] - left) <= abs(right - u[i])) {
			pos[u[i]] = left;
			v.erase(left);
		} else {
			pos[u[i]] = right;
			v.erase(right);
		}
		for (int j = i; j > 0; j--) {
			if (pos[u[j]] < pos[u[j - 1]]) {
				int t = pos[u[j]];
				pos[u[j]] = pos[u[j - 1]];
				pos[u[j - 1]] = t;
			} else {
				break;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		//cout << pos[i] << " ";
		ans += abs(pos[i] - i);
	}
	printf("%d\n", ans);
	return 0;
}
