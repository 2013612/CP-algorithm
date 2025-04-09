#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <string>
using namespace std;

int N, M, Q, a[503][503];
set<int> group;
pair<int, int> fir[200006], sec[200006];
priority_queue<pair<int, pair<int, int>>> pq;
int main(void){
    scanf("%d %d %d", &N, &M, &Q);
    for (int i = 0; i < M; i++) {
        int f1;
        scanf("%d %d %d", &fir[i].first, &fir[i].second, &f1);
        a[fir[i].first][fir[i].second] = f1;
        a[fir[i].second][fir[i].first] = f1;
        sec[i] = make_pair(fir[i].second, fir[i].first);
    }
    sort(fir, fir + M);
    sort(sec, sec + M);
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= N; j++) {
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i < Q; i++) {
        int q;
        string op;
        cin >> op >> q;
        if (op == "+") {
            group.insert(q);
            int index = lower_bound(fir, fir + M, make_pair(q, 0)) - fir;
            while (index < M && fir[index].first == q) {
                if (group.find(fir[index].second) == group.end()) {
                    pq.push(make_pair(a[q][fir[index].second], make_pair(q, fir[index].second)));
                }
                index++;
            }
            index = lower_bound(sec, sec + M, make_pair(q, 0)) - sec;
            while (index < M && sec[index].first == q) {
                if (group.find(sec[index].second) == group.end()) {
                    pq.push(make_pair(a[q][sec[index].second], make_pair(q, sec[index].second))); 
                }
                index++;
            }
        } else {
            group.erase(q);
        }
         if (group.size() == 0 || group.size() == N) {
             printf("0\n");
             continue;
         }
         do {
             if (pq.empty()) {
             	printf("0\n");
             	break;
             }
			 pair<int, pair<int, int>> temp = pq.top();
             if ((group.find(temp.second.first) != group.end()) ^ (group.find(temp.second.second) != group.end())) {
                 printf("%d\n", temp.first);
                 break;
             } else {
                 pq.pop();
             }
         } while (true);
        
    }
    return 0;
}
