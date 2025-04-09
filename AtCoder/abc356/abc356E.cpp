#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, b[1000007];
vector<int> v;
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		b[t]++;
		v.push_back(t);
	}
	
	for (int i = 1; i <= 1e6 + 2; i++) {
		b[i] = b[i - 1] + b[i];
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		long long sum = 0;
		
		int sqrt_n = 1;
		while (sqrt_n * sqrt_n < v[i]) {
			sqrt_n++;
		}
		
		
		int j = 1;
		
		while (v[i] / j > sqrt_n) {
			sum += 1ll * v[i] / j * (b[j] - b[j - 1]);
			j++;
		}
		
		int last = j - 1;
		
		for (int k = sqrt_n; k >= 1; k--) {
			int temp = v[i] / k;
			if (v[i] / temp != k) {
				continue;
			}
			sum += 1ll * (b[temp] - b[last]) * k;
			last = temp;
		}
		
		ans += sum * (b[v[i]] - b[v[i] - 1]);
	}
	
	for (int i = 1; i <= 1e6 + 2; i++) {
		ans -= 1ll * (b[i] - b[i - 1] + 1) * (b[i] - b[i - 1]) / 2;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}