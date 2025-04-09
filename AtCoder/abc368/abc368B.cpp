#include<iostream>
#include<queue>
using namespace std;

int n, a[200006], ans;
priority_queue<int> pq;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pq.push(a[i]);
	}
	
	while (true) {
		int x1 = pq.top();
		pq.pop();
		int x2 = pq.top();
		pq.pop();
		if (x2 <= 0) {
			break;
		}
		x1--;
		x2--;
		pq.push(x1);
		pq.push(x2);
		ans++;
	}
	
	printf("%d\n", ans);
	return 0;
}