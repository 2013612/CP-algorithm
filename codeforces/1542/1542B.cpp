#include<iostream>
using namespace std;

int T, N, a, b;

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of
    // recursive call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &a, &b);
		int x, y;
		int gcd = gcdExtended(a, b, &x, &y);
		if (a == 1) {
			if ((N - 1) % b == 0) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
			continue;
		}
		while (N > 1) {
			if (N % a == 0) {
				N /= a;
			} else {
				if ((N - 1) % b == 0) {
					N = 1;
					break;
				}
				if (N % gcd != 0) {
					break;
				} else {
					int temp = N / gcd;
					int x2 = x * temp;
					int y2 = y * temp;
					if (x2 <= 0) {
						int temp = -x2 / (b / gcd) + 1;
						x2 += temp * (b / gcd);
						y2 -= temp * (a / gcd);
					}
					if (y2 <= 0) {
						int temp = -y2 / (a / gcd) + 1;
						y2 += temp * (a / gcd);
						x2 -= temp * (b / gcd);
					}
					if (x2 < 0 || y2 < 0) {
						break;
					}
					N -= y2 * b;
				}
			}
		}
		if (N == 1) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
