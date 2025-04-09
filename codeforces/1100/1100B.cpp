#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, a[100006], b[100006], counts;
vector<char> ans;
int main(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < M; i++) {
		b[a[i]]++;
		if (b[a[i]] == 1) {
			counts++;
		}
		if (counts == N) {
			for (int j = 1; j <= N; j++) {
				b[j]--;
				if (b[j] == 0) {
					counts--;
				}
			}
			ans.push_back('1');
		} else {
			ans.push_back('0');
		}
	}
	for (int i = 0; i < M; i++) {
		printf("%c", ans[i]);
	}
	return 0;
}
