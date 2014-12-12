// BEGIN CUT HERE

// END CUT HERE
#line 5 "GooseTattarrattatDiv2.cpp"

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

typedef pair<int,int> pr;
typedef vector<int> vec;
typedef vector<vec> matrix;
typedef long long LL;
#define mod 1000000007


class GooseTattarrattatDiv2 {
public:
int getmin(string S) {
	int arr[26];
	memset(arr,0,sizeof arr);
	int len = S.length();
	int mx=0;
	rep(i,len){
	arr[S[i]-'a']++;
	if(arr[S[i]-'a'] > mx)mx = arr[S[i]-'a'];
	}
	return len-mx;

}
};

