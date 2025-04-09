#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int n, k;
map<string, int> m, v;

void g(int l, int r, int pow) {
	if (pow == 0) {
		for (auto [x, y]: v) {
			m[x] += y;
		}
		
		return;
	}
	
	map<string, int> u;
	
	for (int i = l; i <= r; i++) {
		for (auto [x, y]: v) {
			string t = x;
			t.push_back('A' + i);
			sort(t.begin(), t.end());
			u[t] += y;
		}
	}
	
	v = u;
	g(l, r, pow - 1);
}

void f(int len, int pow) {
//	v[""] = 1;
//	g(0, 2, 2);
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			v.clear();
			v[""] = 1;
			g(i, j, pow);
		}
	}
	
	for (auto [x, y]: m) {
		cout << y << " " << x << endl;
	}
	m.clear();
}

int main() {
	scanf("%d %d", &n, &k);
	n = 3;
	k = 2;
	f(n, k);
	
	
	return 0;
}