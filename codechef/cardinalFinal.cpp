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
//uses bitmasks; I have problems understanding its state concept

int main()
{
	int n,arr[101];
	int b,x,c;
	while(si(n)!=EOF){
		rep(i,n)si(arr[i]);

	vector< pair< LL,LL > >mat(1050,mp(0,0));
		rep(j,n){
			b = 0;
			x = arr[j];
			while(arr[j]){
				b |= 1<< (arr[j]%10);
				arr[j]/=10;
			}
			if(mat[b].first < x)
				mat[b].second = 1,mat[b].first = x;
		//	cout<<mat[b].first<< " is "<<x << " and has val "<<mat[b].second<<endl;
			rep(i,1024){
				if(i&b){
				}
				else{
					c = i|b;

				if(mat[c].first < mat[i].first + mat[b].first)
				{
					mat[c].first = mat[i].first + mat[b].first;
					mat[c].second = mat[i].second + mat[b].second;
				}
				else if(mat[c].first == mat[i].first + mat[b].first)
				{
					if(mat[c].second < mat[i].second + mat[b].second)
						mat[c].second = mat[i].second + mat[b].second;
				}

				}

			}

		}
	//	cout<<"sum = "<<mat[1023].first<<endl;
	cout<<mat[1023].second<<endl;
	}

	return 0;
}

