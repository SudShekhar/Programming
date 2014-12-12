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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define sqr(x) (x*x)

char mat[8][8];
void exp(int x,int y){
	int l;
	int r;
	mat[x][y] +=2;
	if(x+4 < 8)mat[x+4][y]+=2;
	else mat[x-4][y]+=2;

	if(y+4 < 8)mat[x][y+4]+=2;
	else mat[x][y-4]+=2;
	
	if(x+4<8 && y+4 <8)mat[x+4][y+4]+=2;
	if(x-4>=0 && y-4>=0)mat[x-4][y-4]+=2;
	
	if(x-4>=0 && y+4<8)mat[x-4][y+4]+=2;
	if(x+4<8 && y-4>=0)mat[x+4][y-4]+=2;
//----------------------------------------------------------
	/*if(x+2 <8)x=x+2;
	else x=x-2;
	if(y+2 < 8)y=y+2;
	else y=y-2;
	
	mat[x][y]+=2;
	if(x+4 < 8)mat[x+4][y]+=2;
	else mat[x-4][y]+=2;

	if(y+4 < 8)mat[x][y+4]+=2;
	else mat[x][y-4]+=2;
	
	if(x+4<8 && y+4 <8)mat[x+4][y+4]+=2;
	if(x-4>=0 && y-4>=0)mat[x-4][y-4]+=2;

	if(x-4>=0 && y+4<8)mat[x-4][y+4]+=2;
	if(x+4<8 && y-4>=0)mat[x+4][y-4]+=2;
*/}
int main()
{
	int v,re,n,m;
	si(re);
	int flg;
	int f,stx,sty,dtx,dty;
	rep(v,re){
		f=0;
		scanf("%*c");
		rep(i,8)
		{
			rep(j,8)
			{
				scanf("%c",&mat[i][j]);
				if(mat[i][j]=='K'){

					if(f==0)stx=i,sty=j,f=1;
					else dtx = i,dty=j;
					mat[i][j]='.';
				}
			}

			scanf("%*c");
		}/*
		rep(i,8){
		rep(j,8)cout<<mat[i][j];
		cout<<endl;
		}*/
	//	cout<<"-------------------------------------------\n";
		exp(dtx,dty);
		exp(stx,sty);
		flg=0;
		/*rep(i,8){
		rep(j,8)cout<<mat[i][j];
		cout<<endl;
		}*/
		rep(i,8){

			rep(j,8)
			if(mat[i][j]=='2')
			{
				cout<<"YES\n";
				flg=1;
				break;
			};
			if(flg==1)break;
		}
		if(flg==0)cout<<"NO\n";
	}
	return 0;
}

