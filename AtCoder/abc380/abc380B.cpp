#include<iostream>
#include<vector>
using namespace std;

string s;
vector<int> a;

int main() {
	cin >> s;
	s.pop_back();
	
	for (auto x: s) {
		if (x == '|') {
			a.push_back(0);
		} else {
			a.back()++;
		}
	}
	
	for (auto x: a) {
		printf("%d ", x);
	}
	printf("\n");
	
	return 0;
}