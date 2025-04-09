#include<iostream>
#include<unordered_set>
using namespace std;

int n;
long long a[20];
unordered_set<long long> us[10004];

void f(int m) {
	int k = m & (-m);
	for (int i = 1; i <= m; i++) {
		if ((i & k) && (i & m) == i) {
			if (us[m - i].empty()) {
				f(m - i);
			}
			
			long long sum = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					sum += a[j];
				}
			}
			
			for (auto x: us[m - i]) {
				us[m].insert(sum ^ x);
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	
	us[0].insert(0);
	
	f((1 << n) - 1);
	
	printf("%d\n", us[(1 << n) - 1].size());
	
	return 0;
}