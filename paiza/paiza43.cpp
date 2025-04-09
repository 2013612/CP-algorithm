#include<iostream>
#include<string>
using namespace std;

void recu(string T, long long * cou) {
	long long num = 0;
	for (int i = 0; i < T.length(); i++) {
		if (T[i] >= 'a' && T[i] <= 'z') {
			if (num > 0) {
				cou[T[i] - 'a'] += num;
				num = 0;
			} else {
				cou[T[i] - 'a']++;
			}
		} else if (T[i] == '(') {
			string k = "";
			int open = 1;
			for (int j = i + 1; ; j++) {
				if (T[j] == '(') {
					open++;
				} else if (T[j] == ')') {
					open--;
					if (open == 0) {
						i = j;
						break;
					}
				}
				k.push_back(T[j]);
			}
			long long temp[30];
			for (int j = 0; j < 26; j++) {
				temp[j] = 0;
			}
			recu(k, temp);
			for (int j = 0; j < 26; j++) {
				cou[j] += temp[j] * num;
			}
			num = 0;
		} else {
			num = num * 10 + T[i] - '0';
		}
	}
}

int main() {
	string S;
	cin >> S;
	long long ans[30];
	for (int i = 0; i < 26; i++) {
		ans[i] = 0;
	}
	recu(S, ans);
	for (int i = 0; i < 26; i++) {
		printf("%c %lld\n", 'a' + i, ans[i]);
	}
	
	return 0;
} 
