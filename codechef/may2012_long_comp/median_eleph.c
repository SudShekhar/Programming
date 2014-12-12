#include<stdio.h>
#include<stdlib.h>

/*void qsrt(int *arr,int l,int r)
{
//	printf("l is %d and r is %d\n",l,r);
	if(l>r)return;
	
	
//	printf("enter\n");
	int p=arr[r];
	int i,less=l,temp;
	for(i=l;i<=r;i++)
	{
		if(arr[i]<p)
		{
	//		printf("exchanging %d with pivot %d\n",arr[i],p);
			temp=arr[less];
			arr[less++]=arr[i];
			arr[i]=temp;
		}
	}
	temp=arr[less];
	arr[less]=arr[r];
	arr[r]=temp;

	qsrt(arr,l,less-1);
	qsrt(arr,less+1,r);
//	printf("**\n");
	for(i=l;i<=r;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("**\n");
	return;
}
*/

int comp(const void *a,const void *b)
{
	int *x=(int*)a;
	int *y=(int*)b;
	return *x - *y;
}
int main()
{	
	int count,flag;
	int t,n,i,j,k;
	scanf("%d",&t);
	int v;
	int max,ind,start,end;
	for(v=0;v<t;v++)
	{

		scanf("%d",&n);
		n=n+1;
			
		int arr[n];
		
		for(i=1;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		
		qsort(&arr[1],n-1,sizeof(int),comp)	;
		/*printf("sorted inp\n");
		for(i=1;i<n;i++)printf("%d ",arr[i]);
		printf("\n");
		*/
		
		max=arr[n-1];
		ind=n-1;
		
		while(arr[ind-1]==max)ind--;

		
		start=ind-1;
		if(start==0)start=1;

		end=ind+1;
		if (end==n)end=n-1;
	
//		printf("initialised ind %d start %d and end %d\n",ind,start,end);
		count=0;
		if(n==2 || ind ==1){printf("0\n");continue;}
		
		while(1)
		{
//			printf("starting serach\n");
			while(start!=1 && end!=n-1)
			{
				start--;
				end++;
			}
			if(start!=1 && end!=ind)start--;
//			printf("makig array fm %d to %d\n",start,end);
			for(i=start;i<=end;i++)
			{
				arr[i]=max;

			}
			count++;
			flag=1;
			for(i=1;i<n;i++)
			{
				if(arr[i]!=max){
					flag=0;break;}
			}
		/*	for(i=1;i<n;i++)printf("%d ",arr[i]);
			printf("\n");
		*/	if(flag==1)break;


			if(start==1)
			{
				start=ind=end;
				//max=arr[end];
			}
			else if(end==n-1)
			{
				end=ind=start;
			}
			//for(i=1;i<n;i++)printf("%d ",arr[i]);
			//printf("\n");
//			printf("reinitialised values are %d fr start and %d for end\n");
		}
		//printf("ans:- ");
		printf("%d\n",count);

	}	
		
	return 0;
	
}



