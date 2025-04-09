#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, a[200006], ans;
vector<int> v;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + N);
	v.push_back(1);
	for (int i = 1; i < N; i++) {
		if (a[i] != a[i - 1]) {
			v.push_back(1);
		} else {
			v.back()++;
		}
	}
	sort(v.begin(), v.end());
	/*for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 1; j <= v[i]; j++) {
			int temp = j;
			int maxi = 0;
			int l = 0;
			while (lower_bound(v.begin() + l, ))
		}
		int temp = v[i];
		int maxi = 0;
		while (binary_search(v.begin(), v.end(), temp)) {
			maxi += temp;
			temp *= 2;
		}
		ans = max(ans, maxi);
	}*/
	for (int i = 1; i < 200006; i++) {
		int temp = i;
		int maxi = 0;
		int l = lower_bound(v.begin(), v.end(), temp) - v.begin();
		while (l != v.size()) {
			maxi += temp;
			temp *= 2;
			l = lower_bound(v.begin() + l + 1, v.end(), temp) - v.begin();
			//cout << maxi << " " << l << endl;
		}
		ans = max(ans, maxi);
	}
	printf("%d\n", ans);
	return 0;
}
