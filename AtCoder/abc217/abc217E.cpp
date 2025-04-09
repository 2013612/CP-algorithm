#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
using namespace std;

int Q, ans;
priority_queue<int, vector<int>, greater<int>> s;
deque<int> d;
int main() {
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int c;
		scanf("%d", &c);
		if (c == 1) {
			int x;
			scanf("%d", &x);
			d.push_back(x);
		} else if (c == 2) {
			if (!s.empty()) {
				printf("%d\n", s.top());
				s.pop();
			} else {
				printf("%d\n", d.front());
				d.pop_front();
			}
		} else {
			while (!d.empty()) {
				s.push(d.front());
				d.pop_front();
			}
		}
	}
	return 0;
}
