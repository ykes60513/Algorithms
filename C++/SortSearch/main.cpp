#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdexcept>

#include "SortAlg.h"
#include "SearchAlg.h"
using namespace std;

inline int generate(){ return (rand()%100 + 1);}

int main(int argc, char* argv[])
{
	int number;
	string choose;
	bool loop = true;
	cout<<"Create array by yourself or automatically? (1/2)\n";
	while (loop){
		try{
			cin>>choose;
			if( stoi(choose) != 1 && stoi(choose) != 2){
				cout<<"Please enter number 1 or 2\n";
			}
			else{
				loop = false;
				break;
			}
		}
		catch(invalid_argument&){
			cout<<"Please enter a valid integer\n";
		}
	}
	cout<<"How many values do you want to sort\n";
	cin>>number;
	int* sortArray = new int[number];
	srand(clock());
	for(int i =0;i<number;i++){
		if(stoi(choose) == 1)
			cin>>sortArray[i];
		else
			sortArray[i] = generate();
	}
	cout<<left<<setw(10)<<"Unsorted"<<": ";
	display(number,sortArray);
	cout<<"Please choose a way you want to sort:\n";
	string method;
	loop = true;
	while(loop){
		cout<<"1.exchangesort 2.mergesort 3.quicksort 4.insertionsort 5.selectionsort\n";
		try
		{
			cin>>method;
			switch(stoi(method)){
				case 1:
					exchangesort(number,sortArray);
					loop = false;
					break;
				case 2:
					mergesort(number,sortArray);
					loop = false;
					break;
				case 3:
					quicksort(0,number-1,sortArray);
					loop = false;
					break;
				case 4:
					insertionsort(number,sortArray);
					loop = false;
					break;
				case 5:
					selectionsort(number,sortArray);
					loop = false;
					break;
				default:
					cout<<"Please enter a valid number:\n";
			}
		}
		catch(invalid_argument&){
			cout<<"Please enter a valid number:\n";
		}

	}

	//exchangesort(number,sortArray);
	cout<<left<<setw(10)<<"Sorted"<<": ";
	display(number,sortArray);
	//cout<<binarySearch(number,sortArray,50)<<"\n";
	return 0;
	//TEST
}
