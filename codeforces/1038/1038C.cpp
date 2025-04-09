#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N;
long long ans;
vector<int> A, B;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int c;
		scanf("%d", &c);
		A.push_back(c);
	}
	for (int i = 0; i < N; i++) {
		int c;
		scanf("%d", &c);
		B.push_back(c);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < N; i++) {
		if (A.back() > B.back()) {
			ans = ans + A.back();
			A.pop_back();
		} else {
			B.pop_back();
		}
		if (A.empty() || B.empty()) {
			break;
		}
		if (A.back() > B.back()) {
			A.pop_back();
		} else {
			ans = ans - B.back();
			B.pop_back();
		}
		if (A.empty() || B.empty()) {
			break;
		}
	}
	if (A.empty()) {
		if (B.size() % 2 == 1) {
			ans = ans - B.back();
			B.pop_back();
		}
		while (B.size()) {
			B.pop_back();
			ans = ans - B.back();
			B.pop_back();
		}
	} else {
		if (A.size() % 2 == 1) {
			A.pop_back();
		}
		while (A.size()) {
			ans = ans + A.back();
			A.pop_back();
			A.pop_back();
		}
	}
	printf("%lld\n", ans);
	return 0;
}
