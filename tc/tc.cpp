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

class SixteenBricks{
public:

int maximumSurface(vector<int> height){
	//int n = height.size();
	sort(height.begin(),height.end());
	reverse(height.begin(),height.end());
	int dp[1<<16];
	int i,j,d;
	int cur,state;
	int count=0;
	for(int i=0;i<(1<<16);i++)
		dp[i] = (1<<31);
	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};
	// memset(dp,0,sizeof dp);
	for(state=(1<<16)-1;state>=0;state--){
		bool table[6][6];
		count=0;
		for(i=0;i<6;i++)
			for(j=0;j<6;j++)
				table[i][j]=false;
		for(i=1;i<=4;i++)
			for( j=1;j<=4;j++)
				if(state&(1<<(4*i+j-5)))
					{
						count++;
						table[i][j]=true;
					}
		if(count==16)
		{
			dp[state]=0;
			continue;
		}
		for(i=1;i<=4;i++)
			for( j=1;j<=4;j++){
				if(table[i][j]==false){
					// we will add this one now
					cur=1;
					for(d=0;d<4;d++)
						if(table[i+ dx[d]][j+dy[d]])
							cur-=height[count];
						else cur+=height[count];
					cur+= dp[(state|(1<<(4*i+j-5)))];
					dp[state] = max(dp[state],cur);	
				}
			}
	}
	return dp[0];
}


};

int main(){
	vector<int> height;
	for(int i=0;i<8;i++)
		height.push_back(1);
	for(int i=0;i<8;i++)
		height.push_back(2);
	SixteenBricks a;
	cout<<a.maximumSurface(height)<<endl; 
}