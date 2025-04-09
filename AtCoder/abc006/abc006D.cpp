#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> a;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		if (a.empty() || a.back() < t) {
			a.push_back(t);
		} else {
			int p = lower_bound(a.begin(), a.end(), t) - a.begin();
			a[p] = t;
		}
	}
	printf("%d\n", n - a.size());
	return 0;
}
