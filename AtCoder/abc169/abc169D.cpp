#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

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
	int num = 0;
	for(int i = 2; i <= n; i++){
		if (v[i]){
			num++;
		}
	}
}

long long N, ans, a[10005];
vector<int> num;
int main() {
	scanf("%lld", &N);
	outputprime(1000007);
	for (int i = 0; i < 10000; i++) {
		a[i] = i * (i + 1) / 2;
	}
	long long time = 1;
	//cout << "!" << endl;
	for (long long i = 1; i * i <= N; i++) {
		//cout << i << endl;
		if (v[i]) {
			//cout << i << endl;
			//cout << i << endl;
			num.push_back(0);
			long long temp = N;
			while(temp % i == 0) {
				num.back() = num.back() + 1;
				temp = temp / i;
				time = time * i;
			}
		}
		//cout << i << endl;
	}
	//cout << "@" << endl;
	if (time != N) {
		num.push_back(1);
	}
	for (auto x:num) {
		int temp = upper_bound(a, a + 10000, x) - a - 1;
		ans += temp;
	}
	cout << ans << endl;
	return 0;
}
