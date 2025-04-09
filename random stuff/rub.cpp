#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int n;
long long d, b, c[150006];
vector<bool> a;

long long gcd(long long a,long long b){
	return a == 0? b : gcd(b%a,a);
}

long long lcm(long long a,long long b){
	return (1ll*a/gcd(a,b)*b);
}

void outputprime(long long n){
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
	scanf("%d", &n);
	long long maxi = 20000000001;
	outputprime(maxi);
	return 0;
}
