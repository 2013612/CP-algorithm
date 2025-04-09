#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const long long M = 1000000000000000000;
vector<bool> a;
int N;
vector<long long> b;

void outputprime(int n){ // vector is used
	a.push_back(false);
	a.push_back(false);
	for(int i = 2; i <= n; i++){
		a.push_back(true);
	}
	for(int i = 2; i*i <= n; i++){
		if (a[i] == false){
			continue;
		} else{
			for (int j = 2*i; j <= n; j+=i){
				a[j] = false;
			}
		}
	}
}

int main(){
	outputprime(60);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 2; ; j++) {
			long long temp = 1;
			for (int k = 0; k < a[i]; k++) {
				temp = temp * j;
			}
			if (temp > M) {
				break;
			} else {
				b.push_back(temp);
			}
		}
	}
	sort(b.begin(), b.end());
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		long long T;
		scanf("%d", &T);
		long long pos = upper_bound(b.begin(), b.end(), T) - b.begin();
		printf("%lld\n", T - 1 - pos);
	}
	return 0;
}
