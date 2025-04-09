#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, H, a[200006], b[200006], ans, dis[200006], air[200006], pos[200006];
int main(){
	scanf("%d %d", &N, &H);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i], &b[i]);
		air[i] = b[i] - a[i];
		if (i == 0) {
			dis[i] = a[i] + 1e9;
		} else {
			dis[i] = a[i] - b[i - 1];
		}
	}
	dis[N] = 2e9 - b[N - 1];
	int height = H;
	int back = 0;
	for (int i = 0; i < N; i++) {
		while (height > 0) {
			pos[i] += air[back];
			height -= dis[back + 1];
			back++;
		}
		if (back == N) {
			break;
		}
		pos[i + 1] = pos[i] - air[i];
		height += dis[i + 1];
	}
	/*for (int i = 0; i < N; i++) {
		cout << pos[i] << endl;
	}*/
	for (int i = 0; i < N; i++) {
		ans = max(ans, pos[i]);
	}
	printf("%d\n", ans + H);
	return 0;
} 
