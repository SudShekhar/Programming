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
bool vow(char c){
if(c=='a' ||c=='e'||c=='i'||c=='o'||c=='u')return true;
else return false;
}

int main()
{
char s[101],w[101];
scanf("%[^\n]",s);
{
int len1 = strlen(s);//len2 = strlen(w);
char ans[101];//ans2[101];
int l=0,k=0;
rep(i,len1){
if(!vow(s[i]))ans[l++]=s[i];
else ans[l++] = s[i],i+=2;
}/*
rep(i,len2){
if(!vow(w[i]))ans2[k++]=w[i];
else {
	ans2[k++] = w[i],i+=2;
	//cout<<"aded"<<ans[k-1]<<" and set i"<<w[i]<<endl;	
}	
}
ans2[k]='\0';*/
ans[l]='\0';
printf("%s\n",ans);
}
return 0;
}

