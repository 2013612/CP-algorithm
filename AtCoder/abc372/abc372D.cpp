#include<iostream>
#include<vector>
using namespace std;

int n, h[200006], ans[200006];
vector<int> v;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	h[0] = 1e9;
	
	for (int i = n; i >= 0; i--) {
		ans[i] = v.size();
		while (!v.empty() && v.back() < h[i]) {
			v.pop_back();
		}
		v.push_back(h[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}