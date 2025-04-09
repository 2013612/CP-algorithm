#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, a[3000007];
vector<int> b, ans;
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
	outputprime(2750132);
	b.push_back(1);
	for (int i = 1; i <= 2750132; i++) {
		if (v[i]) {
			b.push_back(i);
		}
	}
	scanf("%d", &N);
	for (int i = 0; i < 2*N; i++) {
		int temp;
		scanf("%d", &temp);
		a[temp]++;
	}
	for (int i = 2750132; i >= 2; i--) {
		if (a[i] == 0) {
			continue;
		}
		if (v[i]) {
			int temp = lower_bound(b.begin(), b.end(), i) - b.begin();
			a[temp] -= a[i];
			for (int j = 0; j < a[i]; j++) {
				ans.push_back(temp);
			}
		} else {
			for (int j = 1; ; j++) {
				if (i % b[j] == 0) {
					a[i/b[j]] -= a[i];
					break;
				}
			}
			for (int j = 0; j < a[i]; j++) {
				ans.push_back(i);
			}
		}
	}
	for (auto x: ans) {
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}
