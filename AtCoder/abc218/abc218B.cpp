#include<iostream>
using namespace std;

string s;
int main() {
	for (int i = 0; i < 26; i++) {
		int temp;
		scanf("%d", &temp);
		s.push_back('a' + temp - 1);
	}
	cout << s << endl;
	return 0;
}
