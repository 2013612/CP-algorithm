#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int v[3];

int a[3], b[3], c[3];

bool solve2() {
	
	
	int p = max(min({a[0], a[1], a[2]}) + 7 - max({a[0], a[1], a[2]}), 0);
	int q = max(min({b[0], b[1], b[2]}) + 7 - max({b[0], b[1], b[2]}), 0);
	int r = max(min({c[0], c[1], c[2]}) + 7 - max({c[0], c[1], c[2]}), 0);
	
	int v2 = p * q * r;
	
	if (v2 != v[2]) {
		return false;
	}
	
//	printf("\n");
//	
//	for (int l = 0; l < 3; l++) {
//		printf("%d %d %d ", a[l], b[l], c[l]);
//	}
//	printf("\n");
//	
//	printf("pass v2 \n");
	
	int v1 = 0;
	for (int i = 0; i < 3; i++) {
		int p = max(min(a[i], a[(i + 1) % 3]) + 7 - max(a[i], a[(i + 1) % 3]), 0);
		int q = max(min(b[i], b[(i + 1) % 3]) + 7 - max(b[i], b[(i + 1) % 3]), 0);
		int r = max(min(c[i], c[(i + 1) % 3]) + 7 - max(c[i], c[(i + 1) % 3]), 0);
		v1 += p * q * r;
	}
	
	
	
	if (v1 - 3 * v2 != v[1]) {
		return false;
	}
	
//	printf("pass v1 %d %d %d \n", v1, v2, 1029 - v1 + v2);
	
	return (1029 - 2 * v1 + 3 * v2) == v[0];
}

bool solve1() {
	for (int i = -7; i <= 7; i++) {
		for (int j = -7; j <= 7; j++) {
			for (int k = -7; k <= 7; k++) {
				a[2] = i;
				b[2] = j;
				c[2] = k;
				if (solve2()) {
					return true;
				}
			}
		}
	}
	
	return false;
}


int main() {
	scanf("%d %d %d", &v[0], &v[1], &v[2]);
	
	for (int i = -7; i <= 7; i++) {
		for (int j = -7; j <= 7; j++) {
			for (int k = -7; k <= 7; k++) {
				a[1] = i;
				b[1] = j;
				c[1] = k;
				
				if (solve1()) {
					printf("Yes\n");
					for (int l = 0; l < 3; l++) {
						printf("%d %d %d ", a[l], b[l], c[l]);
					}
					printf("\n");
					return 0;
				}
			}
		}
	}
	
	printf("No\n");
	
	return 0;
}