#include<iostream>
using namespace std;

class date{
	private:
		int dd,mm;

	public:
		date(){
			cout<<"reached" << endl;
		}
};

int main()
{
	date today;
	date *p=&today;
	cout<<p<<endl;
	return 0;
}
