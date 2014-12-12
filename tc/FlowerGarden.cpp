#line 2 "FlowerGarden.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007

/*
Question isn't too tough to think about. You just need to find the largest plant that doesn't block any other
plant at each step.

Initially I thought I had to do topological sort, but the issue with this is that plants which don't block
each other i.e. are at the same level also need to have some ordering.


*/


class FlowerGarden {
int graph[51][51];
void dfs(int ind,int vis[],int n,vector<int> &ans,vector<int> &height,vector<pair< int,int> > &st){
	vis[ind]=1;
	cout<<"visiting height "<<height[ind]<<endl;
	for(int i=n-1;i>=0;i--)
		if(graph[ind][st[i].second]==1 && vis[st[i].second]==0)
			dfs(st[i].second,vis,n,ans,height,st);
	
	
	ans.push_back(height[ind]);
	return;
}
public:
vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt) {
	int n = height.size();
	memset(graph,0,sizeof graph);
	int ind;
	for(int i=1;i<=365;i++){
		vector<pair<int,int> > st;
		for(int j=0;j<n;j++){
			if(bloom[j] <= i && wilt[j]>=i)
				st.push_back(make_pair(height[j],j));
		}
		sort(st.begin(),st.end());
		for(int k=0;k<st.size();k++){
			for(int l=k+1;l<st.size();l++)
				if(graph[st[l].second][st[k].second]!=1)
					graph[st[l].second][st[k].second]=1;
		}
		// cout<<endl;
	}
 	
 	rep(i,n)
 	{
 		if(height[i] == 111)
 			cout<<height[i]<<" "<<bloom[i]<<" "<<wilt[i]<<endl;
 		if(height[i] == 112)
 			cout<<height[i]<<" "<<bloom[i]<<" "<<wilt[i]<<endl;
 	}
	// we have an ordering among elements now (according to their original index.
	// cout<<n<<endl;
	// rep(i,n)
	// {		
	// 	rep(j,n)
	// 		cout<<graph[i][j]<<" ";
	// 	cout<<endl;
	// }
	vector<pair<int,int> > st;
	for(int i=0;i<n;i++)
		st.push_back(make_pair(height[i],i));
	sort(st.begin(),st.end());
	// cout<<" height sorted "<<endl;
	// rep(i,n)
	// 	cout<<st[i].first<<" "<<st[i].second<<endl;
	//now we have height
	vector<int> ans;
	int vis[51];
	memset(vis,0,sizeof vis);
	for(int i=n-1;i>=0;i--){
		if(!vis[st[i].second])
			dfs(st[i].second,vis,n,ans,height,st);
	}
	return ans;
}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

