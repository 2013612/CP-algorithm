#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, b[100006];
vector<int> a;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a.empty() || a.back() <= b[i]) {
			a.push_back(b[i]);
		} else {
			int p = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
			a[p] = b[i];
		}
	}
	printf("%d\n", a.size());
	return 0;
}
