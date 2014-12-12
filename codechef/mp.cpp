#include<iostream>

using namespace std;
void f(int i=10,int j=5,int k=10);
void f(int);
int main()
{
	f(1,6);
	return 0;
}

void f(int i,int j,int k)
{
	cout<<i<<"two " <<j<<"  " <<k<< endl;

}
void f(int i)
{
	cout <<"one" <<i<<endl;
}
