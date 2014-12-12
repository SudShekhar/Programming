// BEGIN CUT HERE

// END CUT HERE
#line 5 "FlippingBitsDiv2.cpp"
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
#define pb push_back

typedef pair<int,int> pr;
typedef vector<int> vec;
typedef vector<vec> matrix;
typedef long long LL;
#define mod 1000000007


class FlippingBitsDiv2 {
public:
int getmin(vector <string> S, int M) {
int arr[2501];
int s = S.size();
int len,l=0,numz=0;
rep(i,s){
len = S[i].length();
rep(j,len){
	if(S[i][j]=='0')arr[l++]=0,numz++;
else arr[l++]=1;
}
}
if(numz <= M/2)return numz;
int numM=0;
int t,ind,inde,flg;
//l has the length
while(1){
	t=0;
	ind=-1;inde=-1;
for(int i=0;i<l;i+=M){
	t=0;
	rep(j,M)
		if(arr[i+j]==0)t++;

	if(t >M/2)ind = i+M;
	else break;
//	if(numz - t > (l-i-M)/2)inde = l-i-M;
}
if(ind!=-1){
rep(i,ind)arr[i]^=1,numz+= arr[i]==0?1:0;numM++;}
for(int i=l-1;i>0;i-=M){
t=0;
rep(j,M)
	if(arr[i-j]==0)t++;
if(t>M/2)inde = i-M+1;
else break;
}
if(inde!=-1){
for(int j=inde;j<l;j++)arr[i]^=1,numz+=arr[i]==0?1:0;
numM;
}
if(ind==-1 && inde==-1)break;
}
}
return numM+numz;

}
};


