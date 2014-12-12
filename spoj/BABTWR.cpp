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
struct box{
	int x,y,z;
	box():x(0),y(0),z(0){};
	box(int a,int b, int c):x(a),y(b),z(c){};
};
//defined it opposite to ensure biggest box comes first
bool operator<(const box &a,const box& b){
	return (a.x > b.x || a.x == b.x && a.y>b.y);
}

int main(){
	int n;
	box arr[1000];
	int ans[1000];
	int l,b,h;
	while(1){
		si(n);
		if(n==0)
			break;
		int ind=0;
		rep(i,n){
			si(l),si(b),si(h);
			arr[ind++] = box(l,b,h);
			arr[ind++] = box(b,h,l);
			arr[ind++] = box(h,l,b);
			arr[ind++] = box(l,h,b);
			arr[ind++] = box(b,l,h);
			arr[ind++] = box(h,b,l);
		}
		//created all possible permutations
		memset(ans,0,sizeof ans);
		sort(arr,arr+ind);
		// rep(i,n)
		// 	cout<<arr[i].x<<" "<<arr[i].y<<endl;
		ans[0] = arr[0].z;
		int mx=ans[0];
		for(int i=1;i<ind;i++){
			ans[i]=arr[i].z;
			rep(j,i){
				if(arr[j].x > arr[i].x && arr[j].y > arr[i].y)
					ans[i] = max(ans[i],(ans[j]+arr[i].z));
			}
			mx=max(mx,ans[i]);
		}
		cout<<mx<<endl;
	}
	return 0;
}