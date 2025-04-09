#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, ans, a[103], cou[1004];
vector<bool> v;
vector<int> w;
bool k;

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

int main(){
	scanf("%d", &N);
	if (N == 1) {
		printf("1 0\n");
		return 0;
	}
	outputprime(N);
	for (int i = 0; i <= N; i++) {
		if (v[i] && N % i == 0) {
			w.push_back(i);
		}
	}
	int maxi = 0;
	int num = 1;
	for (int i = 0; i < w.size(); i++) {
		while (N % w[i] == 0) {
			N /= w[i];
			cou[i]++;
		}
		maxi = max(maxi, cou[i]);
		num *= w[i];
	}
	a[0] = 1;
	for (int i = 1; i < 10; i++) {
		a[i] = 2*a[i - 1];
	}
	for (int i = 0; i < 10; i++) {
		if (maxi <= a[i]) {
			ans = i;
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (maxi == a[i]) {
			for (int i = 0; i < w.size(); i++) {
				if (cou[i] != maxi) {
					break;
				}
				if (i + 1 == w.size()) {
					k = true;
				}
			}
			break;
		}
	}
	if (!k) {
		ans++;
	}
	printf("%d %d\n", num, ans);
	return 0;
}
