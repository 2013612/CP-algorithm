#include<iostream>
using namespace std;

int r, g, b;

int main() {
	scanf("%d %d %d", &r, &g, &b);
	string s;
	cin >> s;
	int ans = 1e9;
	if (s == "Red") {
		ans = min(g, b);
	} else if (s == "Green") {
		ans = min(r, b);
	} else {
		ans = min(r, g);
	}
	
	printf("%d\n", ans);
	
	return 0;
}