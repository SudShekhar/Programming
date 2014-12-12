
// Standard includes
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define mod 1000000007
#define si(a) scanf("%d",&a);

int arr[1000][1000];
int sol[1000][1000];

int dfs(int x,int y,int **vis,int &ans){
	if(solve[x][y]!=0)
		return solve[x][y];
	vis[x][y] = 1;
	int val=1;
	int dx[]={-1,-1,1,1};
	int dy[] = {1,1,-1,-1};
	rep(i,4){
		nx = x+dx[i];
		ny = y+dy[i];
		if(nx>=0 && nx<n && ny>=0 && ny<n)
			if(arr[nx][ny] > arr[x][y])
				val += dfs(nx,ny,vis,ans);
	}
	solve[x][y]=val;
	ans=max(ans,val);
	return val;
}

int solve(int n){
	//arr contains the mapping.
	int **vis = new int*[n];
	rep(i,n)
		vis[i] = new int[n];

	int ans=0;
	memset(sol,0,sizeof sol);
	// memset(vis,0,sizeof vis);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(!vis[i][j])
				dfs(i,j,vis,ans);
	}
	return ans;
}

int main(){
	int v,re,n;
	si(re);
	rep(v,re){
		si(n);
		rep(i,n)
			rep(j,n)
				si(arr[i][j]);

	cout<<solve(n);			
	}

}

