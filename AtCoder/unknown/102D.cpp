#include<iostream>
#include<vector>
using namespace std;

int N, node, value[30], value2[30], end_node;
vector<int> a, b, c;
int main(){
	scanf("%d", &N);
	int n = N;
	node = 1;
	value[0] = 1;
	value2[0] = 1;
	for (int i = 1; i < 22; i++) {
		value[i] = value[i - 1] * 2;
		//value2[i] = value2[i - 1] + value[i];
	}
	for (int i = 0; i < 22; i++) {
		if (N == value[i] || N / value[i] == 0) {
			end_node = i;
			break;
		}
	}
	while(n != 1) {
		if (node == end_node - 1) {
			for (int i = 0; i < n; i++) {
				a.push_back(node);
				b.push_back(end_node);
				c.push_back(i * value[node - 1]);
			}
			break;
		}
		if (n % 2 != 0) {
			a.push_back(node);
			b.push_back(end_node);
			N -= value[node - 1];
			c.push_back(N);
		}
		a.push_back(node);
		a.push_back(node);
		b.push_back(node + 1);
		b.push_back(node + 1);
		c.push_back(0);
		c.push_back(value[node - 1]);
		node++;
		n = n / 2;
	}
	printf("%d %d\n", end_node, a.size());
	for (int i = 0; i < a.size(); i++) {
		printf("%d %d %d\n", a[i], b[i], c[i]);
	} 
	return 0;
}
