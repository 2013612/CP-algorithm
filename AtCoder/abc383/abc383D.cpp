#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 2000000;

bool a[2000006];
long long n;
int ans;
vector<int> v;

void seive() {
	a[0] = a[1] = true;
	for (int i = 2; i <= M; i++) {
		if (!a[i]) {
			for (int j = i + i; j <= M; j += i) {
				a[j] = true;
			}
			v.push_back(i);
		}
	}
}

int main() {
	seive();
	scanf("%lld", &n);
	
	for (int i = 2; i <= 40; i++) {
		if (a[i]) {
			continue;
		}
		
		long long k = 1;
		for (int j = 0; j < 8; j++) {
			k *= i;
		}
		
		if (k <= n) {
			ans++;
		}
	}
	
	int r = v.size() - 1;
	
	for (int i = 0; i < r; i++) {
		while (1ll * v[i] * v[i] * v[r] * v[r] > n && i < r) {
			r--;
		}
		
		ans += r - i;
	}
	
	printf("%d\n", ans);
	return 0;
}