#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long sx, sy, tx, ty;

int main() {
	scanf("%lld %lld %lld %lld", &sx, &sy, &tx, &ty);
	long long v = abs(sy - ty);
	if (sx > tx) {
		if ((sx + sy) % 2) {
			sx--;
		}
	} else if (sx < tx) {
		if ((sx + sy) % 2 == 0) {
			sx++;
		}
	}
	if (sx > tx) {
		if ((tx + ty) % 2 == 0) {
			tx++;
		}
	} else if (sx < tx) {
		if ((tx + ty) % 2) {
			tx--;
		}
	}
	
	long long h = max(abs(sx - tx) - v, 1ll * 0);
	h = (h + 1) / 2;
	
	printf("%lld\n", v + h);
	return 0;
}