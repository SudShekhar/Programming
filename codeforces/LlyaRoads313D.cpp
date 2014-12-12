#include <stdio.h>
#include <iostream>
#include <algorithm>
#define INF 999999999999
#define N 350
using namespace std;
int main() {
    int n, m, kk;
    while(scanf("%d%d%d", &n, &m, &kk) != EOF) {
        long long int dp[N][N], w[N][N];
        for(int i = 0; i <= n; i++) 
		for(int j = 0; j <= n; j++) 
			dp[i][j] = INF, w[i][j] = INF, dp[i][0] = 0;//set distance between each ij as INF and between i and 0 as 0
        dp[0][0] = 0;//0 to 0 is 0 cost
        for(int i = 0; i < m; i++) {//for each company
            int l, r;
            long long int c;
            scanf("%d%d%I64d", &l, &r, &c);
            for(int j = l; j <= r; j++) w[l][j] = min(w[l][j], c);//w[l][j] is the cost to repair that particular segment of the road.
        }
        for(int i = 1; i <= n; i++) {//for each vertex
            for(int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j];//
                for(int k = i - j + 1; k <= i; k++) dp[i][j] = min(dp[i][j], dp[k - 1][j - (i - k + 1)] + w[k][i]);
            }
        }
        long long int ans = INF;
        for(int i = kk; i <= n; i++) ans = min(ans, dp[n][kk]);
        if(ans >= INF) printf("-1\n");
        else printf("%I64d\n", ans);
    }
}
