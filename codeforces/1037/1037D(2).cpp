#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, layer[200006], num[200006], seq[200006];
vector<int> a[200006];
queue<int> c;
bool success = true;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		a[A].push_back(B);
		a[B].push_back(A);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &seq[i]);
	}
	for (int i = 1; i <= N; i++) {
		sort(a[i].begin(), a[i].end());
	}
	/*for (int i = 0; i <= N; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}*/
	int i = 1;
	int pos = 0;
	if (seq[0] != 1) {
		success = false;
	}
	while(success && i < N) {
		for (int j = 1; j < a[seq[pos]].size(); j++) {
			if (j == 1 && pos == 0) {
				if (!binary_search(a[seq[pos]].begin(), a[seq[pos]].end(), seq[i])) {
					success = false;
					break;
				}
				i++;
			}
			if (!binary_search(a[seq[pos]].begin(), a[seq[pos]].end(), seq[i])) {
				success = false;
				break;
			}
			i++;
		}
		pos++;
	}
	if (success) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
