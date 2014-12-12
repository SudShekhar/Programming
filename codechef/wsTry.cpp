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

int main()
{
int v,re;
si(re);
int start,num,m1,temp;
int cnt[27];
int max;
int ans[10005];
char s[10005];
int len;
int arr[10005],revArr[10005];
int CT[27],rCT[27];
int M;
//si(re);
rep(v,re)
{
	max = -1;
	M=-1;
	rep(i,27)cnt[i]=0;//set count of each as 0
	rep(i,27)rCT[i]=0,CT[i]=0;
	scanf("%s",s);
	len = strlen(s); //got the length of string
	num = 0;
	rep(i,len)//for each
	{
	if(s[i]=='#') //make # as break points , unki index pr store kro local max and global min from start
	{
		//if(max==0)max=-mod;
	ans[num++] = max;
	arr[num-1] = M;
	rep(i,27)cnt[i]=0;
	max = -1;
	}
	else{
	if(++CT[s[i]-'a']> M)M = CT[s[i]-'a'];	
	cnt[s[i]-'a']++;
	if(cnt[s[i]-'a'] > max)
		max=cnt[s[i]-'a'];//ind = i;
	}
	}
	//need to put a check to ensure no empty substr
	ans[num++]=max,arr[num-1]=M;
	//if(s[len-1] !='#')ans[num++]=max,arr[num-1]=M;

	int revNum =num;// s[len-1]=='#'?num+1:num;	
	int M1=-1;
	for(int k=len-1;k>=0;k--)
	{
		if(s[k]=='#')
		{
		revArr[--revNum] = M1;
		}
		else
		{
		if(++rCT[s[k]-'a']>M1)M1=rCT[s[k]-'a'];
		}
	}
	if(s[0]!='#')revArr[0]=M1;
/*	cout<<s<<endl;
	rep(i,num)cout<<ans[i]<<" ";
	cout<<endl;
	rep(i,num)cout<<arr[i]<<" ";
	cout<<endl;
	
	rep(i,num)cout<<revArr[i]<<" ";
	cout<<endl;
*/	
	start =0;
	m1=-1;
	for(start=0;start<num-3;start++)
	{
		if(arr[start]<= 0 || ans[start+1]<=0 || ans[start+2]<=0||revArr[start+3]<=0)
			continue;
			
		temp = arr[start] + ans[start+1] + ans[start+2]+ revArr[start+3];
		//printf("temp is %d for str %d\n",temp,start);
		if(temp > m1)m1=temp; 
	}
	if(m1!=-1)
	printf("%d\n",m1 + 3);
	else printf("0\n");
	//rep(i,27)CT[i]=0,rCT[i]=0;

}

return 0;
}

