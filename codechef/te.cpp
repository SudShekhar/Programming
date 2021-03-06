#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 502, oo = 1<<30;
int opt[MAX][MAX], n, k, a[MAX], r;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		r = oo;
		scanf("%d %d", &n, &k);
		
		for( int i = 1; i <= n; i ++)
			scanf("%d", a + i);
		
		sort(a + 1, a + n + 1, greater<int>());
		
		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		cout<<endl;

		for( int i = 0; i <= n; i++)
			for( int j = 0; j <= n; j++)
				opt[i][j] = oo;
		opt[0][0] = 0;
		
		for( int K = 0; K < k; K++)
			for( int i = 0; i <= n; i++)
				for( int j = i + 1; j <= n; j++)
					opt[K + 1][j] = min (opt[K + 1][j] , opt[K][i] + a[j]*(j - i));
		
		for( int i = 0; i <= n; i++)
		{
			for( int j = 0; j <= n; j++)
				cout<<opt[i][j]<<" ";
		cout<<endl;
		}


		for( int i = 0; i <= n; i++)
			r = min( r, opt[k][i]);
		
		
		printf("%d\n", r);
	}
	return 0;
}
