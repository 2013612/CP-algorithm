#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int N, a[100006], b[100006];
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &b[i]);
	}
	/*for (int i = 0; i < N - 1; i++) {
		if (a[i] < b[i]) {
			printf("NO\n");
			return 0;
		}
		if (a[i] == 2 && b[i] == 1) {
			return 0;
		}
	}*/
	queue<int> q;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if ((a[0] == (i|j)) && (b[0] == (i&j))) {
				q.push(i);
				q.push(j);
			}
		}
	}
	/*for (int i = 0; i < q.size(); i++) {
		printf("%d ", q.front());
		q.pop();
	}
	printf("\n");*/
	vector<int> ans;
	while (!q.empty()) {
		ans.clear();
		ans.push_back(q.front());
		q.pop();
		ans.push_back(q.front());
		q.pop();
		for (int i = 1; i < N - 1; i++) {
			for (int j = 0; j <= 3; j++) {
				if (a[i] == (ans.back()|j) && b[i] == (ans.back()&j)) {
					ans.push_back(j);
					break;
				}
			}
		}
		if (ans.size() == N) {
			printf("YES\n");
			for (int i = 0; i < N; i++) {
				printf("%d ", ans[i]);
			}
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
