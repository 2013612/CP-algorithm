#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

struct fxx{
	int t, h;
	iterator begin() { 
		return h.begin();
	}
}leak[100006], T[100006];

bool f(fxx a, fxx b) {
	return a.t < b.t ? true : false;
}

bool g(fxx a, fxx b) {
	return a.h > b.h ? true : false;
}
int H, Q;
int main(){
	scanf("%d %d", &H, &Q);
	int mini = 1000000;
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &leak[i].t, &leak[i].h);
		T[i].t = leak[i].t;
		T[i].h = leak[i].h;
		mini = min(mini, leak[i].h);
	}
	if (mini != 0) {
		printf("-1\n");
		return 0;
	}
	sort(leak, leak + Q, f);
	sort(T, T + Q, g);
	leak[Q].t = 1000000;
	double ans = leak[0].t;
	double level = H;
	int speed = 1;
	int i, k;
	k = 0;
	i = 1;
	while(level > 0.000001) {
		if (ans + (level - T[k].h)/speed > leak[i].t && i < Q) {
			level -= (leak[i].t - ans) * speed;
			ans = leak[i].t;
			if (leak[i].h < level) speed++;
			i++;
			continue;
		}
		if (ans + (level - T[k].h)/speed <= leak[i].t && k < Q){
			ans += (level - T[k].h)/speed;
			level = T[k].h;
			k++;
			int M = lower_bound(T, T + Q, level, g) - T.begin();
			int N = upper_bound(T, T + Q, level, g) - T.begin();
			for (int j = 0; j < i; j++) {
				if (leak[j].h == level) {
					speed--;
					break;
				}
			}
		}
	}
	printf("%f\n", ans);
	return 0;
}
