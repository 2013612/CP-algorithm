#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int, int> pii;

int N, ans;
pii a[2004];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		l *= 2;
		r *= 2;
		if (t == 3 || t == 4) {
			l++;
		}
		if (t == 2 || t == 4) {
			r--;
		}
		a[i] = make_pair(l, r);
	}
	sort(a, a + N);
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[j].first <= a[i].second) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
