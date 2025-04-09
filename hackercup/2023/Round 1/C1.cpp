#include<iostream>
#include<set>
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	set<int> ans;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			ans.insert(i + 1);
			for (int j = i; j < n; j += i + 1) {
				if (s[j] == '0') {
					s[j] = '1';
				} else {
					s[j] = '0';
				}
			}
		}
	}
	int q;
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		if (ans.count(t)) {
			ans.erase(t);
		} else {
			ans.insert(t);
		}
	}
	
	printf(" %d", ans.size());

	printf("\n");
}

int main() {
	freopen("back_in_black_chapter_1_input.txt", "r", stdin);
	freopen("back_in_black_chapter_1_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d:", i);
		solve();
	}
	return 0;
}