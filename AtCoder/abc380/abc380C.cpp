#include<iostream>
using namespace std;

int n, k;
string s, t;

int main() {
	scanf("%d %d", &n, &k);
	cin >> s;
	s = "0" + s + "0";
	
	int cnt = 0;
	int cnt2 = 0;
	
	for (int i = 1; i < n + 2; i++) {
		if (cnt == k - 1 && s[i] == '0') {
			cnt2++;
			continue;
		}
		
		if (cnt == k && s[i] == '0' && s[i - 1] == '1') {
			for (int j = 0; j < cnt2; j++) {
				t.push_back('0');
			}
		}
		
		if (s[i] == '1' && s[i - 1] == '0') {
			cnt++;
		}
		
		t.push_back(s[i]);
	}
	
	t.pop_back();
	
	cout << t << endl;
	
	return 0;
}