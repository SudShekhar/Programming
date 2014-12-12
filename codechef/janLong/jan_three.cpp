    #include<stdio.h>
    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
     
    #define MOD 1000000007
    int main(){
    int re,v;
    scanf("%d",&re);
    long long one,two,three;
    vector<long long > arr(3);
    for(v=0;v<re;v++){
    scanf("%lld %lld %lld",&arr[0],&arr[1],&arr[2]);
    // cout<<arr[0]<<endl;
    sort(arr.begin(),arr.end());
    // cout<<arr[0]<<endl;
    arr[0]%=MOD;
    arr[1]=(arr[1]-1)%MOD;
    arr[2]=(arr[2]-2)%MOD;
    long long ans=(((arr[0]*(arr[1]))%MOD)*(arr[2]))%MOD;
    cout<<ans<<endl;
    }
    return 0;
    }
