#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int main() {
	scanf("%d", &n);
	for (int i = n; i < 5000; i++) {
		if (i % 4 == 2) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}