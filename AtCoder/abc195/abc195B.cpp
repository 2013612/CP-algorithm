#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int A, B, W;
int main() {
	scanf("%d %d %d", &A, &B, &W);
	W *= 1000;
	int maxi = 0;
	int mini = 1e9;
	for (int i = 1; i <= W; i++) {
		double temp = (double) W / i;
		if (temp >= A && temp <= B) {
			maxi = max(maxi, i);
			mini = min(mini, i);
		}
	}
	if (maxi == 0) {
		printf("UNSATISFIABLE\n");
	} else {
		printf("%d %d\n", mini, maxi);
	}
	return 0;
}
