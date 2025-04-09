#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long a, b;
int m, ans;
vector<long long> v;

void count() {
	for (int i = 1; i <= 9; i++) {
		for (int j = i; j <= 9; j++) {
			long long t = 0;
			if (i == j) {
				v.push_back(i);
			} else {
				for (int k = i; k <= j; k++) {
					t = t * 10 + k;
				}
				for (int k = j - 1; k >= i; k--) {
					t = t * 10 + k;
				}
				v.push_back(t);
			}
			
		}
	}
	sort(v.begin(), v.end());
}

void solve() {
	scanf("%lld %lld %d", &a, &b, &m);
	ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= a && v[i] <= b && v[i] % m == 0) {
			ans++;
		}
	}

	printf("%d\n", ans);
}

int main() {
	freopen("cottontail_climb_part_1_input.txt", "r", stdin);
	freopen("cottontail_climb_part_1_output.txt", "w", stdout);
	count();
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}