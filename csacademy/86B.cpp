#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, C, S;

struct fxx{
	int A, B;
}fac[10];

bool f(fxx a, fxx b) {
	return (a.A*(S + a.B)*(S + b.B) + b.A*S*(S + b.B) < b.A*(S + b.B)*(S + a.B) + a.A*S*(S + a.B)) ? true : false;
}


int main(){
	scanf("%d %d %d", &N, &C, &S);
	for (int i = 0; i < N; i++) {
		cin >> fac[i].A >> fac[i].B;
	}
	int cookies = 0;
	sort(fac, fac + N, f);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (C*fac[i].B > (fac[i].A)*(S + fac[i].B) + S*((S - (fac[i].A - cookies) % S) % S)) {
			ans += (fac[i].A - cookies) / S;
			cookies = (S - (fac[i].A - cookies) % S) % S;
			if (cookies != 0) {
				ans += 1;
			}
			S += fac[i].B;
		}
	}
	ans += (C - cookies) / S;
	if ((C - cookies) % S != 0) {
		ans += 1;
	}
	printf("%d\n", ans);
	return 0;
}
