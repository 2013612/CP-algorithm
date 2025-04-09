#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, a[100006], ans;
vector<int> factor;
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

int main(){
	scanf("%d", &N);
	outputprime(200);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		for (int j = 100; j >= 2;) {
			if (v[a[i]]) {
				break;
			}
			if (!v[j] || a[i] % j != 0) {
				j--;
				continue;
			}
			a[i] = a[i]/j;
			factor.push_back(j);
		}
	}
	sort(a, a + N);
	sort(factor.begin(), factor.end());
	for (int i = factor.size() - 1; i >= 0; i--) {
		a[0] *= factor[i];
		for (int j = 1; j < N; j++) {
			if (a[j - 1] > a[j]) {
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			} else {
				break;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		ans += a[i];
	}
	printf("%d\n", ans);
	return 0;
}
