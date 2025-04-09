#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int K;
string S;
int main() {
	cin >> S >> K;
	sort(S.begin(), S.end());
	for (int i = 0; i < K - 1; i++) {
		next_permutation(S.begin(), S.end());
	}
	cout << S << endl;
	return 0;
}
