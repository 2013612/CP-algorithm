#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;
vector<int> v;

int main() {
	scanf("%d", &n);
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		if (a[i] == 1) {
			int x;
			scanf("%d", &x);
			v.push_back(x);
		} else {
			int k = 0;
			if (v.size()) {
				k = v.back();
				v.pop_back();
			}
			printf("%d\n", k);
		}
	}
	
	return 0;
}