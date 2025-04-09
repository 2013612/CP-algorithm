#include<iostream>
#include<vector>

const long long M = 4294967296; 
int n, A, B, C, D;
// std::vector<bool> a;

/*void outputprime(int n){ // vector is used
	a.push_back(false);
	a.push_back(false);
	for(int i = 2; i <= n; i++){
		a.push_back(true);
	}
	for(int i = 2; i*i <= n; i++){
		if (a[i] == false){
			continue;
		} else {
			for (int j = 2*i; j <= n; j+=i){
				a[j] = false;
			}
		}
	}
} */

unsigned int f(int x) {
	unsigned int x2 = (x*x) % M;
	unsigned int x3 = (x2*x) % M;
	return ((A*x3 + B*x2) % M + C*x + D) % M;
} 

int main() {
	scanf("%d %d %d %d %d", &n, &A, &B, &C, &D);
	unsigned int ex;
	// outputprime(n);
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		int num = i;
		ex = 0;
		/* if (a[i]) {
			ex = f(i);
		} else */{
			for (int j = 2; ; ) {
				if (num % j == 0) {
					ex = (ex + f(j)) % M;
					num = num/j;
				} else {
					j++;
				}
				if (num == 1) {
					break;
				}
			}
		}
		ans += ex;
	}
	printf("%d\n", ans);
	return 0;
}
