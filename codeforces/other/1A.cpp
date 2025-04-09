#include<iostream>
#include<math.h> 
using namespace std;

int N, M, A;
int main() {
	cin >> N >> M >> A;
	long long ans = ceil(double(N) / A) * ceil(double(M) / A);
	cout << ans << endl; 
	return 0;
}
