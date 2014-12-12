long numWays(int width, int height, String[] bad)
{
	int dp[width+1][height+1];
	dp[0][0]=1;
	map<pair<int, int> , pair<int,int> > banned;
	for(int i=0;i<bad.size();i++){
		start=0;
		num=0;
		for(int j=0;j<bad[i].size();j++){
			if(bad[i][j] == ' ') // start to j-1 is a number
			{
				num=0;
				while(start<j){
					num = num*10 + (bad[i][start]-'0');
					start++;
				}
				temp[ind]=num;
			}
		}
	}
}