#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

int T, N, M, CRT[6], product;

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

int pos(int x, int m){
	return ((x % m) + m ) % m; 
}

int inv(int a, int m){
	return pos(E_gcd({a,1,0},{m,0,1}).x, m);
}

int CRT2(int a, int b, int m, int n){ // be aware of overflow
	return (1ll*inv(n,m)*n*a + 1ll*inv(m,n)*n*b) % (m*n);
}

int main() {
	cin >> T >> N >> M;
	int number[] = {5, 7, 11, 13, 16, 17};
	product = 1;
	for (int i = 0; i < 6; i++) {
		product *= number[i];
	}
	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 18; k++) {
				printf("%d ", number[j]);
			}
			printf("\n");
			fflush(stdout);
			for (int k = 0; k < 18; k++) {
				int temp;
				cin >> temp;
				CRT[j] += temp;
			}
			CRT[j] = CRT[j] % number[j];
		}
		int a = CRT[0];
		int b = CRT[1];
		int m = number[0];
		int n = number[1];
		for (int j = 2; j < 6; j++) {
			a = CRT2(a, b, m, n);
			b = CRT[j];
			m = m * n;
			n = number[j];
		}
		a = CRT2(a, b, m, n);
		cout << a << endl;
		int temp;
		cin >> temp;
		break;
	}
}
