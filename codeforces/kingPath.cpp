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
#define mod 1000000007
int d[2][8] = {-1,-1,-1,0,0,1,1,1,
		-1,0,1,-1,1,-1,0,1};
map < pair<int,int>,int > dis;
set < pair<int,int> > allowed;
queue <pair < int,int> > q;
int main()
{
pr start,end;
si(start.first),si(start.second);
si(end.first),si(end.second);
int n;
si(n);
int x,y,z,ii;
rep(i,n)
{
	si(x),si(y),si(z);

	for(ii=y;ii<=z;ii++)
	{
		allowed.insert(mp(x,ii));
	}
}
//allowed now has all the allowed blocks;
dis[start] = 0;

int i;

q.push(start);
pr current;
while(!q.empty())
{
current = q.front();
q.pop();

for(i=0;i<8;i++)
{
	x = current.first + d[0][i];
	y = current.second + d[1][i];
	//if a and y are allowed
	pr a = mp(x,y);
	if(!allowed.count(a) || dis[a] )
		continue;
//	printf("allowed %d %d\n",a.first,a.second);
	dis[a] = dis[current]+1;
	q.push(a);
}

}
if(!allowed.count(end) || !dis[end])
	cout<<"-1\n";

else cout<<dis[end]<<endl;	


return 0;
}

