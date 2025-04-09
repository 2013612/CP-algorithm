#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < min(a.size(), b.size()); i++) {
		if ((a[a.size() - i - 1] - '0') + (b[b.size() - i - 1] - '0') >= 10) {
			printf("Hard\n");
			return 0;
		}
	}
	printf("Easy\n");
	return 0;
}
