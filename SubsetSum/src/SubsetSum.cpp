//============================================================================
// Name        : SubsetSum
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : To get the value of sum of all possible subsets of a given set of numbers.
//============================================================================

#include <iostream>
#include <stdlib.h>
//#define N 10

using namespace std;


void SubsetSumInt(int* intArray, bool* hitarray, int num_ints, int sum_ints)

{

	int i = 0;
	int j=0;
for (i = 0; i < num_ints; i++)
{
	for (j = sum_ints; j >= intArray[i] ; j--)
	{
		hitarray[j] |= hitarray[j-intArray[i]];
	}
}

}


template <class T>
void SubsetSum( const T* numArray, const T sum_nums,bool* hitarray, int num_count)

{

	int i = 0;
	int j=0;
for (i = 0; i < num_count; i++)
{
	for (j = sum_nums; j >= numArray[i] ; j--)
	{
		hitarray[j] |= hitarray[j-numArray[i]];
	}
}

};


int main()
{
	//cout<<"bla"<<endl;
	int intArray[10];
	int sum = 0;


	for (int i = 0; i < 10; i++)
	{

		intArray[i] = rand()%2 + 3 ;
		cout << intArray[i] <<" ";
		sum += intArray[i];
	}

	bool* hitarray = (bool *)malloc(sizeof(bool)*(sum+3));
	for (int i = 0; i < sum+3; i++)
	{
		hitarray[i] = false;

	}
	hitarray[0]=true;
	SubsetSum(intArray,sum,hitarray,10);
	cout<<endl;
    for (int i = 0; i < sum+3; ++i)
     {
     	if( hitarray[i]) cout << "sum "<< i <<" is a hit"<<endl;
     	else cout << "sum "<< i <<" is a not hit"<<endl;

     }

	return 0;
}
