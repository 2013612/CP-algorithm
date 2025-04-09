#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n;
set<int> s;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		s.insert(t);
	}
	printf("%d\n", s.size());
	return 0;
}
