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
	int n;int x;
	int arr[101];int match;
	int mcount,mcard,sm,card;
	set < pair< int,pr > >mset;
	int temp;
	int b,c;
	while(si(n)!=EOF){
		rep(i,n)si(arr[i]);
		mset.clear();
		mcount = 0,mcard=0;
		rep(i,n){
			b =0;
			mcount = 0,mcard=0;
			x = arr[i];
			while(arr[i]!=0){
				b|= (1 << (arr[i]%10));
				arr[i]/=10;
			}
			//mset.insert(mp(b,1));
			temp = b; //store representation of the number
			//inserted all numbers;
			EACH(it,mset)
			{	b = temp;
				c = (*it).first;
				if(c&b){
				}
				else{
					
				sm = (*it).second.second + x;
				card = (*it).second.first+1;

				if(sm > mcount)
				{
					mcount = sm;
					mcard = card;
				}
				else if(sm == mcount)
				{
					if(card > mcard)mcard= card;
				}
				c = c|b;
				//cout<<"added "<<b<<endl;
				mset.insert(mp(c,(mp(card,sm))));
				}
				//cout<<(*it).first << " "<<(*it).second<<endl;
			}
			if(mcount < x)
			{
				mcount = x;
				mcard = 1;
			}
			mset.insert(mp(temp,(mp(1,x))));
		}
		printf("%d\n",mcard);
	}
	return 0;
}

