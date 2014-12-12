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
int m,n;
int arr[100001];
int ans[100001];
int ind[100001];
int res[100001];
struct comp{
bool operator()(const pair <int,int> &x,const pair<int,int>&y)const{
if(2*ans[x.first]-ans[x.second]!=2*ans[y.first]-ans[y.second])
	return (2*ans[x.first]-ans[x.second]) < (2*ans[y.first]-ans[y.second]);
return x<y;

}
};

map<int,int>Free;
set <pair<int,int>,comp> s;

bool cmpIndex(int u,int v){
return arr[u] < arr[v];
}

void cal(){
	rep(i,n)ind[i]=i;
	sort(ind,ind+n,cmpIndex);
	sort(arr,arr+n);
//sorted all arrays

	rep(i,n){
		while(!s.empty()){
			pr it = *(s.begin());
			if(2*ans[it.first]-ans[it.second]> arr[ind[i]])break;
			Free[2*ans[it.first]-ans[it.second]]=1;
			set<pr>::iterator p = s.begin();
			s.erase(p);
			it.second--;
			if(it.second>=0)
				s.insert(it);
		
		}
		if(Free[arr[i]]==0){
		ans[m]=arr[i];
		res[m]=ind[i];
		s.insert(mp(m,m++));
		}	

	}
	return;
}

int main()
{
si(n);
rep(i,n)si(arr[i]);
m=0;
cal();

cout<<m<<endl;
rep(i,m)cout<<ans[i]<<" ";
cout<<endl;


return 0;
}

