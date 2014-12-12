// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>

//Data Structures
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define all(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pil(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)

typedef pair<int,int> pr;
typedef vector<int> vec;
typedef vector<vec> matrix;
typedef long long LL;
#define mod 1000000009
/*
Suffix array O(n lg^2 n)
LCP table O(n)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)


const int MAXN = 100002;
	//char * S;
int N, gap;
LL sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

bool sufCmp(int i, int j)
{
	if (pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap;
	j += gap;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA(int *S)
{
	//N = strlen(S);
	REP(i, N) sa[i] = i, pos[i] = S[i];
	for (gap = 1;; gap *= 2)
	{
			sort(sa, sa + N, sufCmp);
			REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
			//pos[sa`:[i]] = tmp[i];
			REP(i, N) pos[sa[i]] = tmp[i];
			if (tmp[N - 1] == N - 1) break;
	}
}

void buildLCP(int *S)
{
		for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
		{
			for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k] &&i+k<N && j+k<N;)
			++k;
			if(k>mod)k%=mod;
			lcp[pos[i]] = k;
			if (k)--k;
		}
}



int main()
{
	int v,re;
	si(re);
	int arr[100001];
	int s[100001];
	int n;int x;
	rep(v,re){
	si(n);
	if(n==1)
	{
		si(x);
		printf("0\n");
		continue;
	}
	
	rep(i,n)si(arr[i]);
	rep(i,n-1)s[i] =(arr[i+1]-arr[i]);
//	s[n-1]='\0';
	
//	scanf("%s",s);
	
	
	N=n-1;
	
	buildSA(s);
	buildLCP(s);
	//rep(i,N)printf("%d\n",sa[i]);
	LL ans = 0;
	ans = N - sa[0];
	FOR(i,1,N){
	ans+= N-sa[i] - lcp[i-1];
	if(ans>mod)ans%=mod;
	}
	printf("%lld\n",ans);//<<endl;	
	}
	
	

return 0;
}

