#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

const int M = 1000007;
int T, N, a[200006], p[M], b[200006];
vector<int> q;

int gcd(int a, int b) {
	return b == 0? a : gcd(b, a % b);
}

void prime() {
	for (int i = 1; i <= M; i++) {
		p[i] = i;
	}
	for (int i = 2; i <= M; i++) {
		if (p[i] == i) {
			q.push_back(i);
		}
		for (auto j : q) {
			if (i * j > M || j > p[i]) {
				break;
			}
			p[i * j] = p[i];
		}
	}
}

int main() {
	scanf("%d", &T);
	prime();
	while (T-- > 0) {
		scanf("%d", &N);
		int g = 0;
		bool same = true;
		int ans = 0;
		int maxi = 0;
		unordered_set<int> fac;
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			g = gcd(g, a[i]);
		}
		for (int i = 0; i < N; i++) {
			a[i] /= g;
			same = same && a[i] == 1;
			maxi = max(maxi, a[i]);
			for (int temp = a[i]; a[i] != 1; ) {
				fac.insert(p[temp]);
				if (p[temp] == temp) {
					break;
				}
				temp = p[temp];
			}
		}
		if (same) {
			printf("0\n");
			continue;
		}
		for (auto x : fac) {
			//cout << x << endl;
			int temp = 0;
			for (int j = 0; j < 2 * N; j++) {
				if (a[j % N] % x == 0) {
					temp++;
				} else {
					ans = max(ans, temp);
					temp = 0;
					if (j > N) {
						break;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
