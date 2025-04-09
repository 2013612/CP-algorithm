#include<bits/stdc++.h>
using namespace std;

int n, a[200005], b[200005], c[200005];
vector<int> z_to_o, o_to_z, o_to_o;
long long ans, sum1, sum2, sum3;

void g() {
	long long res = 0;
	long long sum = sum1 + sum3;
	int u = z_to_o.size();
	int v = o_to_z.size();
	
	{
		for (int i = 0; i < v; i++) {
			sum -= o_to_z[i];
			res += sum;
		}
		
		for (int i = 0; i < u; i++) {
			sum += z_to_o[i];
			res += sum;
		}
	}
	
	ans = res;
}

int f(int a, int b) {
	return a + b;
}

int e() {
	return 0;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	
	
	for (int i = 0; i < n; i++) {
		if (a[i] == 0 && b[i] == 1) {
			z_to_o.push_back(c[i]);
			sum2 += c[i];
		} else if (a[i] == 1 && b[i] == 0) {
			o_to_z.push_back(c[i]);
			sum1 += c[i];
		} else if (a[i] == 1 && b[i] == 1) {
			o_to_o.push_back(c[i]);
			sum3 += c[i];
		}
	}
	
	sort(z_to_o.begin(), z_to_o.end());
	sort(o_to_z.begin(), o_to_z.end(), greater<int>());
	sort(o_to_o.begin(), o_to_o.end(), greater<int>());
	
	g();
	
	int u = z_to_o.size();
	int v = o_to_z.size();
	int w = o_to_o.size();
	
	int i = 0, j = u - 1;
	
	long long temp = ans;
	
	for (int k = 0; k < w; k++) {
		while (i < v && o_to_z[i] >= o_to_o[k]) {
			sum1 -= o_to_z[i];
			i++;
		}
		
		while (j >= 0 && z_to_o[j] >= o_to_o[k]) {
			sum2 -= z_to_o[j];
			j--;
		}
		
		temp += sum1;
		temp += sum2;
		temp += 2 * sum3 - o_to_o[k];
		temp -= 1ll * (v - i + j + 1) * o_to_o[k];
		
		ans = min(ans, temp);
		
		sum3 -= o_to_o[k];
	}
	
	printf("%lld\n", ans);
	
	return 0;
}