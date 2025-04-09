#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int x[200006], y[200006], pre_x[1000006];
long long sum_x, sum_y, ans;
unordered_map<int, int> um;

int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		sum_x += x[i];
		sum_y += y[i];
	}
	sort(x, x + n);
	sort(y, y + n);
	{
		int cur = 0;
		int p = n;
		long long t = sum_x - 1ll * n * -2e6;
		for (int i = -2e6; i <= 2e6; i++) {
			if (t <= d) {
				pre_x[t]++;
			}
			
			while (cur < n && x[cur] == i) {
				cur++;
				p -= 2;
			}
			t -= p;
		}
		
		for (int i = 0; i <= 1e6; i++) {
			pre_x[i + 1] += pre_x[i];
		}
	}
	
	{
		int cur = 0;
		int p = n;
		long long t = sum_y - 1ll * n * -2e6;
		for (int i = -2e6; i <= 2e6; i++) {
			long long left = d - t;
			if (left >= 0) {
				ans += pre_x[left];
			}
			
			while (cur < n && y[cur] == i) {
				cur++;
				p -= 2;
			}
			t -= p;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}