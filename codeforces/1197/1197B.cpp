#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, a[300006], ans, maxi;
vector<int> lef, rig;

int main() {
	scanf("%d", &N);
	lef.push_back(-1);
	rig.push_back(-1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (a[i] == N) {
			maxi = i;
		}
	}
	for (int i = 0; i <= maxi; i++) {
		lef.push_back(a[i]);
	}
	for (int i = N - 1; i > maxi; i--) {
		rig.push_back(a[i]);
	}
	/*for (int i = 0; i < lef.size(); i++) {
		cout << lef[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < rig.size(); i++) {
		cout << rig[i] << " ";
	}
	cout << endl;*/
	for (int i = N; i >= 1; i--) {
		if (lef.back() == i) {
			lef.pop_back();
		} else if (rig.back() == i) {
			rig.pop_back();
		} else {
			//cout << i << endl;
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
