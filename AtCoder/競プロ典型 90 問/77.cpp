#include<iostream>
#include<utility>
#include<algorithm>
#include<atcoder/all>
using namespace std;

typedef pair<long long, long long> pll;

int N, T;
pll start[20005], des[20005];
atcoder::mf_graph<int> graph(40005);

void find(int start, pll pos) {
  if (binary_search(des, des + N, pos)) {
    graph.add_edge(start, lower_bound(des, des + N, pos) - des + N + 1, 1);  
  }
}

int main() {
  scanf("%d %d", &N, &T);
  for (int i = 0; i < N; i++) {
    int x, y;
  	scanf("%d %d", &x, &y);
    start[i] = make_pair(x, y);
  }
  for (int i = 0; i < N; i++) {
    int x, y;
  	scanf("%d %d", &x, &y);
    des[i] = make_pair(x, y);
  }
  sort(des, des + N);
  for (int i = 1; i <= N; i++) {
  	graph.add_edge(0, i, 1);
    graph.add_edge(N + i, 2 * N + 1, 1);
  }
  for (int i = 0; i < N; i++) {
    find(i + 1, make_pair(start[i].first + T, start[i].second));
    find(i + 1, make_pair(start[i].first + T, start[i].second + T));
    find(i + 1, make_pair(start[i].first, start[i].second + T));
    find(i + 1, make_pair(start[i].first - T, start[i].second + T));
    find(i + 1, make_pair(start[i].first - T, start[i].second));
    find(i + 1, make_pair(start[i].first - T, start[i].second - T));
    find(i + 1, make_pair(start[i].first, start[i].second - T));
    find(i + 1, make_pair(start[i].first + T, start[i].second - T));
  }
  if (graph.flow(0, 2 * N + 1) != N) {
    printf("No\n");
  } else {
    printf("Yes\n");
    vector<atcoder::mf_graph<int>::edge> edges = graph.edges();
    for (auto x:edges) {
    	if (x.flow == 1 && x.from >= 1 && x.from <= N) {
          int dir = 0;
          if (start[x.from - 1].second == des[x.to - N - 1].second) {
          	if (start[x.from - 1].first > des[x.to - N - 1].first) {
            	dir = 5;
            } else {
             	dir = 1; 
            }
          } else if (start[x.from - 1].first == des[x.to - N - 1].first) {
          	if (start[x.from - 1].second > des[x.to - N - 1].second) {
            	dir = 7;
            } else {
            	dir = 3;
            }
          } else if (start[x.from - 1].first > des[x.to - N - 1].first) {
          	if (start[x.from - 1].second > des[x.to - N - 1].second) {
            	dir = 6;
            } else {
            	dir = 4;  
            }
          } else if (start[x.from - 1].first < des[x.to - N - 1].first){
          	if (start[x.from - 1].second > des[x.to - N - 1].second) {
            	dir = 8;
            } else {
            	dir = 2;
            }
          }
          printf("%d ", dir);
        }
    }
    printf("\n");
  }
  return 0;
}
