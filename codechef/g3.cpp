#include<iostream>
using namespace std;

class str{
	private:
		char *p;
	public:
		str(char* t)
		{
			p=t;
		display();
		}
	void display()
	{
		cout<<p<<endl;
	}
};

int main()
{
	str s1="absds";

	return 0;
}
