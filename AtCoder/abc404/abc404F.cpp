#include<iostream>
#include<vector>
using namespace std;

long double g(int m, int last, int cnt, long double sum, int t, int k);

int n, t, m, k;
bool visit[50][50];
long double mem[50][50];

long double f(int t, int k) {
	if (t * m < k) {
		return 0;
	}
	
	if (m >= n * k) {
		return 1;
	}
	
	if (visit[t][k]) {
		return mem[t][k];
	}
	
	visit[t][k] = true;
	
	mem[t][k] = g(m, 1, 0, 0, t, k);
		
	return mem[t][k];
}

long double g(int mm, int last, int cnt, long double sum, int t, int k) {
	if (mm == 0) {
		return sum + f(t - 1, k) * (n - cnt) / n;
	}
	
	long double temp = 0;
	
	if (cnt + 1 < n) {
		for (int i = last; 2 * i <= mm && i <= k; i++) {
			long double p = f(t - 1, k - i) / n;
			temp = max(temp, g(mm - i, i, cnt + 1, sum + p, t, k));
		}
	}
	
	long double p = f(t - 1, k - mm) / n;
	temp = max(temp, g(0, mm, cnt + 1, sum + p, t, k));
	
	return temp;
}

int main() {
	scanf("%d %d %d %d", &n, &t, &m, &k);
	
	printf("%.9Lf\n", f(t, k));
	
	return 0;
}