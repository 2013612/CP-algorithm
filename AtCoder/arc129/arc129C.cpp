#include<iostream>
#include<algorithm>
using namespace std;

int n, a[5003], b[100006], c[10];
string ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i < 5003; i++) {
		a[i] = i * (i + 1) / 2;
	}
	b[0] = 1;
	for (int i = 1; i < 100006; i++) {
		b[i] = (b[i - 1] * 10) % 7;
	}
	{
		int i = 0;
		while (n > 0) {
			{
				int j = 1;
				while (a[j] <= n) {
					j++;
				}
				n -= a[j - 1];
				c[i] = j;
			}
			if (i == 0) {
				c[i]--;
			}
			i++;
		}
	}
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", c[i]);
//	}
//	printf("\n");
	int cur = 0;
	for (int i = 0, j = 0; j < 7; i++) {
		if (c[j] == 0) {
			j++;
			continue;
		}
		for (int k = 1; k <= 7; k++) {
			//printf("%d %d %d %d\n", cur, k, b[i], j);
			if ((cur + k * b[i]) % 7 == j % 7) {
				ans.push_back('0' + k);
				cur = j;
				break;
			}
		}
		c[j]--;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}
