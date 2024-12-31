#include <iostream>
#include "SimpleVector.h"
#include <vector>

using namespace std;

int main()
{
    SimpleVector<int>* SV = new SimpleVector<int>(3);
    
    SV->push_back(5);
    SV->push_back(2);
    SV->push_back(9);
    SV->push_back(7);
    SV->push_back(1);

    cout<<"===========";
    SV->sortData();

    int b = 1;
	 vector<int> a;
     a.reserve(10);
	 a.push_back(5);
	 a.push_back(2);
	 a.push_back(9);
	 a.push_back(7);
	 a.push_back(1);

     sort(a.begin(), a.end());

	 a.pop_back();
	 a.pop_back();
	 a.pop_back();
    //vector<int> vi = new vector<int>(3);
}
