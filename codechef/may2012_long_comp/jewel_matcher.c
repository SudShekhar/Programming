#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int rep,v,i,j;
	char jew[102],mine[102];
	scanf("%d",&rep);
	char c;
	int k,l,flag;
	int count;
	for(v=0;v<rep;v++)
	{	k=0;l=0;
		flag=0;
	//	scanf("%s %s",jew,mine);
		
		scanf(" %c",&c);
		//printf("\n value of c is %c\n",c);
		
		
		while (1)
		{	flag=0;
			//if(bins(jew,k,c))jew[k++]=c;
			for(i=0;i<k;i++)
			{
				if(jew[i]==c)
				{
					flag=1;
					break;
				}
			}
			if(flag==0){
				jew[k++]=c;
			//	printf("inserted %c\n",jew[k-1]);
			}
			
			scanf("%c",&c);
			if(c==' '||c=='\n')break;
		}
		jew[k]='\0';
	//	printf("%s",jew);
		scanf("%s",mine);
		count=0;
		for(i=0;i<strlen(jew);i++)
		{
			for(j=0;j<strlen(mine);j++)
			{
				if(jew[i]==mine[j])count++;
			}
		}
		printf("%d\n",count);
	}
return 0;
}
