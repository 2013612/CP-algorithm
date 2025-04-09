#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool last;
int N, a[300006], b[300006], ans, cou;
priority_queue<int,vector<int>,greater<int>> pq;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= N; i++) {
		if (i != b[i - 1]) {
			break;
		}
		if (i == N) {
			cout << 0 << endl;
			return 0;
		}
	}
	if (b[N - 1] != 0) {
		for (int i = 0; i < b[N - 1]; i++) {
			if (b[N - 1 - i] != b[N - 1] - i) {
				last = true;
				break;
			}
		}
	} else {
		last = true;
	}
	if (!last) {
		for (int i = 0; i < N; i++) {
			if (a[i] != 0) {
				pq.push(a[i]);
			}
		}
		int cou2 = 0;
		for (int i = b[N - 1] + 1; i <= N;) {
			if (pq.size() == 0) {
				break;
			}
			if (pq.top() == i) {
				pq.pop();
				i++;
				if (b[cou2] != 0) {
					pq.push(b[cou2]);
				}
				cou2++;
			} else {
				break;
			}
			if (i == N + 1) {
				cout << N - b[N - 1] << endl;
				return 0;
			}
		}
		cout << N + N - b[N - 1] + 1 << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (a[i] != 0) {
			pq.push(a[i]);
		}
	}
	for (int i = 1; i <= N;) {
		if (pq.size() == 0) {
			if (b[cou] != 0) {
				pq.push(b[cou]);
			}
			ans++;
			cou++;
			continue;
		}
		if (pq.top() == i) {
			pq.pop();
			i++;
			if (b[cou] != 0) {
				pq.push(b[cou]);
			}
			cou++;
		} else {
			if (b[cou] != 0) {
				pq.push(b[cou]);
			}
			ans++;
			cou++;
		}
	}
	cout << ans + N << endl;
	return 0;
}
