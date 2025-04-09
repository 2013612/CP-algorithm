#include<iostream>
#include<unordered_map>
using namespace std;

int q;
unordered_map<int, int> um;

int main() {
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++) {
		int t, x;
		scanf("%d", &t);
		if (t == 3) {
			printf("%d\n", um.size());
		} else {
			scanf("%d", &x);
			if (t == 1) {
				um[x]++;
			} else {
				um[x]--;
				if (um[x] == 0) {
					um.erase(x);
				}
			}
		}
	}
	
	return 0;
}