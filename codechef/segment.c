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

int flip(int node,int l,int r,int *A,int *M,int i,int j)
{
	int p1,p2;

	if(i>r || j<l)
	{
		return -1;
	}
	
	if(l>=i && r<=j)
	{
		//M[node]=!M[node];
		int x;
		for(x=l;x<=r;x++)A[x]=!A[x];
		return M[node];
		//	return M[node];
	}

	p1=flip(node*2,l,(l+r)/2,A,M,i,j);
	p2=flip(node*2+1,(l+r)/2+1,r,A,M,i,j);

	if(p1==-1)
		return M[node]=A[p2];
	if(p2==-1)
		return M[node]=A[p1];
	if(A[p1]<=A[p2])
		return M[node]=A[p1];
	//return;// M[node]=p2;
}

int count(int node,int l,int r,int *A,int *M,int i,int j)
{
	int p1,p2;

	if(i>r || j<l)
	{
		return 0;
	}
	if(l>=i && r<=j)
	{
		//M[node]=!M[node];
		//return M[node];
		if(M[node])
			return (r-l);
		else return 0;
	}

	p1=count(node*2,l,(l+r)/2,A,M,i,j);
	p2=count(node*2+1,(l+r)/2+1,r,A,M,i,j);

	/*if(p1==0)
		return M[node]=p2;
	if(p2==-1)
		return M[node]=p1;
	if(A[p1]<=A[p2])
		return M[node]=p1;*/
	return p1+p2;
}
int main()
{	int z;
	int n,i,j,k;
	int arr[100000];
	int q;
	SI(n);
	SI(q);
	int M[100000];
	rep(i,100000)
		M[i]= -1;
	f(i,1,n)
		arr[i]=0;


	init(1,0,n-1,arr,M,n);
	
	rep(i,q)
	{
	int x,y;
	SI(x);
	SI(y);
	SI(z);
	
	if(x){
		PI(count(1,0,n-1,arr,M,y,z));
				
	}
	else flip(1,0,n-1,arr,M,y,z);

		
	
	
	
	printf("segments array\n");
	rep(i,n)
		printf("%d ",M[i]);
	printf("\n");
	printf("element array\n");
	f(i,0,n) 
		printf("%d ",arr[i]);
	printf("--------------\n");
	}
	return 0;
}

