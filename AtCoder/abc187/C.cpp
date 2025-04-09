#include<iostream>
#include<string>
#include<set>
using namespace std;

set<string> with, without;
int N;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		if (temp[0] != '!') {
			with.insert(temp);
		} else {
			without.insert(temp.substr(1));
		}
	}
	
	for (auto str: with) {
		if (without.find(str) != without.end()) {
			cout << str << endl;
			return 0;
		}
	}
	
	cout << "satisfiable" << endl;
	return 0;
}
