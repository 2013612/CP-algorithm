#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>
using namespace std;

int N, ans, a[100006];
vector<pair<int, int>> s;
int main() {
	scanf("%d", &N);
	s.push_back(make_pair(0, 0));
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= N; i++) {
		if (a[i] > s.back().first) {
			s.push_back(make_pair(a[i], 1));
		} else if (a[i] == s.back().first) {
			s.back().second++;
		} else {
			while (s.back().first > a[i]) {
				pair<int, int> temp = s.back();
				s.pop_back();
				ans = max(ans, temp.first * temp.second);
				if (a[i] > s.back().first) {
					s.push_back(make_pair(a[i], temp.second + 1));
				} else if (a[i] == s.back().first) {
					s.back().second += temp.second + 1;
				} else {
					s.back().second += temp.second;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
