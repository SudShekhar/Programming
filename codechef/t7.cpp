#include<iostream>
using namespace std;
class user{
	private:
		int i;
		float j;

	public:
		user(){
			i=10; j=8.5;
		}

		
		void display(){
			cout<<i<<endl<<j<<endl;
		}
};

int main()
{	
	cout<< sizeof(user);
	user u1;
	cout<<endl<<sizeof(u1)<<endl;
	u1.display();
	return 0;
}

