//Template
//Question - D of round 179 Div 2 - greg and graph
// By Anudeep :)
//Includes
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

//M lazy ;)
typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vs;
typedef pair< int ,int > pii;
typedef vector <ll> vll;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

int o[505],v[505];
int a[505][505];
ll ans[505];
int main() {
	int n;
	ll anss=0;
	scanf("%d",&n);
	rep(i,n) rep(j,n) scanf("%d",&a[i][j]);
	rep(i,n) scanf("%d",&o[i]),o[i]--;
	//scanned up the order of deletions
//as in 4 goes first and otherwise (say)

	rep(i,n) v[o[i]]=i;
	//set up the same inside a different array, v now contains the time at which 4 goes
	for(int ii=n-1; ii>=0; ii--) {
		int k = o[ii];
		//got the final deletions
		anss = 0;
		rep(i,n) rep(j,n) {
			int t = a[i][k] + a[k][j];
			//took path thru that final deletion
			if(t<a[i][j]) a[i][j] = t;
			//set that path as ans
			if(v[i]>=ii && v[j]>=ii) anss += a[i][j];
			//if this 
		}
		ans[ii] = anss;
	}
	rep(i,n) printf("%I64d ",ans[i]);
	return 0;
}
