#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> v;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		v.push_back(t);
		while (v.size() > 1 && v.back() == v[v.size() - 2]) {
			v.pop_back();
			v.back()++;
		}
	}
	
	printf("%d\n", v.size());
	
	return 0;
}