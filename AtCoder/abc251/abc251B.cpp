#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

int n, ans, a[200006], w;
unordered_set<int> us;
int main() {
	scanf("%d %d", &n, &w);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > w) {
			continue;
		}
		us.insert(a[i]);
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] > w) {
				continue;
			}
			us.insert(a[i] + a[j]);
			for (int k = j + 1; k < n; k++) {
				if (a[i] + a[j] + a[k] <= w) {
					us.insert(a[i] + a[j] + a[k]);
				}
			}
		}
	}
	printf("%d\n", us.size());
	return 0;
}