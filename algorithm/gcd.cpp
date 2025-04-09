#include<iostream>
#include<vector>
int gcd(int a,int b){
	return a == 0? b : gcd(b%a,a);
}

long long lcm(int a,int b){
	return (1ll*a/gcd(a,b)*b);
}

struct data{
	int a, x, y;
};

data E_gcd(data m, data n){
	int k = m.a/n.a;
	m.a -= n.a*k;
	m.x -= n.x*k;
	m.y -= n.y*k;
	return m.a == 0? n : E_gcd(n, m);
}

data E_gcd2(data m, data n){
	int k = m.a/n.a;
	m.a -= n.a*k;
	m.x -= n.x*k;
	m.y -= n.y*k;
	return m.a == 0? m : E_gcd2(n, m);
}

int pos(int x, int m){
	return ((x % m) + m ) % m; 
}

int inv(int a, int m){
	return pos(E_gcd({a,1,0},{m,0,1}).x, m);
}

int CRT(int a, int b, int m, int n){ // be aware of overflow
	return (inv(n,m)*n*a + inv(m,n)*n*b) % (m*n);
}

int CRT2(int a, int b, int m, int n){  // be aware of overflow
	data k = E_gcd({m,1,0}, {n,0,1});
	return pos(a*n*k.y + b*m*k.x, m*n);
}

bool isprime(int x){
	for (int i = 2; i*i <= x; i++){
		if (x % i == 0){
			return false;
		}
	}
	return true;
}

int outputprime(int n){ // vector is used
	std::vector<bool> v;
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
	return num;
}

int main() {
	int a, b;
	scanf("%d", &a);
	printf("%d\n", outputprime(a));
	return 0;
}
