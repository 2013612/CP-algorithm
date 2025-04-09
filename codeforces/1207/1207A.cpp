#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, ans, b, p, f, h, c;
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d %d %d", &b, &p, &f);
		scanf("%d %d", &h, &c);
		int maxi = b/2;
		ans = 0;
		if (h > c) {
			if (p >= maxi) {
				ans = maxi * h;
			} else {
				ans = p * h + min(maxi - p, f) * c;
			}
		} else {
			if (f >= maxi) {
				ans = maxi * c;
			} else {
				ans = f * c + min(maxi - f, p) * h;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
