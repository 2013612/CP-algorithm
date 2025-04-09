#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, Q, a[100006][2];
int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < Q; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp == 1) {
			int b, c;
			scanf("%d %d", &b, &c);
			a[b][1] = c;
			a[c][0] = b;
		} else if (temp == 2) {
			int b, c;
			scanf("%d %d", &b, &c);
			a[b][1] = 0;
			a[c][0] = 0;
		} else {
			int b;
			scanf("%d", &b);
			int cnt = 1;
			string ans = to_string(b);
			int cur = b;
			while (true) {
				if (a[cur][1] == 0) {
					break;
				}
				cnt++;
				cur = a[cur][1];
			}
			cur = b;
			while (true) {
				if (a[cur][0] == 0) {
					break;
				}
				cnt++;
				cur = a[cur][0];
			}
			printf("%d ", cnt);
			for (int i = 0; i < cnt; i++) {
				printf("%d ", cur);
				cur = a[cur][1];
			}
			printf("\n");
		}
	}
	return 0;
}
