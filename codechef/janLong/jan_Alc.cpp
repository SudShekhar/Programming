// Standard includesi
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>
#include<climits>

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
{	int ans;
	int ar[17];
	int x,v,re,i,j,n,k,m,temp;
	int count,max;
	cin>>re;
	
	for(v=0;v<re;v++)
	{	
		int MIN = INT_MAX;
		bool found=false;
		cin>>n>>k>>m;
	//	cout<<n<<endl;
		for(i=0;i<n;i++) cin>>ar[i];
		
		//fprintf(stderr,"hey\n");
	//finding out the limiting binary number
		LL lim=pow(2,n);
//	cout<<lim;
	for(x=0;x<lim;x++){
	//checking for 1->n-1
		vector <int> arr(ar,ar+sizeof(ar)/sizeof(ar[0]));
		//making up the required array
		ans=0;
		for(i=0;i<n;i++)
		{
			 temp=1<<i;
			if(x&temp){
				arr[i]++;
				ans++;
			}
	//cout<<arr[i]<<" ";
		}
	//	cout<<"  listed \n";
		//checking if valid
		int flag=0;
		for(i=0;i<=n-k;i++)
		{	
			count=1;
			max=arr[i];
			for(j=1;j<k;j++)
			{
				if(arr[i+j]==max)count++;
				if(arr[i+j]>max)
				{
					max=arr[i+j];
					count=1;
				}
			}
			if(count >= m)
			{
				flag=1;
				break;
			}
		//	cout<< "found " <<count <<" max for "<<i <<"to " <<i+j;
		}
		if(flag==0) {
	/*	cout<<"found cout=="<<count<<" int ans for " << i << "in arr\n ";
			for(i=0;i<n;i++)cout<<arr[i]<<" ";
			cout<<endl;
*/
			//cout<<count<<endl;
			//cout<<x<<endl;
			found=true;
			if(ans<MIN)MIN=ans;

			}
		}
		
		if(found)printf("%d\n",MIN);
		else printf("-1\n");
	}
return 0;
}





