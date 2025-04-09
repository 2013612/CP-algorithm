#include<iostream>
#include<set>
using namespace std;

int x[9] = {2, 1, -1, -2, -2, -1, 1, 2, 0};
int y[9] = {1, 2, 2, 1, -1, -2, -2, -1, 0};

int n, m;
long long ans = 0;
set<pair<int, int>> s;

bool in(int a) {
	return a > 0 && a <= n;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		for (int j = 0; j < 9; j++) {
			if (in(a + x[j]) && in(b + y[j])) {
				s.insert({a + x[j], b + y[j]});
			}
		}
	}
	
	printf("%lld\n", 1ll * n * n - s.size());
	
	return 0;
}