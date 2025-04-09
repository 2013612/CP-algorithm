#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N, future, before, ans[103], arr[10];
bool safe[10];

void com(int cost, int pos, vector<int> path) {
	if (cost >= ans[0]) return;
	
	bool finish = true;
	for (int i = 1; i <= N; i++) {
		finish = finish && arr[i];
	}
	
	if (pos == N && finish) {
		ans[0] = cost;
		for (int i = 0; i < path.size(); i++) {
			ans[i + 1] = path[i];
		}
		return;
	}
	
	for (int i = 1; i <= N; i++) {
		if (i == pos || !safe[i]) continue;
		path.push_back(i);
		arr[i]++;
		for (int j = i + 1; j <= N; j++) {
			safe[j] = !safe[j];
		}
		
		if (i < pos) {
			com(cost + before, i, path);
		} else {
			com(cost + future, i, path);
		}
		path.pop_back();
		arr[i]--;
		for (int j = i + 1; j <= N; j++) {
			safe[j] = !safe[j];
		}
	}
}

int main() {
	scanf("%d", &N);
	scanf("%d %d", &future, &before);
	string temp1;
	cin >> temp1;
	for (int i = 1; i <= N; i++) {
		safe[i] = (temp1[i - 1] == 's');
	}
	ans[0] = 1e9;
	vector<int> temp;
	com(0, N, temp);
	printf("%d", N);
	for (int i = 1; ; i++) {
		printf(" %d", ans[i]);
		if (ans[i] == N) break;
	}
	printf("\n");
	return 0;
}
