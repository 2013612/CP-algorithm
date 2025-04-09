#include<iostream>
#include<vector>
using namespace std;

int n, p[200006], head[200006], ind[200006];
long long k;
vector<int> v[200006];

int pow(int a, long long x, int m) {
	if (x == 0) {
		return 1;
	}
	
	if (x & 1) {
		return 1ll * a * pow(a, x - 1, m) % m;
	} else {
		int t = pow(a, x / 2, m);
		return 1ll * t * t % m;
	}
}

int main() {
	scanf("%d %lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		if (head[i] == 0) {
			head[i] = i;
			v[i].push_back(i);
			int next = p[i];
			while (next != i) {
				head[next] = i;
				v[i].push_back(next);
				ind[next] = v[i].size() - 1;
				next = p[next];
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int m = v[head[i]].size();
		int time = pow(2, k, m);
		
		printf("%d ", v[head[i]][(ind[i] + time) % m]);
	}
	
	printf("\n");
	
	return 0;
}