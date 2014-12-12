#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
// #define  pr
// 99 100 2 1 
//    1 100 1
bool def(pair< pair<int,int> ,pair<int ,int> > &a,int ay,int dy,int hy){
	// cout<<"Cost "<<a.first.first<<" "<<a.first.second<<" "<<a.second.first<<" "<<a.second.second<<endl;
	if(hy==0 && a.second.second!=0)
		return true;
	else if(a.second.second==0)return false;
	int lx = ay- a.second.first;
	int ly = a.first.second - dy;
	lx = max(lx,0);
	ly = max(ly,0);
	if(lx == 0 && ly == 0)
		return false;
	else if(lx==0)return true;
	else if (ly==0)return false;
	int xsteps = (hy/ly)+(hy%ly==0?0:1);
	int ysteps = (a.second.second/lx) + (a.second.second%lx==0?0:1);
	if(xsteps < ysteps)
		return true;
	return false;
}
int def(int ax,int dx,int hx,int ay,int dy,int hy){
	// cout<<"Cost "<<a.first.first<<" "<<a.first.second<<" "<<a.second.first<<" "<<a.second.second<<endl;
	int lx = ay- dx;
	int ly = ax - dy;
	lx = max(lx,0);
	ly = max(ly,0);
	if(ly==0)
		return (1<<20);
	while(hy>0){
		hy -= ly;
		hx-=lx;
	}
	if(hx>0)
		return 0;
	return abs(hx)+1;
}
#define mp make_pair
int main(){
	int ax,dx,hx;
	int ay,dy,hy;
	int c1,c2,c3;
	si(hx),si(ax),si(dx);
	si(hy),si(ay),si(dy);
	si(c3),si(c1),si(c2);
	int nax,ndx,nhx;
	long long cst;
	long long ans=9999999999;
	for(int i=0;!i || ax-dy+i<=hy;i++){
		for(int j=0;!j || dx+j<=ay;j++){
				nax = ax+i;
				ndx = dx+j;
				cst = i*c1+j*c2;
				nhx = def(nax,ndx,hx,ay,dy,hy);
				ans=min(ans,cst+nhx*c3);
		}
	}

	cout<<ans<<endl;
	return 0;

	// priority_queue<pair< pair<int,int> ,pair<int,int> > > q;
	// pair< pair<int,int> ,pair<int ,int> > cur=make_pair(make_pair(0,ax),make_pair(dx,hx));
	// pair< pair<int,int> ,pair<int ,int> > temp;
	// q.push(cur);
	// int cst;
	// set<pair< pair<int,int> ,pair<int ,int> > > st;
	// st.insert(cur);
	// while(!q.empty()){
	// 	cur=q.top();
	// 	q.pop();
	// 	// if(st.find(cur)!=st.end())
	// 	// 	continue;
	// 	// st.insert(cur);
	// 	if(def(cur,ay,dy,hy)){
	// 		cout<<-cur.first.first<<endl;
	// 		break;
	// 	}
	// 	cst = cur.first.first;

	// 	temp = mp(mp(cst-c1,cur.first.second+1),cur.second);
	// 	if(st.find(temp) == st.end()){
	// 		q.push(temp);
	// 		st.insert(temp);
	// 	}
	// 	temp = mp(mp(cst-c2,cur.first.second),mp(cur.second.first+1,cur.second.second));
	// 	if(st.find(temp) == st.end()){
	// 		q.push(temp);
	// 		st.insert(temp);
	// 	}
	// 	temp = mp(mp(cst-c3,cur.first.second),mp(cur.second.first,cur.second.second+1));
	// 	if(st.find(temp) == st.end()){
	// 		q.push(temp);
	// 		st.insert(temp);
	// 	}	
	// }
	// return 0;
}
