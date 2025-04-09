#include<iostream>
using namespace std;

int N;
int a[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
bool ans[2004];
int main() {
	int temp;
	cin >> temp;
	for (int x : a) {
		for (int i = x; i <= 1000; i += x) {
			ans[i] = true;
		}
	}
	if (ans[temp]) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
