#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N, a[200006], count;
string s;
bool T[30];
vector<int> exist[30];

void clear() {
	for (int i = 0; i < 30; i++) {
		T[i] = false;
	}
}

int main() {
	scanf("%d", &N);
	cin >> s;
	count = 1;
	exist[s[0] - 'a'].push_back(1);
	a[0] = 1;
	for (int i = 1; i < N; i++) {
		clear();
		int num = 0;
		for (int j = s[i] - 'a' + 1; j < 26; j++) {
			if (!exist[j].empty()) {
				for (auto x:exist[j]) {
					if (!T[x]) {
						T[x] = true;
						num++;
					}
				}
			}
		}
		//cout << num << " " << count << endl;
		if (num == count) {
			count++;
			exist[s[i] - 'a'].push_back(count);
			a[i] = count;
		} else {
			bool done = false;
			for (auto x: exist[s[i] - 'a']) {
				if (!T[x]) {
					a[i] = x;
					done = true;
					break;
				}
			}
			if (!done) {
				for (int j = 1; ; j++) {
					if (!T[j]) {
						exist[s[i] - 'a'].push_back(j);
						a[i] = j;
						break;
					}
				}
			}
		}
	}
	cout << count << endl;
	for (int i = 0; i < N; i++) {
		cout << a[i] << " "; 
	}
	cout << endl;
	return 0;
} 
