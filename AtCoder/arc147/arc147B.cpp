#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, p[403], b[403];
vector<int> odd, even;
vector<pair<int, int>> ans;

void swapA(int pos) {
	b[p[pos]]++;
	b[p[pos + 1]]--;
	
	swap(p[pos], p[pos + 1]);
	
	ans.push_back({0, pos});
}

void swapB(int pos) {
	b[p[pos]] += 2;
	b[p[pos + 2]] -= 2;
	
	swap(p[pos], p[pos + 2]);
	
	ans.push_back({1, pos});
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		b[p[i]] = i;
		if ((p[i] - i) & 1) {
			if (p[i] & 1) {
				odd.push_back(p[i]);
			} else {
				even.push_back(p[i]);
			}
		}
	}
	
	for (int i = 0; i < odd.size(); i++) {
		while (abs(b[even[i]] - b[odd[i]]) > 1) {
			swapB(min(b[even[i]], b[odd[i]]));
		}
		swapA(min(b[even[i]], b[odd[i]]));
	}
	
	for (int i = 1; i <= n; i++) {
		while (b[i] != i) {
			swapB(b[i] - 2);
		}
	}
	
	printf("%d\n", ans.size());
	for (auto [type, pos]: ans) {
		printf("%c %d\n", type == 0 ? 'A' : 'B', pos);
	}
	return 0;
}