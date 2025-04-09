#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

int n, ans, a[200006], mark;
unordered_set<string> us;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		int k;
		cin >> s >> k;
		if (!us.count(s)) {
			us.insert(s);
			if (k > mark) {
				ans = i + 1;
				mark = k;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}