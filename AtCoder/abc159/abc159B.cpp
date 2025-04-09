#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string S;
int N;

bool pal(int a, int b) {
	for (int i = 0; i < (b - a + 1)/2; i++) {
		if (S[a + i - 1] != S[b - i - 1]) {
			return false;
		}
	}
	return true;
}

int main(){
	cin >> S;
	N = S.length();
	if (pal(1, N) && pal(1, (N - 1)/2) && pal((N + 3)/2, N)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
