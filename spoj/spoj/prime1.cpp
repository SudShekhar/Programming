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
    int casen;
    scanf("%d\n", &casen);
    while(casen--)
    {
        int n,m;
        scanf("%d %d\n", &n, &m);

        int * primes = new int[m-n+1];
        for(int i=0;i<m-n+1;++i)
        primes[i] = 0;

        for(int p=2;p*p<=m;++p)
        {
           cout<<"checnking for "<<p<<endl;
		int less = n / p;
            less *= p; // first number <= N && p divides N

            for(int j=less;j<=m;j+=p) if(j != p && j >= n)
            primes[j - n] = 1;
        }

        for(int i=0;i<m-n+1;++i)
        {
            if(primes[i] == 0 && n+i != 1) // We don't want to print if it's 1
            printf("%d\n",n+i);
        }

        if(casen)
          printf("\n");

        delete [] primes;
    }
    return 0;
}

