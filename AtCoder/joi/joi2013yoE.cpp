#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, a[103][6], imos[103][103][103];
long long ans;
vector<int> x, y, z;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4], &a[i][5]);
		x.push_back(a[i][0]);
		x.push_back(a[i][3]);
		y.push_back(a[i][1]);
		y.push_back(a[i][4]);
		z.push_back(a[i][2]);
		z.push_back(a[i][5]);
	}
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	sort(y.begin(), y.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	sort(z.begin(), z.end());
	z.erase(unique(z.begin(), z.end()), z.end());
	for (int i = 0; i < n; i++) {
		int x1 = lower_bound(x.begin(), x.end(), a[i][0]) - x.begin();
		int x2 = lower_bound(x.begin(), x.end(), a[i][3]) - x.begin();
		int y1 = lower_bound(y.begin(), y.end(), a[i][1]) - y.begin();
		int y2 = lower_bound(y.begin(), y.end(), a[i][4]) - y.begin();
		int z1 = lower_bound(z.begin(), z.end(), a[i][2]) - z.begin();
		int z2 = lower_bound(z.begin(), z.end(), a[i][5]) - z.begin();
		imos[x1][y1][z1]++;
		imos[x1][y2][z1]--;
		imos[x2][y1][z1]--;
		imos[x2][y2][z1]++;
		imos[x1][y1][z2]--;
		imos[x1][y2][z2]++;
		imos[x2][y1][z2]++;
		imos[x2][y2][z2]--;
	}
	for (int i = 0; i < y.size(); i++) {
		for (int j = 0; j < z.size(); j++) {
			for (int k = 1; k < x.size(); k++) {
				imos[k][i][j] += imos[k - 1][i][j];
			}
		}
	}
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < z.size(); j++) {
			for (int k = 1; k < y.size(); k++) {
				imos[i][k][j] += imos[i][k - 1][j];
			}
		}
	}
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < y.size(); j++) {
			for (int k = 1; k < z.size(); k++) {
				imos[i][j][k] += imos[i][j][k - 1];
			}
		}
	}
	for (int i = 0; i < x.size() - 1; i++) {
		for (int j = 0; j < y.size() - 1; j++) {
			for (int l = 0; l < z.size() - 1; l++) {
				if (imos[i][j][l] >= k) {
					ans += 1ll * (x[i + 1] - x[i]) * (y[j + 1] - y[j]) * (z[l + 1] - z[l]);
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
