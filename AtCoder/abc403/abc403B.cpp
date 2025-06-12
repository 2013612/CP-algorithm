#include<iostream>
using namespace std;

string t, u;

int main() {
	cin >> t >> u;
	
	for (int i = 0; i <= t.size() - u.size(); i++) {
		for (int j = 0; j < u.size(); j++) {
			if (t[i + j] != '?' && t[i + j] != u[j]) {
				break;
			}
			
			if (j + 1 == u.size()) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	
	printf("No\n");
	
	return 0;
}