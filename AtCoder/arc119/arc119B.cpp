#include<iostream>
#include<string>
using namespace std;

int N, ans;
string S, T;
int main() {
	scanf("%d", &N);
	cin >> S >> T;
	int Sone = 0;
	int Tone = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') {
			Sone++;
		}
		if (T[i] == '1') {
			Tone++;
		}
	}
	if (Sone != Tone) {
		printf("-1\n");
		return 0;
	}
	Sone = Tone = 0;
	int pos = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') {
			Sone++;
		}
		if (T[i] == '1') {
			Tone++;
		}
		if (Sone == Tone) {
			ans += min(Sone, i - pos - Sone + 1);
			pos = i + 1;
			Sone = Tone = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
