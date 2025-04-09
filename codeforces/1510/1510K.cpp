#include<iostream>
using namespace std;

int N, a[2004], b[2004], ans;

void swap1() {
	for (int i = 1; i <= 2 * N; i += 2) {
		int temp = a[i + 1];
		a[i + 1] = a[i];
		a[i] = temp;
	}
}

void swap2() {
	for (int i = 1; i <= N; i++) {
		int temp = a[i];
		a[i] = a[N + i];
		a[N + i] = temp;
	}
}

bool checksorted() {
	for (int i = 1; i <= 2 * N; i++) {
		if (a[i] != i) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= 2 * N; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	ans = 1e9;
	for (int i = 0; i <= 2 * N; i++) {
		if (a[1] == 1 && checksorted()) {
			ans = min(ans, i);
			break;
		}
		if (i & 1) {
			swap2();
		} else {
			swap1();
		}
	}
	for (int i = 1; i <= 2 * N; i++) {
		a[i] = b[i];
	}
	for (int i = 0; i <= 2 * N; i++) {
		if (a[1] == 1 && checksorted()) {
			ans = min(ans, i);
			break;
		}
		if (i & 1) {
			swap1();
		} else {
			swap2();
		}
	}
	if (ans > 1e8) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}
