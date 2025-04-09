#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int T, N;
string ans;
int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		ans.clear();
		if (N % 2 == 0) {
			N = N / 2;
			for (int j = 0; j < N; j++) {
				ans.push_back('1');
			}
		} else {
			N -= 3;
			ans.push_back('7');
			N = N/2;
			for (int j = 0; j < N; j++) {
				ans.push_back('1');
			}
		}
		cout << ans << endl;
	}
	return 0;
}
