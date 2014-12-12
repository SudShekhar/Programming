#line 2 "Family.cpp"

#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)


class Family {
int graph[101][101];
int colrs[101];

bool colorable(int ind,int n,int colr){
	colrs[ind]=colr;
	int opColr = colr==1?2:1;
	rep(i,n)
		if(graph[ind][i]!=0){
			if(colrs[i] == colr)//this is some other node
				return false;
			else if(colrs[i]==0){//this is unvisited node
				bool val = colorable(i,n,opColr);
				if(!val)
					return false;
			}

		} // this isn't a repeated node
	return true;
}
public:
string isFamily(vector <int> parent1, vector <int> parent2) {
	int n = parent1.size();
	memset(colrs,0,sizeof colrs);
	memset(graph,0,sizeof graph);
	for(int i=0;i<n;i++){
		if(parent1[i]!=-1 && parent2[i]!=-1){
			graph[parent2[i]][parent1[i]]=1;
			graph[parent1[i]][parent2[i]]=1;
		}
	}
	// now we need to see if graph is 2 colorable.
	rep(i,n)
		if(colrs[i]==0)
			if(!colorable(i,n,1))
				return "Impossible";
	return "Possible";		
}
};

// BEGIN CUT HERE
// #include <ctime>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <sstream>
// #include <iostream>
// #include <algorithm>
// using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing Family (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415124042;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Family _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent1[] = {-1,-1,0};
				int parent2[] = {-1,-1,1};
				_expected = "Possible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 1:
			{
				int parent1[] = {-1,-1,-1,-1,-1};
				int parent2[] = {-1,-1,-1,-1,-1};
				_expected = "Possible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 2:
			{
				int parent1[] = {-1,-1,0,0,1};
				int parent2[] = {-1,-1,1,2,2};
				_expected = "Impossible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 3:
			{
				int parent1[] = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6};
				int parent2[] = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1};
				_expected = "Possible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 4:
			{
				int parent1[] = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11};
				int parent2[] = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13};
				_expected = "Impossible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			/*case 5:
			{
				int parent1[] = ;
				int parent2[] = ;
				_expected = ;
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int parent1[] = ;
				int parent2[] = ;
				_expected = ;
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int parent1[] = ;
				int parent2[] = ;
				_expected = ;
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
