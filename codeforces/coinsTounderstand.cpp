//I hate this town, bacause it's too filled with memories I'd rather forget.
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

//kAc
const double pi = acos(-1.0), eps = 1e-9;
const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
const int MO = (int)(1e9 + 7);

//Two becomes one,and it through all eternity.
#define ALL(x) x.begin(), x.end()
#define fr(x, E) for (__typeof(E.begin()) x = E.begin(); x != E.end(); x++)
#define MP make_pair
#define PB push_back
#define FR first
#define SC second
#define ERR cerr << "ERROR" << endl
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PIII pair<PII, int>
#define PDI pair<double, int>
#define PID pair<int, double>
#define SZ(a) (int)((a).size())
#define VEC vector
#define STR string
#define ISS istringstream
#define OSS ostringstream
#define CLR(a, b) memset(a, b, sizeof(a))
#define gmin(a, b) { if (b < a) a = b; }
#define gmax(a, b) { if (b > a) a = b; }

using namespace std;
int vis[1000001], next[1000001], a[1000001], n, q;
LL t;
int f[1000001];
int in[1000001];
bool must[1000001];
void dfs(int x)
{
	if (vis[x]) { puts("0"); exit(0); }
	vis[x] = true;
	if (next[x] == 0) { must[x] =true; return; }
	a[next[x]] += a[x];
	dfs(next[x]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("temp.in", "r", stdin); freopen("temp.out", "w", stdout);
#endif
   	scanf("%d%d%d", &n, &q, &t);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= q; i++){
		int b, c; scanf("%d%d", &b, &c);
		next[b] = c; 
		++in[c];
	}
	for (int i = 1; i <= n; i++) if (in[i] == 0){
		dfs(i);
	}
	int ok = true;
	for (int i = 1; i <= n; i++) if (!vis[i]) ok = false;
	if (!ok) { puts("0"); return 0; }
	for (int i =1; i <= n; i++) if (!must[i]) t -= a[i];
	if (t < 0) { puts("0"); return 0; }
	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	printf("\n");
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= t; j++) if (j + a[i] <= t) f[j + a[i]] = (f[j + a[i]] + f[j]) % MO;
	cout << f[t] << endl;
}
