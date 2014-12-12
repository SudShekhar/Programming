#include<stdio.h>
 
//#DEFINE MAX(a,b) a>b?a:b;
#define MIN(a,b) a<b?a:b;
 
int gcd(int a,int b)
{	int t;
while(a%b)
{
t=b;
b=a%b;
a=t;
}
return b;
}
int main()
{
int v,rep,n,m,a,b;
scanf("%d",&rep);
int count1,count2,c;
int lev1,lev2;
int temp;
for(v=0;v<rep;v++)
{
scanf("%d %d %d",&n,&m,&c);
count1=0;
count2=0;
 
a=n>m?n:m;
b=n<m?n:m;
 
if((c%gcd(a,b))!=0 || c>a || c<0)
{
printf("-1\n");
continue;
}
if(c==a|| c==b)
{
printf("1\n");
continue;
}
lev1=lev2=0;
while(lev1!=c && lev2!=c)
{	
if(lev2==b){
lev2=0;
// printf("emptying b\n");
}
else if(lev1==0){
lev1=a;
// printf("filling a\n");
}
else {
if(lev2 + lev1 <b){
lev2=lev2+lev1;
lev1=0;
}
else{	lev1=lev1+lev2-b;
lev2=b;
}
// printf("redistributing as a-%d and b-%d\n",lev1,lev2);
}
count1++;
}
// printf("count1 %d\n",count1);
lev1=0;
lev2=0;
while(lev2!=c && lev1!=c)
{	
if(lev1==a){
lev1=0;
// printf("emptying b\n");
}
else if(lev2==0){
lev2=b;
// printf("filling a\n");
}
else {
if(lev2 + lev1 <a){
lev1=lev1+lev2;
lev2=0;
}
else{
lev2=lev1+lev2-a;
lev1=a;
}
// printf("redistributing as a-%d and b-%d\n",lev1,lev2);
}
count2++;
if(count2>count1)break;
}
count1=MIN(count1,count2);
printf("%d\n",count1);
}
return 0;
}
 
