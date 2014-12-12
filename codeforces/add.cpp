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

int main()
{
int n,k;
bool st[3];
si(n);
int i,j;
int arr[102];
rep(i,3)st[i]=false;
for(i=0;i<n;i++)
{
	si(arr[i]);
}
sort(arr,arr+n);
int ans =0;
int flag,x,temp,top,ind;int ANS[5];int stack[5];
rep(i,n)
{
	flag = 0;
	ind = 0,top = 0;
	temp = arr[i];
	if(arr[i] == 0 and st[0] == false) {
		ANS[ans++]=0;
		continue; 
	}	
	while(arr[i]!=0)
	{

	x = arr[i]%10;
	if(x!=0 and st[ind] == true ) //that is there is that digit already
	{
		flag=1;
		break;
	}

	if(x!=0 and st[ind]==false)stack[top++] = ind;
	arr[i]/=10;ind++;
	}
	if(flag == 0){
		ANS[ans++]=temp;
		while(top)st[stack[--top]]=true;
	}
}
printf("%d\n",ans);
rep(l,ans)
	printf("%d ",ANS[l]);
printf("\n");
return 0;
}

