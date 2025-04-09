#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int Q, N, a[100006], ans;
vector<int> b[100006], prime;
int intervalA[100006], intervalB[100006], num_interval; 
set<int> factor;

void outputprime(int n){
	std::vector<bool> v;
	v.push_back(false);
	v.push_back(false);
	for(int i = 2; i <= n; i++){
		v.push_back(true);
	}
	for(int i = 2; i*i <= n; i++){
		if (v[i] == false){
			continue;
		} else{
			for (int j = 2*i; j <= n; j+=i){
				v[j] = false;
			}
		}
	}
	for(int i = 2; i <= n; i++){
		if (v[i]){
			prime.push_back(i);
		}
	}
}

int main() {
	scanf("%d %d", &N, &Q);
	outputprime(100006);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		int temp = a[i];
		for (int j = 0; prime[j] * prime[j] <= temp; j++) {
			if (temp % prime[j] == 0) {
				b[i].push_back(prime[j]);
				while (temp % prime[j] == 0) {
					temp /= prime[j];
				}
			}
		}
		if (temp > 1) {
			b[i].push_back(temp);
		}
	}
	int left = 0;
	int right = 0;
	bool add = true;
	while (right < N) {
		bool contain = false;
		for (auto x:b[right]) {
			if (factor.count(x)) {
				contain = true;
				break;
			}
		}
		if (!contain) {
			for (auto x:b[right]) {
				factor.insert(x);
			}
			right++;
			add = true;
		} else {
			if (add) {
				intervalA[num_interval] = left;
				intervalB[num_interval] = right - 1;
				num_interval++;
				add = false;
			}
			for (auto x:b[left]) {
				factor.erase(x);
			}
			left++;
		}
	}
	intervalA[num_interval] = left;
	intervalB[num_interval] = right - 1;
	num_interval++;
	
	for (int i = 0; i < Q; i++) {
		ans = 0;
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		r--;
		while (l <= r) {
			int index = upper_bound(intervalA, intervalA + num_interval, l) - intervalA;
			index--;
			l = intervalB[index] + 1;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
