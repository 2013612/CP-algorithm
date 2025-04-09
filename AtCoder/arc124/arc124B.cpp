#include<iostream>
#include<set>
#include<unordered_map>
using namespace std;

int N, a[2003], b[2003];
set<int> ans;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < N; i++) {
		unordered_map<int, int> m;
		for (int j = 0; j < N; j++) {
			if (j != i) {
				m[b[j]]++;
			}
		}
		int x = a[0] ^ b[i];
		for (int j = 1; j < N; j++) {
			int temp = x ^ a[j];
			if (m.count(temp)) {
				m[temp]--;
				if (m[temp] == 0) {
					m.erase(temp);
				}
			} else {
				break;
			}
			if (j == N - 1) {
				ans.insert(x);
			}
		}
	}
	printf("%d\n", ans.size());
	for (auto x:ans) {
		printf("%d\n", x);
	}
	return 0;
}
