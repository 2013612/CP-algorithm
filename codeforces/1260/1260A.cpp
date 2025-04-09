#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

long long N, c, sum;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &c, &sum);
		long long temp = sum % c;
		long long temp2 = sum/c;
		if (temp == 0) {
			printf("%lld\n", c * temp2 * temp2);
		} else {
			//cout << remainder << " " << c << " " << sum/c << endl;
			printf("%lld\n", (c - temp) * temp2 * temp2 + temp * (temp2 + 1) * (temp2 + 1));
		}
	}
	return 0;
} 
