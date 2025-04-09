#include<iostream>
#include<string>
using namespace std;

int T, N;
string S;

int main() {
	freopen("alchemy_input.txt", "r", stdin);
	freopen("alchemy_output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		cin >> S;
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (S[j] == 'A') {
				cnt++;
			}
		}
		
		printf("Case #%d: ", i);
		if (cnt == N/2 || cnt == N/2 + 1) {
			printf("Y\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}
