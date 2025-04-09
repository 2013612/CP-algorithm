#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, a[200006];
long long T, ans;
vector<int> c, d;
bool first = true;
int main() {
	scanf("%d %lld", &N, &T);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	long long temp = 0;
	for (int i = 0, j = 0; j < N; ) {
		if (temp + a[j] < T) {
			if (first) {
				c.push_back(i);
			}
			temp = temp + a[j];
			j++;
			first = false;
		} else {
			if (!first) {
				d.push_back(j);
			}
			if (i == j) {
				j++;
			}
			temp = temp - a[i];
			i++;
			first = true;
		}
	}
	if (c.size() > d.size()) {
		d.push_back(N - 1);
	}
	for (int i = 0; i < c.size(); i++) {
		
	}
	printf("%d\n", ans);
	return 0;
}
