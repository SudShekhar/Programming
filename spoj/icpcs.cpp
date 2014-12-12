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

class Team{
	public:
	vec attempt,time;
	char arr[100];
	int rank,pen,ques;
	int num;
	//public:
	void setTeam(int n){	
		num = n;
		 time.resize(n);
		attempt.resize(n);
		ques=0;
		rep(i,n)
		{

			scanf("%d%*c%s",&attempt[i],arr);
			if(arr[0]=='-')time[i] = 0;
			else {
				time[i]=atoi(arr);
				ques++;
			}
			
		}
	}
	void setRank(int n){
		rank = n;
	}
	int getRank(){
		return rank;
	}
	bool operator<(const Team &  B) const 
	{
		return (ques > B.ques) || (ques == B.ques && pen < B.pen);
	
	}
	void print(){
	
		rep(i,num)
		{
			cout<<attempt[i]<<"/"<<time[i]<<endl;
		}
	}
	int Pen(int check)
	{
		int ans =0;
		rep(i,num)
		{
			ans+=time[i] + attempt[i]*check;
		}

		return ans;

	}
};

int main()
{
	int NumT,NumP;

	cin >> NumT >>NumP;
	vector <Team> arr(NumT);
	rep(i,NumT)
		arr[i].setTeam(NumP);	

	sort(all(arr));
	int r=1;
	rep(i,NumT)
	{
	//	arr[i].print();
	//cout<<"--------"<<endl;
	arr[i].setRank(r);
	while(arr[i].ques == arr[i+1].ques && arr[i].pen == arr[i+1].pen) {
		arr[i+1].rank = r;
		i++;
	}

	r++;
	}
	int max= 

	
	

return 0;
}

