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
#include<sstream>

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

long long decode(string one)
{	int i;
	int len = one.length();
	string ans="";
//	cout<<len<<endl;
	int time;
	for(i=0;i<=len-2;i+=2)
	{	
	
		time=	((int)(one[i]-'0'));
	//	cout<<"tuime"<<time<<endl;
		rep(k,time)
		ans+= (one[i+1]);	
	//	cout<<ans<<"000 "<<endl;
	}
//	cout<<ans<< " str "<<endl;
	//return
		//strtoul((char*)ans.c_str(),NULL,10) <<endl;
	return atoll((char*)ans.c_str());//<<"atoi"<<endl;
//	return 1;
}
string encode(string inp)
{
	string ans="";
//	cout<<"got"<<ans<<endl;
	int len=inp.length();
char x;int count;
	rep(i,len)
	{
		 x = inp[i];
		count=1;
		while(inp[i+1] == x && count<9){
			i++;
			count++;
		}
		ans+=(count + '0');
		ans+= x;


	}

//	cout<<ans<<endl;
	return ans;

}
int main()
{
char first[100],second[100];
 long long num1,num2,num3;
 string ans;
char sign;
while(((scanf("%s %c %s",first,&sign,second)))!=EOF)
{	
	string s1(first);
	string s2(second);
//	cout<<s1<<endl;
//	fprintf(stderr,"%s\n",first);
	 num1 = decode(s1);
	//int num2 = decode(second);
	num2 = decode(s2);
//	cout<<num1<<endl;
//	cout<<num2<<endl;
	switch (sign){
		case '+': num3=num1+num2;
				break;
		case '-': num3 = num1 - num2;break;
		 case '*' : num3 = num1*num2;break;
		 case '/' : num3 = num1/num2;break;
	}
//	cout<<"int "<<num3<<endl;	
	ostringstream convert;
	convert << num3;
	string result = encode(convert.str());
	//cout<<result[0]<<"sampl"<<endl;	
	cout<<s1 << " "<<sign<<" "<<s2<<" = "<<result<<endl;
	
}

return 0;
}

