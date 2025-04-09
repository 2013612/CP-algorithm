#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<map>
using namespace std;

long long n;
unordered_set<long long> us;
map<long long, int> m;
long long mid = -1;
vector<int> v;

bool has_zero(long long a) {
	while (a != 0) {
		if (a % 10 == 0) {
			return true;
		}
		a /= 10;
	}
	
	return false;
}

bool is_pal(long long a) {
	string s = to_string(a);
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	
	return true;
}

int find_pair(int a) {
	int b = 0;
	while (a != 0) {
		b = b * 10 + a % 10;
		a /= 10;
	}
	
	return b;
}

void solve(long long a) {
	if (us.count(a)) {
		return;
	}
	
	if (!has_zero(a) && is_pal(a)) {
		mid = a;
		return;
	}
	
	us.insert(a);
	
	for (auto x: m) {
		if (x.first > a) {
			break;
		}
		if (a % x.first == 0) {
			v.push_back(x.second);
			solve(a / x.first);
			if (mid > 0) {
				return;
			}
			v.pop_back();
		}
	}
}


int main() {
	scanf("%lld", &n);
	for (int i = 2; i <= 1e6; i++) {
		if (has_zero(i)) {
			continue;
		}
		
		int rev = find_pair(i);
		
		m[1ll * i * rev] = rev;
	}
	
	solve(n);

	if (mid < 0) {
		printf("-1\n");
	} else {
		for (int i = 0; i < v.size(); i++) {
			printf("%d*", v[i]);
		}
		printf("%lld", mid);
		for (int i = 0; i < v.size(); i++) {
			printf("*%d", find_pair(v[v.size() - i - 1]));
		}
		printf("\n");
	}
	
	return 0;
}