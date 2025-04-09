#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

int N, a[103];
int prime[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
long long ans;

int main() {
	scanf("%d", &N);
	ans = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	ans = 1e18;
	for (int i = 1; i < (1 << 15); i++) {
		vector<int> p;
		int temp = i;
		int cou = 0;
		//cout << i << endl;
		while (temp > 0) {
			if (temp & 1) {
				p.push_back(prime[cou]);
			}
			cou++;
			temp = temp / 2;
		}
		
		//cout << "@" << endl;
		//cout << p.size() << endl;
		bool success = true;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < p.size(); k++) {
				if (a[j] % p[k] == 0) break;
				if (k == p.size() - 1) {
					success = false;
				}
			}
			if (!success) break;
		}
		//cout << "#" << endl;
		if (success) {
			long long temp2 = 1;
			for (auto x:p) {
				temp2 *= x;
			}
			ans = min(ans, temp2);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
