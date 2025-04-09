#include<iostream>
#include<unordered_map>
using namespace std;

int n;
unordered_map<int, int> um;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (um.count(a)) {
			printf("%d ", um[a]);
		} else {
			printf("-1 ");
		}
		um[a] = i + 1;
	}
	
	return 0;
}