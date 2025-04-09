#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<chrono>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int t, n, k;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d %d", &n, &k);
		bool can = false;
		unordered_set<int, custom_hash> us;
		for (int i = 0; i < n; i++) {
			int p;
			scanf("%d", &p);
			us.insert(p);
			if (us.count(p - k) || us.count(p + k)) {
				can = true;
			}
		}
		if (can) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
