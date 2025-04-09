#include<iostream>
using namespace std;

int N, a[100006];

int inversions(int a[], int length) {
	if (length <= 1) {
		return 0;
	}
	int ans = inversions(a, length/2) + inversions(a + length/2, length - length/2);
	int b[length];
	int l = 0;
	int r = length/2;
	int pos = 0;
	for (int i = 0; i < length; i++) {
		if (l == length/2) {
			b[i] = a[r];
			r++;
		} else if (r == length) {
			b[i] = a[l];
			l++;
			ans += length - length/2;
		} else {
			if (a[l] <= a[r]) {
				b[i] = a[l];
				ans += r - length/2;
				l++;
			} else {
				b[i] = a[r];
				r++;
			}
		}
	}
	cout << "!" << " ";
	for (int i = 0; i < length; i++) {
		a[i] = b[i];
		cout << a[i] << " ";
	}
	cout << endl;
	cout << ans << endl;
	return ans;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", inversions(a, N));
	return 0;
}
