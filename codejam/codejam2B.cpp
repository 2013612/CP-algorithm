#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stdlib.h>
using namespace std;

int T;
int main(){
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int num = rand() % 20 + 1;
		int vase = 0;
		for (int j = 1; j <= 100; j++) {
			int temp;
			cin >> temp;
			if (j == 100) {
				cout << num << " " << 100 << endl;
			} else {
				vase = vase % 20 + 1;
				if (vase == num) {
					vase = vase % 20 + 1;
				}
				cout << vase << " " << j << endl;
			}
		}
	}
	return 0;
}
