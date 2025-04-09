#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

long long N, ans, r, b, k;

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &r, &b, &k);
		if (r > b) {
			long long temp = r;
			r = b;
			b = temp;
		}
		if (r * (k - 1) + (gcd(r, b) + 1) <= b) {
			cout << "REBEL" << endl;
			continue;
		} else {
			cout << "OBEY" << endl;
		}
	}
	return 0;
} 
