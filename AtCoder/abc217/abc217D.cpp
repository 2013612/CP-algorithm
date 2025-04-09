#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int L, Q;
set<int> s;
int main() {
	scanf("%d %d", &L, &Q);
	s.insert(0);
	s.insert(L);
	for (int i = 0; i < Q; i++) {
		int c, x;
		scanf("%d %d", &c, &x);
		if (c == 1) {
			s.insert(x);
		} else {
			auto a = s.lower_bound(x);
			printf("%d\n", (*a) - (*(--a)));
		}
	}
	return 0;
}
