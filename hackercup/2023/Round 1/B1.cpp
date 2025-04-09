#include<iostream>
#include<map>
#include<vector>
using namespace std;

void solve() {
	map<int, int> m;
	int p;
	scanf("%d", &p);
	int temp = p;
	int sum = 0;
	vector<int> ans;
	for (int i = 2; i * i <= temp; ) {
		if (temp % i == 0) {
			m[i]++;
			temp /= i;
			sum += i;
		} else {
			i++;
		}
	}
	
	if (temp != 1) {
		sum += temp;
		m[temp]++;
	}
	
	if (sum > 41) {
		printf(" -1");
	} else {
		for (int i = 0; i < 41 - sum; i++) {
			ans.push_back(1);
		}
		for (auto it = m.begin(); it != m.end(); it++) {
			for (int i = 0; i < it->second; i++) {
				ans.push_back(it->first);
			}
		}
		printf(" %d", ans.size());
		for (auto v: ans) {
			printf(" %d", v);
		}
	}

	printf("\n");
}

int main() {
	freopen("sum_41_chapter_1_input.txt", "r", stdin);
	freopen("sum_41_chapter_1_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d:", i);
		solve();
	}
	return 0;
}