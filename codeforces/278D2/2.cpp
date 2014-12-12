#include<bits/stdc++.h>
using namespace std;

int main(){
	double arr[4];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf",&arr[i]);
	sort(arr,arr+n);
	switch(n){
		case 4:
			break;
		case 3:
			arr[3] = arr[0]+ (arr[1]+arr[2])/2;
			break;
		case 2:
			arr[2] = 4*arr[1]-arr[0];
			arr[3] = arr[0]*3;
			break;
		case 1:
			arr[1]=arr[2] = 2*arr[0];
			arr[3] = arr[2]/2*3;
			break;
	}
	double sum=0;
	for(int i=0;i<4;i++)sum+=arr[i];
	if(sum/4 == arr[3]-arr[0] && arr[3]-arr[0] == (arr[1]+arr[2])/2)
	{
		cout<<"YES\n";
		for(int k=n;k<4;k++)
			cout<<arr[k]<<endl;
	}
	else cout<<"NO\n";
	return 0;
}
