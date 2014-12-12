#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define f(i,start,end) for(i=start;i<end;i++)
int *answer;
using namespace std;
struct event{
	int start;
	int end;
	int value;
};
event * arr;
#define max(a,b) a>b?a:b
int comp(const void *a,const void*b)
{
	const event *x= (const event *)a;
	const event *y= (const event *)b;
//	cout<<"got " <<x->end << "and "<<y->end <<endl;
	
	//cout<<"compa" << x->value;
	return ((x->end) - (y->end));
/*	if(x->end>y->end)return 1;
	else if(x->end<y->end)return -1;
	else return 0;
*/	
}

int compute(event *arr,int n)
{
	int i,ans;
	if(n<0)return 0;
	if(answer[n]!=-1)
		return answer[n];
//	if(n==0)return arr[0].value;
	else
	{
		for(i=n;i>=0;i--)
		{
			if(arr[i].end<=arr[n].start)break;
		}


		answer[n]=max(compute(arr,n-1),(compute(arr,i)+arr[n].value));
		//	cout<<"max value for" <<n<<"is "<<ans<<endl;
		return answer[n];
	}

}


int main()
{

	int rep,v,n,i,j;

	cin>>rep;

	f(v,0,rep)
	{
		cin>>n;
		f(i,0,3)
		{
			arr=new event[n];
		}
		answer= new int[n];
		f(i,0,n){
			cin>>arr[i].start>>arr[i].end>>arr[i].value;
			answer[i]=-1;
		}
		
	//	cout<<"brfore"<<endl;
	/*	f(i,0,n){
		cout<<arr[i].start<<" "<<arr[i].end<<" "<<arr[i].value<<endl;
		}
*/
		qsort(arr,n,sizeof(event),comp);
	/*	cout<<"after\n";

		f(i,0,n)
		{
		cout<<arr[i].start<<" "<<arr[i].end<<" "<<arr[i].value<<endl;
		}
	*/
		cout<<compute(arr,n-1)<<endl;
		delete []answer;
		
	
	}
	
	return 0;
	
}



