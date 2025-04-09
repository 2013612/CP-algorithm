#include<iostream>
#include<vector>
using namespace std;

int m;
vector<int> ans;
int main() {
	scanf("%d", &m);
	
	while (m > 0) {
		int k = 1;
		int i = 0;
		do {
			if (k > m) {
				m -= k / 3;
				ans.push_back(i - 1);
				k = 0;
				break;
			}
			k *= 3;
			i++;
		} while (i <= 10);
		
		if (k > 0) {
			m -= k / 3;
			ans.push_back(10);
		}
	}
	
	printf("%d\n", ans.size());
	for (auto x: ans) {
		printf("%d ", x);
	}
	printf("\n");
	
	return 0;
}