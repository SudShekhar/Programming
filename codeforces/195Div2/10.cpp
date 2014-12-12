#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
#define sqr(x) ((x) * (x))
using namespace std;
#define N 200005

int a[N], ans, m, n, now;
set<int> z;

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n ; ++i)
        scanf("%d", &a[i]);
    int j, flag = 0;
    for (j = 30; j >= 0; --j)
    {
        m = 0;
        for (int i = 1; i <= n; ++i)
        if ((a[i] >> j) & 1)
        {
            if (m) now = now & a[i], m++;
            else now = a[i], m++;
        }
        if (m && now % (1 << j) == 0)
        {
            flag = 1;
            break;
        }
    }
   
        for (int i = 1; i <= n; ++i)
        if ((a[i] >> j) & 1)
            z.insert(a[i]);
    
   
    printf("%d\n", z.size());
    for (set<int>::iterator p = z.begin(); p != z.end(); ++p)
        printf("%d ", *p);
    printf("\n");
    return 0;
}
