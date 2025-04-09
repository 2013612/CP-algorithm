#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		string S;
		string ans = "a";
		int K;
		cin >> K >> S;
		int temp = 0;
		for (int j = 0; j < S.length(); j++) {
			temp += (S[j] - '0');
		}
		if (temp % 2 != 0) {
			bool sec = false;
			for (int j = 0; j < S.length(); j++) {
				if ((S[j] - '0') % 2 != 0) {
					if (!sec) {
						sec = true;
					} else {
						S.erase(S.begin() + j);
						break;
					}
				}
				if (j == S.length() - 1 && sec) {
					ans = "-1";
					break;
				}
			}
		}
		if (!S.empty()) {
			while ((S.back() - '0') % 2 == 0){
				//cout << "!" << S << endl;
				S.pop_back();
				if (S.empty()) {
					break;
				}
			}
		}
		if (S.empty()) {
			ans = "-1";
		} else if (ans == "a") {
			ans = S;
		}
		cout << ans << endl;
	}
	return 0;
}
