#include<iostream>
using namespace std;

int h, w, p[2];
string s[103], x;

int main() {
	scanf("%d %d", &h, &w);
	scanf("%d %d", &p[0], &p[1]);
	
	s[0] = string(100, '#');
	s[h + 1] = string(100, '#'); 
	
	for (int i = 1; i <= h; i++) {
		cin >> s[i];
		s[i] = "#" + s[i] + "#";
	}
	
	cin >> x;
	
	for (int i = 0; i < x.size(); i++) {
		int np0 = p[0];
		int np1 = p[1];
		if (x[i] == 'U') {
			np0--;
		} else if (x[i] == 'D') {
			np0++;
		} else if (x[i] == 'L') {
			np1--;
		} else {
			np1++;
		}
		
		if (s[np0][np1] == '.') {
			p[0] = np0;
			p[1] = np1;
		}
	}
	
	printf("%d %d\n", p[0], p[1]);
	
	return 0;
}