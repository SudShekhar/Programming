#include<iostream>
using namespace std;
class sample{
	private:
		int data1;
		int data2;

		class node{
			public:
			int data;
			node* link;
		}*p;

	public:
		 sample();
		void display();
		void create(int i){
			p=new node;
			p->data=i;
		}
};

int  main()
{
	sample s;
	s.create(5);
	s.display();
	return 0;
}

sample:: sample()
{
	data1=5;
	data2=2;
}

void sample::display()
{
	cout<< data1 << "   " <<data2<<endl;
	cout<< "p has " <<p->data<< endl;
}
