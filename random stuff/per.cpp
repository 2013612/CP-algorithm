#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

string S;
map<char, int> sum;
long long K, two;

void output(string a, string k) {
	if (a.length() == S.length()) {
		cout << a;
		cout << endl;
		return;
	}
	for (int i = 0; i < k.length(); i++) {
		output(a + k[i], k.substr(0, i) + k.substr(i + 1, k.length() - i - 1));
	}
} 

void repeat(string a) {
	if (a.length() == S.length()) {
		cout << a << endl;
		return;
	}
	for (auto x:sum) {
		if (x.second > 0) {
			sum[x.first]--;
			repeat(a + x.first);
			sum[x.first]++;
		}
	}
}

void repeatk(string a) {
	//cout << a.length() << "@" << endl;
	if (a.length() == K) {
		cout << a << endl;
		return;
	}
	for (auto x:sum) {
		if (x.second > 0) {
			sum[x.first]--;
			repeatk(a + x.first);
			sum[x.first]++;
		}
	}
}

void subset() {
	for (int i = 0; i < two; i++) {
		int temp = i;
		for (int j = 0; j < S.length(); j++) {
			if (i & (1<<j)) {
				cout << char('a' + j) << " ";
			}
		}
		/*int count = 0;
		while (temp > 0) {
			if (temp % 2) {
				cout << char('a' + count) << " ";
			}
			count++;
			temp /= 2;
		}*/
		cout << endl;
	}
}

void subset2(string a, int b) {
	cout << a << endl;
	for (int i = b; i < S.length(); i++) {
		subset2(a + S[i], i + 1);
	}
}

int main() {
	cin >> S >> K;
	sort(S.begin(), S.end());
	//output("", S);
	two = 1 << S.length();
	for (int i = 0; i < S.length(); i++) {
		sum[S[i]] += 1;
	}
	//repeatk("");
	//subset();
	subset2("", 0);
	return 0;
}
