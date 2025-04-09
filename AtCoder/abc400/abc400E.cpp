#include<iostream>
#include<set>
#include<vector>
using namespace std;

const int M = 1e6;

int q;
set<long long> s;
bool p[1000006];
vector<int> v;

void init() {
	p[0] = p[1] = true;
	
	for (int i = 2; i <= M; i++) {
		if (!p[i]) {
			v.push_back(i);
			for (int j = i + i; j <= M; j += i) {
				p[j] = true;
			}
		}
	}
	
	for (int i = 0; v[i] * v[i] < M; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			long long a = v[i];
			
			while (a * v[j] <= 1e6) {
				long long b = v[j];
				
				while (a * b <= 1e6) {
					s.insert(1ll * a * a * b * b);
					b *= v[j];
				}
				
				a *= v[i];
			}
		}
	}
	
	
}

int main() {
	init();
	
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++) {
		long long a;
		scanf("%lld", &a);
		
		printf("%lld\n", *(--s.upper_bound(a)));
	}
	
	return 0;
}