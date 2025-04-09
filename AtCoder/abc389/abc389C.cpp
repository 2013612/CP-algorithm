#include<iostream>
#include<vector>
using namespace std;

int q, offset;
vector<long long> a(1, 0);

int main() {
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		
		if (t == 1) {
			int l;
			scanf("%d", &l);
			a.push_back(a.back() + l);
		} else if (t == 2) {
			offset++;
		} else {
			int k;
			scanf("%d", &k);
			printf("%lld\n", a[k + offset - 1] - a[offset]);
		}
	}
	
	return 0;
}