// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>
#include<math.h>
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

//vector< vector<int> > arr(350,vector<int> (350) );
int arr[350][350];

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
vector<int> num(10000000,0);
int n;
void zap(int i,int j){
	//cout<<"zapped ("<<i<<","<<j<<")\n";
					if(i+1 < n && arr[i+1][j]>=0 &&  num[arr[i+1][j]]==-1 && arr[i+1][j]&1)
					{
						arr[i+1][j]=-1;
						zap(i+1,j);
					}
					if(j+1 < n && arr[i][j+1]>=0&& num[arr[i][j+1]]==-1 && arr[i][j+1]&1)
					{
						arr[i][j+1]=-1;
						zap(i,j+1);
					}
					if(j-1 >=0 && arr[i][j-1]>=0&&  num[arr[i][j-1]]==-1 && !(arr[i][j-1]&1)){
						arr[i][j-1]=-1;
						zap(i,j-1);
					}
	return ;
}

void zip(int i,int j){
	//cout<<"zipped ("<<i<<","<<j<<")\n";
			if(i+1 < n && arr[i+1][j]>=0  && !(arr[i+1][j]&1) &&  arr[i+1][j]!=2 )
					{
						arr[i+1][j]=-2;
						zip(i+1,j);
					}
					if(j+1 < n && arr[i][j+1]>=0  && !(arr[i][j+1]&1) && arr[i][j+1]!=2 ){
						arr[i][j+1]=-2;
						zip(i,j+1);
					}
					//if(i==1 && j==1) cout<<"yes\n";
			if(j-1 >=0 && arr[i][j-1]>=0 && !(arr[i][j-1]&1) && arr[i][j-1] !=2){
						arr[i][j-1]=-2;
						zip(i,j-1);
					}
						
	return ;
}

int main()
{
	int re,v,i,j,k;
	
	//map <int,int> count;
	int ind=2;
	//initialising the basics
	num[0]=-1;
	num[1]=-1;
	
	num[2]=0;
	num[3]=1;
	int lim=10000000;
	int l=sqrt(lim);
	
	//calculating the rest of the numbers;
	for(i=4;i<=l;i++)
	{	
		if(num[i]!=-1){
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0){
				//if(i==5)cout<<i<<"    broken by " <<j<<endl;	
				num[i]=-1;
					break;
			}
		}
		
	if(num[i]!=-1){
		
		if(!num[i])num[i]=ind++;
		
		for(k=2*i;k<10000000;k+=k)
			{
			num[k]=-1;
			}
			
		}
		
		}
	}
	for(i=l;i<lim;i++)
	{
		if(num[i]!=-1)num[i]=ind++;
	}
	/*for(i=0;i<100;i++)
	{
		if(!num[i])
			cout<<count[i] << ") "<<i<<endl;
	}
	*/
	
	scanf("%d",&re);
	
	//for each cohesive try
	for(v=0;v<re;v++)
	{
		cin >> n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		int ans=0;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{	//cout << "got "<<arr[i][j]<<endl;
				if(arr[i][j]==-1 || arr[i][j]==-2){
					continue;
				}
				
				//ensured not a previously nulled block
				else 
				if(num[arr[i][j]] == -1)//that it is not prime
				{
					if(arr[i][j]&1)
					{
					//amongst the odd numbers
					ans+=arr[i][j]/2+2;
					
					arr[i][j]=-1;
					zap(i,j);
					}
					
					else{
						//EVEN SET
						
						ans+=arr[i][j]/2;
						arr[i][j]=-2;
						zip(i,j);
						/*if(j+1 < n &&arr[i][j+1]>=0&& num[arr[i][j+1]] && !(arr[i][j+1]&1))arr[i][j+1]=-2; //set the next num as a null
						
						if(i+1 < n && arr[i+1][j]>=0&& num[arr[i+1][j]] && !(arr[i+1][j]&1))arr[i+1][j]=-2;
					*/
					}
					
				}
				else 
				{
					ans+=num[arr[i][j]];
					arr[i][j]=-1;
				}
			}
		}
		
	//	cout<<"Hey";
		//cout<<endl;
		/*for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout<<arr[i][j]<<" ";
			cout<<endl;
		}*/
		printf("%d\n",ans);
	}

	return 0;
}

