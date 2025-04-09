#include<iostream>
#include<string>
using namespace std;

int T, N, M, P, C[103], pow[103];
string a[103], b[103];
bool t[2000];
char c[103];

int to_num(string s) {
	int num = 1;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[s.length() - i - 1] == '1') {
			ans += num;
		}
		num *= 2;
	}
	return ans;
}

string to_str(int A) {
	int num = pow[P];
	string temp;
	for (int i = 0; i < P; i++) {
		if (A >= num) {
			temp.push_back('1');
			A -= num;
		} else {
			temp.push_back('0');
		}
		num /= 2;
	}
	return temp;
}

int main(){
	//freopen("B-small-attempt1.in", "r", stdin);
	//freopen("B-small-attempt1.out", "w", stdout);
	scanf("%d", &T);
	pow[0] = 1;
	for (int i = 1; i < 12; i++) {
		pow[i] = pow[i-1]*2;
	}
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &M, &P);
		for (int j = 0; j < N; j++) {
			scanf("%s", c);
			a[j] = c;
			for (int k = 0; k < P; k++) {
				if (a[j][k] == '1') {
					C[k]++;
				}
			}
		}
		for (int j = 0; j < M; j++) {
			scanf("%s", c);
			b[j] = c;
			t[to_num(b[j])] = true;
		}
		int ans = 100000;
		for (int j = 0; j < pow[P]; j++) {
			int ans_temp = 0;
			if (!t[j]) {
				string temp = to_str(j);
				for (int k = 0; k < P; k++) {
					if (temp[k] == '0') {
						ans_temp += C[k];
					} else {
						ans_temp += N - C[k];
					}
				}
				ans = min(ans, ans_temp);
			}
		}
		printf("Case #%d: %d\n", i + 1, ans);
		for (int j = 0; j < 1100; j++) {
			t[j] = false;
		}
		for (int j = 0; j < 103; j++) {
			C[j] = 0;
		}
	}
	return 0;
}
