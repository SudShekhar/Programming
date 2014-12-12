#include<bits/stdc++.h>
using namespace std;
bool has(int x){
	if(x<0)x=-x;
	bool ans=false;
	bool add=false;
	while(x!=0){
		if(x%10 == 8)
			ans=true;
		x/=10;
	}
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	int cnt=0;
	if(has(n))cnt++,n++;
	while(1){
		if(has(n)){
			cout<<cnt<<endl;
			break;
		}
		n++;
		cnt++;
	}
	return 0;
}
