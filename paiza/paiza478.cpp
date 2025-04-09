#include<iostream>
#include<stack>
using namespace std;

int h, w, row[503], ans;

void find_max() {
	stack<int> s;
	for (int i = 0; i <= w; i++) {
		while (!s.empty() && row[s.top()] > row[i]) {
			int t = s.top();
			s.pop();
			ans = max(ans, row[t] * (s.empty() ? i : i - s.top() - 1));
		}
		s.push(i);
	}
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < w; j++) {
			if (s[j] == '.') {
				row[j]++;
			} else {
				row[j] = 0;
			}
		}
		find_max();
	}
	
	printf("%d\n", ans);
	return 0;
}