#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, ans;
string S;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> S;
		cout << S[0];
		for (int j = 1; j < S.length() - 1; j += 2) {
			cout << S[j];
		}
		cout << S.back() << endl;
	}
	return 0;
}
