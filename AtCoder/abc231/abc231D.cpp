#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int n, m, a[100006], b[10];
bool can = true;
unordered_map<int, int> um;
unordered_set<int> us;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		us.insert(i);
	}
	for (int i = 0; i < m; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if (us.count(t1) == 0 && us.count(t2) == 0) {
			if (um.count(t1) == 0 || um.count(t2) == 0) {
				can = false;
				break;
			} else {
				int fk1 = um[t1];
				int fk2 = um[t2];
				if (fk1 == t2 || fk2 == t2) {
					can = false;
					break;
				}
				um[fk1] = fk2;
				um[fk2] = fk1;
				um.erase(t1);
				um.erase(t2);
			}
		} else if (us.count(t1) == 1 && us.count(t2) == 1) {
			um[t1] = t2;
			um[t2] = t1;
			us.erase(t1);
			us.erase(t2);
		} else {
			if (us.count(t2) == 0) {
				swap(t1, t2);
			}
			if (um.count(t1) == 0) {
				can = false;
				break;
			}
			int fk = um[t1];
			um[fk] = t2;
			um[t2] = fk;
			um.erase(t1);
			us.erase(t2);
		}
	}
	if (can) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
