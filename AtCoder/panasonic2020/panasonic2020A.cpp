#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int K, ans;
int main() {
	int a[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	scanf("%d", &K);
	printf("%d\n", a[K - 1]);
	return 0;
}
