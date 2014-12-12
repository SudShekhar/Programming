/*Ques: wants magic num with only 0 and 4 st num(4)%7==0 and num(7)%4==0
 * print num(4) in smallest st num given num digits*/


#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,m,ans,rem;
	int rep,v;
	scanf("%d",&rep);
	for(v=0;v<rep;v++)
	{
		scanf("%d",&n);
		ans=(n/7)*7;//assuming num(4) is largest possible multiple(7)<n
		rem=n-ans;//num(7)=rem
		while(ans>=0)
		{
			if(rem%4==0)break;
			else
			{
				ans-=7;//checking each combo
				rem+=7;
			}
		}
		if(ans<0)
			printf("-1\n");//if no sch num possible
		else
			printf("%d\n",ans);
	}
	return 0;
}

