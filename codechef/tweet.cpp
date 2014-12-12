#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
#define f(i,start,end) for(i=start;i<end;i++)

int main()
{
	bool *open,*close;

	int rep,v,n,k,i,j;
	char s[20];
//	cin>>rep;
	char c;
	int len;
	int count;
//	f(v,0,rep)
//	{
		count=0;
		cin>>n;
		cin>>k;
		open =new bool[n];
		
		f(i,0,k)
		{
			scanf("%c",&c);
			scanf("%[^\n]",s);
			len=strlen(s);
			//scanf("%c",&c);
	//	printf("%c\n",s[len-1]);
		if(s[len-1]=='L')
		{
			cout<<"0\n";
			f(i,0,n)open[i]=0;
			count=0;
		}
		else
		{
			open[s[len-1]-'0'-1]=!(open[s[len-1]-'0'-1]);
			if(open[s[len-1]-'0'-1]){
				count++;
			}
			else count--;

			cout<<count<<endl;
		}


		//cout<<s;
	//	}

	}
	return 0;
}

