#include<iostream>
using namespace std;

int N, zero;
bool pos, neg;
double X[100006], Y[100006];

double abs(double a) {
	return a >= 0? a: -a;
}
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &X[i], &Y[i]);
		if (Y[i] > 0) {
			pos = true;
		} else if (Y[i] < 0) {
			neg = true;
		} else {
			zero++;
		}
		Y[i] = abs(Y[i]);
	}
	if ((pos && neg) || zero > 1) {
		printf("-1\n");
		return 0;
	}
	
	return 0;
}
