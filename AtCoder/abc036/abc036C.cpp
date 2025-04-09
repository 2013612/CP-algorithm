#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> a, b;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		a.push_back(t);
		b.push_back(t);
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for (int i = 0; i < n; i++) {
		printf("%d\n", lower_bound(a.begin(), a.end(), b[i]) - a.begin());
	}
	return 0;
}

