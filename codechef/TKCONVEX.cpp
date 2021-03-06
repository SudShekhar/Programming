#include<cstdio>
#include<vector>
#include<algorithm>
 
using namespace std;
#include<ctime>
#define TIME_LIMIT 0.99
inline double gettime() { return (double)clock() / CLOCKS_PER_SEC ; }
double timelimit;
typedef long long ll;
int N,K;
vector<pair<ll,int> > sticks;
vector<pair<ll,int> > ans1;
vector<pair<ll,int> > ans2;
 
bool next_combination (vector <int> & a, int n) {
int k = (int)a.size();
for(int i=k-1;i>=0;--i)
if(a[i] < n-k + i +1){
++a[i];
for(int j=i+1;j<k;++j)
a[j] = a[j-1]+1;
return true;
}
return false;
}
 
bool solve1(){
int i,j,w,c,from,to;
ll sum;
bool found;
ans1.clear();ans2.clear();
for(w=0,sum=0;w<K-1;w++){
sum += sticks[w].first;
}
found = false; c = K-1;
while(!found && c<N){
if(sum>sticks[c].first){
found=true;c++;from = c-K;to = c-1;
for(j=0;j<K;j++){
ans1.push_back(sticks[c-K+j]);
}
}else{
sum += sticks[c].first;
sum -= sticks[c-K+1].first;
c++;
}
}
if(!found)return false;
for(w=0,sum=0,i=0;w<K-1;w++,i++){
while((i>=from)&&(i<=to))i++;
sum += sticks[i].first;
}
while((i>=from)&&(i<=to))i++;
found = false;c=i;
while(!found && c<N){
if(sum>sticks[c].first){
found=true;
//ans2
for(j=K-1;j>=0;j--){
ans2.push_back(sticks[c]);
c--;
while((c>=from)&&(c<=to))c--;
}
}else{
sum += sticks[c].first;
sum -= sticks[c-K+1].first;
c++;
while((c>=from)&&(c<=to))c++;
}
}
return found;
}
 
bool solve2(){
vector<int> array;
int i,j,idx,w;
ll totsum,sum1,sum2;
bool sw;
for(w=0;w<=N-2*K;w++){
totsum = 0;
for(i=w;i<w+2*K;i++){ totsum += sticks[i].first;}
array.clear();
for(i=0;i<K-1;i++){array.push_back(i+1);}
while(next_combination(array,2*K-2)){
//for(i=0;i<array.size();i++)printf("%d ",array[i]);printf("\n");
sum1 = 0;
for(i=0;i<K-1;i++){ idx = w + array[i]-1; sum1 += sticks[idx].first; }
if((sum1>sticks[idx+1].first)&&(totsum - sum1 - sticks[idx+1].first > 2*sticks[w+2*K-1].first)){
// soln found
ans1.clear();ans2.clear();
for(i=1,j=0;i<=2*K;i++){
if((i==array[j])||(w+i-1==idx+1)){ans1.push_back(sticks[w+i-1]);j++;}
else ans2.push_back(sticks[w+i-1]);
}
return true;
}
}
}
return false;
}
int main(){
int i;
ll l;
timelimit = gettime() + TIME_LIMIT;
scanf("%d %d",&N,&K);
for(i=0;i<N;i++){
scanf("%lld",&l);
sticks.push_back(make_pair(l,i+1));
}
sort(sticks.begin(),sticks.end());
bool res = (solve1() || solve2());
if(res){
printf("Yes\n");
for(i=0;i<ans1.size();i++)printf("%d ",ans1[i].second);
for(i=0;i<ans2.size();i++)printf("%d ",ans2[i].second);
printf("\n");
}
else printf("No\n");
//while(gettime() < timelimit);
return 0;
}
