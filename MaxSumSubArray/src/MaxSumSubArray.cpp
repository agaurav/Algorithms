//============================================================================
// Name        : MaxSumSubArray.cpp
// Author      : Ashish Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Given an array of positive & negative values find the subarray (continuous) having max sum of its element
//============================================================================

#include <iostream>
#include <cstdlib>
#define N 10
using namespace std;

template<class T>
const T MaxSumSubArray(const T* dArray, int count)
    {
    T* maxSum = (T*) malloc(sizeof(T)*count);
    int i;
    T maxS;
    maxSum[0] = dArray[0];
    maxS = maxSum[0];
    if(count == 1)
	return (maxSum[0]);
    for (i=1;i<count;i++)
	{
	maxSum[i] = max(dArray[i],maxSum[i-1]+dArray[i]);
	maxS<maxSum[i]?maxS=maxSum[i]:maxS;
	}
    return (maxS);
    }
;

int main()
    {
    int mi,mj,mx;
    double val[N];
    cout<<endl;
    for(mi=0;mi<N;mi++)
	{
	mj = rand();
	mx = rand();
	val[mi] = mx-mj;
	//val[mi] = (double) (rand()%8 -4);
	cout<<val[mi]<<" ";
	}

    cout<<endl<<MaxSumSubArray(val,N);

    return (0);
    }
