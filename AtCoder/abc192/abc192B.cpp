#include<iostream>
#include<string>
using namespace std;

string s;
bool success = true;
int main() {
	cin >> s;
	bool lo = true;
	for (auto x:s) {
		if (lo && (x < 'a' || x > 'z')) {
			success = false;
			break;
		} else if (!lo && (x < 'A' || x > 'Z')) {
			success = false;
			break;
		}
		lo = !lo;
	}
	if (success) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
