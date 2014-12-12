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


int main()
{
	char msg[100001],code[100001];
	char str[100001];
	int ind=0;
	int n;
	si(n);
	rep(i,n)
	{
		scanf("%s",str);
		strcpy((msg+ind),str);
		ind+=strlen(str);
	}

	int len = strlen(msg);
	scanf("%s",code)	;
	int flag=0;;
	int j;
	int l = strlen(code);
	bool w = true;
	int cnt=0;
	rep(i,l)
	{
		if(code[i]=='3')
		{
			
			cnt++;
			if(w==true){
				cout<<"no\n";
				return 0;
			}
			code[i]='#';
			j=i-1;
			while(code[j]!='<'){
			if(code[j]>='a' && code[j]<='z')
			{
				cout<<"no\n";
				return 0;
				break;
			}
				code[j--]='#';
			}
			code[j]='#';
			w = true;
		}
		else w=false;
	}
	if(cnt!=n+1)
	{
		cout<<"no\n";
		return 0;
	}
	rep(i,l)if(code[i]=='<' || code[i]=='>')
		code[i]='#';
	ind=0;
	j=0;
	while (j<len)
	{	while(code[ind]=='#')ind++;

		if(msg[j] == code[ind])
			j++,ind++;
		else {
			flag=1;
			break;
		}
		if(ind > l){
			flag=1;
			break;
		}
	}
	while(ind<l){

		if(code[ind]!='#')
			flag=1;
		ind++;
	}

	if(flag==1)
		cout<<"no\n";
	else cout<<"yes\n";

	return 0;
}

