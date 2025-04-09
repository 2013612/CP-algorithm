#include<iostream>
#include<algorithm>
using namespace std;

int a[10];
pair<int, string> ans[40];

bool f(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	
	return a.first > b.first;
}

int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 1; i <= 31; i++) {
		for (int j = 0; j < 5; j++) {
			if (i & (1 << j)) {
				ans[i].second.push_back('A' + j);
				ans[i].first += a[j];
			}
		}
	}
	
	sort(ans + 1, ans + 32, f);
	for (int i = 1; i <= 31; i++) {
		cout << ans[i].second << endl;
	}
	
	return 0;
}