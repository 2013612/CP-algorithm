#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<unordered_map>
using namespace std;

typedef pair<int, pair<int, int>> pp;

string key(int a, int b, int c) {
	string s;
	char temp[20];
	sprintf(temp, "%04d%04d%04d", a, b, c);
	s = temp;
	return s;
}

const int M = 1e9 + 7;
int T;
unordered_map<string, long long> mymap;

long long cal(int de, int fr, int ba) {
	//printf("%d %d %d\n", de, fr, ba);
	if (de == 1 || fr == 0) return 1;
	string K = key(de, fr, ba);
	if (mymap.count(K) > 0) {
		return mymap[K];
	} else {
		long long temp = (cal(de, fr - 1, ba + 1) + cal(de - 1, ba, fr)) % M;
		mymap[K] = temp;
		return temp;
	}
}

int main() {
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int N, K;
		scanf("%d %d", &N, &K);
		printf("%lld\n", cal(K, N, 0));
	}
	return 0;
}
