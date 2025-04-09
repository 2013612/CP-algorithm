#include<iostream>
using namespace std;

int g(int a) {
	if (a == 0 || a == 1) {
		return 0;
	}
	
	int cnt = 0;
	
	for (int i = 2; i * i <= a; ) {
		if (a % i == 0) {
			a /= i;
			cnt++;
		} else {
			i++;
		}
	}
	
	return cnt + 1;
}

int main() {
	int n;
	scanf("%d", &n);
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		ans = ans ^ g(a);
	}
	
	if (ans != 0) {
		printf("Anna\n");
	} else {
		printf("Bruno\n");
	}
	
	return 0;
}