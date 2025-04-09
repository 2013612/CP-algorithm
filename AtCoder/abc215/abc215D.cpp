#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int N, M, p[200006];
long long a[100006];
set<int> q;

void f() {
	for (int i = 1; i <= 100003; i++) {
		p[i] = i;
	}
	for (int i = 2; i <= 100003; i++) {
		if (p[i] == i) {
			q.insert(i);
		}
		for (int j: q) {
			if (i * j > 100003 || j > p[i]) {
				break;
			}
			p[i * j] = p[i];
		}
	}
}

int main() {
	f();
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		for (int j = 2; j * j <= a[i]; j++) {
			while (a[i] % j == 0) {
				a[i] /= j;
				q.erase(j);
			}
		}
		if (a[i] > 1) {
			q.erase(a[i]);
		}
	}
	set<int> temp;
	temp.insert(1);
	for (auto x: q) {
		long long t = x;
		while (t <= M) {
			for (auto y:temp) {
				if (t * y <= M) {
					temp.insert(t * y);
				} else {
					break;
				}
			}
			t = t * x;
		}
	}
	printf("%d\n", temp.size());
	for (auto x:temp) {
		printf("%d\n", x);
	}
	return 0;
}
