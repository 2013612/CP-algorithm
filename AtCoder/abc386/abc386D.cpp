#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, a[200006], ans;
vector<pair<int, int>> b, w;

bool f(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int x, y;
		char c;
		scanf("%d %d %c", &x, &y, &c);
		
		if (c == 'B') {
			b.push_back({x, y});
		} else {
			w.push_back({x, y});
		}
	}
	
	sort(b.begin(), b.end(), f);
	sort(w.begin(), w.end(), f);
	
	int k = -1;
	int j = 0;
	for (int i = 0; i < w.size(); i++) {
		while (j < b.size() && b[j].first >= w[i].first) {
			k = max(k, b[j].second);
			j++;
		}
		
		if (w[i].second <= k) {
			printf("No\n");
			return 0;
		}
	}
	
	printf("Yes\n");
	
	return 0;
}