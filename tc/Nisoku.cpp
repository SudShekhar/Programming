// BEGIN CUT HERE

// END CUT HERE
#line 5 "Nisoku.cpp"

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

#define max(a,b)a>b?a:b
class Nisoku {
public:
double theMax(vector <double> cards) {
	sort(all(cards));
	//double ans = *cards.end();
	int len = cards.size();
	double mat[len][len];
	int j,k;
	double q;
	memset(mat,0,sizeof(mat));
	if(len==1)return cards[0];
	FOR(i,0,len)mat[i][i]=cards[i];
/*
	rep(i,len){
		rep(j,len)cout<<mat[i][j]<<" ";
		cout<<endl;
	}*/
	double a;
	for(int l=2;l<=len;l++){
	
	for(int i=0;i<len-l+1;i++){
	
		j = i+l-1;
		mat[i][j]=0;
		for(k=i;k<j;k++)
		{
			q = max((mat[i][k]*mat[k+1][j]),(mat[i][k]+mat[k+1][j]));
			//cout<<"q="<<q<<"while m = "<<mat[i][j]<<endl;
			if(q > mat[i][j])mat[i][j]=q;
		}
		a = max(cards[i]+cards[j],cards[i]*cards[j]);
		q = max(mat[i+1][j-1]+a,mat[i+1][j-1]*a);
		mat[i][j]=max(q,mat[i][j]);
	}	
	}

/*	rep(i,len)
	{
		rep(j,len)cout<<mat[i][j]<<" ";
	cout<<endl;
	}*/
	double ans = mat[0][len-1];
	return ans;
}
};
/*
int main(){
vector<double> arr;

int n;
si(n);double x;
rep(i,n)scanf("%lf",&x),arr.pb(x);

//rep(i,n)cout<<arr[i]<<" ";
//cout<<endl;
Nisoku a;

cout<< a.theMax(arr)<<endl;

}*/
