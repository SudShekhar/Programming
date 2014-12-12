#include<iostream>
#include<new>
#define f(i,start,end) for(i=start;i<end;i++)
using namespace std;
struct node{
	int data;
	node* p;
};
class stack{
	private:
		node* p;
	public:
		stack(int i)
		{
		p=new node;
		p->data=i;
		};
		
		void push(int i)
		{
			node *t;
			t=new node;
			t->data=i;
			t->p=p;
			p=t;
		}

		int pop(){
			if(p==NULL)return -1;
			node *t;
			t=p;
			p=t->p;
			
			return (t->data);
		}
		~stack(){
			if (p==NULL)return;

			node* t;
			
			while(p!=NULL)
			{
				t=p->p;
				delete p;
				p=t;
			}
		}
};

int main()
{
int i;
	stack a(5);

a.push(6);
f(i,0,10)a.push(i);

f(i,0,10)cout<<a.pop()<<endl;
i=a.pop();

cout<<"gpt " << i<<endl;

return 0;
}
