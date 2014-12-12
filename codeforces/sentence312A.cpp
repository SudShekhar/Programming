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
int n;
char s[102];
si(n);
scanf("%*c");
int f,g,len;
while(n>0)
{	
	f=0,g=0;fflush(stdin);
	
	
	scanf("%[^\n]%*c",s);
	n--;
	
	if(s[0]=='m' &&s[1]=='i'&&s[2]=='a'&&s[3]=='o' && s[4]=='.')
		f = 1;
	len = strlen(s);
	
	if(strncmp(&s[len-5],"lala.",5) == 0) g=1;
	
	if(g == 0 && f==1) printf("Rainbow' s\n");
	
	else if(f==0 && g==1)printf("Freda' s\n");
	
	else printf("OMG>.< I don't know!\n");
	
}
return 0;
}

