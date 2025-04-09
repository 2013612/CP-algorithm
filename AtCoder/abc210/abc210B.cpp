#include<iostream>
#include<string>
using namespace std;

int N;
string S;
int main() {
	cin >> N >> S;
	bool ans = false;
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') {
			if (ans) {
				printf("Aoki\n");
			} else {
				printf("Takahashi\n");
			}
			break;
		}
		ans = !ans;
	}
	return 0;
}
