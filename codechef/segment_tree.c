#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define PI(a) printf("%d\n",a);
#define f(i,start,end) for(i=start;i<end;i++)
#define SI(a) scanf("%d",&a);
#define SC(a) scanf("%c",&a);
#define ST(a) scanf("%s",a);
#define SF(a) scanf("%f",&a);
#define LL long long
#define rep(i,end) for(i=0;i<end;i++)
void init(int node,int l,int r,int *arr,int *M,int n)
{
	if(l==r) 
	{
		M[node]=0;
	//	PI(l);
	}
	else
	{	
		//printf("calling %d-%d\n",l,(l+r)/2);
		init(2*node,l,(r+l)/2,arr,M,n);
		
//		printf("calling %d-%d\n",(l+r)/2+1,r);
		init(2*node+1,(l+r)/2+1,r,arr,M,n);

		if(arr[M[2*node]]<=arr[M[2*node+1]])
			M[node]=M[2*node];
		else
			M[node]=M[node*2 +1];
//		printf("set set M[%d] == %d\n",node,M[node]);
	
	}
}

int query(int node,int l,int r,int *A,int *M,int i,int j)
{
	int p1,p2;

	if(i>r || j<l)
	{
		return -1;
	}
	if(l>=i && r<=j)
	{
		return M[node];
	}

	p1=query(node*2,l,(l+r)/2,A,M,i,j);
	p2=query(node*2+1,(l+r)/2+1,r,A,M,i,j);

	if(p1==-1)
		return M[node]=p2;
	if(p2==-1)
		return M[node]=p1;
	if(A[p1]<=A[p2])
		return M[node]=p1;
	return M[node]=p2;
}



int main()
{
	int n,i,j,k;
	int arr[1000];
	int q;
	SI(n);
	SI(q);
	int M[1000];
	rep(i,1000)
		M[i]= -1;
	f(i,1,n)
		arr[i]=i;


	init(1,0,n-1,arr,M,n);
	
	int x,y;
	printf("enert\n");
	SI(x);
	SI(y);

	printf("---%d----\n",arr[query(1,0,n-1,arr,M,x,y)]);
	
	
	rep(i,n)
		PI(M[i]);

	f(i,0,n) printf("%d ",arr[i]);
	printf("\n");
	return 0;
}

