#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, k, a[500006];
set<int> s;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + k);
	int t = a[0];
	for (int i = 0; i < k; i++) {
		s.insert(a[i]);
	}
	printf("%d\n", t);
	auto now = s.lower_bound(t);
	for (int i = k; i < n; i++) {
		s.insert(a[i]);
		if (a[i] > t) {
			now++;
			t = *now;
		}
		printf("%d\n", t);
	}
	return 0;
}
