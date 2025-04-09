#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int M = 100000;
int N, A[1004][4];
long long ans;
bool exist[200006][200006];

int gcd(int a, int b) {
	return a == 0? b: gcd(b % a, a);
}

int abs(int a) {
	return a >= 0? a: -a;
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &A[i][0], &A[i][1], &A[i][2], &A[i][3]);
		int h = A[i][2] - A[i][0];
		int v = A[i][3] - A[i][1];
		int ratio = gcd(abs(h), abs(v));
		for (int i = 0; i <= ratio; i++) {
			int x = A[i][0] + h/ratio*i;
			int y = A[i][1] + v/ratio*i;
			if (!exist[x + M][y + M]) {
				ans++;
				exist[x + M][y + M] = true;
			}
		}
	} 
	printf("%lld", ans);
	return 0;
}
