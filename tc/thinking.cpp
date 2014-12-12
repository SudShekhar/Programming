#include<bits/stdc++.h>
using namespace std;
int main(){
	pair<int,int> cur = make_pair(1,1);
	queue<pair<int,int> > q;
	q.push(cur);
	int cnt=0;
	while(!q.empty()){
		if(cnt>=20)
			break;
		cnt++;
		cur = q.front();
		cout<<cur.first<< " "<<cur.second<<endl;
		// getchar();
		q.pop();
		q.push(make_pair(cur.first+cur.second,cur.second));
		q.push(make_pair(cur.first,cur.second+cur.second));
	}
	return 0;
}