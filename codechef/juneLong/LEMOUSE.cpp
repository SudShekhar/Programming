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
#define min(a,b) a>b?b:a
int main()
{
	int fromTop,fromBelow;
int n,m;
int v,re;
int arr[103][103];
int fear[103][103];
char move[103][103]; 
int x,y;
si(re);
char s[103];
rep(v,re){
si(n),si(m);

rep(i,n)
{
	scanf("%s",s);
	rep(j,m)
	{
	arr[i][j]= s[j]-'0';
	}
}
fear[0][0] = arr[0][0] + arr[1][0] + arr[0][1];

for(int i=1;i<n;i++)fear[i][0] = fear[i-1][0] + (arr[i][1]==1?1:0) + (((i<n-1)&&(arr[i+1][0]==1))?1:0),move[i][0]='u';

for(int i=1;i<m;i++)fear[0][i] = fear[0][i-1] + (i<m-1 && arr[0][i+1]==1?1:0) + (arr[1][i]==1?1:0) , move[0][i]='b';
//set up intial conditions
//got fear for each corner set
for(int i=1;i<n;i++) //each row
{
	for(int j=1;j<m;j++) //each col
	{
		fromTop = fear[i-1][j];
		if(arr[i][j-1]==1 && move[i-1][j]=='u')fromTop++; //if it comes to the front right bar

		fromBelow = fear[i][j-1];
		if(arr[i-1][j] == 1 && move[i][j-1] =='b')fromBelow++;
		if(fromTop < fromBelow){

		fear[i][j] = fromTop ;
		move[i][j]='u';}
		else if(fromBelow < fromTop){
		fear[i][j]=fromBelow;
		move[i][j]='b';
		}
		else{
		fear[i][j]=fromBelow;
		move[i][j]='c';
		}
		if((j<m-1&&arr[i][j+1]==1))fear[i][j]++;
		if(i<n-1&&arr[i+1][j]==1)fear[i][j]++;
	
		//ans[i][j] = min(ans[i-1][j] , ans[i][j-1]) + arr[i][j];//add prev path stuff , add present weakness
	//printf("%d ",fear[i][j]);
	}
}/*
rep(i,n)
{
	rep(j,m)printf("%d ",fear[i][j]);
	printf("\n");
}
rep(i,n){
rep(j,m)printf("%c ",move[i][j]);
printf("\n");
}
*/
printf("%d\n",fear[n-1][m-1]);//print min

}

return 0;
}

