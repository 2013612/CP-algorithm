#include<iostream>
#include<deque>
using namespace std;

int t, a[200006], n;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		deque<int> ans;
		int left = 0;
		int right = n - 1;
		if (a[left] > a[right]) {
			ans.push_back(a[left]);
			left++;
		} else {
			ans.push_back(a[right]);
			right--;
		}
		for (int i = 0; i < n - 2; i++) {
			if (a[left] > a[right]) {
				if (ans.back() < a[left]) {
					break;
				} else {
					ans.push_front(a[left]);
					left++;
				}
			} else {
				if (ans.front() < a[right]) {
					break;
				} else {
					ans.push_back(a[right]);
					right--;
				}
			}
		}
		if (ans.front() > a[left]) {
			ans.push_back(a[left]);
		} else if (ans.back() > a[left]) {
			ans.push_front(a[left]);
		}
		if (ans.size() != n) {
			printf("-1\n");
		} else {
			for (auto x:ans) {
				printf("%d ", x);
			}
			printf("\n");
		}
	}
}
