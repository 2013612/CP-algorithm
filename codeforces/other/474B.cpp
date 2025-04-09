#include<iostream>
#include<algorithm>
using namespace std;

int N, a[100006], M;
int main() {
	cin >> N;
	a[0] = 1;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		a[i] = a[i - 1] + temp;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		int k = upper_bound(a, a + N + 1, temp) - a;
		cout << k << endl;
	}
	return 0;
}
