#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
	int m,u;
	scanf("%d ",&m);
	char s[500];
	int a[26];
	for(u=0;u<m;u++)
	{
		scanf("%[^\n] ",s);
		int len=strlen(s);
		int i;
		for(i=0;i<26;i++)
			a[i]=0;
		for(i=0;i<len;i++)
		{
			if(s[i]>='a' && s[i]<='z')
				a[s[i]-'a']++;
			else if(s[i]>='A' && s[i]<='Z')
				a[s[i]-'A']++;
		}
		int j;
		for(i=0;i<26;i++)
		{
			for(j=i+1;j<26;j++)
			{
				if(a[j]>a[i])
				{
					int temp=a[j];
					a[j]=a[i];
					a[i]=temp;
				}
			}
		}
		long long int ans=0;
		for(i=0;i<26;i++)
		{
			if(a[i]==0)
				break;
			else
				ans+=(26-i)*a[i];
		}
		printf("Case #%d: %lld\n",u+1,ans);


	}

	return 0;
}
