#include<iostream>
#include<string.h>

using namespace std;
class address{
	private :
		char name[10];
		char city[10];
	
		address (const char *a,const char *b)

		{
			strcpy(name,a);
			strcpy(city,b);
		}
public:
		void print(){
			cout<<name<<endl<<city<<endl;
			cout<<"size "<<sizeof(city) << "   name "<<sizeof(name)<<endl;
		}
};

int main()
{
	address my("sud","Londonismycuty");
	my.print();
	return 0;
}
