#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N, ans, a, b;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		if ((a + b) % 3 == 0 && b <= 2 * a) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
} 
