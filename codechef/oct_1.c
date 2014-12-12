#include<stdio.h>
#include<stdlib.h>
#define f(i,start,end) for(i=start;i<end;i++)

int bins(int i,int *arr,int r,int l)
{	
	if(l>r)return -1;
	int m=(l+r)/2;
	
	if(arr[m]==i)return m;
	else if(arr[m]<i)return bins(i,arr,r,m+1);
	else return bins(i,arr,m-1,l);

}
int comp(const void*a,const void*b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int ans;
	int T,Nin,Nfl,L;
	int i,j,k;
	scanf("%d",&T);
	int sin[2][100];
	int len;
	int rc;
	while(T)
	{
		ans=0;
		len=0;
	scanf("%d %d",&Nin,&Nfl);
	f(i,0,Nin) 
		{
		scanf("%d %d",&k,&L);
		rc=-1;
		f(j,0,len)if(L==sin[1][j])rc = j;
			if(rc==-1)
			{//	printf("got new level %d\n",L);
				sin[0][len]=k;
				sin[1][len++]=L;
			}
		else sin[0][rc]+=k;
		}
		//scanf("%d %d",&sin[0][i],&sin[1][i]);
	
//	f(i,0,len)printf("%d %d \n",sin[0][i],sin[1][i]);
/*	printf("\n");
//	qsort(sin[1],sizeof(int),len,comp);

	f(i,0,len)printf("%d ",sin[1][i]);
	printf("\n");
*/
	f(i,0,Nfl)
	{
		scanf("%d %d",&k,&L);
		//rc=bins(L,sin[1],len,0);
		f(j,0,len){
			if(sin[1][j]==L)
			{
				sin[0][j]-=k;

				if(sin[0][j]<0){
					ans-=sin[0][j];
					sin[0][j]=0;
				}
			break;
			}
		}
	//	printf("level is %d\n",rc);
	}
	printf("%d\n",ans);
	T--;
	}
	
return 0;
}
