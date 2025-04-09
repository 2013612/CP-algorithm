#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, m, q, w[102], k[5000], a[20], c[5000][5000], d[5000][2000], e[5000][2000];
string k2[5000];
char p[20];

int to_num(string p) {
	int num = 0;
	for (int j = 1; j <= p.length(); j++) {
		num += (p[j-1] - '0') * a[p.length() - j];
	}
	return num;
}

string to_str(int b) {
	string temp = {};
	for (int i = n - 1; i >= 0; i--){
		if (b >= a[i]) {
			temp.push_back('1');
			b -= a[i];
		} else {
			temp.push_back('0');
		}
	}
	return temp;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	a[0] = 1;
	for (int i = 1; i < 13; i++) {
		a[i] = a[i-1] * 2;
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", p);
		string t = p;
		k[to_num(t)]++;
	}
	for (int i = 0; i < a[n]; i++) {
		k2[i] = to_str(i);
	}
	for (int i = 0; i < a[n]; i++) {
		for (int j = i; j < a[n]; j++) {
			for (int k = 0; k < n; k++) {
				if (k2[i][k] == k2[j][k]) {
					c[i][j] += w[k];
				}
			}
		}
	}
	for (int i = 0; i < a[n]; i++) {
		for (int j = 0; j < a[n]; j++) {
			if (i > j) {
				d[i][c[j][i]] += k[j];
			} else {
				d[i][c[i][j]] += k[j];
			}
		}
	}
	for (int i = 0; i < a[n]; i++) {
		for (int j = 0; j < 2000; j++) {
			if (j == 0) {
				e[i][j] = d[i][j];
			} else {
				e[i][j] = e[i][j-1] + d[i][j];
			}
		}
	}
	for (int i = 0; i < q; i++) {
		string temp_s;
		int temp_i;
		scanf("%s %d", p, &temp_i);
		temp_s = p;
		int temp = to_num(temp_s);
		printf("%d\n", e[temp][temp_i]);
	}
	return 0;
}
