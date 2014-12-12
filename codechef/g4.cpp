#include<iostream>
using namespace std;

class rect{
	private:
		int l,b;
	public:
		rect(int x,int y){
			l=x;
			b=y;
			display();
		}
		void display()
		{
			cout<<b<<endl<<l<<endl;
		}
		~rect(){
			cout<<"the end\n"<<this->b<<endl;
		}
};

int main()
{
	rect r1(5,6);
	rect r2(5,9);
	rect *r3;
	r3= new rect(5,18);
	delete r3;
	cout<<"over\n";
	return 0;
}

