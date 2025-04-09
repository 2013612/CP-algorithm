#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int h, w, n;
pair<int, int> c[200006];
pair<pair<int, int>, int> d[200006], e[200006];
vector<int> v[200006];

int main() {
	scanf("%d %d %d", &h, &w, &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c[i].first, &c[i].second);
		d[i] = {c[i], i + 1};
		e[i] = {{c[i].second, c[i].first}, i + 1};
	}
	d[n] = {{1, 1}, 0};
	d[n + 1] = {{h, w}, n + 1};
	e[n] = {{1, 1}, 0};
	e[n + 1] = {{w, h}, n + 1};
	sort(d, d + n + 2);
	sort(e, e + n + 2);
	
	for (int i = 0; i < n + 1; i++) {
		
	}
	
	return 0;
}