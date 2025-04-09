#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int w;
vector<int> ans;
int main() {
	scanf("%d", &w);
	for (int i = 1; i < 100; i++) {
		ans.push_back(i);
		ans.push_back(i * 100);
		ans.push_back(i * 10000);
	}
	ans.push_back(1e6);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d%c", ans[i], i == ans.size() - 1 ? '\n': ' ');
	}
	return 0;
}