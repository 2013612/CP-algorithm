#include<iostream>
#include<atcoder/all>
#include<unordered_set>
using namespace std;
using namespace atcoder;
typedef modint998244353 mint;

string n;
int m;
unordered_set<int> us[10005];
mint ans, fac[20005];

mint ncr(int a, int b) {
	if (a < b) {
		return 0;
	}
	return fac[a] / fac[b] / fac[a - b];
}

int main() {
	cin >> n;
	scanf("%d", &m);
	fac[0] = 1;
	for (int i = 1; i < 20000; i++) {
		fac[i] = fac[i - 1] * i;
	}
	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		us[0].insert(k);
	}
	for (int i = 0; i < n.size(); i++) {
		us[i + 1] = us[i];
		us[i + 1].erase(n[i] - '0');
	}
	for (int i = n.size() - 1; i >= 0; i--) {
		for (int j = n[i] - '0' - 1; j >= 0; j--) {
			unordered_set<int> t = us[i];
			t.erase(j);
			int free = n.size() - i - 1;
			if (free < t.size()) {
				continue;
			}
			ans += ncr(free + 9, free);
			ans -= ncr(free + 9 - t.size(), free);
		}
	}
	printf("%d\n", ans);
}
