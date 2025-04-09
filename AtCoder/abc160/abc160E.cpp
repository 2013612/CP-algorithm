#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long A, B, C, X, Y, ans;
vector<long long> p, q, r;
int main() {
	cin >> X >> Y >> A >> B >> C;
	for (int i = 0; i < A; i++) {
		long long temp;
		cin >> temp;
		p.push_back(temp);
	}
	for (int i = 0; i < B; i++) {
		long long temp;
		cin >> temp;
		q.push_back(temp);
	}
	for (int i = 0; i < C; i++) {
		long long temp;
		cin >> temp;
		r.push_back(temp);
	}
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	sort(r.begin(), r.end());
	int count = 0;
	while (X + Y > count) {
		int maxi;
		if (X == 0) {
			maxi = max(q.back(), r.back());
		} else if (Y == 0) {
			maxi = max(p.back(), r.back());
		} else {
			maxi = max(p.back(), max(q.back(), r.back()));
		}
		if (maxi == p.back()) {
			ans += p.back();
			p.pop_back();
			X--;
		} else if (maxi == q.back()) {
			ans += q.back();
			q.pop_back();
			Y--;
		} else {
			ans += r.back();
			r.pop_back();
			count++;
		}
	}
	cout << ans << endl;
	return 0;
}
