#include<bits/stdc++.h>
using namespace std;

unordered_map<int, list<int>::iterator> um;
list<int> li;
int q;

int main() {
	scanf("%d", &q);

	li.push_back(0);
	um[0] = li.begin();

	for (int i = 1; i <= q; i++) {
		int t, x, y;
		scanf("%d %d", &t, &x);

		if (t == 1) {
			auto it = li.insert(um[x], i);
			um[i] = it;
		} else {
			scanf("%d", &y);

			auto it1 = um[x];
			auto it2 = um[x];

			while (true) {
				if (it1 != li.begin()) {
					it1--;
				}

				if (it2 != li.end()) {
					it2++;
				}

				if (*it1 == y) {
					break;
				}

				if (it2 != li.end() && *it2 == y) {
					break;
				}
			}

			long long sum = 0;
			if (*it1 == y) {
				auto it = it1;
				it++;
				while (*it != x) {
					sum += *it;
					um.erase(*it);
					li.erase(it);
					it = it1;
					it++;
				}
			} else {
				auto it = it2;
				it--;
				while (*it != x) {
					sum += *it;
					um.erase(*it);
					li.erase(it);
					it = it2;
					it--;
				}
			}

			printf("%lld\n", sum);
		}

	}
	
	return 0;
}