#include<iostream>
#include<string>
#include<stdio.h>
int main()
{
	int i,j,n;
char ch;
	scanf("%d",&n);
	scanf("%c",&ch);

	for(j=1;j<=n;j++)
	{
		char line[1000],c[27];

		gets(line);
//		printf("%s\n",line);
		//scanf("%[^\n]",line);
		scanf("%s",c);
		scanf("%c",&ch);
		
		
		for(i=0;line[i]!='\0';i++)
		{
			if(line[i]!=' ')
			{
				int x=(int)line[i];
				x=x-65;
				line[i]=c[x];
				//line[i]=c[(int)line[i]-65];
			}
		}
		printf("%d %s\n",j,line);

	
	}
	return 0;
}
		
