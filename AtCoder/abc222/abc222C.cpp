#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;

int N, M;
string s[203];
pair<int, int> p[203];

bool f(pii a, pii b) {
	if (a.first == b.first) {
		return b.second > a.second;
	} else {
		return a.first > b.first;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= 2 * N; i++) {
		cin >> s[i];
		p[i] = {0, i};
	}
	for (int i = 0; i < M; i++) {
		for (int j = 1; j <= N; j++) {
			if (s[p[2 * j - 1].second][i] == 'G' && s[p[2 * j].second][i] == 'C') {
				p[2 * j - 1].first++;
			}
			if (s[p[2 * j - 1].second][i] == 'C' && s[p[2 * j].second][i] == 'P') {
				p[2 * j - 1].first++;
			}
			if (s[p[2 * j - 1].second][i] == 'P' && s[p[2 * j].second][i] == 'G') {
				p[2 * j - 1].first++;
			}
			if (s[p[2 * j - 1].second][i] == 'G' && s[p[2 * j].second][i] == 'P') {
				p[2 * j].first++;
			}
			if (s[p[2 * j - 1].second][i] == 'C' && s[p[2 * j].second][i] == 'G') {
				p[2 * j].first++;
			}
			if (s[p[2 * j - 1].second][i] == 'P' && s[p[2 * j].second][i] == 'C') {
				p[2 * j].first++;
			}
		}
		sort(p + 1, p + 2 * N + 1, f);
	}
	for (int i = 1; i <= 2 * N; i++) {
		printf("%d\n", p[i].second);
	}
	return 0;
}
