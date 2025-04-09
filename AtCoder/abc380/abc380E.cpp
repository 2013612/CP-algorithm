#include<iostream>
#include<set>
using namespace std;

set<pair<pair<int, int>, int>> s;
int n, q, cnt[500006];

int main() {
	scanf("%d %d", &n, &q);
	
	for (int i = 0; i <= n + 1; i++) {
		cnt[i] = 1;
		s.insert({{i, i}, i});
	}
	
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, c;
			scanf("%d %d", &x, &c);
			auto temp = s.upper_bound({{x + 1, -1}, -1});
			auto next = temp;
			auto cur = --temp;
			auto prev = --temp;
			
			pair<int, int> interval = (*cur).first;
			int len = (*cur).first.second - (*cur).first.first + 1;
			
			cnt[(*cur).second] -= len;
			cnt[c] += len;
			
			if ((*next).second == c) {
				interval.second = (*next).first.second;
				s.erase(next);
			}
			s.erase(cur);
			if ((*prev).second == c) {
				interval.first = (*prev).first.first;
				s.erase(prev);
			}
			
			s.insert({interval, c});
		} else {
			int c;
			scanf("%d", &c);
			printf("%d\n", cnt[c]);
		}
	}
	
	return 0;
}