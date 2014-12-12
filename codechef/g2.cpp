#include<iostream>
using namespace std;

class data{
	private:
		int m1,m2;
	public:
		data(){
			display();
			cout<<"constructor"<<endl;
		}
		void display(){
			cout<<"hel ";
		}
};
int main()
{
	data d1;
	return 0;
}
