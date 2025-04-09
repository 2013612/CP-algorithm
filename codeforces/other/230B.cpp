#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int N;
long long A;
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
	cin >> N;
	outputprime(1000007);
	for (int i = 0; i < N; i++) {
		cin >> A;
		long long temp = sqrt(A);
		if (v[temp] && A == temp*temp) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
