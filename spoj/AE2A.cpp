
// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>
#include<sstream>
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
// p[1000][6003];
int md[1000][6003];
/*
 A dp problem of the type P(n,k)
 simply take n upto 1000 and for each add the corresponding possibilities
 */
class BigInt{
	public:
	string s;

	BigInt(){
	s = "0";
	}
	BigInt(int i){
	stringstream ss;
	ss<< i;
	s = ss.str();
	
	}

	BigInt add(BigInt a){	
	int l1 = a.s.size();
	int l2 = s.size();

	if(l1 < l2) a.s = "0" + a.s;
	else s = "0"+s;
	int back = 0;
	int j = max(l1,l2);
	while(j){
	back = back + a.s[j]-'0' + s[j]-'0';
	a.s[j] = '0' + back%10;
	back/=10;
	j--;
	}
	while(back!=0)
	{
	       a.s = "0"+a.s;
	       a.s[0]=back%10+'0';
	       back/=10;
	}
	return a;
	}
};
BigInt& operator+(BigInt &lhs,BigInt &a)
{
	int l1 = a.s.size();
	int l2 = lhs.s.size();

	if(l1 < l2) a.s = "0" + a.s;
	else lhs.s = "0"+lhs.s;
	int back = 0;
	int j = max(l1,l2);
	while(j){
	back = back + a.s[j]-'0' + lhs.s[j]-'0';
	a.s[j] = '0' + back%10;
	back/=10;
	j--;
	}
	while(back!=0)
	{
	       a.s = "0"+a.s;
	       a.s[0]=back%10+'0';
	       back/=10;
	}
	return a;
}
BigInt p[1000][6003];
int main()
{
int re;
si(re);
int n,k;

memset(p,0,sizeof(p));
for(int i=1;i<=6;i++){
	p[1][i]=100;//set up base probabilities
}

for(int i=2;i<110;i++)
{
	p[i][1]=0;
	md[i][1]=0;

	p[i][2] = (p[i-1][1]);
	//md[i][2] = (p[i-1][1] +md[i-1][1])%6;

	p[i][3]=(p[i-1][1] + p[i-1][2]);
//	md[i][3]=(p[i-1][1] + p[i-1][2] + md[i-1][1]+md[i-1][2])%6;
	
	p[i][4]=(p[i-1][1] + p[i-1][2] + p[i-1][3]);
//	md[i][4]=(p[i-1][1] + p[i-1][2] + p[i-1][3] + md[i-1][1]+md[i-1][2]+md[i-1][3])%6;
	
	p[i][5] = (p[i-1][1]+p[i-1][2]+p[i-1][3] + p[i-1][4]);
///	md[i][5] = (p[i-1][1]+p[i-1][2]+p[i-1][3] + p[i-1][4] + md[i-1][1]+md[i-1][2]+md[i-1][3]+md[i-1][4])%6;
	
	p[i][6] = (p[i-1][1]+p[i-1][2]+p[i-1][3]+p[i-1][4]+ p[i-1][5]);
//	md[i][6] = (p[i-1][1]+p[i-1][2]+p[i-1][3]+p[i-1][4]+ p[i-1][5] + md[i-1][1]+md[i-1][2]+md[i-1][3]+md[i-1][4]+md[i-1][5])%6;

//	md[i][1]=0;
	
	for(int j=7;j<=6*i;j++)
	{
		p[i][j] = (p[i-1][j-1] + p[i-1][j-2] + p[i-1][j-3] + p[i-1][j-4]+p[i-1][j-5] + p[i-1][j-6]);

//		md[i][j] = (p[i-1][j-1] + p[i-1][j-2] + p[i-1][j-3] + p[i-1][j-4]+p[i-1][j-5] + p[i-1][j-6]
//				+md[i-1][j-1] + md[i-1][j-2]+md[i-1][j-3]+md[i-1][j-4]+md[i-1][j-5]+md[i-1][j-6])%6;
				
				//if(p[i][j] < 0) {cout<<"fish "<<i<<" "<<j<<endl;
	//		return 0;}
	}
}
rep(v,re){
	si(n),si(k);
	if(n>110 || k>660)printf("0\n");
	else{

	//LL ans = (LL)(p[n][k]);// / (LL)pow(6,n);
	/*if(ans > p[n][k]){
		printf("fish\n");
		ans-=1;
	}
*/
		cout<<p[n][k].s<<endl;
	//printf("%lld\n",ans);
	}
}
return 0;
}

