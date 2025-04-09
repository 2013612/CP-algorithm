#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// Function for extended Euclidean Algorithm 
long long gcdExtended(long long a, long long b, long long *x, long long *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
 
    long long x1, y1; // To store results of recursive call 
    long long gcd = gcdExtended(b%a, a, &x1, &y1); 
 
    // Update x and y using results of 
    // recursive call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
 
    return gcd; 
} 

int T;
long long two[103];
int main() {
	scanf("%d", &T);
	two[0] = 1;
	for (int i = 1; i < 63; i++) {
		two[i] = 2 * two[i - 1];
	}
	for (int i = 0; i < T; i++) {
		long long c, d, x, g_c, g_d;
		scanf("%lld %lld %lld", &c, &d, &x);
		long long g = gcdExtended(c, d, &g_c, &g_d);
		if (x % g != 0) {
			printf("0\n");
			continue;
		}
		long long ans = 0;
		g_c *= x / g;
		g_d *= x / g;
		g_c -= (-g_d / (c / g) + 5) * (d / g);
		g_d += (-g_d / (c / g) + 5) * (c / g);
		while (g_d <= 0) {
			g_c -= d / g;
			g_d += c / g;
		}
		g_c += (-g_d / (c / g) - 5) * (d / g);
		g_d -= (-g_d / (c / g) - 5) * (c / g);
		while (g_d >= 0) {
			g_c += d / g;
			g_d -= c / g;
		}
		for (int j = 0; j < 4000000; j++) {
			//cout << g_c << " " << g_d << " " << ans << endl;
			if (g_c % g_d == 0) {
				long long left = -g_c / g_d;
				int cou = 0;
				for (int j = 2; j * j <= left; j++) {
					if (left % j == 0) {
						cou++;
						while (left % j == 0) {
							left /= j;
						}
					}
				}
				if (left != 1) {
					cou++;
				}
				ans += two[cou];
			}
			g_c += d / g;
			g_d -= c / g;
		}
//		while (abs(g_d) <= g_c) {
//			//cout << g_c << " " << g_d << " " << ans << endl;
//			if (g_c % g_d == 0) {
//				long long left = -g_c / g_d;
//				int cou = 0;
//				for (int j = 2; j * j <= left; j++) {
//					if (left % j == 0) {
//						cou++;
//						while (left % j == 0) {
//							left /= j;
//						}
//					}
//				}
//				if (left != 1) {
//					cou++;
//				}
//				ans += two[cou];
//			}
//			g_c += d / g;
//			g_d -= c / g;
//		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
