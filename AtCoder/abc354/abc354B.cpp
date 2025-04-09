#include<iostream>
#include<algorithm>
using namespace std;

string s[103];
int sum;

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		int c;
		scanf("%d", &c);
		sum = (sum + c) % n;
	}
	
	sort(s, s + n);
	
	cout << s[sum] << endl;
	
	return 0;
}