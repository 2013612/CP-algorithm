#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans;
string t = "Takahashi";

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		if (a == t) {
			ans++;
		}
	}	
	
	printf("%d\n", ans);
	return 0;
}