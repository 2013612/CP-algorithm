#include<iostream>
#include<string>
using namespace std;

int N, Q;
string s;
string t;
void sort(int l, int r) {
	if (l >= r) {
		return;
	}
	int mid = (l + r)/2;
	sort(l, mid);
	sort(mid + 1, r);
	for (int i = l, j = mid+1, k = 0; ; k++) {
		if (i == mid+1) {
			for (int p = j; p < r + 1; p++) {
				t[k] = s[p];
			}
			break;
		} else if (j == r + 1) {
			for (int p = i; p < mid+1; p++) {
				t[k] = s[p];
			}
			break;
		}
		printf("? %c %c\n", s[i], s[j]);
		fflush(stdout);
		char ans;
		scanf(" %c", &ans);
		if (ans == '>') {
			t[k] = s[j];
			j++;
		} else {
			t[k] = s[i];
			i++;
		}
	}
	for (int i = l; i < r+1; i++) {
		s[i] = t[i];
	}
}
int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++) {
		s.push_back('A' + i);
	}
	t = s;
	sort(0, N-1);
	printf("! ");
	for (int i = 0; i < N; i++) {
		printf("%c", s[i]);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}
