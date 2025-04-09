#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int X, Y, Z;
int main() {
	scanf("%d %d %d", &X, &Y, &Z);
	for (int i = 1; i < 1e8; i++) {
		if (i * X >= Y * Z) {
			printf("%d\n", i - 1);
			return 0;
		}
	}
}
