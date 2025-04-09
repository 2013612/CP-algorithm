#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long T, N, ans, a[10000007];
vector<bool> v;

void outputprime(int n){ // vector is used
	v.push_back(false);
	v.push_back(false);
	for(int i = 2; i <= n; i++){
		v.push_back(true);
	}
	for(int i = 2; i*i <= n; i++){
		if (v[i] == false){
			continue;
		} else{
			for (int j = 2*i; j <= n; j+=i){
				v[j] = false;
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	outputprime(N);
	a[1] = 1;
	for (int i = 2; i <= N; i++) {
		int temp = i;
		if (v[i]) {
			a[i] = 2;
			continue;
		}
		int cou = 0;
		for (int j = 2; ; j++) {
			if (v[j]) {
				while (temp % j == 0) {
					cou++;
					temp /= j;
				}
				if (cou > 0) {
					a[i] = (cou + 1) * a[temp];
					break;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		ans += i * a[i];
	}
	printf("%lld\n", ans);
	return 0;
}
