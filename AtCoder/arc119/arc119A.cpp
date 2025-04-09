#include<iostream>
using namespace std;

long long N;
int main() {
	scanf("%lld", &N);
	long long mini = 1e18;
	for (long long i = 0; (1ll << i) <= N; i++) {
		//cout << (1ll << i) << endl;
		mini = min(mini, i + N / (1ll << i) + N % (1ll << i));
		cout << i << " " << mini << endl;
	}
	printf("%lld\n", mini);
	return 0;
}
