#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int cou = 200001;
int N, a[200006];
vector<int> ans, use;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		ans.push_back(cou + i);
	}
	int now = 0;
	int now2 = 0;
	int fk = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] > now) {
			int temp = a[i] - 1;
			while (temp >= now) {
				if (a[now2] == temp) {
					use.push_back(now2);
					now2++;
					continue;
				}
				if (fk < use.size()) {
					ans[use[fk]] = temp;
					fk++;
					temp--;
					continue;
				}
				ans[now2] = temp;
				now2++;
				temp--;
			}
			now = a[i];
		}
	}
	for (auto x:ans) {
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}
