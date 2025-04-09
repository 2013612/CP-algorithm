#include<iostream>
using namespace std;

int N, a[100006], pos;
long long ans;
bool zero;
int main() {
	scanf("%d", &N);
	pos = 1;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp == 0) {
			zero = true;
		} else if (temp < 0) {
			pos *= -1;
		}
		ans += abs(abs(temp) - 1);
	}
	if (!zero && pos != 1) {
		ans += 2;
	}
	printf("%lld", ans);
	return 0;
}
