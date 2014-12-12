#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define f(i,start,end) for(i=start;i<end;i++)
#define SI(a) scanf("%d",&a);
#define SC(a) scanf("%c",&a);
#define ST(a) scanf("%s",a);
#define SF(a) scanf("%f",&a);
#define LL long long
#define PI(a) printf("%d\n",a);

int main()
{
	int rep,v,n,i,j,k,count,type;
	int m;
	SI(rep);
	f(v,0,rep)
	{
		SI(count);
		f(i,0,count)
		{
			SI(n);
			SI(m);
			SI(type);

			
			if(m&1)
			{
				if(n==type)
				{
					PI(m/2);
				}
				else
				{
					PI(m/2 +1);
				}
			}

			else
			{
				//if (n!=type)
					{PI(m/2);}
			//	else 
			//		PI(m/2 +1);
			}
		}
	}



	return 0;
}

