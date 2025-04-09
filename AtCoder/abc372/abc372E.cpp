#include<iostream>
#include<vector>
using namespace std;

int n, q, a[200006];
vector<int> v[200006];

int find(int x) {
	if (a[x] == x) {
		return x;
	}
	
	return a[x] = find(a[x]);
}

void merge(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) {
		return;
	}
	int i = 0;
	int j = 0;
	vector<int> nv;
	while (nv.size() < 10 && (i < v[fx].size() || j < v[fy].size())) {
		if (i == v[fx].size()) {
			nv.push_back(v[fy][j]);
			j++;
		} else if (j == v[fy].size()) {
			nv.push_back(v[fx][i]);
			i++;
		} else {
			if (v[fx][i] > v[fy][j]) {
				nv.push_back(v[fx][i]);
				i++;
			} else {
				nv.push_back(v[fy][j]);
				j++;
			}
		}
	}
	a[fy] = fx;
	v[fx] = nv;
}

int main() {
	scanf("%d %d", &n, &q);
	
	for (int i = 1; i <= n; i++) {
		a[i] = i;
		v[i].push_back(i);
	}
	
	for (int i = 0; i < q; i++) {
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if (t == 1) {
			merge(x, y);
		} else {
			int fx = find(x);
			if (v[fx].size() < y) {
				printf("-1\n");
			} else {
				printf("%d\n", v[fx][y - 1]);
			}
		}
	}
	
	return 0;
}