#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;
queue<int> q;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		if (a[i] == 1) {
			int x;
			scanf("%d", &x);
			q.push(x);
		} else {
			printf("%d\n", q.front());
			q.pop();
		}
	}
	return 0;
}