#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, a[200006], c[200006];
bool d[200006], e[200006], f;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		/*if (a[i] != i) {
			d[a[i]] = true;
		}*/
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		//if (!d[i]) {
			int num = i;
			while(!e[num]) {
				e[num] = true;
				num = a[num];
			}
			int p = num;
			int mini = c[num];
			c[num] = 0;
			num = a[num];
			while(p != num) {
				mini = min(mini, c[num]);
				if (mini == 0) {
					break;
				}
				c[num] = 0;
				num = a[num];
			}
			ans += mini;
		//}
	}
	printf("%d\n", ans);
	return 0;
}
