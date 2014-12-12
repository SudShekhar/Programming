/* Author : Mayank Natani
Email-id : mayanknatani6@gmail.com, mayank.natani@students.iiit.ac.in */
 
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
typedef vector<int > vi;
typedef vector<long long int > vl;
typedef vector<bool > vb;
typedef vector<char > vc;
typedef vector<vi > vvi;
 
#define pb push_back
#define si(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",n)
#define all(a) a.begin(),a.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin() ; it != container.end() ; it++) //to traverse any container
#define present(container,element) (container.find(element)!=container.end()) //should be used for set,map etc.
#define vpresent(container,element) (find(all(container),element)!=container.end()) //should be used for vectors.
#define PI 3.14159265359
#define DegToRad(a) PI/180*a
#define RadToDeg(a) 180/PI*a
int gcd(int a,int b){ if(a==0) return b; return(b%a,a);}
int global_time=0;
typedef struct vertex{
int time;
int low;
bool used ;
int parent;
vi edge;
bool is_cut;
}vertex;
vector < vertex > v(3002);
 
void FindArticulation(int n){
global_time++;
v[n].low = global_time;
v[n].time = global_time;
v[n].used =true;
int no_of_children =0;
int child;
for(int i=0;i<v[n].edge.size();i++){
child = v[n].edge[i];
if(child == v[n].parent)
continue;
if(v[child].used)
v[n].low = min(v[child].time,v[n].low);
else{
v[child].parent=n;
FindArticulation(child);
v[n].low = min(v[child].low,v[n].low);
if(v[child].low >= v[n].time && v[n].parent!=-1)
v[n].is_cut=true;
no_of_children++;
}
}
if(no_of_children>1 && v[n].parent==-1)
v[n].is_cut=true;
return;
}
 
 
int main(){
int test;
si(test);
while(test--){
global_time=0;
int n,m,k;
si(n);si(m);si(k);
int a,b;
for(int i=0;i<n;i++){
v[i].time =-1;
v[i].low = 1e9;
v[i].parent = -1;
v[i].used = false;
v[i].is_cut=false;
v[i].edge.clear();
}
 
for(int i=0;i<m;i++){
si(a);si(b);
v[a].edge.pb(b);
v[b].edge.pb(a);
}
FindArticulation(0);
int ans_count=0;
for(int i=0;i<n;i++){
if(v[i].is_cut)
ans_count++;
}
printf("%d\n",ans_count*k);
}
return 0;
}
