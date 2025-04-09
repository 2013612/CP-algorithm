#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N, ans;
int main() {
	scanf("%d", &N);
	for (long long i = 1; i <= 50000; i++) {
		if (i * (i + 1) / 2 >= N) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
