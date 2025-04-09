#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
using namespace std;

int N, ans, a[100005];
map<int, int> b, c;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		b[temp]++;
	}
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		c[temp]++;
	}
	sort(a, a + N);;
	for (int i = 0; i < N; i++) {
		map<int,int>::iterator b1 = b.upper_bound(a[i]);
		if (b1 == b.end()) {
			ans = i;
			break;
		}
		map<int,int>::iterator c1 = c.upper_bound(b1->first);
		if (c1 == c.end()) {
			ans = i;
			break;
		}
		if (b1->second == 1) {
			b.erase(b1);
		} else {
			b1->second--;
		}
		if (c1->second == 1) {
			c.erase(c1);
		} else {
			c1->second--;
		}
		ans = i + 1;
	}
	printf("%d\n", ans);
	return 0;
}
