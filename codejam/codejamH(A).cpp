#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int T, P, N;
string a[103];
bool b[103];
long long two[55];
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	two[0] = 1;
	for (int i = 1; i < 55; i++) {
		two[i] = 2 * two[i - 1];
	}
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &P);
		for (int j = 0; j < P; j++) {
			char c[60];
			scanf("%s", c);
			a[j] = c;
		}
		sort(a, a + P);
		for (int j = 0; j < P - 1; j++) {
			if (!b[j]) {
				for (int k = j + 1; k < P; k++) {
					for (int l = 0; l < a[j].size(); l++) {
						if (a[j][l] != a[k][l]) {
							break;
						}
						if (l + 1 == a[j].size()) {
							b[k] = true;
						}
					}
				}
			}
		}
		long long ans = two[N];
		for (int j = 0; j < P; j++) {
			if (!b[j]) {
				ans -= two[N - a[j].size()];
			}
		}
		printf("Case #%d: %lld\n", i + 1, ans);
		for (int j = 0; j < 103; j++) {
			b[j] = false;
		}
	}
	return 0;
}
