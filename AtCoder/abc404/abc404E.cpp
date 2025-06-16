#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, c[2004], a[2004], d[2004], ans;
vector<int> v(1, 0);

int main() {
	scanf("%d", &n);
	
	for (int i = 1; i < n; i++) {
		scanf("%d", &c[i]);
		d[i] = -1;
	}
	
	for (int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
		
		if (a[i]) {
			v.push_back(i);
		}
	}

	while (v.size() > 1) {
		int cur = v.back();
		v.pop_back();
		int tar = v.back();
		queue<int> q;
		q.push(cur);
		d[cur] = 0;
		
		while (q.size()) {
			int p = q.front();
			q.pop();
			
			if (p - c[p] <= tar) {
				d[tar] = d[p] + 1;
				break;
			}
			
			for (int i = 1; i <= c[p]; i++) {
				if (d[p - i] < 0) {
					d[p - i] = d[p] + 1;
					q.push(p - i);
				}
			}
		}
		
		ans += d[tar];
	}
	
	printf("%d\n", ans);
	return 0;
}