// int main(int argc, char* argv[])
// {
// 	if (argc == 1) 
// 	{
// 		cout << "Testing FlowerGarden (500.0 points)" << endl << endl;
// 		for (int i = 0; i < 20; i++)
// 		{
// 			ostringstream s; s << argv[0] << " " << i;
// 			int exitCode = system(s.str().c_str());
// 			if (exitCode)
// 				cout << "#" << i << ": Runtime Error" << endl;
// 		}
// 		int T = time(NULL)-1415456609;
// 		double PT = T/60.0, TT = 75.0;
// 		cout.setf(ios::fixed,ios::floatfield);
// 		cout.precision(2);
// 		cout << endl;
// 		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
// 		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
// 	}
// 	else
// 	{
// 		int _tc; istringstream(argv[1]) >> _tc;
// 		FlowerGarden _obj;
// 		vector <int> _expected, _received;
// 		time_t _start = clock();
// 		switch (_tc)
// 		{
// 			case 0:
// 			{
// 				int height[] = {401, 267, 259, 760, 846, 105, 126, 717, 669, 864, 449, 87, 276, 670, 861, 60, 660, 28, 94, 788, 111, 305, 580, 848, 163, 112, 355};
// 				int bloom[] = {219, 345, 30, 234, 14, 338, 301, 69, 50, 204, 33, 85, 137, 293, 50, 304, 227, 330, 309, 286, 349, 185, 291, 339, 339, 157, 290};
// 				int wilt[] = {343, 358, 365, 336, 295, 350, 351, 84, 52, 324, 363, 356, 183, 350, 222, 329, 362, 342, 358, 305, 356, 363, 365, 343, 350, 311, 353};
// 				int __expected[] = {60, 28, 87, 94, 112, 105, 111, 126, 163, 259, 276, 267, 305, 355, 401, 449, 717, 669, 580, 660, 670, 848, 760, 788, 846, 861, 864};
// 				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
// 				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
// 			}
// 			// case 1:
// 			// {
// 			// 	int height[] = {5,4,3,2,1};
// 			// 	int bloom[] = {1,5,10,15,20};
// 			// 	int wilt[] = {4,9,14,19,24};
// 			// 	int __expected[] = { 5,  4,  3,  2,  1 };
// 			// 	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
// 			// 	_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
// 			// }
// 			// case 2:
// 			// {
// 			// 	int height[] = {5,4,3,2,1};
// 			// 	int bloom[] = {1,5,10,15,20};
// 			// 	int wilt[] = {5,10,15,20,25};
// 			// 	int __expected[] = { 1,  2,  3,  4,  5 };
// 			// 	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
// 			// 	_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
// 			// }
// 			// case 3:
// 			// {
// 			// 	int height[] = {5,4,3,2,1};
// 			// 	int bloom[] = {1,5,10,15,20};
// 			// 	int wilt[] = {5,10,14,20,25};
// 			// 	int __expected[] = { 3,  4,  5,  1,  2 };
// 			// 	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
// 			// 	_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
// 			// }
// 			// case 4:
// 			// {
// 			// 	int height[] = {1,2,3,4,5,6};
// 			// 	int bloom[] = {1,3,1,3,1,3};
// 			// 	int wilt[] = {2,4,2,4,2,4};
// 			// 	int __expected[] = { 2,  4,  6,  1,  3,  5 };
// 			// 	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
// 			// 	_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
// 			// }
// 			// case 5:
// 			// {
// 			// 	int height[] = {3,2,5,4};
// 			// 	int bloom[] = {1,2,11,10};
// 			// 	int wilt[] = {4,3,12,13};
// 			// 	int __expected[] = { 4,  5,  2,  3 };
// 			// 	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
// 			// 	_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
// 			// }
// 			/*case 6:
// 			{
// 				int height[] = ;
// 				int bloom[] = ;
// 				int wilt[] = ;
// 				int __expected[] = ;
// 				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
// 				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
// 			}*/
// 			/*case 7:
// 			{
// 				int height[] = ;
// 				int bloom[] = ;
// 				int wilt[] = ;
// 				int __expected[] = ;
// 				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
// 				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
// 			}*/
// 			/*case 8:
// 			{
// 				int height[] = ;
// 				int bloom[] = ;
// 				int wilt[] = ;
// 				int __expected[] = ;
// 				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
// 				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
// 			}*/
// 			default: return 0;
// 		}
// 		cout.setf(ios::fixed,ios::floatfield);
// 		cout.precision(2);
// 		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
// 		if (_received == _expected)
// 			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
// 		else
// 		{
// 			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
// 			cout << "           Expected: {";
// 			for (unsigned i = 0; i < _expected.size(); i++)
// 			{
// 				if (i) cout << ",";
// 				cout << " " << _expected[i];
// 			}
// 			cout << " }" << endl;
// 			cout << "           Received: {";
// 			for (unsigned i = 0; i < _received.size(); i++)
// 			{
// 				if (i) cout << ",";
// 				cout << " " << _received[i];
// 			}
// 			cout << " }" << endl;
// 		}
// 	}
// }

// END CUT HERE
int main(){
	int height[] = {401, 267, 259, 760, 846, 105, 126, 717, 669, 864, 449, 87, 276, 670, 861, 60, 660, 28, 94, 788, 111, 305, 580, 848, 163, 112, 355};
	int bloom[] = {219, 345, 30, 234, 14, 338, 301, 69, 50, 204, 33, 85, 137, 293, 50, 304, 227, 330, 309, 286, 349, 185, 291, 339, 339, 157, 290};
	int wilt[] = {343, 358, 365, 336, 295, 350, 351, 84, 52, 324, 363, 356, 183, 350, 222, 329, 362, 342, 358, 305, 356, 363, 365, 343, 350, 311, 353};
	int expected[] = {60, 28, 87, 94, 112, 105, 111, 126, 163, 259, 276, 267, 305, 355, 401, 449, 717, 669, 580, 660, 670, 848, 760, 788, 846, 861, 864};
	FlowerGarden a;
	vector<int> op = a.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int)));			
	rep(i,op.size())
		cout<<op[i]<<" ";
	cout<<endl;
	rep(i,op.size())
		cout<<expected[i]<<" ";
	cout<<endl;
}
