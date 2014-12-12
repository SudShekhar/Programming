#include<stdio.h>
#define f(i,start,end) for(i=start;i<end;i++)
char arr[14][14];
int n;

#define min(a,b) a<b?a:b
int get(int x,int y,int t)
{
	if(x==y==0 && t==0)
	{	arr[0][0]=0;
		return 0;
	}
	if(x==y==0 && t!=0) return 1000;
	if(x<0 || y<0)return 1000;
	if(x>=n||y>=n)return 1000;

	if(arr[x][y]=='#')return 1000;
	if(arr[x][y]=='*')t--;

	if(arr[x][y]==-5)
	{

	arr[x][y]=min(min(min(get(x-1,y,t) , get(x+1,y,t) ), get (x,y-1,t) ), get(x,y+1,t) )+1;
	} 
	return arr[x][y];
}

int main()
{
	int rep,v,i,j,k;
	//char arr[14][14];
	scanf("%d",&rep);

	f(v,0,rep){
	scanf("%d",&n);
	int t=0;

f(i,0,14)
	f(j,0,14)
		arr[i][j]=-5;
	

	f(i,0,n){
		f(j,0,n){
			scanf("%c",&arr[i][j]);
		if(arr[i][j]=='*')t++;
		}
		scanf("%*c");
	}
	int ans;
	
	f(i,0,n){
		f(j,0,n){
			printf("%c",arr[i][j]);
	//	if(arr[i][j]=='*')t++;
		}
		printf("\n");
	}
	ans=get(n-1,n-1,t);

	printf("%d\n",ans);
	}
	return 0;
}
	


