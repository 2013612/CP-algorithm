#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long A, B, K, NCR[103][103];
string ans;

string solve(long long a, long long b, long long pos) {
	//cout << pos << endl;
	if (a == 0) {
		string temp;
		for (int i = 0; i < b; i++) {
			temp.push_back('b');
		}
		return temp;
	} else if (b == 0) {
		string temp;
		for (int i = 0; i < a; i++) {
			temp.push_back('a');
		}
		return temp;
	}
	if (pos > NCR[a + b - 1][a - 1]) {
		return "b" + solve(a, b - 1, pos - NCR[a + b - 1][b]);
	} else {
		return "a" + solve(a - 1, b, pos);
	}
}

int main() {
	scanf("%lld %lld %lld", &A, &B, &K);
	for (int i = 1; i <= 70; i++) {
		NCR[i][0] = 1;
		NCR[i][i] = 1;
	}
	for (int i = 2; i <= 70; i++) {
		for (int j = 1; j < i; j++) {
			NCR[i][j] = NCR[i - 1][j - 1] + NCR[i - 1][j];
		}
	}
//	for (int i = 1; i <= 10; i++) {
//		for (int j = 0; j <= i; j++) {
//			cout << NCR[i][j] << " ";
//		}
//		cout << endl;
// 	}
	cout << solve(A, B, K) << endl;
	return 0;
}
