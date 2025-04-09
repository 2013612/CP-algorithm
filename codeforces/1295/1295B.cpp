#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int T, N, X, a[100006];
string S;
int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &X);
		cin >> S;
		//cout << "!"; 
		for (int i = 0; i < N; i++) {
			if (S[i] == '0') {
				a[i + 1] = a[i] + 1;
				//cout << a[i + 1] << " ";
			} else {
				a[i + 1] = a[i] - 1;
				//cout << a[i + 1] << " ";
			}
		}
		//cout << endl;
		int ans = 0;
		if (a[N] == 0) {
			for (int i = 0; i < N; i++) {
				if (a[i] == X) {
					ans = -1;
					break;
				}
			}
		} else {
			for (int i = 0; i < N; i++) {
				int temp = X - a[i];
				if (temp % a[N] == 0 && temp / a[N] >= 0) {
					ans++;
				} 
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
