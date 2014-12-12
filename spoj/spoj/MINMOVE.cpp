//good ques ... understood the pattern but took time to realize the code

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
#define MIN(a,b) a>b?b:a
int main()
{
	string s;
	int min,cur,offset;
	cin>>s;
	int len = s.length();
	min=0,cur=1,offset=0;
	
	while(min +offset+1 <  len and cur <len) 
	{
		if(s[min+offset]==s[(cur+offset)%len]) offset++; //if they are same
		else if(s[min+offset] < s[(cur+offset)%len] ) { // if we find the current substring is less than the min , obv till (cur + offset)  all will be greater than min cuz the numbers from min to cur are greater and the corresponding numbers are equal!
			cur = cur+offset+1;offset= 0;

		}
		else {
		// found that cur+offset is less than min +offset... clearly now the ques is which to chose from cur and min+offset+1....
		min = max(min+offset+1,cur);
	
		//Reason --> let's say we match till ( min+offset ) to (cur+offset):
		//	case1: cur > min+offset+1 : here we will pick cuz obv if (min+offset+1) had been the min lexicographical string we would have got that as min bfre the present position
		// case 2 : cur < min+offset+1 :  we kno that the (min+offset) < (cur+offset) also its less than all (min,min+offset-1)... since cur is in direct correspondence with that one we dont need to set cur up and can directly go to this min+offset
		cur=min+1;
		offset=0;
		}

		
	}
	cout<<min<<endl;
	

return 0;
}

