#include<iostream>
#include<queue>
#include<map>
using namespace std;

const int x[4] = {1, 0, -1, 0};
const int y[4] = {0, 1, 0, -1};

int h, w, d, ans;
string s[1003];

void cnt() {
	queue<pair<int, int>> q;
	map<pair<int, int>, int> m;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == 'H') {
				q.push({i, j});
				m[{i, j}] = 0;
			}
		}
	}
	
	while (q.size()) {
		auto [u, v] = q.front();
		q.pop();
		
		if (m[{u, v}] == d) {
			continue;
		}
		
		for (int i = 0; i < 4; i++) {
			int new_u = u + x[i];
			int new_v = v + y[i];
			if (m.count({new_u, new_v}) || new_u < 0 || new_u >= h || new_v < 0 || new_v >= w || s[new_u][new_v] == '#') {
				continue;
			}
			
			if (s[new_u][new_v] == '.') {
				s[new_u][new_v] = 'C';
			}
			
			q.push({new_u, new_v});
			m[{new_u, new_v}] = m[{u, v}] + 1;
		}
	}
}

int main() {
	scanf("%d %d %d", &h, &w, &d);
	
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	
	cnt();
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == 'H' || s[i][j] == 'C') {
				ans++;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}