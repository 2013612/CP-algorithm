#include<iostream>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;

const int N = 200006;  // limit for array size
int n, q;  // array size
ppp t[2 * N];

ppp combine(ppp a, ppp b) {
	ppp temp = a;
  	if (b.first.first > temp.first.first) {
  		temp.second = temp.first;
  		temp.first = b.first;
	  } else if (b.first.first == temp.first.first) {
	  	temp.first.second += b.first.second;
	  } else if (b.first.first > temp.second.first) {
	  	temp.second = b.first;
	  } else if (b.first.first == temp.second.first) {
	  	temp.second.second += b.first.second;
	  }
	  
	  if (b.second.first > temp.second.first) {
	  	temp.second = b.second;
	  } else if (b.second.first == temp.second.first) {
	  	temp.second.second += b.second.second;
	  }
	  
	  return temp;
}


void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) {
  	t[i] = combine(t[i<<1], t[i<<1|1]);
  }
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = {{value, 1}, {0, 0}}; p >>= 1; ) {
  	t[p] = combine(t[p<<1], t[p<<1|1]);
  }
}

ppp query(int l, int r) {  // sum on interval [l, r)
   ppp resl, resr;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}


int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		t[n + i] = {{a, 1}, {0, 0}};
//		modify(i, a);
	}
	build();
	for (int i = 0; i < q; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		
		if (a == 1) {
			modify(b - 1, c);
		} else {
			ppp k = query(b - 1, c);
			printf("%d\n", k.second.second);
		}
	}
	
	return 0;
}