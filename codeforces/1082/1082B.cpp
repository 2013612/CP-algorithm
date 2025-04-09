#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, ans;
char c[100006];
bool ALLS = false;
int main(){
	scanf("%d", &N);
	scanf("%s", c);
	for (int i = 0; i < N; i++) {
		bool swap = false;
		int cou = 0;
		int pos = 0;
		for (int j = i; j < N; j++) {
			if (c[j] == 'G') {
				cou++;
			} else {
				if (!swap) {
					for (int k = N - 1; k > j; k--) {
						if (c[k] == 'G') {
							cou++;
							swap = true;
							c[k] = 'S';
							pos = k;
							break;
						}
						if (k == j + 1) {
							ALLS = true;
						}
					}
				} else {
					break;
				}
			}
			if (ALLS) {
				break;
			}
		}
		ans = max(ans, cou);
		if (swap) {
			c[pos] = 'G';
		}
		if (ALLS) {
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
