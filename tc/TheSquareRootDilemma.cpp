#line 2 "TheSquareRootDilemma.cpp"

// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007

int primes[87779];
class TheSquareRootDilemma {
	vector<long long> squares;
	vector<int> stored;

	int ind,is;
	void init(){
		// stored.resize(5000);
		is=0;
		// memset(primes,true,sizeof primes);
		for(int i=2;i<77777;i++){
			if(primes[i]==0){
				stored.push_back(i);
				for(int j=2*i;j<=77777;j+=i)
					primes[j]=1;
			}
		}
		// stored.resize(is);
		squares.resize(77778);
		long long val = 77777;
		// long long MAXN = val*val;
		ind=0;
		for(long long i=1;i<=val;i++){
			squares[ind++]= i*i;
		}
	}

public:
bool cmp(long long a,long long b){
	return a<b;
}
long long getNextSq(long long val){
	// cout<<" Value for " <<val;
	long long ans=1;
	int count=0;
	int pr;
	// // cout<<stored.size() << "size "<<endl;
	for(int i=0;i<stored.size();i++){
		pr = stored[i];
		if(val<pr)
			break;
		count=0;
		while(val%pr==0)
			count++,val/=pr;
		// cout<<pr<<" se krne par <"<<count<<endl;
		if(count%2!=0)
			ans*=pr;
	}
	if(val!=1 && val!=0){
		//this number is a prime itesel
		ans*=val;
	}
	// cout<<" "<<ans<<endl;
	return ans;
}
int countPairs(long long N, long long M) {
	init();
	int ans=0;
	if(N>M){
		N=N+M-(M=N);
	}
	int idx;
	// cout<<ind<<endl;
	long long val;
	// cout<<N<<" "<<M<<endl;	
	vector<long long > :: iterator it;
	for(long long i=1;i<=N;i++){
		// int idx = lower_bound(squares.begin(),squares.end(),i) - squares.begin();
		// while(idx<ind && squares[idx]%i!=0)idx++;
		// cout<<squares[idx]<<" for i "<<i<<endl;
		val = M/(getNextSq(i));

		// cout<<"for "<<i<<"Only numbers below "<<val<<endl;
		idx = upper_bound(squares.begin(),squares.end(),val) - squares.begin();
		// cout<<"Thus we add "<<idx<<endl;
		ans+= idx;
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

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing TheSquareRootDilemma (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415615266;
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
		TheSquareRootDilemma _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 50005;
				int M =  7777;
				_expected = 113985;
				_received = _obj.countPairs(N, M); break;
			}
			case 1:
			{
				int N = 10;
				int M = 1;
				_expected = 3;
				_received = _obj.countPairs(N, M); break;
			}
			case 2:
			{
				int N = 3;
				int M = 8;
				_expected = 5;
				_received = _obj.countPairs(N, M); break;
			}
			case 3:
			{
				int N = 100;
				int M = 100;
				_expected = 310;
				_received = _obj.countPairs(N, M); break;
			}
			case 4:
			{
				int N = 77777;
				int M =  24512;
				_expected = 278870;
				_received = _obj.countPairs(N, M); break;
			}
			/*case 5:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.countPairs(N, M); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.countPairs(N, M); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
