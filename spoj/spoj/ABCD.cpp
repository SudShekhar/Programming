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
string s;
int flag=0;
vector<char> ans;
int v;

bool comp(pair<int,int> x ,pr y)
{
	return x.second > y.second;
}

void create(vector<char> arr,vector< pr > nums)
{	
	int len = arr.size();
//	cout<<"got"<<arr[len-1]<<endl;
	//for(char c = 'A';c<='D';c++)
	// {
	//prev=create(i+1,prev.append("A"),ca-1,cb,cc,cd);
	sort(all(nums),comp);
	rep(k,4)
	{	
		char i = nums[k].first + 'A';
		if(i!=s[len] && i!=arr[len-1] && nums[k].second>0){
			//check not same as prev and above elements
			arr.pb(i);
			//if all elements filled
			if(arr.size() == 2*v){
				flag =1;
				rep(x,arr.size())
				{
					ans[x]=arr[x];
				}
				return;
			}
			//if not
			nums[k].second--;
			create(arr,nums);
			if(flag ==0)break;
			else{
				//cout<<"rejected "<<arr[arr.size()-1]<<endl;
				arr.pop_back();
				nums[k].second++;
			}
		}
	}
	return;
}


int ca,cb,cc,cd;
int main()
{
	int re,n,i,j;
	cin >> v;
	// string s;
	cin>>s;

	vector< pair<int,int> > arr;
	arr.pb(mp(0,v));
	arr.pb(mp(1,v));
	arr.pb(mp(2,v));
	arr.pb(mp(3,v));

	// int ca,cb,cc,cd;

	rep(i,2*v)
	{
		arr[s[i]-'A'].second--;
	}
	// ca=arr[0],cb=arr[1],cc=arr[2],cd=arr[3];
	vector<char> arr1;
	ans.clear();
	ans.resize(2*v);
	sort(all(arr),comp);
	rep(k,4)
	{
		char i = arr[k].first + 'A';
	
		if(s[0]!=i && arr[k].second>0)
		{	arr1.pb(i);
			arr[k].second--;
	
			create(arr1,arr);
			//check if true end
			if(flag ==0)break;
			else{
				//remove it and continue
				arr1.pop_back();
				arr[k].second++;
			}
		}
	}
	//cout<<ans<<endl;
	for(i=0;i<2*v;i++)
		cout<<ans[i];
	cout<<endl;


	return 0;
}

