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
	map<int,int> arr;
	int x;
	rep(i,6)
		si(x),arr[x]++;
	int diff1=-1,diff2=-1;
	bool legs=false;
	int temp;
	map<int,int>::iterator it;
	for(it = arr.begin();it!=arr.end();it++){
		if((*it).second ==4)
			legs=true;
		else if((*it).second >4){
			legs=true;
			temp =(*it).second-4;
			if(temp >= 1 && diff1 == -1)
				diff1 = (*it).first;
			else diff2 = (*it).first;
			if(temp == 2)
				diff2 = diff1;
		}
		else if((*it).second==2){
			diff1=diff2=(*it).first;
		}
		else{
			if(diff1 == -1)
				diff1 = (*it).first;
			else diff2 = (*it).first;
		}

	}
	if(legs==false || diff1 ==-1 || diff2 == -1)
		cout<<"Alien\n";
	else if(legs == true && diff1 == diff2)
		cout<<"Elephant"<<endl;
	else cout<<"Bear"<<endl;
return 0;
}

