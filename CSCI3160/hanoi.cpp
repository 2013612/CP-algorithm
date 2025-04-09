#include<iostream>
using namespace std;

int N, from, to;

void hanoi(int from, int to, int N) {
	if (N == 1) {
		printf("%d %d %d\n", from, to, N);
		return;
	}
	hanoi(from, 6 - from - to, N - 1);
	printf("%d %d %d\n", from, to, N);
	hanoi(6 - from - to, to, N - 1);
}

int main(){
	scanf("%d %d %d", &from, &to, &N);
	hanoi(from, to, N);
	return 0;
}
