#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, m, q, w[102], k[5000], a[20];
string p, k2[5000];

int to_num(string p) {
	int num = 0;
	for (int j = 1; j <= p.length(); j++) {
		num += (p[j] - '0') * a[p.length() - j];
	}
	return num;
}

string to_str(int b) {
	string temp;
	for (int i = n - 1; i >= 0; i--){
		if (b > a[i]) {
			temp.push_back(1);
			b -= a[i];
		} else {
			temp.push_back(0);
		}
	}
	return temp;
}

int comp(string temp_s, int temp_i) {
	int value = 0;
	int num = 0;
	for (int i = 0; i < a[n]; i++) {
		if (k[i] > 0) {
			for (int j = 0; j < n; j++) {
				if (k2[i][j] == temp_s[j]) {
					value += w[j];
				}
				if (value > temp_i) {
					break;
				}
			}
			if (value <= temp_i) {
				num += k[i];
			}
		}
	}
	return num;
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
	for (int i = 0; i < 5000; i++) {
		k2[i] = to_str(i);
	}
	for (int i = 0; i < n; i++) {
		cin >> p;
		k[to_num(p)]++;
	}
	for (int i = 0; i < q; i++) {
		string temp_s;
		int temp_i;
		cin >> temp_s >> temp_i;
		cout << comp(temp_s, temp_i) << endl;
	}
	return main();
}
