/* Author : Yashasvi girdhar
*/

/* Data Structure Includes */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>

/*other Includes */
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>

/* C Includes */
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef vector<int > vd;
typedef vector<long long int > vl;
typedef vector<bool > vb;
typedef vector<char > vc;
typedef vector<vd > vvd;

#define pb push_back
#define si(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",n)
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define all(a) a.begin(),a.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin() ; it != container.end() ; it++) //to traverse any container
#define present(container,element) (container.find(element)!=container.end()) //should be used for set,map etc.
#define vpresent(container,element) (find(all(container),element)!=container.end()) //should be used for vectors.
#define PI 3.14159265359
#define DegToRad(a) PI/180*a
#define RadToDeg(a) 180/PI*a

#define SIEVE(a) ({int b=ceil(sqrt(a));vd d(a,0);vd e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})


#define debug 0


int gcd(int a,int b){
	    if(b>a) return gcd(b,a);
	        return b==0?a:gcd(b,a%b);
}
void swap(int *m,int *n){
    int temp = *n;
    *n = *m;
    *m = temp;
}
struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.first < right.first;
    }
};

int compare (const void *a, const void *b){
	const int *ia = (const int *)a; // casting pointer types 
	const int *ib = (const int *)b;
	return *ia  - *ib; 
}

int main(){
    int n;
    si(n);
    long long int a[n];
    int negcount=0;
 
    REP(i,n){
		scanf("%lld",&a[i]);
		if(a[i] < 0){
			negcount++;
		}
    }
    long long int x;
    scanf("%lld",&x);
    if(negcount==0 || x==0){
		cout<<"0\n";
		return 0;
	}
	
	sort(a,a+n);
    long long int ans=0;
    int check=0;
    int flag=0;
    if(debug)
		cout<<"x= "<<x<<" negcount= "<<negcount<<endl;
	
	int tempmin=999999, tempmindex=-1;
		
	REP(i,n){
		if(a[i] >= check){
			if(i==0){
				flag=1;
				break;
			}
			tempmin = a[i-1];
			tempmindex = i-1;
			break;				
		}
		else if(i==n-1){
			tempmin = a[i];
			tempmindex = i;
		}
	}
	
	while(x < negcount && tempmindex>0){
		if(debug){
			cout<<"while\n";
			REP(i,n)
				cout<<a[i]<<" ";
			cout<<endl;
		}
		
		if(flag==1)
			break;
		if(debug)
			cout<<"min= "<<tempmin<<" minindex = "<<tempmindex<<endl;
		
		ans += abs(tempmin - check) * x;
		check -= abs(tempmin - check);
	
		if(debug)	
			cout<<"ans = "<<ans<<" check= "<<check<<endl;
			
		//cout<<"tempmin = "<<tempmin<<endl;	
		for(int i = tempmindex ; i >=0 ; i--){
			if(a[i] < check){
				negcount = i+1;
				break;
			}
			else if(i==0){
				negcount=0;
			}
				
		}
		if(debug)
			cout<<"x= "<<x<<" negcount= "<<negcount<<endl;
		tempmin = a[negcount-1];
		tempmindex = negcount -1;
	}

	if(flag==1){
		cout<<ans<<endl;
		return 0;	
	}
	REP(i,n){
		if(a[i] < check)
			ans += (abs(a[i]) - abs(check));
		else
			break;
	}
	cout<<ans<<endl;	
	return 0;
}
