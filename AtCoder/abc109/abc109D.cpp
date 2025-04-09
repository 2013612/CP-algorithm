#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int H, W, a[502][502];
vector<int> ans;
int main(){
	scanf("%d %d", &H, &W);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < H; i++) {
		if (i == H - 1) {
			for (int j = 0 ; j < W - 1; j++) {
				if (a[i][j] % 2 == 1) {
					a[i][j] -= 1;
					a[i][j + 1] += 1;
					ans.push_back(i);
					ans.push_back(j);
					ans.push_back(i);
					ans.push_back(j + 1);
				}
			}
			break;
		}
		for (int j = 0; j < W; j++) {
			if (j == W - 1) {
				if (a[i][j] % 2 == 1) {
					a[i][j] -= 1;
					a[i + 1][j] += 1;
					ans.push_back(i);
					ans.push_back(j);
					ans.push_back(i + 1);
					ans.push_back(j);
				}
				break;
			}
			if (a[i][j] % 2 == 1) {
				if (a[i][j + 1] % 2 == 1) {
					a[i][j] -= 1;
					a[i][j + 1] += 1;
					ans.push_back(i);
					ans.push_back(j);
					ans.push_back(i);
					ans.push_back(j + 1);
				} else {
					a[i][j] -= 1;
					a[i + 1][j] += 1;
					ans.push_back(i);
					ans.push_back(j);
					ans.push_back(i + 1);
					ans.push_back(j);
				}
			}
		}
	}
	printf("%d", (ans.size() + 1)/4);
	for (int i = 0; i < (ans.size() + 1)/4; i++) {
		printf("\n");
		for (int j = 0; j < 4; j++) {
			printf("%d", ans[i*4 + j] + 1);
			if (j != 3) {
				printf(" ");
			}
		}
	}
	/*for (int i = 0; i < H; i++) {
		printf("\n");
		for (int j = 0; j < W; j++) {
			printf("%d ", a[i][j]);
		}
	}*/
	return 0;
}
