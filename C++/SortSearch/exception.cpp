#include <iostream>
#include <string>

#include <stdexcept>
using namespace std;
int main()
{
	string qwe;
	cin>>qwe;
	int choose;
	try{
		cin>>choose;
		cout<<stoi(qwe)<<"\n";
		int a[3] = {1,2,3};
		cout<<sizeof(a)/sizeof(a[0])<<"\n";
		cout<<choose<<"\n";

	}
	catch(invalid_argument&){
		cout<<"ERROR\n";
	}
	return 0;
}
