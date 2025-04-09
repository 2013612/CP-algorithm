#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, L, ans;
string A, B, C[3000];
vector<char> temp;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		ans = 0;
		scanf("%d", &L);
		cin >> A;
		cin >> B;
		int count = 0;
		for (int j = 1; j <= L; j++) {
			for (int k = 0; k <= L - j; k++) {
				for (int l = k; l < k + j; l++) {
					temp.push_back(B[l]);
				}
				sort(temp.begin(), temp.end());
				for (int l = 0; l < temp.size(); l++) {
					C[count].push_back(temp[l]);
				}
				temp.clear();
				count++;
			}
		}
		sort(C, C + L*(L + 1)/2);
		for (int j = 1; j <= L; j++) {
			for (int k = 0; k <= L - j; k++) {
				for (int l = k; l < k + j; l++) {
					temp.push_back(A[l]);
				}
				sort(temp.begin(), temp.end());
				string S;
				for (int l = 0; l < temp.size(); l++) {
					S.push_back(temp[l]);
				}
				if (binary_search(C, C + L*(L + 1)/2, S)) {
					ans++;
				}
				temp.clear();
			}
		}
		printf("Case #%d: %d\n", i + 1, ans);
		for (int j = 0; j < 3000; j++) {
			C[j].clear();
		}
	}
	return 0;
}
