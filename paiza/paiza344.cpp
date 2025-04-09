#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int N;
    scanf("%d", &N);
    char input[N + 2];
    scanf("%s", input);
    int num[N];
    for (int i = 0; i < N; i++) {
        num[i] = input[i] - '0';
    }
    int prefix[N + 1];
    prefix[0] = 0;
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + num[i - 1];
    }
    int suffix[N + 1];
    suffix[0] = 0;
    for (int i = 1; i <= N; i++) {
        suffix[i] = suffix[i - 1] + num[N - i];
    }
    int ans = 1e9;
    int right = lower_bound(suffix, suffix + N + 1, prefix[N] / 3 - 8) - suffix;
    right = N - right;
    int index = 0;
	for (int i = 0; i <= right; i++) {
        int l = lower_bound(prefix, prefix + N + 1, prefix[N] / 3 - 8 + prefix[i]) - prefix;
        int r = lower_bound(suffix, suffix + N + 1, prefix[N] / 3 + 1 - prefix[i]) - suffix;
        r = N - r;
        int a = 0;
        int b = 0;
        int c = prefix[N] / 3 - 8;
        int mini = -1;
        int maxi = 1e9;
        for (int j = l; j <= N - 1 && a <= maxi && a <= prefix[N] / 3 + 8; j++) {
        	a = 0;
        	b = 0;
	        c = prefix[N] / 3 - 8;
	        mini = -1;
	        maxi = 1e9;
            for (int k = r; k <= N && c >= mini && c >= prefix[N] / 3 - 8 && c <= prefix[N] / 3 + 8; k++) {
                a = prefix[j] - prefix[i];
                b = prefix[k] - prefix[j];
                c = prefix[N] - prefix[k] + prefix[i];
                mini = min(a, min(b, c));
                maxi = max(a, max(b, c));
                ans = min(ans, maxi - mini);
                index++;
//                printf("%d %d %d %d\n", i, j, k, ans);
//                printf("%d %d %d %d %d\n", a, b, c, maxi, mini);
            }
        }
        if (ans == 0) {
            break; 
        }
    }
//     for (int i = 0; i < N - 2; i++) {
//         for (int j = i + 1; j < N - 1; j++) {
//             for (int k = j + 1; k < N; k++) {
//                 int cal[3];
//                 cal[0] = prefix[i] + prefix[N] - prefix[k];
//                 cal[1] = prefix[j] - prefix[i];
//                 cal[2] = prefix[k] - prefix[j];
//                 sort(cal, cal + 3);
//                 ans = min(ans, cal[2] - cal[0]);
//                 if (cal[2] - cal[0] == 1) printf("%d %d %d %d\n", i, j, k, ans);
//                 if (ans == 0) {
//                     printf("0\n");
//                     return 0;
//                 }
//             }
//         }
//     }
//     printf("%d %d %d %d\n", prefix[40] - prefix[7], prefix[73] - prefix[40], prefix[N] - prefix[73] + prefix[7], prefix[N]);
    printf("%d\n", index);
	printf("%d\n", ans);
    return 0;
}
