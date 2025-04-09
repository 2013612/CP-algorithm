#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, ans, a[1000007];
vector<int> b[6];
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = N - 1; i >= 0; i--) {
		if (a[i] == 4) {
			b[0].push_back(i);
		} else if (a[i] == 8) {
			b[1].push_back(i);
		} else if (a[i] == 15) {
			b[2].push_back(i);
		} else if (a[i] == 16) {
			b[3].push_back(i);
		} else if (a[i] == 23) {
			b[4].push_back(i);
		} else {
			b[5].push_back(i);
		}
	}
	int temp = min(b[0].size(), min(b[1].size(), min(b[2].size(), min(b[3].size(), min(b[4].size(), b[5].size())))));
	while (temp != 0) {
		//cout << ans << endl;
		if (b[0].back() >= b[1].back()) {
			//cout << "!" << endl;
			b[1].pop_back();
			ans++;
		} else if (b[1].back() >= b[2].back()) {
			//cout << "@" << endl;
			b[2].pop_back();
			ans++;
		} else if (b[2].back() >= b[3].back()) {
			//cout << "#" << endl;
			b[3].pop_back();
			ans++;
		} else if (b[3].back() >= b[4].back()) {
			//cout << "$" << endl;
			b[4].pop_back();
			ans++;
		} else if (b[4].back() >= b[5].back()) {
			//cout << "%" << endl;
			b[5].pop_back();
			ans++;
		} else {
			//cout << "^" << endl;
			b[0].pop_back();
			b[1].pop_back();
			b[2].pop_back();
			b[3].pop_back();
			b[4].pop_back();
			b[5].pop_back();
		}
		temp = min(b[0].size(), min(b[1].size(), min(b[2].size(), min(b[3].size(), min(b[4].size(), b[5].size())))));
	}
	printf("%d\n", ans + b[0].size() + b[1].size() + b[2].size() + b[3].size() + b[4].size() + b[5].size());
	return 0;
}
