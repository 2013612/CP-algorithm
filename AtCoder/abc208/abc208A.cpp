#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int A, B;
int main() {
	scanf("%d %d", &A, &B);
	if (6 * A >= B && A <= B) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
