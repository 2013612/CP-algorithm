#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector<int> ans;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		if (ans.empty() || ans.back() < temp) {
			ans.push_back(temp);
		} else {
			int pos = lower_bound(ans.begin(), ans.end(), temp) - ans.begin();
			ans[pos] = temp;
		}
	}
	printf("%d\n", ans.size());
	return 0;
}
