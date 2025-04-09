#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int T, N;

struct list {
	string first, second;
} flight[10005], land[10005];

bool f(list a, list b) {
	return a.first < b.first;
}

bool g(list a, list b) {
	return a.second < b.second;
}

int main(){
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			char temp1[10], temp2[10];
			scanf("%s", temp1);
			scanf("%s", temp2);
			flight[j].first = temp1;
			flight[j].second = temp2;
			land[j].first = temp1;
			land[j].second = temp2;
		}
		sort(flight, flight + N, f);
		sort(land, land + N, g);
		int temp;
		for (int j = 0, k = 0; j < N; j++, k++) {
			if (flight[j].first != land[k].second) {
				if (flight[j].first != land[k + 1].second) {
					temp = j;
					break;
				} else {
					k++;
				}
			}
			if (k == N - 1) {
				temp = N - 1;
			}
		}
		vector<string> v;
		for (int j = 0; j < N; j++) {
			v.push_back(flight[j].first);
		}
		printf("Case #%d: %s-%s", i + 1, flight[temp].first.c_str(), flight[temp].second.c_str());
		for (int j = 1; j < N; j++) {
			temp = lower_bound(v.begin(), v.end(), flight[temp].second) - v.begin();
			printf(" %s-%s", flight[temp].first.c_str(), flight[temp].second.c_str());
		}
		printf("\n");
	}
	return 0;
}
