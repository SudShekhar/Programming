#include<iostream>
#include<stdio.h>
#include<iomanip>
#define COL 3
#define ROW 3
using namespace std;


struct matrix
{
	int arr[ROW][COL];
};

void init(matrix*,int);
void pr(matrix);
matrix operator +(matrix a,matrix b);
matrix operator -(matrix a,matrix b)
{	int i,j;
	matrix m;
	for(i=0;i<ROW;i++)
		for(j=0;j<COL;j++)
			m.arr[i][j]=a.arr[i][j]-b.arr[i][j];

	return m;
}

matrix operator *(matrix a,matrix b)
{
	int i,j,k;
	matrix c;
	for(i=0;i<ROW;i++)
		for(j=0;j<COL;j++)
		{
			c.arr[i][j]=0;

			for(k=0;k<ROW;k++)
				c.arr[i][j]+=(a.arr[i][k]*b.arr[k][j]);
		}
	return c;
}

int main()	
{

	matrix a,b,c;
	init(&a,3);
	init(&b,5);
//	pr(a);
	c=a+b;
	b=c-b;

	pr(c);
	cout<<"hwllo\n\n";
	pr(b);

	a=c*b;

	pr(a);
	return 0;
}



void init(matrix *m,int v)
{
	int i,j;

	for(i=0;i<ROW;i++)
		for(j=0;j<COL;j++)
			m->arr[i][j]=v;

	return;
}

void pr(matrix m)
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
			cout<<m.arr[i][j]<<"   ";
		cout<<endl;
	}
	return;
}

matrix operator +(matrix a,matrix b)
{
	int i,j;
	matrix m;
	for(i=0;i<ROW;i++)
		for(j=0;j<COL;j++)
			m.arr[i][j]=a.arr[i][j]+b.arr[i][j];

	return m;
}
