#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, cnt;
vector<pii> v;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		cnt++;
		if (v.empty() || v.back().first != a) {
			v.push_back({a, 1});
		} else {
			v.back().second += 1;
			if (v.back().first == v.back().second) {
				cnt -= a;
				v.pop_back();
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
