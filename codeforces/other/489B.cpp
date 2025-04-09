#include<iostream>
#include<algorithm>
using namespace std;

int N, M, a[103], b[103], ans;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> b[i];
	}
	sort(a, a + N);
	sort(b, b + M);
	int i = 0;
	int j = 0;
	while (i < N && j < M) {
		if (abs(a[i] - b[j]) <= 1) {
			i++;
			j++;
			ans++;
		} else if (a[i] > b[j]) {
			j++;
		} else {
			i++;
		}
	}
	cout << ans << endl;
	return 0;
}
