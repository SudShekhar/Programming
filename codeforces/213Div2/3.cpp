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
	LL a;
	char s1[4010];
	sl(a);
	scanf("%s",s1);
	int s[4010];
	int cnt=0;
	int n = strlen(s1);
	rep(i,n){
		s[i]= s1[i]-'0';
		if(s[i]==0)cnt++;
	}


	LL arr[40000];
	memset(arr,0,sizeof arr);
	int sm;
	
	rep(i,n){
		sm=0;
		FOR(j,i,n)
		{
			sm+=s[j];
			if(sm>36002)break;
			arr[sm]++;
			//	cout<<"i is "<<i<<" while j is "<<j<<" sum si"<<sm<<endl;
		}
	}
	//rep(i,a+1)cout<<i<<" = "<<arr[i]<<endl;
	LL ans=0;
	LL lm = 36002;
	LL a1,b;
	if(a){
		///cout<<lm<<endl;
		FOR(i,1,lm+1){
			if(arr[i] !=0 && a%i==0  && (a/i) <=lm){
				a1 = arr[i];
				b=arr[(a/i)];
				ans+= a1*b;
			}
		}
	}
	else{
		LL c;
		c = 0;
		rep(i,lm)
		{
			c+=arr[i];
			if(i>=1)
				ans+=(arr[i]*arr[0]);

		}
		//cout<<arr[0]*c + ans<<endl;
		ans+=arr[0]*c;
	}
	
	cout<<ans<<endl;
	return 0;
}

